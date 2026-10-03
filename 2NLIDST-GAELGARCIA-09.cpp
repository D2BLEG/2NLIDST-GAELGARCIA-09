#include <iostream>
using namespace std;

#define MaxTamC 10 /// Tamaño máximo de la cola

typedef int TipoData;

// SE CORRIGIÓ: 'final' ahora se pasa por referencia (&final) para guardar el avance
void ingresar_valores(int frente, int& final, TipoData A[], int& contador) {
    if ((final + 1) % MaxTamC == frente) {
        cout << "Desbordamiento de la cola (Cola llena)." << endl;
        return;
    }

    TipoData elemento;
    cout << "Ingrese un elemento para la cola: ";
    cin >> elemento;

    final = (final + 1) % MaxTamC;
    A[final] = elemento;
    contador++;
    cout << "Elemento " << contador << " agregado a la cola." << endl;
}

void eliminar_elemento(int& frente, int final, int& contador) {
    if (frente == final) {
        cout << "La cola esta vacia, no se puede eliminar." << endl;
        return;
    }

    frente = (frente + 1) % MaxTamC;
    contador--;
    cout << "Elemento eliminado de la cola." << endl;
}

void imprimir(int frente, int final, TipoData A[]) {
    if (frente == final) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    cout << "Elementos de la cola en el orden de ingreso: ";
    for (int i = (frente + 1) % MaxTamC; i != (final + 1) % MaxTamC; i = (i + 1) % MaxTamC) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    TipoData A[MaxTamC];
    int contador = 0;
    int frente = 0;
    int final = 0;
    char respuesta;

    cout << "Desea agregar elementos a la cola? (s/n): ";
    cin >> respuesta;

    while ((respuesta == 's' || respuesta == 'S') && contador < MaxTamC - 1) {
        ingresar_valores(frente, final, A, contador);

        if (contador < MaxTamC - 1) {
            cout << "Desea agregar mas elementos a la cola? (s/n): ";
            cin >> respuesta;
        }
    }

    if (frente == final) {
        cout << "La cola esta vacia." << endl;
        return 0;
    }

    TipoData primerElemento = A[(frente + 1) % MaxTamC];
    cout << "\nEl primer elemento de la cola es: " << primerElemento << endl;

    eliminar_elemento(frente, final, contador);
    imprimir(frente, final, A);

    return 0;
}