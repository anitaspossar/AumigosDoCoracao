/**
 * @file app.c
 * @brief Aplicação principal da clínica veterinária
 * @author Isabella,Anita,Henrique,Pablo
 * @date 2025-06-29
 *
 * Contém o loop principal do programa e a interface de menu.
 */

#include <stdio.h>
#include "pacientes.h"

void exibirMenu();
void PausarParaContinuar();

/**
 * @brief Função principal
 *
 * @return int Código de saída (0 para sucesso)
 *
 * @note Inicializa o sistema e entra no loop do menu
 */
int main() {
    inicializaPacientes();
    exibirMenu();
    return 0;
}

/**
 * @brief Exibe o menu principal e gerencia o fluxo
 *
 * @details Mostra as opções disponíveis e redireciona para
 * as funções específicas do módulo pacientes.
 *
 * Fluxo:
 * 1. Exibe menu
 * 2. Processa escolha
 * 3. Executa operação
 * 4. Repete até saída
 *
 * Chamado automaticamente pela main()
 */
void exibirMenu() {
    int opcao;
    do {
        printf("\nMenu Principal\n");
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