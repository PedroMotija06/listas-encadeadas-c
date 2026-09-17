#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inserir_no_inicio(No **inicio) {
    int valor;

    printf("Digite o numero que va ser adicionado: ");
    if (scanf("%d", &valor) != 1) {
        printf("Entrada invalida! Digite um numero.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    No *novo = malloc(sizeof(No));
    
    if(novo == NULL) {
        printf("Erro de alocação\n");
        return;
    }

    novo->valor = valor;

    novo->proximo = *inicio; 

    *inicio = novo;

}

void inserir_no_final(No **inicio) {
    int valor;

    printf("Digite o numero que va ser adicionado: ");
    if (scanf("%d", &valor) != 1) {
        printf("Entrada invalida! Digite um numero.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    No *novo = malloc(sizeof(No));

    if(novo == NULL) {
        printf("Erro de alocação\n");
        return;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    }
    
    else {
        No *anterior = *inicio;

        while (anterior->proximo != NULL) {
            anterior = anterior->proximo;
        }

        anterior->proximo = novo;
    }
}

void inserir_no_meio(No **inicio) {
    int valor;
    int posicao;
    int contador = 1;
    int tamanho = contar_elementos(*inicio);

    printf("Digite o numero que va ser adicionado: \n");
    if (scanf("%d", &valor) != 1) {
        printf("Entrada invalida! Digite um numero.\n");
        int g;
        while ((g = getchar()) != '\n' && g != EOF);
        return;
    }
    
    printf("Digite a posicao do numero que va ser adicionado: \n");
    if (scanf("%d", &posicao) != 1) {
        printf("Entrada invalida! Digite um numero.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    if (posicao == 1 || *inicio == NULL) {

        No *novo = malloc(sizeof(No));
        
        if(novo == NULL) {
            printf("Erro de alocação\n");
            return;
        }

        novo->valor = valor;

        novo->proximo = *inicio; 

        *inicio = novo;
    }

    else {
        No *novo = malloc(sizeof(No));

        if(novo == NULL) {
            printf("Erro de alocação\n");
            return;
        }
        
        novo->valor = valor;
        novo->proximo = NULL;

        No *anterior = *inicio;

        while (contador != (posicao - 1)) {
            if (contador > (tamanho + 1)) {
                printf("Digite um valor dentro do limite de posicao!\n");
                free(novo);
                return;
            }

            anterior = anterior->proximo;
            contador++;
        }

        No *atual = anterior->proximo;
        anterior->proximo = novo;
        novo->proximo = atual;
    }
}

void remover_numero(No **inicio) {
    int valor;

    printf("Digite o numero que va ser removido: ");
    if (scanf("%d", &valor) != 1) {
        printf("Entrada invalida! Digite um numero.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    No *atual = *inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Numero nao encontrado na lista.\n");
    }

    else if (anterior == NULL) {
        *inicio = atual->proximo;
        free(atual);
    }

    else {
        anterior->proximo = atual->proximo;
        free(atual);
    }
}

void encontrar_maior(No *atual) {
    if (atual == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    int maior = atual->valor;
    while (atual != NULL) {
        if (atual->valor > maior) {
            maior = atual->valor;
        }
        atual = atual->proximo;
    }
    printf("%d\n", maior);
}

void encontrar_menor(No *atual) {
    if (atual == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    int menor = atual->valor;
    while (atual != NULL) {
        if (atual->valor < menor) {
            menor = atual->valor;
        }
        atual = atual->proximo;
    }
    printf("%d\n", menor);

}

int contar_elementos(No *atual) {
    int contador = 0;
    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }
    return contador;
}

void imprimir_lista(No *atual) {
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}