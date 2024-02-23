#include <iostream>

using namespace std;


struct Nodo {
    int dato;
    Nodo* siguiente;

    Nodo(int d) : dato(d), siguiente(nullptr) {}
};

class Pila {
private:
    Nodo* tope;

public:
    Pila() : tope(nullptr) {}

    void push(int elemento) {
        Nodo* nuevoNodo = new Nodo(elemento);
        nuevoNodo->siguiente = tope;
        tope = nuevoNodo;
    }

    void pop() {
        if (!tope) {
            cout << "Error: La pila esta vacia." << endl;
        } else {
            Nodo* temp = tope;
            tope = tope->siguiente;
            delete temp;
        }
    }

    int top() {
        if (!tope) {
            cout << "Error: La pila esta vacia." << endl;
            return -1;
        } else {
            return tope->dato;
        }
    }

    bool empty() {
        return !tope;
    }

    void mostrar() {
        Nodo* actual = tope;
        cout << "Elementos de la pila:" << endl;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};
class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    void enqueue(int elemento) {
        Nodo* nuevoNodo = new Nodo(elemento);
        if (!frente) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    void dequeue() {
        if (!frente) {
            cout << "Error: La cola esta vacia.." << endl;
        } else {
            Nodo* temp = frente;
            frente = frente->siguiente;
            delete temp;
            if (!frente) final = nullptr;
        }
    }

    int front() {
        if (!frente) {
            cout << "Error: La cola esta vacia." << endl;
            return -1;
        } else {
            return frente->dato;
        }
    }

    bool empty() {
        return !frente;
    }

    void mostrar() {
        Nodo* actual = frente;
        cout << "Elementos de la cola:" << endl;
        while (actual) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};

int main() {
    Pila pila;
    Cola cola;
    pila.push(1);
    pila.push(2);
    pila.push(3);

    cola.enqueue(1);
    cola.enqueue(2);
    cola.enqueue(3);

    int opcion;
    int elemento;

    do {
        cout << "Menu:" << endl;
        cout << "1. Agregar elemento a la pila" << endl;
        cout << "2. Quitar elemento de la pila" << endl;
        cout << "3. Ver pila" << endl;
        cout << "4. Agregar elemento a la cola" << endl;
        cout << "5. Quitar elemento de la cola" << endl;
        cout << "6. Ver cola" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el elemento a agregar a la pila: ";
                cin >> elemento;
                pila.push(elemento);
                break;
            case 2:
                pila.pop();
                break;
            case 3:
                pila.mostrar();
                break;
            case 4:
                cout << "Ingrese el elemento a agregar a la cola: ";
                cin >> elemento;
                cola.enqueue(elemento);
                break;
            case 5:
                cola.dequeue();
                break;
            case 6:
                cola.mostrar();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}