/**
* @file pacientes.c
 * @brief Implementação do sistema de gerenciamento de pacientes
 * @author Isabella,Anita,Henrique,Pablo
 * @date 2025-06-29
 *
 * Contém a implementação completa de todas as funções declaradas
 * no arquivo pacientes.h, com manipulação de arquivos e memória.
 */

#include "pacientes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


p_paci pacientes[MAX_Pacientes]; ///< Array global de ponteiros para pacientes
int totalPacientes = 0;          ///< Contador atual de pacientes cadastrados

/// Atribuição do caminho para do TXT para uma variável para mais facilidade
const char *ARQUIVO_PACIENTES = "C:\\Users\\anita\\CLionProjects\\ProjetoMaromo\\ClinicaAumigosdoCoracao\\pacientes.txt";

/* [Funções auxiliares já documentadas no .h] */
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void inicializaPacientes() {
    for (int i = 0; i < MAX_Pacientes; i++) {
        pacientes[i] = NULL;
    }
    carregarPacientesDoArquivo();
}

/**
 * @brief Gera um ID único e aleatório de 9 dígitos
 * @return long ID no intervalo 100.000.000 - 999.999.999
 *
 * Implementação:
 * 1. Inicializa o gerador de números aleatórios na primeira chamada (seed baseada no tempo)
 * 2. Gera um número no intervalo [100.000.000, 999.999.999]
 *
 * Características:
 * - Garante 9 dígitos fixos
 * - Baixa probabilidade de colisão (1 em 900 milhões)
 * - Não é criptograficamente seguro
 *
 * Exemplo de uso:
 * long novo_id = gerar_id_unico();
 * printf("ID Gerado: %ld", novo_id);
 */
long gerar_id_unico() {
    static int inicializado = 0;
    if (!inicializado) {
        srand(time(NULL));
        inicializado = 1;
    }
    return 100000000 + (rand() % 900000000); // Entre 100.000.000 e 999.999.999
}

/*
 * @brief Exibe os dados completos de um paciente
 * Ponteiro para o paciente (NULL-safe)
 *
 * @warning Exibe mensagem de erro se ponteiro for NULL
 * @note Formatação consistente com bordas visuais
 */
void exibirDadosPaciente(paciente *p_a) {
    if (p_a == NULL) {
        printf("Paciente não encontrado.\n");
        return;
    }
    printf("\n-----------------------------\n");
    printf("ID: %ld\n", p_a->ID);
    printf("Nome Paciente: %s\n", p_a->NOMEp);
    printf("Idade: %d meses\n", p_a->IDADE);
    printf("Tutor: %s\n", p_a->NOMEt);
    printf("Especie: %s\n", p_a->ESPECIE);
    printf("Raca: %s\n", p_a->RACA);
    printf("Telefone: %lld\n", p_a->TELEFONE);
    printf("-----------------------------\n");
}

/* ----------------- PERSISTÊNCIA ----------------- */

/**
 * @brief Salva todos os pacientes no arquivo TXT
 *
 * Formato do arquivo:
 * ID;Nome;Especie;Raça;Idade;Tutor;Telefone;\n
 *
 * @warning Sobrescreve o arquivo completamente a cada operação
 * Imprime mensagem de erro se falhar ao abrir arquivo
 */
void salvarPacientesNoArquivo() {
    FILE *arquivo = fopen(ARQUIVO_PACIENTES, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar!\n");
        return;
    }

    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i] != NULL) {
            fprintf(arquivo, "%ld;%s;%s;%s;%d;%s;%lld;\n",
                   pacientes[i]->ID,
                   pacientes[i]->NOMEp,
                   pacientes[i]->ESPECIE,
                   pacientes[i]->RACA,
                   pacientes[i]->IDADE,
                   pacientes[i]->NOMEt,
                   pacientes[i]->TELEFONE);
        }
    }
    fclose(arquivo);
}

/**
 * @brief Carrega pacientes do arquivo TXT para memória
 *
 * @details Processamento:
 * 1. Abre arquivo em modo leitura
 * 2. Passa por cada linha usando strtok()
 * 3. Aloca memória para cada paciente
 * 4. Adiciona ao array global
 *
 * @note Cria arquivo novo se não existir
 * @warning Faz validação básica de campos
 */
void carregarPacientesDoArquivo() {
    FILE *arquivo = fopen(ARQUIVO_PACIENTES, "r");
    if (arquivo == NULL) {
        printf("Arquivo de pacientes não encontrado. Um novo será criado.\n");
        return;
    }

    char linha[512];
    while (fgets(linha, sizeof(linha), arquivo) != NULL && totalPacientes < MAX_Pacientes) {
        paciente *p = (paciente*)malloc(sizeof(paciente));
        if (p == NULL) continue;

        char *token = strtok(linha, ";");
        if (token == NULL) {
            free(p);
            continue;
        }
        p->ID = atol(token);

        token = strtok(NULL, ";");
        if (token == NULL) {
            free(p);
            continue;
        }
        strncpy(p->NOMEp, token, MAX_NOMEP);

        token = strtok(NULL, ";");
        if (token == NULL) {
            free(p);
            continue;
        }
        strncpy(p->ESPECIE, token, MAX_ESPECIE);

        token = strtok(NULL, ";");
        if (token == NULL) {
            free(p);
            continue;
        }
        strncpy(p->RACA, token, MAX_RACA);

        token = strtok(NULL, ";");
        if (token == NULL) {
            free(p);
            continue;
        }
        p->IDADE = atoi(token);

        token = strtok(NULL, ";");
        if (token == NULL) {
            free(p);
            continue;
        }
        strncpy(p->NOMEt, token, MAX_NOMET);

        token = strtok(NULL, ";");
        if (token == NULL) {
            free(p);
            continue;
        }
        p->TELEFONE = atoll(token);

        pacientes[totalPacientes++] = p;
    }
    fclose(arquivo);
}

/* ----------------- OPERAÇÕES FUNDAMENTAIS ----------------- */

/**
 * @brief Cadastra um novo paciente no sistema
 *
 * Fluxo completo:
 * 1. Valida capacidade máxima
 * 2. Coleta dados interativamente
 * 3. Aloca memória
 * 4. Adiciona ao array
 * 5. Persiste no arquivo
 *
 * @warning Mensagens de erro para:
 * - Limite excedido
 * - Falha de alocação
 *
 * Atualiza arquivo imediatamente após cadastro
 */
void cadastrarPaciente() {
    if (totalPacientes >= MAX_Pacientes) {
        printf("Limite máximo de pacientes atingido!\n");
        return;
    }

    paciente temp;

    temp.ID = gerar_id_unico();
    printf("ID gerado: %ld\n", temp.ID);

    printf("Nome do paciente: ");
    fgets(temp.NOMEp, MAX_NOMEP, stdin);
    removerNovaLinha(temp.NOMEp);

    printf("Idade (em meses): ");
    scanf("%d", &temp.IDADE);
    limparBufferEntrada();

    printf("Nome do tutor: ");
    fgets(temp.NOMEt, MAX_NOMET, stdin);
    removerNovaLinha(temp.NOMEt);

    printf("Especie: ");
    fgets(temp.ESPECIE, MAX_ESPECIE, stdin);
    removerNovaLinha(temp.ESPECIE);

    printf("Raca: ");
    fgets(temp.RACA, MAX_RACA, stdin);
    removerNovaLinha(temp.RACA);

    printf("Telefone: ");
    scanf("%lld", &temp.TELEFONE);
    limparBufferEntrada();

    pacientes[totalPacientes] = (paciente*)malloc(sizeof(paciente));
    if (pacientes[totalPacientes] == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    *pacientes[totalPacientes] = temp;
    totalPacientes++;

    salvarPacientesNoArquivo();
    printf("Paciente cadastrado com sucesso!\n");
}

/**
 * @brief Consulta paciente por ID(long)
 *
 * Realiza busca linear no array de pacientes
 */
void consultarPacienteID() {
    long id;
    printf("Digite o ID: ");
    scanf("%ld", &id);
    limparBufferEntrada();

    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i] != NULL && pacientes[i]->ID == id) {
            exibirDadosPaciente(pacientes[i]);
            return;
        }
    }
    printf("Paciente não encontrado!\n");
}

/**
 * @brief Consulta paciente por Nome(string)
 *
 * Realiza busca linear no array de pacientes
 */
void consultarPacienteNome() {
    char nome[MAX_NOMEP];
    printf("Digite o nome (ou parte): ");
    fgets(nome, MAX_NOMEP, stdin);
    removerNovaLinha(nome);

    int encontrados = 0;
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i] != NULL && strstr(pacientes[i]->NOMEp, nome) != NULL) {
            exibirDadosPaciente(pacientes[i]);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum paciente encontrado!\n");
    }
}

/**
 * @brief Consulta paciente por Especie(string)
 *
 * Realiza busca linear no array de pacientes
 */
void consultarPacienteEspecie() {
    char especie[MAX_ESPECIE];
    printf("Digite a espécie: ");
    fgets(especie, MAX_ESPECIE, stdin);
    removerNovaLinha(especie);

    int encontrados = 0;
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i] != NULL && strstr(pacientes[i]->ESPECIE, especie) != NULL) {
            exibirDadosPaciente(pacientes[i]);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum paciente encontrado!\n");
    }
}

/**
 * @brief Consulta paciente por Raca(string)
 *
 * Realiza busca linear no array de pacientes
 */
void consultarPacienteRaca() {
    char raca[MAX_RACA];
    printf("Digite a raça: ");
    fgets(raca, MAX_RACA, stdin);
    removerNovaLinha(raca);

    int encontrados = 0;
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i] != NULL && strstr(pacientes[i]->RACA, raca) != NULL) {
            exibirDadosPaciente(pacientes[i]);
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum paciente encontrado!\n");
    }
}

/**
 * @brief Edita os dados de um paciente existente
 *
 * Essa função permite mudar as informações de um animal já cadastrado.
 *
 * Como funciona:
 * 1. Pede o número de ID do paciente
 * 2. Procura o paciente no sistema
 * 3. Se achar, mostra os dados atuais
 * 4. Pergunta cada informação que pode ser alterada
 *    - Se apertar ENTER sem digitar nada, mantém o valor antigo
 * 5. Salva as mudanças no arquivo
 *
 * Exemplo de uso:
 * > Digite o ID do paciente: 123456789
 * > (Mostra os dados atuais)
 * > Novo nome [Rex]:
 * > (Se apertar ENTER, continua "Rex")
 *
 * @warning Atenção:
 * - O ID não pode ser alterado
 * - As mudanças são salvas automaticamente
 * - Se digitar errado, não tem como desfazer!
 */
void alterarDadosPaciente() {
    long id;
    printf("Digite o ID do paciente: ");
    scanf("%ld", &id);
    limparBufferEntrada();

    int index = -1;
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i] != NULL && pacientes[i]->ID == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Paciente não encontrado!\n");
        return;
    }

    exibirDadosPaciente(pacientes[index]);
    printf("\nEDITANDO PACIENTE (deixe em branco para manter)\n");

    char buffer[MAX_NOMEP];

    printf("Novo nome [%s]: ", pacientes[index]->NOMEp);
    fgets(buffer, MAX_NOMEP, stdin);
    removerNovaLinha(buffer);
    if (strlen(buffer) > 0) {
        strcpy(pacientes[index]->NOMEp, buffer);
    }

    printf("Nova idade [%d]: ", pacientes[index]->IDADE);
    fgets(buffer, MAX_NOMEP, stdin);
    removerNovaLinha(buffer);
    if (strlen(buffer) > 0) {
        pacientes[index]->IDADE = atoi(buffer);
    }

    printf("Novo tutor [%s]: ", pacientes[index]->NOMEt);
    fgets(buffer, MAX_NOMET, stdin);
    removerNovaLinha(buffer);
    if (strlen(buffer) > 0) {
        strcpy(pacientes[index]->NOMEt, buffer);
    }

    printf("Nova especie [%s]: ", pacientes[index]->ESPECIE);
    fgets(buffer, MAX_ESPECIE, stdin);
    removerNovaLinha(buffer);
    if (strlen(buffer) > 0) {
        strcpy(pacientes[index]->ESPECIE, buffer);
    }

    printf("Nova raca [%s]: ", pacientes[index]->RACA);
    fgets(buffer, MAX_RACA, stdin);
    removerNovaLinha(buffer);
    if (strlen(buffer) > 0) {
        strcpy(pacientes[index]->RACA, buffer);
    }

    printf("Novo telefone [%lld]: ", pacientes[index]->TELEFONE);
    fgets(buffer, MAX_RACA, stdin);
    removerNovaLinha(buffer);
    if (strlen(buffer) > 0) {
        pacientes[index]->TELEFONE = atoll(buffer);
    }

    salvarPacientesNoArquivo();
    printf("Dados atualizados com sucesso!\n");
}

/**
 * @brief Exclui paciente do sistema
 *
 * @details Operação IRREVERSÍVEL que:
 * 1. Libera memória alocada
 * 2. Reorganiza o array
 * 3. Atualiza o arquivo
 *
 * Arquivo atualizado imediatamente
 */
void excluirPaciente() {
    long id;
    printf("Digite o ID do paciente a excluir: ");
    scanf("%ld", &id);
    limparBufferEntrada();

    int cont = -1;
    for (int i = 0; i < totalPacientes; i++) {
        if (pacientes[i] != NULL && pacientes[i]->ID == id) {
            cont = i;
            break;
        }
    }

    if (cont == -1) {
        printf("Paciente não encontrado!\n");
        return;
    }

    free(pacientes[cont]);
    for (int i = cont; i < totalPacientes - 1; i++) {
        pacientes[i] = pacientes[i + 1];
    }
    totalPacientes--;
    salvarPacientesNoArquivo();
    printf("Paciente excluído com sucesso!\n");
}

/**
 * @brief Lista todos os pacientes cadastrados
 *
 * @details Exibe relatório completo com:
 * - Todos os campos de cada paciente
 * - Contagem total
 *
 * @warning Mensagem de aviso se nenhum paciente cadastrado
 */
void visualizarTodosPacientes() {
    if (totalPacientes == 0) {
        printf("Nenhum paciente cadastrado!\n");
        return;
    }

    printf("\n=== LISTA DE PACIENTES ===\n");
    for (int i = 0; i < totalPacientes; i++) {
        exibirDadosPaciente(pacientes[i]);
    }
    printf("Total: %d pacientes\n", totalPacientes);
}