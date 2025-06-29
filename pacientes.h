#ifndef PACIENTES_H
#define PACIENTES_H

#define MAX_Pacientes 100000
#define MAX_NOMEP 61
#define MAX_NOMET 61
#define MAX_RACA 61
#define MAX_ESPECIE 50

typedef struct Paciente {
    long ID;
    char NOMEp[MAX_NOMEP];
    int IDADE;
    char NOMEt[MAX_NOMET];
    char ESPECIE[MAX_ESPECIE];
    char RACA[MAX_RACA];
    long long TELEFONE;
} paciente;

typedef paciente *p_paci;

// Declarações das funções
void limparBufferEntrada();
void removerNovaLinha(char *str);
void inicializaPacientes();
long gerar_id_unico();
void exibirDadosPaciente(paciente *p_a);
void salvarPacientesNoArquivo();
void carregarPacientesDoArquivo();
void cadastrarPaciente();
void consultarPacienteID();
void consultarPacienteNome();
void consultarPacienteEspecie();
void consultarPacienteRaca();
void alterarDadosPaciente();
void excluirPaciente();
void visualizarTodosPacientes();

#endif // PACIENTES_H