#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
};

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void insertEnd(struct Node** head, int data) {
  struct Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    (*head)->next = newNode;
    (*head)->prev = newNode;
  } else {
    struct Node* last = (*head)->prev;
    last->next = newNode;
    newNode->prev = last;
    newNode->next = *head;
    (*head)->prev = newNode;
  }
}

void deleteNode(struct Node** head, int key) {
  if (*head == NULL) {
    printf("La lista esta vacia!\n");
    return;
  }
  struct Node* current = *head;
  int deleted = 0;
  do {
    if (current->data == key) {
      if (current == *head) {
        *head = current->next;
      }
      current->prev->next = current->next;
      current->next->prev = current->prev;
      free(current);
      deleted = 1;
      printf("%d se ha borrado en la estructura!\n", key);
      break;
    }
    current = current->next;
  } while (current != *head);
  if (!deleted) {
    printf("%d no se ha encontrado en la estructura!\n", key);
  }
}

void printList(struct Node* head) {
  if (head == NULL) {
    printf("La lista esta vacia!\n");
    return;
  }
  printf("Mostrando estructura:\n");
  struct Node* current = head;
  do {
    printf("%d --> ", current->data);
    current = current->next;
  } while (current != head);
  printf("\n");
}

int main() {
  struct Node* head = NULL;

  insertEnd(&head, 1);
  insertEnd(&head, 2);
  insertEnd(&head, 3);

  int option, data, key;
  do {
    printf("Bienvenido, va a realizar alguna operacion:\n");
    printf("1. Insertar\n");
    printf("2. Eliminar\n");
    printf("3. Mostrar lista\n");
    printf("4. Salir\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        printf("Ingrese el valor a insertar: ");
        scanf("%d", &data);
        insertEnd(&head, data);
        break;
      case 2:
        printf("Ingrese el valor a eliminar: ");
        scanf("%d", &key);
        deleteNode(&head, key);
        break;
      case 3:
printf("Mostrando la lista:\n");
  printList(head);
  break;
case 4:
  printf("Gracias por utilizar el programa. ¡Hasta luego!\n");
  return 0;

default:
  printf("Opción no válida. Por favor, elija una opción del menú.\n");
  break;
    }
  } while (option != 4);
}