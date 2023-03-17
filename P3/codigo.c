#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} 
Posicion;

bool dentro_del_tablero(Posicion p) {
    return p.x >= 0 && p.x < 8 && p.y >= 0 && p.y < 8;
}

void mostrar_tablero(char tablero[][8]) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void movimientos_caballo(Posicion p, Posicion movimientos[]) {
    int num_movimientos = 0;
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    for (int i = 0; i < 8; i++) {
        Posicion nueva_pos = {p.x + dx[i], p.y + dy[i]};
        if (dentro_del_tablero(nueva_pos)) {
            movimientos[num_movimientos] = nueva_pos;
            num_movimientos++;
        }
    }
}

void movimientos_alfil(Posicion p, Posicion movimientos[]) {
    int num_movimientos = 0;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2) {
            int dx = i, dy = j;
            while (true) {
                Posicion nueva_pos = {p.x + dx, p.y + dy};
                if (!dentro_del_tablero(nueva_pos)) {
                    break;
                }
                movimientos[num_movimientos] = nueva_pos;
                num_movimientos++;
                dx += i;
                dy += j;
            }
        }
    }
}

void movimientos_torre(Posicion p, Posicion movimientos[]) {
    int num_movimientos = 0;
    for (int dx = -7; dx <= 7; dx++) {
        for (int dy = -7; dy <= 7; dy++) {
            if ((dx == 0 || dy == 0) && dx != dy) {
                Posicion nueva_pos = {p.x + dx, p.y + dy};
                if (dentro_del_tablero(nueva_pos)) {
                    movimientos[num_movimientos] = nueva_pos;
                    num_movimientos++;
                }
            }
        }
    }
}

void movimientos_reina(Posicion p, Posicion movimientos[]) {
    int num_movimientos = 0;
    for (int dx = -7; dx <= 7; dx++) {
        for (int dy = -7; dy <= 7; dy++) {
            if ((dx == 0 || dy == 0 || dx == dy || dx == -dy) && (dx != 0 || dy != 0)) {
                Posicion nueva_pos = 
                {p.x + dx, p.y + dy};
                if (dentro_del_tablero(nueva_pos)) {
                movimientos[num_movimientos] = nueva_pos;
                num_movimientos++;
                }
          }
        }
    }
}

void movimientos_rey(Posicion p, Posicion movimientos[]) {
int num_movimientos = 0;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
for (int i = 0; i < 8; i++) {
Posicion nueva_pos = {p.x + dx[i], p.y + dy[i]};
if (dentro_del_tablero(nueva_pos)) {
movimientos[num_movimientos] = nueva_pos;
num_movimientos++;
        }
    }
}

int main() {
char tablero[8][8];
for (int i = 0; i < 8; i++) {
for (int j = 0; j < 8; j++) {
tablero[i][j] = '.';
    }
}
int opcion = 0;
do {
    printf("\nMenu de opciones:\n");
    printf("1.- Caballo\n");
    printf("2.- Alfil\n");
    printf("3.- Torre\n");
    printf("4.- Reina\n");
    printf("5.- Rey\n");
    printf("6.- Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion >= 1 && opcion <= 5) {
        printf("Ingrese las coordenadas (x,y): ");
        int x, y;
        scanf("%d %d", &x, &y);
        Posicion p = {x, y};

        Posicion movimientos[27];
        int num_movimientos = 0;
        switch (opcion) {
            case 1: movimientos_caballo(p, movimientos); num_movimientos = 8; break;
            case 2: movimientos_alfil(p, movimientos); num_movimientos = 13; break;
            case 3: movimientos_torre(p, movimientos); num_movimientos = 14; break;
            case 4: movimientos_reina(p, movimientos); num_movimientos = 27; break;
            case 5: movimientos_rey(p, movimientos); num_movimientos = 8; break;
        }
        for (int i = 0; i < num_movimientos; i++) {
            Posicion nueva_pos = movimientos[i];
            if (tablero[nueva_pos.x][nueva_pos.y] == '.') {
                tablero[nueva_pos.x][nueva_pos.y] = 'X';
            }
        }
        switch (opcion) {
            case 1: tablero[x][y] = 'C'; break;
            case 2: tablero[x][y] = 'A'; break;
            case 3: tablero[x][y] = 'T'; break;
            case 4: tablero[x][y] = 'Q'; break;
            case 5: tablero[x][y] = 'R'; break;
        }
        printf("\n");
        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j < 8; j++) {
                printf("%c ", tablero[i][j]);
            }
            printf("\n");
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (tablero[i][j] == 'X' || tablero[i][j] == 'C' || tablero[i][j] == 'A' || tablero[i][j] == 'T' || tablero[i][j] == 'Q' || tablero[i][j] == 'R') {
                    tablero[i][j] = '.';
                }
            }
        }
    }
} 
while (opcion != 6);
return 0;
}