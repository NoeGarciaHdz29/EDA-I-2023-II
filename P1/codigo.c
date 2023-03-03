#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void movimientos_alfil(int x, int y, int movimientos[][2], int* num_movimientos) {
    *num_movimientos = 0;
    for (int i = 0; i < 8; i++) {
        if (i != x) {
            movimientos[*num_movimientos][0] = i;
            movimientos[*num_movimientos][1] = y;
            (*num_movimientos)++;
        }
        if (i != y) {
            movimientos[*num_movimientos][0] = x;
            movimientos[*num_movimientos][1] = i;
            (*num_movimientos)++;
        }
    }
}
void movimientos_torre(int x, int y, int movimientos[][2], int* num_movimientos) {
    *num_movimientos = 0;
    for (int i = 0; i < 8; i++) {
        if (i != x) {
            movimientos[*num_movimientos][0] = i;
            movimientos[*num_movimientos][1] = y;
            (*num_movimientos)++;
        }
        if (i != y) {
            movimientos[*num_movimientos][0] = x;
            movimientos[*num_movimientos][1] = i;
            (*num_movimientos)++;
        }
    }
}
void imprimir_tablero(int x, int y, int movimientos[][2], int num_movimientos) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            bool es_movimiento = false;
            for (int k = 0; k < num_movimientos; k++) {
                if (movimientos[k][0] == i && movimientos[k][1] == j) {
                    es_movimiento = true;
                    break;
                }
            }
            if (i == x && j == y) {
                if (movimientos_alfil(x, y, movimientos, &num_movimientos), num_movimientos > 0) {
                    printf("A ");
                }  else if (movimientos_torre(x, y, movimientos, &num_movimientos), num_movimientos > 0) {
                    printf("T ");
                } else {
                    printf(". ");
                }
            } else if (es_movimiento) {
                printf("x ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}
void menu() {
    int opcion, x, y;
    int movimientos[64][2];
    int num_movimientos;
    while (true) {
        printf("\nPrograma para saber la ubicacion de tu pieza y sus posibles moviminetos\n");
        printf("\n\nEscoge una opcion\n");
        printf("\n1.- Alfil\n2.- Torre\n3.- Salir\n");
        scanf("%d", &opcion);
        if (opcion == 1) {
            printf("Ingrese la coordenada x: ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y: ");
            scanf("%d", &y);
            movimientos_alfil(x, y, movimientos, &num_movimientos);
            imprimir_tablero(x, y, movimientos, num_movimientos);
        } else if (opcion == 2) {
            printf("Ingrese la coordenada x: ");
            scanf("%d", &x);
            printf("Ingrese la coordenada y: ");
            scanf("%d", &y);
            movimientos_torre(x, y, movimientos, &num_movimientos);
            imprimir_tablero(x, y, movimientos, num_movimientos);
        } else if (opcion == 3) {
            break;
        } else {
            printf("Opción inválida\n");
        }
    }
}

int main() {
    menu();
    return 0;
}