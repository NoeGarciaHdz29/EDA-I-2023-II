#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head;

    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    do {
        printf("%d --> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

void search(struct Node* head, int value) {
    struct Node* current = head;

    if (head == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

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

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;

    int value;
    printf("Ingrese el valor: ");
    scanf("%d", &value);

    search(head, value);

    printf("Mostrando estructura:\n");
    printList(head);

    return 0;
}