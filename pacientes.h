/**
* @file pacientes.h
 * @brief Sistema de Gerenciamento de Pacientes Veterinários
 * @author Isabella,Anita,Henrique,Pablo
 * @date 2025-06-29
 * @copyright ALUNOS FATEC 2025 - Turma 2º Sem. de 2024
 *
 * Este arquivo contém as definições e estruturas para o sistema
 * de gerenciamento da clínica "Aumigos do Coração".
 */
#ifndef PACIENTES_H
#define PACIENTES_H

#define MAX_Pacientes 100000
#define MAX_NOMEP 61
#define MAX_NOMET 61
#define MAX_RACA 61
#define MAX_ESPECIE 50

/**
 * @brief Estrutura que representa um paciente animal
 *
 * Armazena todos os dados relevantes de um paciente da clínica veterinária,
 * incluindo informações do animal e do tutor.
 */
typedef struct Paciente {
    long ID;
    char NOMEp[MAX_NOMEP];
    int IDADE;
    char NOMEt[MAX_NOMET];
    char ESPECIE[MAX_ESPECIE];
    char RACA[MAX_RACA];
    long long TELEFONE;
} paciente;

/**
 * @brief Tipo ponteiro para a estrutura paciente
 */
typedef paciente *p_paci;

/* ---------- FUNÇÕES DE MANIPULAÇÃO BÁSICA ---------- */

/**
 * @brief Limpa o buffer de entrada do teclado
 *
 * Remove caracteres extras que possam ter ficado no buffer de entrada
 * após operações como scanf().
 */
void limparBufferEntrada();

/**
 * @brief Remove caracteres de nova linha de strings
 */
void removerNovaLinha(char *str);

/* ---------- FUNÇÕES DE GERENCIAMENTO ---------- */

/**
 * @brief Inicializa o sistema de pacientes
 *
 * Prepara a estrutura de dados para uso, carregando os pacientes
 * do arquivo TXT na inicialização.
 */
void inicializaPacientes();

/**
 * @brief Gera um ID único de 9 dígitos
 * @return long ID sequencial único
 *
 * A sequência reinicia após atingir 999.999.999
 */
long gerar_id_unico();

/**
 * @brief Exibe os dados de um paciente formatados
 * parametro:p_a Ponteiro para o paciente a ser exibido
 */
void exibirDadosPaciente(paciente *p_a);

/* ---------- FUNÇÕES DE PERSISTÊNCIA ---------- */

/**
 * @brief Salva todos os pacientes no arquivo TXT
 *
 * @warning Sobrescreve o arquivo completo a cada chamada
 */
void salvarPacientesNoArquivo();

/**
 * @brief Carrega pacientes do arquivo TXT para memória
 *
 * @note Chamado automaticamente durante inicializaPacientes()
 */
void carregarPacientesDoArquivo();

/* ---------- OPERAÇÕES PRINCIPAIS ---------- */

/**
 * @brief Cadastra um novo paciente no sistema
 *
 * Coleta todos os dados necessários via console e armazena
 * tanto na memória quanto no arquivo TXT.
 */
void cadastrarPaciente();

/**
 * @brief Consulta paciente por ID
 *
 * Exibe os dados completos do paciente correspondente ao ID fornecido.
 * Caso não encontre, exibe mensagem de erro.
 */
void consultarPacienteID();

/**
 * @brief Consulta paciente(s) por nome (ou parte)
 *
 * Realiza busca parcial case-insensitive no nome do animal.
 * Pode retornar múltiplos resultados.
 */
void consultarPacienteNome();

/**
 * @brief Consulta pacientes por espécie
 *
 * Lista todos os pacientes da espécie informada (ex: "Cão", "Gato").
 */
void consultarPacienteEspecie();

/**
 * @brief Consulta pacientes por raça
 *
 * Lista todos os pacientes da raça informada (ex: "Poodle", "Siamês").
 */
void consultarPacienteRaca();

/**
 * @brief Altera dados de um paciente existente
 *
 * Permite editar qualquer campo do paciente, mantendo o mesmo ID.
 * Atualiza imediatamente o arquivo TXT após modificação.
 */
void alterarDadosPaciente();

/**
 * @brief Remove um paciente do sistema
 *
 * @warning Operação irreversível - remove tanto da memória quanto do arquivo
 */
void excluirPaciente();

/**
 * @brief Lista todos os pacientes cadastrados
 *
 * Exibe um relatório completo com todos os pacientes em ordem de cadastro.
 */
void visualizarTodosPacientes();

#endif // PACIENTES_H