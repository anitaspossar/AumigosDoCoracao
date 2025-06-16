#ifndef PACIENTES_H
#define PACIENTES_H

#define MAX_Pacientes 100000
#define MAX_NOMEP 61
#define MAX_NOMET 61
#define MAX_RACA 61
#define MAX_ESPECIE 50

typedef struct Paciente{
    int ID;
    char NOMEp[MAX_NOMEP];
    int IDADE;
    char NOMEt[MAX_NOMET];
    char ESPECIE[MAX_ESPECIE];
    char RACA[MAX_RACA];
    int TELEFONE;
}paciente;

//Define um tipo 'p_paci'  como um ponteiro para a struct Paciente
typedef paciente *p_paci;

extern p_paci pacientes[MAX_Pacientes];

//Inicializar o vetor com todas as posições nulas, para não ocupar memória
void inicializaPacientes();

//Cadastrar paciente
void cadastrarPaciente();

//Consultar paciente
void consultarPacienteID();
void consultarPacienteNome();
void consultarPacienteEspecie();
void consultarPacienteRaca();
void consultarPacienteTutor();

//Alterar dados do paciente
void alterarDadosPaciente();

//Imprimir todos os dados dos pacientes ou somente de um
void visualizarTodosPacientes();
void visualizarUmPaciente();

void exibirMenu();

void PausarParaContinuar();

void exibirMenu();

void PausarParaContinuar();

void exibirMenu();

void PausarParaContinuar();
#endif //PACIENTES_H
