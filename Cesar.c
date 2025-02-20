#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 128

void Cifrar(char frase[Max], int numero);
void Decifrar(char frase[Max], int numero);

void Decifrar(char frase[Max], int numero) {
    size_t i;
    for (i = 0; i < strlen(frase); i++) {
        frase[i] = frase[i] - numero;
    }
    printf("La frase decifrada es: %s\n", frase);
}

void Encriptar(char frase[Max], int numero) {
    size_t i;
    for (i = 0; i < strlen(frase); i++) {
        frase[i] = frase[i] + numero;
    }
    printf("La frase cifrada es: %s\n", frase);
}

int main() {
    int x;
    char frase[Max];

    printf("Ingrese la frase a cifrar: ");
    fgets(frase, Max, stdin);

    // Eliminar el salto de línea (\n) de la entrada
    frase[strcspn(frase, "\n")] = '\0';

    printf("Ingrese el número de desplazamiento: ");
    scanf("%d", &x);

    Encriptar(frase, x);
    Desencriptar(frase, x);

    return 0;
}
