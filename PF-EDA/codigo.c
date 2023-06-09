#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_TRABAJADORES 100

typedef struct {
    char codigo[10];
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

typedef struct {
    int id;
    char nombre[50];
    char puesto[50];
} Trabajador;

void administrarInventario(Producto inventario[], int *numProductos);
void atenderClientes(Producto inventario[], int numProductos);
void mostrarInventario(Producto inventario[], int numProductos);
void OrdenarInventario(Producto inventario[], int numProductos);
void ordenarPorCodigo(Producto inventario[], int numProductos);
void ordenarPorNombre(Producto inventario[], int numProductos);

void administrarPersonal(Trabajador personal[], int *numTrabajadores);
void darAltaTrabajador(Trabajador personal[], int *numTrabajadores);
void darBajaTrabajador(Trabajador personal[], int *numTrabajadores);
void cambiarPuestoTrabajador(Trabajador personal[], int numTrabajadores);
void mostrarPersonal(Trabajador personal[], int numTrabajadores);

void copiarCadena(char destino[], const char origen[]) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

int compararCadenas(const char cadena1[], const char cadena2[]) {
    int i = 0;
    while (cadena1[i] != '\0' && cadena2[i] != '\0') {
        if (cadena1[i] != cadena2[i]) {
            return cadena1[i] - cadena2[i];
        }
        i++;
    }
    if (cadena1[i] == '\0' && cadena2[i] == '\0') {
        return 0;
    } else if (cadena1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    Producto inventario[MAX_PRODUCTOS];
    Trabajador personal[MAX_TRABAJADORES];
    int numProductos = 0;
    int numTrabajadores = 0;
    int opcion;

    do {
        printf("\nMENÚ PRINCIPAL\n");
        printf("1. Administrar Inventario\n");
        printf("2. Atender Clientes\n");
        printf("3. Administrar Personal\n");
        printf("0. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                administrarInventario(inventario, &numProductos);
                break;
            case 2:
                atenderClientes(inventario, numProductos);
                break;
            case 3:
                administrarPersonal(personal, &numTrabajadores);
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

/*APARTADO DE ADMINISTRACION DE INVENTARIO */

void administrarInventario(Producto inventario[], int *numProductos) {
    int opcion;

    do {
        printf("\nMENÚ DE ADMINISTRACIÓN DE INVENTARIO\n");
        printf("1. Agregar producto\n");
        printf("2. Eliminar producto\n");
        printf("3. Mostrar inventario\n");
        printf("4. Ordenar inventario\n");
        printf("0. Volver al menú principal\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (*numProductos < MAX_PRODUCTOS) {
                    Producto nuevoProducto;
                    printf("\nAGREGAR PRODUCTO\n");
                    printf("Ingrese el código del producto: ");
                    scanf("%s", nuevoProducto.codigo);
                    printf("Ingrese el nombre del producto: ");
                    scanf("%s", nuevoProducto.nombre);
                    printf("Ingrese la cantidad del producto: ");
                    scanf("%d", &nuevoProducto.cantidad);
                    printf("Ingrese el precio del producto: ");
                    scanf("%f", &nuevoProducto.precio);
                    inventario[*numProductos] = nuevoProducto;
                    (*numProductos)++;
                    printf("Producto agregado correctamente.\n");
                } else {
                    printf("No se pueden agregar más productos. Límite máximo alcanzado.\n");
                }
                break;
            case 2:
                if (*numProductos > 0) {
                    char codigo[10];
                    int indice = -1;
                    printf("\nELIMINAR PRODUCTO\n");
                    printf("Ingrese el código del producto a eliminar: ");
                    scanf("%s", codigo);
                    for (int i = 0; i < *numProductos; i++) {
                        if (compararCadenas(inventario[i].codigo, codigo) == 0) {
                            indice = i;
                            break;
                        }
                    }
                    if (indice != -1) {
                        for (int i = indice; i < *numProductos - 1; i++) {
                            inventario[i] = inventario[i + 1];
                        }
                        (*numProductos)--;
                        printf("Producto eliminado correctamente.\n");
                    } else {
                        printf("No se encontró un producto con el código ingresado.\n");
                    }
                } else {
                    printf("No hay productos en el inventario.\n");
                }
                break;
            case 3:
                mostrarInventario(inventario, *numProductos);
                break;
            case 4:
            	printf("\nORDENAR INVENTARIO\n");
                printf("1. Ordenar por código\n");
                printf("2. Ordenar por nombre\n");
                printf("Ingrese la opción: ");
                scanf("%d", &opcion);

                switch (opcion) {
                    case 1:
                        ordenarPorCodigo(inventario, *numProductos);
                        break;
                    case 2:
                        ordenarPorNombre(inventario, *numProductos);
                        break;
                    default:
                        printf("Opción inválida.\n");
                        break;
                }
                break;
            case 0:
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 0);
}


void mostrarInventario(Producto inventario[], int numProductos) {
    printf("\nINVENTARIO\n");
    printf("-------------------------------------------------\n");
    printf("Código\t\tNombre\t\tCantidad\tPrecio\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%s\t\t%s\t\t%d\t\t%.2f\n", inventario[i].codigo, inventario[i].nombre, inventario[i].cantidad, inventario[i].precio);
    }
    printf("-------------------------------------------------\n");
}


void ordenarPorCodigo(Producto inventario[], int numProductos) {
    int i, j;
    Producto temp;

    for (i = 0; i < numProductos - 1; i++) {
        for (j = 0; j < numProductos - i - 1; j++) {
            if (strcmp(inventario[j].codigo, inventario[j + 1].codigo) > 0) {
                temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }

    printf("\nINVENTARIO ORDENADO POR CODIGO \n");
    printf("-------------------------------------------------\n");
    printf("Código\t\tNombre\t\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%s\t\t%s\t\n", inventario[i].codigo, inventario[i].nombre);
    }
    printf("-------------------------------------------------\n");
}



void ordenarPorNombre(Producto inventario[], int numProductos) {
    int i, j;
    Producto temp;

    for (i = 0; i < numProductos - 1; i++) {
        for (j = 0; j < numProductos - i - 1; j++) {
            if (strcmp(inventario[j].nombre, inventario[j + 1].nombre) > 0) {
                temp = inventario[j];
                inventario[j] = inventario[j + 1];
                inventario[j + 1] = temp;
            }
        }
    }
    
printf("\nINVENTARIO ORDENADO POR NOMBRE \n");
    printf("-------------------------------------------------\n");
    printf("Código\t\tNombre\t\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%s\t\t%s\t\n", inventario[i].codigo, inventario[i].nombre);
    }
    printf("-------------------------------------------------\n");

}

/*APARTADO DE ATENCION AL CLIENTE*/

void atenderClientes(Producto inventario[], int numProductos) {
    int opcion;

    do {
        printf("\nMENÚ DE ATENCIÓN A CLIENTES\n");
        printf("1. Realizar venta\n");
        printf("2. Mostrar inventario\n");
        printf("0. Volver al menú principal\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (numProductos > 0) {
                    char codigo[10];
                    int cantidad;
                    int indice = -1;
                    printf("\nREALIZAR VENTA\n");
                    printf("Ingrese el código del producto: ");
                    scanf("%s", codigo);
                    for (int i = 0; i < numProductos; i++) {
                        if (compararCadenas(inventario[i].codigo, codigo) == 0) {
                            indice = i;
                            break;
                        }
                    }
                    if (indice != -1) {
                        printf("Ingrese la cantidad a vender: ");
                        scanf("%d", &cantidad);
                        if (cantidad <= inventario[indice].cantidad) {
                            float total = cantidad * inventario[indice].precio;
                            printf("Venta realizada. Total a pagar: %.2f\n", total);
                            inventario[indice].cantidad -= cantidad;
                        } else {
                            printf("No hay suficiente stock para realizar la venta.\n");
                        }
                    } else {
                        printf("No se encontró un producto con el código ingresado.\n");
                    }
                } else {
                    printf("No hay productos en el inventario.\n");
                }
                break;
            case 2:
                mostrarInventario(inventario, numProductos);
                break;
            case 0:
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 0);
}

/*APARTADO DE ADMINISTRACION DE PERSONAL*/

void administrarPersonal(Trabajador personal[], int *numTrabajadores) {
    int opcion;

    do {
        printf("\nMENÚ DE ADMINISTRACIÓN DE PERSONAL\n");
        printf("1. Dar de alta a un trabajador\n");
        printf("2. Dar de baja a un trabajador\n");
        printf("3. Cambiar el puesto de un trabajador\n");
        printf("4. Mostrar personal\n");
        printf("0. Volver al menú principal\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                darAltaTrabajador(personal, numTrabajadores);
                break;
            case 2:
                darBajaTrabajador(personal, numTrabajadores);
                break;
            case 3:
                cambiarPuestoTrabajador(personal, *numTrabajadores);
                break;
            case 4:
                mostrarPersonal(personal, *numTrabajadores);
                break;
            case 0:
                printf("Volviendo al menú principal...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 0);
}

void darAltaTrabajador(Trabajador personal[], int *numTrabajadores) {
    if (*numTrabajadores < MAX_TRABAJADORES) {
        Trabajador nuevoTrabajador;
        printf("\nDAR DE ALTA A UN TRABAJADOR\n");
        printf("Ingrese el ID del trabajador: ");
        scanf("%d", &nuevoTrabajador.id);

        // Limpiar el búfer del teclado después de leer el ID
        while (getchar() != '\n');

        printf("Ingrese el nombre del trabajador: ");
        fgets(nuevoTrabajador.nombre, sizeof(nuevoTrabajador.nombre), stdin);
        nuevoTrabajador.nombre[strcspn(nuevoTrabajador.nombre, "\n")] = '\0';  // Eliminar el salto de línea

        printf("Ingrese el puesto del trabajador: ");
        fgets(nuevoTrabajador.puesto, sizeof(nuevoTrabajador.puesto), stdin);
        nuevoTrabajador.puesto[strcspn(nuevoTrabajador.puesto, "\n")] = '\0';  // Eliminar el salto de línea

        personal[*numTrabajadores] = nuevoTrabajador;
        (*numTrabajadores)++;
        printf("Trabajador dado de alta correctamente.\n");
    } else {
        printf("No se pueden agregar más trabajadores. Capacidad máxima alcanzada.\n");
    }
}

void darBajaTrabajador(Trabajador personal[], int *numTrabajadores) {
    if (*numTrabajadores > 0) {
        int id;
        int encontrado = 0;
        printf("\nDAR DE BAJA A UN TRABAJADOR\n");
        printf("Ingrese el ID del trabajador a dar de baja: ");
        scanf("%d", &id);

        for (int i = 0; i < *numTrabajadores; i++) {
            if (personal[i].id == id) {
                encontrado = 1;
                for (int j = i; j < (*numTrabajadores)-1; j++) {
                    personal[j] = personal[j+1];
                }
                (*numTrabajadores)--;
                printf("Trabajador dado de baja correctamente.\n");
                break;
            }
        }

        if (!encontrado) {
            printf("No se encontró un trabajador con el ID proporcionado.\n");
        }
    } else {
        printf("No hay trabajadores para dar de baja.\n");
    }
}

void cambiarPuestoTrabajador(Trabajador personal[], int numTrabajadores) {
    if (numTrabajadores > 0) {
        int id;
        int encontrado = 0;
        printf("\nCAMBIAR PUESTO DE UN TRABAJADOR\n");
        printf("Ingrese el ID del trabajador al que desea cambiarle el puesto: ");
        scanf("%d", &id);

        for (int i = 0; i < numTrabajadores; i++) {
            if (personal[i].id == id) {
                encontrado = 1;
                printf("Ingrese el nuevo puesto del trabajador: ");
                scanf("%s", personal[i].puesto);
                printf("Puesto cambiado correctamente.\n");
                break;
            }
        }

        if (!encontrado) {
            printf("No se encontró un trabajador con el ID proporcionado.\n");
        }
    } else {
        printf("No hay trabajadores para cambiarles el puesto.\n");
    }
}

void mostrarPersonal(Trabajador personal[], int numTrabajadores) {
    if (numTrabajadores > 0) {
        printf("\nPERSONAL\n");
        printf("ID\tNombre\t\t\tPuesto\n");
        for (int i = 0; i < numTrabajadores; i++) {
            printf("%d\t%s\t\t%s\n", personal[i].id, personal[i].nombre, personal[i].puesto);
        }
    } else {
        printf("No hay trabajadores registrados.\n");
    }
}