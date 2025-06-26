#include <stdio.h>
#include <stdlib.h>
#include "pacientes.h"

void exibirMenu();

void PausarParaContinuar();

int main(void) {

    exibirMenu();
}

void exibirMenu(){

    int opcao = 0;
    do {
        printf("\nMenu Principal\n");
        printf("\nAVISO: Para salvar as informacoes no arquivo \npressione 8 para sair do sistema.\n");
        printf("\n_______________________________________________\n");
        printf("1. Cadastrar Novo Paciente\n");
        printf("2. Consultar Paciente por ID\n");
        printf("3. Consultar Paciente por Nome\n");
        printf("4. Consultar Paciente pela Especie\n");
        printf("5. Consultar Paciente pela Raca\n");
        printf("6. Alterar Dados do Paciente\n");
        printf("7. Visualizar todos os pacientes cadastrados\n");
        printf("8. Sair do sistema\n");
        printf("_______________________________________________\n");
        printf("Escolha sua opcao:\n");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                cadastrarPaciente();
            break;
            case 2:
                consultarPacienteID();
            break;
            case 3:
                consultarPacienteNome();
            break;
            case 4:
                consultarPacienteEspecie();
            break;
            case 5:
                consultarPacienteRaca();
            break;
            case 6:
                alterarDadosPaciente();
            break;
            case 7:
                visualizarTodosPacientes();
            break;
            case 8:
                printf("Encerrando Sistema\n");
            break;
            default:
                printf("Opcao invalida\n");
        }
        if (opcao == 8) {
            PausarParaContinuar();
        }
    }while (opcao != 8);{
        printf("Programa finalizado\n");
        exit(0);
    }
}

void PausarParaContinuar(){
    printf("\nPressione uma tecla para continuar...\n");
    getchar();
}
