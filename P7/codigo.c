#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la lista
struct Node {
    int data;
    struct Node* next;
};

// Función para imprimir la lista ligada circular
void printList(struct Node* head) {
    struct Node* current = head;

    // Si la lista está vacía, imprimir mensaje
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    // Si la lista no está vacía, imprimir cada elemento
    do {
        printf("%d --> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

// Función para buscar un elemento en la lista ligada circular
void search(struct Node* head, int value) {
    struct Node* current = head;

    // Si la lista está vacía, imprimir mensaje
    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    // Si la lista no está vacía, buscar el elemento
    do {
        if (current->data == value) {
            printf("%d se encuentra en la estructura!\n", value);
            return;
        }
        current = current->next;
    } while (current != head);

    printf("%d no se encuentra en la estructura...\n", value);
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Asignar memoria para cada nodo
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    // Asignar valores a cada nodo
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;

    // Pedir al usuario que ingrese un valor para buscar
    int value;
    printf("Ingrese el valor: ");
    scanf("%d", &value);

    // Buscar el valor ingresado por el usuario en la lista
    search(head, value);

    // Imprimir la lista ligada circular
    printf("Mostrando estructura:\n");
    printList(head);

    return 0;
}