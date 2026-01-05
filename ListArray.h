#ifndef LISTARRAY_H
#define LISTARRAY_H
#include <ostream>
#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {

    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;

        // Método privado para redimensionar el array
        void resize(int new_size) {

            T* new_arr = new T[new_size];

            for (int i = 0; i < n; i++) {
                new_arr[i] = arr[i];
            }

            delete[] arr;

            arr = new_arr;
            max = new_size;
        }

    public:
        // Constructor

        ListArray() {
            n = 0;
            max = MINSIZE;
            arr = new T[MINSIZE]; // Reserva inicial
        }

        // Destructor

        ~ListArray() {
            delete[] arr;
        }

        // Sobrecarga del operador []
        
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida!");
            }
            return arr[pos];
        }

        // Sobrecarga del operador <<

        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list) {
            out << "List => [" << std::endl;
            for (int i = 0; i < list.n; i++) {
                out << "  " << list.arr[i] << std::endl;
            }
            out << "]" << std::endl;
            return out;
        }

        // Implementación de métodos heredados de List<T> 

        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición inválida!");
            }

            if (n >= max) {
                resize(max * 2);
            }

            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];
            }

            arr[pos] = e;
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
                throw std::out_of_range("Posición inválida!");
            }

            T removed_element = arr[pos];

            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];
            }

            n--;
            
            return removed_element;
        }

        T get(int pos) override {
             if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición inválida!");
            }
            return arr[pos];
        }

        int search(T e) override {
            for (int i = 0; i < n; i++) {
                if (arr[i] == e) {
                    return i;
                }
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
