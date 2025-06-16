#include <stdio.h>
#include <stdlib.h>


void exibirMenu();

void PausarParaContinuar();

int main(void) {
    int opcao = 0;
    do {
        exibirMenu();
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                printf("cadastro");
            break;
            case 2:
                printf("consulta sadisgraca");
            break;
            case 3:
                printf("consulta pela desgraca do nome");
            break;
            case 4:
                printf("altera tudo cadela");
            break;
            case 5:
                printf("Encerrando Sistema\n");
            break;
            default:
                printf("Opcao invalida\n");
        }
        if (opcao == 5) {
            PausarParaContinuar();
        }
    }while (opcao != 5);{
        printf("Programa finalizado\n");
        return 0;
    }
}

    void exibirMenu(){
        printf("\nMenu Principal\n");
        printf("1. Cadastrar Novo Paciente\n");
        printf("2. Consultar Paciente por ID\n");
        printf("3. Consultar Paciente por Nome\n");
        printf("4. Alterar Dados do Paciente\n");
        printf("5. Sair do sistema\n");
        printf("Escolha sua opcao:\n");
    }

    void PausarParaContinuar(){
        printf("\nPressione uma tecla para continuar...\n");
        getchar();
    }
