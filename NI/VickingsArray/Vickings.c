#include <stdio.h>
#include <stdlib.h>

#define LETTERS 26

int main(int argc, char** argv) {
    char chars[LETTERS];
    char *result = NULL;
    int max, num, n, m;

    // Inicializa o vetor de letras
    for(n = 0; n < LETTERS; ++n) {
        chars[n] = 'A' + n;
    }

    // Obtem o numero de valores a serem lidos
    scanf("%d", &max);

    // Aloca espaco para o resultado
    result = (char*) malloc(max + 1);
    if (result == NULL) exit (1);

    for(n = 0; n < max; ++n) {
        // Le a letra atual
        scanf("%d", &num);

        // Estoca a letra correspondente no resultado
        result[n] = chars[num-1];

        // Move as letras anteriores para a direita
        for(m = num-1; m > 0; --m) {
            chars[m] = chars[m-1];
        }

        // Coloca a letra atual na frente
        chars[0] = result[n];
    }

    // Null string terminator no resultado...
    result[n] = '\0';

    // Exibe o resultado
    printf("%s\n", result);

    return (EXIT_SUCCESS);
}