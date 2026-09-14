#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

    No *inicio = NULL;

    while(1) {
        printf("====LISTA====\n");
        printf("1 - Inserir numero no comeco.\n");
        printf("2 - Inserir numero no fim.\n");
        printf("3 - Remover numero.\n");
        printf("4 - Listar numeros.\n");
        printf("5 - Mostrar maior.\n");
        printf("6 - Mostrar menor.\n");
        printf("7 - Fazer a contagem dos numeros.\n");
        printf("8 - Sair.\n");

        int n;
        if (scanf("%d",&n) != 1) {
            printf("Entrada invalida! Digite um numero.");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }

        if (n == 1) {
            inserir_no_inicio(&inicio);
        }

        else if (n == 2) {
            inserir_no_final(&inicio);
        }

        else if (n == 3) {
            remover_numero(&inicio);
        }

        else if (n == 4) {
            imprimir_lista(inicio);
        }

        else if (n == 5) {
            encontrar_maior(inicio);
        }

        else if (n == 6) {
            encontrar_menor(inicio);
        }

        else if (n == 7) {
            contar_elementos(inicio);
        }

        else if (n == 8) {
            break;
        }

        else {
            printf("Digite um numero de 1 a 8!\n");
        }
    }

    return 0;
}