#include <stdio.h>

// Funciones para imprimir el tablero y las piezas
void imprimirTablero(char tablero[][8]);
void imprimirReina(char tablero[][8], int x, int y);
void imprimirRey(char tablero[][8], int x, int y);
void imprimirMovimientosRey(char tablero[][8], int x, int y);

int main() {
    char tablero[8][8];
    int opcion, x, y;

    do {
        // Mostrar el menú de opciones
        printf("\nPrograma para saber la ubicacion de tu pieza y sus posibles moviminetos");
        printf("\n\nEscoge una opcion\n");
        printf("1. Reina\n");
        printf("2. Rey\n");
        printf("3. Salir\n");
        scanf("%d", &opcion);

        // Salir del programa si se selecciona la opción 3
        if (opcion == 3) {
            break;
        }

        // Pedir las coordenadas
        printf("Ingrese las coordenadas (x,y): ");
        scanf("%d %d", &x, &y);

        // Inicializar el tablero con '-' en todas las casillas
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                tablero[i][j] = '-';
            }
        }

        // Imprimir el tablero con la pieza seleccionada y los movimientos permitidos
        switch (opcion) {
            case 1:
                imprimirReina(tablero, x, y);
                break;
            case 2:
                imprimirRey(tablero, x, y);
                imprimirMovimientosRey(tablero, x, y);
                break;
            default:
                printf("Opción inválida.\n");
        }

        imprimirTablero(tablero);

    } while (opcion != 3);

    return 0;
}

void imprimirTablero(char (*tablero)[8]) {
    printf("\n   0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", *(tablero[i]+j));
        }
        printf("\n");
    }
    printf("\n");
}

void imprimirReina(char (*tablero)[8], int x, int y) {
    // Imprimir el rey en las coordenadas indicadas
    *(*(tablero+x)+y) = 'Q';

    // Marcar los movimientos permitidos en diagonal, horizontal y vertical
    for (int i = 0; i < 8; i++) {
        *(*(tablero+x)+i) = 'X';
        *(*(tablero+i)+y) = 'X';
        if (x+i < 8 && y+i < 8) *(*(tablero+x+i)+y+i) = 'X';
        if (x-i >= 0 && y-i >= 0) *(*(tablero+x-i)+y-i) = 'X';
        if (x-i >= 0 && y+i < 8) *(*(tablero+x-i)+y+i) = 'X';
        if (x+i < 8 && y-i >= 0) *(*(tablero+x+i)+y-i) = 'X';
    }
}

void imprimirRey(char (*tablero)[8], int x, int y) {
    // Imprimir el rey en las coordenadas indicadas
    *(*(tablero+x)+y) = 'R';
}

void imprimirMovimientosRey(char tablero[][8], int x, int y) {
    // Marcar los movimientos permitidos del rey
    if (x-1 >= 0) {
        tablero[x-1][y] = 'X';
        if (y-1 >= 0) tablero[x-1][y-1] = 'X';
        if (y+1 < 8) tablero[x-1][y+1] = 'X';
    }
    if (x+1 < 8) {
        tablero[x+1][y] = 'X';
        if (y-1 >= 0) tablero[x+1][y-1] = 'X';
        if (y+1 < 8) tablero[x+1][y+1] = 'X';
    }
    if (y-1 >= 0) tablero[x][y-1] = 'X';
    if (y+1 < 8) tablero[x][y+1] = 'X';
}
