def decimal_a_binario(n):
    if n == 0:
        return "0"
    elif n == 1:
        return "1"
    else:
        return decimal_a_binario(n // 2) + str(n % 2)


def fibonacci_inverso(n):
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        return [1, 0]
    else:
        fibo = [0, 1]
        for _ in range(2, n):
            fibo.append(fibo[-1] + fibo[-2])
        return fibo[::-1]


def menu():
    while True:
        print("Menú de opciones:")
        print("1 - Conversion de bases")
        print("2 - Serie de Fibonacci (inverso)")
        print("3 - Salir")
        opcion = int(input("Ingrese la opción: "))

        if opcion == 1:
            numero = int(input("Ingrese un número entero: "))
            binario = decimal_a_binario(numero)
            print("El número decimal", numero, "en binario es:", binario)
        elif opcion == 2:
            numero = int(input("Ingrese un número entero: "))
            fibonacci = fibonacci_inverso(numero)
            print("Los primeros", numero, "términos de la serie de Fibonacci en orden inverso son:")
            print(fibonacci)
        elif opcion == 3:
            break
        else:
            print("Opción inválida. Por favor, ingrese una opción válida.")

menu()