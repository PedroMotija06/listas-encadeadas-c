#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    int valor;
    struct No *proximo;
} No;

void inserir_no_inicio(No **inicio);
void inserir_no_final(No **inicio);
void remover_numero(No **inicio);
void encontrar_maior(No *atual);
void encontrar_menor(No *atual);
void contar_elementos(No*atual);
void imprimir_lista(No *atual);

#endif
