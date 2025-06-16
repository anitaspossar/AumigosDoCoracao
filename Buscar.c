#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NOMEP 61
void consultarPacienteNome(){
  FILE *F
  char linha [258];
  char buscarPaciente[MAX_NOMEP];
  int found = 0;
  file = fopen("pacientes.txt", "r");
  printf("Insira o nome do paciente que quer buscar: ");
  scanf("%c", &buscarPaciente);
    if (strcmp(linha, buscarPaciente) == 0){
      printf("Nome encontrado: %s\n", linha);
      found = 1;
      break;}