import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D 
import random

times = 0

def insertionSort_graph(n_lista):
    global times
    for index in range(1, len(n_lista)):
        times += 1
        actual = n_lista[index]
        posicion = index
        while posicion > 0 and n_lista[posicion-1] > actual:
            times += 1
            n_lista[posicion] = n_lista[posicion-1]
            posicion -= 1
        n_lista[posicion] = actual
    return n_lista

def quickSort(n_lista):
    if len(n_lista) <= 1:
        return n_lista
    pivot = n_lista[len(n_lista) // 2]
    left = [x for x in n_lista if x < pivot]
    middle = [x for x in n_lista if x == pivot]
    right = [x for x in n_lista if x > pivot]
    return quickSort(left) + middle + quickSort(right)

def mergeSort(n_lista):
    if len(n_lista) <= 1:
        return n_lista
    mid = len(n_lista) // 2
    left = n_lista[:mid]
    right = n_lista[mid:]
    left = mergeSort(left)
    right = mergeSort(right)
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

TAM = 101
eje_x = list(range(1, TAM, 1))
eje_y_insertion = []
eje_y_quick = []
eje_y_merge = []

for num in eje_x:
    lista_variable = random.sample(range(0, 1000), num)
    print(lista_variable)
    times = 0
    lista_insertion = insertionSort_graph(lista_variable.copy())
    eje_y_insertion.append(times)
    times = 0
    lista_quick = quickSort(lista_variable.copy())
    eje_y_quick.append(times)
    times = 0
    lista_merge = mergeSort(lista_variable.copy())
    eje_y_merge.append(times)

fig, ax = plt.subplots(facecolor='w', edgecolor='k')
ax.plot(eje_x, eje_y_insertion, marker="o", color="b", linestyle='-', label="Insertion Sort")
ax.plot(eje_x, eje_y_quick, marker="o", color="r", linestyle='-', label="QuickSort")
ax.plot(eje_x, eje_y_merge, marker="o", color="g", linestyle='-', label="Merge Sort")

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.grid(True)
ax.legend()

plt.title("Sorting Algorithms")
plt.show()