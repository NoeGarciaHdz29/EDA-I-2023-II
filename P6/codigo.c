#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct node {
    char data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct deque {
    Node* front;
    Node* rear;
} Deque;

void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

int isDequeEmpty(Deque* deque) {
    return deque->front == NULL;
}

void enqueueFront(Deque* deque, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;
    if (deque->front == NULL) {
        deque->rear = newNode;
    } else {
        deque->front->prev = newNode;
    }
    deque->front = newNode;
}

void enqueueRear(Deque* deque, char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;
    if (deque->rear == NULL) {
        deque->front = newNode;
    } else {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
}

char dequeueFront(Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("La cola doble esta vacia\n");
        return '\0';
    } else {
        Node* temp = deque->front;
        char data = temp->data;
        deque->front = temp->next;
        if (deque->front == NULL) {
            deque->rear = NULL;
        } else {
            deque->front->prev = NULL;
        }
        free(temp);
        return data;
    }
}

char dequeueRear(Deque* deque) {
    if (isDequeEmpty(deque)) {
        printf("La cola doble esta vacia\n");
        return '\0';
    } else {
        Node* temp = deque->rear;
        char data = temp->data;
        deque->rear = temp->prev;
        if (deque->rear == NULL) {
            deque->front = NULL;
        } else {
            deque->rear->next = NULL;
        }
        free(temp);
        return data;
    }
}

int isPalindrome(char* str) {
    Deque deque;
    initDeque(&deque);
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        enqueueRear(&deque, str[i]);
    }
    while (!isDequeEmpty(&deque) && deque.front != deque.rear) {
        char frontChar = dequeueFront(&deque);
        char rearChar = dequeueRear(&deque);
        if (frontChar != rearChar) {
            return 0;
        }
    }
    return 1;
}

int main() {
char str[MAX_LENGTH];
printf("Ingrese una palabra: ");
scanf("%s", str);
if (isPalindrome(str)) {
printf("La palabra %s es un palindromo\n", str);
} else {
printf("La palabra %s no es un palindromo\n", str);
}
return 0;
}
