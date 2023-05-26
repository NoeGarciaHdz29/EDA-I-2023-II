class Libro:
    def _init_(self, titulo, id):
        self.titulo = titulo
        self.id = id

class Biblioteca:
    def _init_(self):
        self.libros = []

    def agregar_libro(self, titulo):
        id = len(self.libros) + 1
        libro = Libro(titulo, id)
        self.libros.append(libro)
        print("Libro agregado correctamente.")
        


    def eliminar_libro(self, titulo):
        for libro in self.libros:
            if libro.titulo == titulo:
                self.libros.remove(libro)
                print("Libro eliminado correctamente.")
                return
        print("No se encontro el libro en la biblioteca.")

    def ordenar_libros(self, criterio):
        if criterio == 'titulo':
            self.libros.sort(key
                             
                             =lambda libro: libro.titulo)
        elif criterio == 'id':
            self.libros.sort(key=lambda libro: libro.id)
        else:
            print("Criterio de ordenamiento invalido. Selecciona 'titulo' o 'id'.")
            return

        print("Biblioteca ordenada correctamente.")

    def mostrar_biblioteca(self):
        if not self.libros:
            print("La biblioteca esta vacia.")
        else:
            print("Libros en la biblioteca:")
            for libro in self.libros:
                print(f"ID: {libro.id} - Titulo: {libro.titulo}")


biblioteca = Biblioteca()

while True:
    print("\n--- Menu ---")
    print("1 - Agregar libro")
    print("2 - Eliminar libro")
    print("3 - Ordenar biblioteca")
    print("4 - Ver biblioteca")
    print("5 - Salir")

    opcion = input("Selecciona una opcion: ")

    if opcion == '1':
        titulo = input("Ingrese el titulo del libro: ")
        biblioteca.agregar_libro(titulo)
    elif opcion == '2':
        titulo = input("Ingrese el titulo del libro a eliminar: ")
        biblioteca.eliminar_libro(titulo)
    elif opcion == '3':
        criterio = input("Ingrese el criterio de ordenamiento ('titulo' o 'id'): ")
        biblioteca.ordenar_libros(criterio)
    elif opcion == '4':
        biblioteca.mostrar_biblioteca()
    elif opcion == '5':
        break
    else:
        print("Opcion invalida. Por favor, seleccione una opcion valida.")