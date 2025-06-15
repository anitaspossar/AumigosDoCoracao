#include "pacientes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Definicao do array global para ponteiro de pacientes
p_paci pacientes[MAX_Pacientes];

//funcao para remover o buffer caracteres restantes da memoria do teclado
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void removerNovaLinha(char * str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len -1] == '\n') {
        str[len - 1] = '\0';
    }
}
