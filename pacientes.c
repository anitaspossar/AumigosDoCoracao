#include "pacientes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


p_paci pacientes[MAX_Pacientes];
int totalPacientes = 0;
const char *ARQUIVO_PACIENTES = "C:\\Users\\anita\\CLionProjects\\ProjetoMaromo\\ClinicaAumigosdoCoracao\\pacientes.txt";

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

long gerar_id_unico() {
    static int inicializado = 0;
    if (!inicializado) {
        srand(time(NULL));
        inicializado = 1;
    }
    return 100000000 + (rand() % 900000000); // Entre 100.000.000 e 999.999.999
}

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

void excluirPaciente() {
    long id;
    printf("Digite o ID do paciente a excluir: ");
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

    free(pacientes[index]);
    for (int i = index; i < totalPacientes - 1; i++) {
        pacientes[i] = pacientes[i + 1];
    }
    totalPacientes--;
    salvarPacientesNoArquivo();
    printf("Paciente excluído com sucesso!\n");
}

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