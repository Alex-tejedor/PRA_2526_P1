#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first; // Puntero al primer nodo
        int n;          // Número de elementos

    public:
        // Constructor
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        // Destructor: Libera la memoria nodo a nodo
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        // Operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en operator[]");
            }
            
            // Recorremos la lista hasta llegar a 'pos'
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        // Operador <<
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            out << "List => [" << std::endl;
            Node<T>* aux = list.first;
            while (aux != nullptr) {
                out << "  " << aux->data << std::endl;
                aux = aux->next;
            }
            out << "]" << std::endl;
            return out;
        }

        // --- Implementación de métodos heredados ---

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición inválida en insert");
            }

            // Caso especial: Insertar al principio (cambia 'first')
            if (pos == 0) {
                first = new Node<T>(e, first);
            } 
            // Caso general: Insertar en medio o final
            else {
                Node<T>* prev = first;
                // Avanzamos hasta el nodo ANTERIOR a la posición (pos-1)
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                // Creamos el nodo nuevo apuntando al siguiente del anterior
                prev->next = new Node<T>(e, prev->next);
            }
            n++;
        }

        void append(T e) override {
            insert(n, e);
        }

        void prepend(T e) override {
            insert(0, e);
        }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en remove");
            }

            Node<T>* aux = first;
            T dataRemoved;

            // Caso especial: Eliminar el primero
            if (pos == 0) {
                first = first->next; // El segundo pasa a ser el primero
                dataRemoved = aux->data;
                delete aux;
            } 
            // Caso general: Eliminar en medio o final
            else {
                Node<T>* prev = first;
                // Avanzamos hasta el anterior (pos-1)
                for (int i = 0; i < pos - 1; i++) {
                    prev = prev->next;
                }
                aux = prev->next;       // El nodo a borrar
                prev->next = aux->next; // Saltamos el nodo a borrar
                dataRemoved = aux->data;
                delete aux;
            }
            
            n--;
            return dataRemoved;
        }

        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida en get");
            }
            
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        int search(T e) override {
            Node<T>* aux = first;
            int i = 0;
            while (aux != nullptr) {
                if (aux->data == e) {
                    return i;
                }
                aux = aux->next;
                i++;
            }
            return -1;
        }

        bool empty() override {
            return n == 0;
        }

        int size() override {
            return n;
        }
};

#endif
