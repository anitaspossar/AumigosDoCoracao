#include "pacientes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Definicao do array global para ponteiro de pacientes
p_paci pacientes[MAX_Pacientes];

//funcao para remover o buffer caracteres restantes da memoria do teclado
void limparBufferEntrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerNovaLinha(char * str){
    size_t len = strlen(str);
    if (len > 0 && str[len -1] == '\n') {
        str[len - 1] = '\0';
    }
}

void exibirDadosPaciente(paciente *p_a){
    if (p_a == NULL) {
        printf("Referencia de paciente nula... \n");
        return;
    }
    printf("\n-----------------------------\n");
    printf("ID: %d \n", p_a->ID);
    printf("Nome Paciente: %s \n", p_a->NOMEp);
    printf("Idade do paciente: %d \n", p_a->IDADE);
    printf("Nome Tutor: %s \n", p_a->NOMEt);
    printf("Especie: %s \n", p_a->ESPECIE);
    printf("Raca: %s \n", p_a->RACA);
    printf("Telefone para contato: %.0lf \n", p_a->TELEFONE);
    printf("-----------------------------\n");
}

void inicializaPacientes(){
    for (int i=0; i<MAX_Pacientes; i++) {
        pacientes[i] = NULL;
    }
}

//cadastrar novo paciente
void cadastrarPaciente(){
    int i = 0;
    int posicao = -1;
    for (i=0; i<MAX_Pacientes;i++) {
        if (pacientes[i] == NULL) {
            posicao = i;
            break;
        }
    }
    if (posicao == -1) {
        printf("Nao ha espaco na memoria para mais pacientes\n");
        return;
    }

    pacientes[posicao] =(paciente*) malloc(sizeof(paciente));
    if (pacientes[posicao] == NULL) {
        printf("Alocacao invalida\n");
        return;
    }

    printf("Cadastrando novo paciente na posicao %d. \n", posicao);
    //Leitura do id
    printf("Digite o numero do ID do paciente: \n");
    scanf("%d", &pacientes[posicao]->ID);
    limparBufferEntrada();

    printf("Digite o nome do paciente: \n");
    fgets(pacientes[posicao]->NOMEp, sizeof(pacientes[posicao]->NOMEp), stdin);
    removerNovaLinha(pacientes[posicao]->NOMEp);

    printf("Digite a idade do paciente(em meses): \n");
    scanf("%d", &pacientes[posicao]->IDADE);
    limparBufferEntrada();

    printf("Digite o nome do tutor: \n");
    fgets(pacientes[posicao]->NOMEt, sizeof(pacientes[posicao]->NOMEt), stdin);
    removerNovaLinha(pacientes[posicao]->NOMEt);

    printf("Digite a especie do paciente: \n");
    fgets(pacientes[posicao]->ESPECIE, sizeof(pacientes[posicao]->ESPECIE), stdin);
    removerNovaLinha(pacientes[posicao]->ESPECIE);

    printf("Digite a raca do paciente: \n");
    fgets(pacientes[posicao]->RACA, sizeof(pacientes[posicao]->RACA), stdin);
    removerNovaLinha(pacientes[posicao]->RACA);

    // Colocar um if para conferir se o telefone tem todos os digitos (sem faltar algum digito)
    printf("Digite o telefone para contato: \n");
    scanf("%lf", &pacientes[posicao]->TELEFONE);
    limparBufferEntrada();

    printf("Paciente [%s] cadastrado com sucesso..\n", pacientes[posicao]->NOMEp);
}

//consultar um paciente por ID
void consultarPacienteID(){
    int encontrado = 0;
    int idBusca;
    printf("Digite o ID do paciente procurado: \n");
    scanf("%d", &idBusca);
    limparBufferEntrada();

    for (int i=0; i<MAX_Pacientes; i++) {
        if (pacientes[i] != NULL) {
            if (pacientes[i]->ID == idBusca) {
                printf("Paciente encontrado \n");
                exibirDadosPaciente(pacientes[i]);
                encontrado = 1;
                break;
            }
        }
    }
    if (!encontrado) {
        printf("Paciente nao encontrado...\n");
    }
}

void consultarPacienteNome() {
    char nomeBusca[MAX_NOMEP];
    int encontrado = 0;
    limparBufferEntrada();

    printf("Digite o nome(ou parte do nome) do paciente a ser encontrado: \n");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    removerNovaLinha(nomeBusca);

    if(strlen(nomeBusca)==0) {
        printf("O nome inserido não foi encontrado, digite novamente. \n");
        return;
    }
    for(int i=0; i<MAX_Pacientes; i++) {
        if(pacientes[i] != NULL) {
            if(strstr(pacientes[i]->NOMEp, nomeBusca) != NULL) {
                printf("Paciente encontrado \n");
                exibirDadosPaciente(pacientes[i]);
                encontrado++;
            }
        }
    }
}

void consultarPacienteEspecie(){
    char especieBusca[MAX_ESPECIE];
    int encontrado = 0;
    limparBufferEntrada();

        printf("Digite para consultar os pacientes pela especie: \n");
            fgets(especieBusca, sizeof(especieBusca), stdin);
        removerNovaLinha((especieBusca));

        if(strlen(especieBusca) == 0) {
            printf("Escreva corretamente a especie a ser procurada. \n");
            return;
        }
        for(int i=0; i<MAX_Pacientes; i++) {
            if(pacientes[i] != NULL) {
                if(strstr(pacientes[i]->ESPECIE, especieBusca) != NULL) {
                    exibirDadosPaciente(pacientes[i]);
                    encontrado++;
                }
            }
        }
    }

void consultarPacienteRaca() {
    char racaBusca[MAX_RACA];
    int encontrado = 0;
    limparBufferEntrada();

    printf("Digite para consultar os pacientes pela raca: \n");
        fgets(racaBusca, sizeof(racaBusca), stdin);
    removerNovaLinha(racaBusca);

    if(strlen(racaBusca)==0) {
        printf("Escreva corretamente a raca a ser procurada. \n");
        return;
    }
    for(int i=0; i<MAX_Pacientes; i++) {
        if(pacientes[i] != NULL) {
            if(strstr(pacientes[i]->RACA, racaBusca) != NULL) {
                exibirDadosPaciente(pacientes[i]);
                encontrado++;
                }
            }
        }
    }

void alterarDadosPaciente()
{
    int idBusca;
    int indicePaciente = -1;
    char bufferEntrada[MAX_Pacientes];
    int idadeNova;
    double telefoneNovo;
    printf("\n-->Alterar dados do paciente pelo id encotrada <--\n");
    printf("Digite a id a ser encontrada: \n");
        scanf("%d", &idBusca);
    limparBufferEntrada();

    //Encontrar aluno a ser alterado
    for (int i=0; i<MAX_Pacientes; i++) {
        if (pacientes[i] != NULL) {
            if (pacientes[i]->ID == idBusca) {
                indicePaciente = i;
                break;
            }
        }
    }
    if (indicePaciente == -1) {
        printf("Paciente nao encontrado.\n");
        return;
    }

    printf("Paciente encontrado na posicao: %d \n", indicePaciente);
    exibirDadosPaciente(pacientes[indicePaciente]);

    printf("-> Iniciando o processo de alteracao de dados <-\n");
    printf("Para cada campo abaixo, digite o NOVO VALOR ou pressione ENTER para manter.\n");

    //Alterar Nome
    printf("Nome Atual: %s \n", pacientes[indicePaciente]->NOMEp);
    printf("Digite o novo nome: \n");
        fgets(bufferEntrada, sizeof(bufferEntrada), stdin);
    removerNovaLinha(bufferEntrada);
    if (strlen(bufferEntrada) > 0) {
        strcpy(pacientes[indicePaciente]->NOMEp, bufferEntrada);
        printf("Nome alterado para: %s \n", pacientes[indicePaciente]->NOMEp);
    }else {
        printf("Nome mantido: %s\n", pacientes[indicePaciente]->NOMEp);
    }

    // Procurar meio de automatizar para conforme acesso ao sistema, contabilizar dia e conforme isso atualizar idade...
    //Alterar a idade do paciente
    printf("Idade do paciente: %d \n", pacientes[indicePaciente]->IDADE);
    printf("Digite a nova idade: \n");
        scanf("%d", &idadeNova);
    limparBufferEntrada();
    pacientes[indicePaciente]->IDADE = idadeNova;
    printf("Idade nova: %d \n", pacientes[indicePaciente]->IDADE);

    //Alterar Nome Tutor
    printf("Nome Atual do tutor: %s \n", pacientes[indicePaciente]->NOMEt);
    printf("Digite o novo nome: \n");
    fgets(bufferEntrada, sizeof(bufferEntrada), stdin);
    removerNovaLinha(bufferEntrada);
    if (strlen(bufferEntrada) > 0) {
        strcpy(pacientes[indicePaciente]->NOMEt, bufferEntrada);
        printf("Nome alterado para: %s \n", pacientes[indicePaciente]->NOMEt);
    }else {
        printf("Nome mantido: %s\n", pacientes[indicePaciente]->NOMEt);
    }

    //Alterar Especie
    printf("Especie atual do paciente: %s \n", pacientes[indicePaciente]->ESPECIE);
    printf("Digite a nova especie: \n");
    fgets(bufferEntrada, sizeof(bufferEntrada), stdin);
    removerNovaLinha(bufferEntrada);
    if (strlen(bufferEntrada) > 0) {
        strcpy(pacientes[indicePaciente]->ESPECIE, bufferEntrada);
        printf("Especie alterada para: %s \n", pacientes[indicePaciente]->ESPECIE);
    }else {
        printf("Especie mantida: %s\n", pacientes[indicePaciente]->ESPECIE);
    }

    //Alterar a raça
    printf("Raca atual do paciente: %s \n", pacientes[indicePaciente]->RACA);
    printf("Digite a nova raca: \n");
    fgets(bufferEntrada, sizeof(bufferEntrada), stdin);
    removerNovaLinha(bufferEntrada);
    if (strlen(bufferEntrada) > 0) {
        strcpy(pacientes[indicePaciente]->RACA, bufferEntrada);
        printf("Raca alterada para: %s \n", pacientes[indicePaciente]->RACA);
    }else {
        printf("Raca mantida: %s\n", pacientes[indicePaciente]->RACA);
    }

    //Alterar o telefone do tutor
    printf("Telefone do paciente: %.0lf \n", pacientes[indicePaciente]->TELEFONE);
    printf("Digite o novo telefone: \n");
    scanf("%d", &telefoneNovo);
    limparBufferEntrada();
    pacientes[indicePaciente]->TELEFONE = telefoneNovo;
    printf("Idade nova: %.0lf \n", pacientes[indicePaciente]->TELEFONE);

    printf("Alteracao concluida com sucesso! \nDados finais: \n");
    exibirDadosPaciente(pacientes[indicePaciente]);
}

void visualizarTodosPacientes(){
    int contador = 0;
    for (int i=0; i<MAX_Pacientes; i++) {
        if (pacientes[i] != NULL) {
            contador++;
            exibirDadosPaciente(pacientes[i]);
        }
    }
    if (contador == 0) {
        printf("Nenhum paciente cadastrado \n");
    }else {
        printf("Qtd. de pacientes atualmente cadastrados: %d \n", contador);
    }
}
