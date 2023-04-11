// Implementacion de cola circular en C

#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Se revisa si la cola esta llena
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Se revisa si la cola esta vacia
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Añadir un elemento
void enQueue(int element) {
  if (isFull())
    printf("\n La cola esta llena!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\n Insertado -> %d", element);
  }
}

// Eliminar un elemento
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n La cola esta vacia !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // La cola solo tiene un elemento, entonces se reinicia
    // la cola despues de eliminarla.
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Elemento eliminado -> %d \n", element);
    return (element);
  }
}

// Se muestra la cola
void display() {
  int i;
  if (isEmpty())
    printf(" \n Cola vacia\n");
  else {
    printf("\n Frente -> %d ", front);
    printf("\n Elementos -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Parte trasera -> %d \n", rear);
  }
}

int main() {
  // Fracasa porque front = -1
  deQueue();

  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);

  // Fracasa en encolar porque front == 0 && rear == SIZE - 1
  enQueue(6);

  display();
  deQueue();

  display();

  enQueue(7);
  display();

  // Fracasa en encolar porque front == rear + 1
  enQueue(8);

  return 0;
}