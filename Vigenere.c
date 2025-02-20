#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max 128

void CifrarVigenere(char frase[Max], char clave[Max]);
void DecifrarVigenere(char frase[Max], char clave[Max]);

void CifrarVigenere(char frase[Max], char clave[Max]) {
    size_t i, j = 0;
    size_t lenFrase = strlen(frase);
    size_t lenClave = strlen(clave);

    for (i = 0; i < lenFrase; i++) {
        if (isalpha(frase[i])) {  // Solo cifra letras
            char base = isupper(frase[i]) ? 'A' : 'a';
            int desplazamiento = toupper(clave[j % lenClave]) - 'A';
            frase[i] = (frase[i] - base + desplazamiento) % 26 + base;
            j++;
        }
    }
    printf("La frase encriptada es: %s\n", frase);
}

void DecifrarVigenere(char frase[Max], char clave[Max]) {
    size_t i, j = 0;
    size_t lenFrase = strlen(frase);
    size_t lenClave = strlen(clave);

    for (i = 0; i < lenFrase; i++) {
        if (isalpha(frase[i])) {  // Solo decifra letras
            char base = isupper(frase[i]) ? 'A' : 'a';
            int desplazamiento = toupper(clave[j % lenClave]) - 'A';
            frase[i] = (frase[i] - base - desplazamiento + 26) % 26 + base;
            j++;
        }
    }
    printf("La frase desencriptada es: %s\n", frase);
}

int main() {
    char frase[Max];
    char clave[Max];

    printf("Ingrese la frase a encriptar: ");
    fgets(frase, Max, stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Eliminar el salto de línea

    printf("Ingrese la palabra clave: ");
    fgets(clave, Max, stdin);
    clave[strcspn(clave, "\n")] = '\0';  // Eliminar el salto de línea

    CifrarVigenere(frase, clave);
    DecifrarVigenere(frase, clave);

    return 0;
}
