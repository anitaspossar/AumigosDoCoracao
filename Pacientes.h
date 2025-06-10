//
// Created by aluno on 09/06/2025.
//

#ifndef PACIENTES_H
#define PACIENTES_H

#define MAX_Pacientes 100000
#define MAX_NOMEP 61
#define MAX_NOMET 61
#define MAX_RACA 61
#define MAX_ESPECIE 50
typedef struct paciente{
    int ID;
    char NOME [MAX_NOMEP];
    char NOME_T[MAX_NOMET];
    char Raca[MAX_RACA];
    char Especie [MAX_ESPECIE];
    int Telefone;
    int Idade;
}paciente;

typedef paciente *p_paci;

extern p_paci Pacientes [MAX_Pacientes];


#endif //PACIENTES_H
