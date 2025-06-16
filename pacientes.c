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
    printf("Telefone para contato: %d \n", p_a->TELEFONE);
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

    printf("Cadastrando novo na aluno na posicao %d do vetor: \n", posicao);
    //Leitura do id
    printf("Digite o numero do ID do paciente: \n");
    scanf("%d", &pacientes[posicao]->ID);
    limparBufferEntrada();

    printf("Digite o nome do paciente: \n");
    fgets(pacientes[posicao]->NOMEp, sizeof(pacientes[posicao]->NOMEp), stdin);
    removerNovaLinha(pacientes[posicao]->NOMEp);

    printf("Digite a idade do paciente: \n");
    scanf("%d", &pacientes[posicao]->IDADE);

    printf("Digite o nome do tutor: \n");
    fgets(pacientes[posicao]->NOMEt, sizeof(pacientes[posicao]->NOMEt), stdin);
    removerNovaLinha(pacientes[posicao]->NOMEt);

    printf("Digite a especie do paciente: \n");
    fgets(pacientes[posicao]->ESPECIE, sizeof(pacientes[posicao]->ESPECIE), stdin);
    removerNovaLinha(pacientes[posicao]->ESPECIE);

    printf("Digite a raca do paciente: \n");
    fgets(pacientes[posicao]->RACA, sizeof(pacientes[posicao]->RACA), stdin);
    removerNovaLinha(pacientes[posicao]->RACA);

    printf("Digite a idade do paciente: \n");
    scanf("%d", &pacientes[posicao]->IDADE);
    //raca, especie telefone

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
                printf("Aluno encontrado \n");
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

    printf("Digite o nome(ou parte do nome) a ser encontrado: \n");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
    removerNovaLinha(nomeBusca);

    if(strlen(nomeBusca)==0) {
        printf("O nome inserido não foi encontrado, digite novamente. \n");
        return;
    }
    for(int i=0; i<MAX_Pacientes; i++) {
        if(pacientes[i] != NULL) {
            if(strstr(pacientes[i]->NOMEp, nomeBusca) != NULL) {
                exibirDadosPaciente(pacientes[i]);
                encontrado++;
            }
        }
    }

    void consultarPacienteEspecie() {
        char especieBusca[MAX_ESPECIE];
        int achado = 0;
        limparBufferEntrada();

        printf("Digite para consultar os pacientes pela raça");
            fgets(especieBusca, sizeof(especieBusca), stdin);
        removerNovaLinha((especieBusca));

        if(strlen(especieBusca) == 0) {
            printf("Escreva corretamente a especie a ser procurada. \n");
            return;
        }
        for(int i=0; i<MAX_Pacientes; i++) {
            if(strstr(pacientes[i]->ESPECIE, especieBusca) != NULL) {
                exibirDadosPaciente(pacientes[i]);
                achado++;
            }
        }
    }

    void consultarPacienteRaca() {

    }
    void consultarPacienteTutor();
}
