#include <stdio.h>
#include "pacientes.h"

void exibirMenu();
void PausarParaContinuar();

int main() {
    inicializaPacientes();
    exibirMenu();
    return 0;
}

void exibirMenu() {
    int opcao;
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
        printf("7. Excluir paciente\n");
        printf("8. Visualizar todos os pacientes cadastrados\n");
        printf("9. Sair do sistema\n");
        printf("_______________________________________________\n");
        printf("Escolha sua opcao:\n");
        scanf("%d",&opcao);

        limparBufferEntrada();

        switch(opcao) {
            case 1: cadastrarPaciente(); break;
            case 2: consultarPacienteID(); break;
            case 3: consultarPacienteNome(); break;
            case 4: consultarPacienteEspecie(); break;
            case 5: consultarPacienteRaca(); break;
            case 6: alterarDadosPaciente(); break;
            case 7: excluirPaciente(); break;
            case 8: visualizarTodosPacientes(); break;
            case 9:
                printf("Saindo...\n");
            salvarPacientesNoArquivo();
            break;
            default: printf("Opção inválida!\n");
        }

        if (opcao != 9) {
            PausarParaContinuar();
        }
    } while (opcao != 9);
}

void PausarParaContinuar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}