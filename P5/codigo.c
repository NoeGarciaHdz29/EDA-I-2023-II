#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

void push(Stack* stack, int item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Desbordamiento de pila\n");
        exit(EXIT_FAILURE);
    }
    stack->top++;
    stack->items[stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Subdesbordamiento de pila\n");
        exit(EXIT_FAILURE);
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}

void enqueue(Queue* queue, int item) {
    if (queue->rear == MAX_SIZE - 1) {
        printf("Desbordamiento de cola\n");
        exit(EXIT_FAILURE);
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

int dequeue(Queue* queue) {
    if (queue->front == queue->rear) {
        printf("Subdesbordamiento de cola\n");
        exit(EXIT_FAILURE);
    }
    queue->front++;
    return queue->items[queue->front];
}

int main() {
    Stack stack;
    Queue queue;
    stack.top = -1;
    queue.front = 0;
    queue.rear = -1;
    int option;
    
    for (int i = MAX_SIZE; i > 0; i--) {
        push(&stack, i);
    }

    do {
        printf("Menú:\n");
        printf("1. Formarse\n");
        printf("2. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (stack.top == -1) {
                    printf("Ya no hay turnos disponibles...\n");
                } else {
                    int turn = pop(&stack);
                    enqueue(&queue, turn);
                    printf("El elemento se encuentra formado en la cola con el turno %d.\n", turn);
                }
                break;
            case 2:
                break;
            default:
                printf("Opción inválida\n");
                break;
        }
    } while (option != 2 && stack.top != -1);

    if (stack.top == -1) {
        printf("Último elemento en el tope de la pila: null\n");
    } else {
        printf("Último elemento en el tope de la pila: %d\n", stack.items[stack.top]);
    }
    if (queue.front > queue.rear) {
        printf("Último elemento formado en la cola: null\n");
    } else {
        printf("Último elemento formado en la cola: %d\n", queue.items[queue.rear]);
    }

    return 0;
}