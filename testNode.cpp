#include <iostream>
#include "Node.h"

int main(){
    Node<char>* first = new Node<char>('A');
    first = new Node<char>('R', first);
    first = new Node<char>('P', first);

    std::cout << "Secuencia: ";
    Node<char>* aux = first;
    while (aux != nullptr){
        std::cout << aux->data << " ";
        aux = aux->next;
    }
    std::cout << std::endl;
    
    // (Opcional pero recomendado) Limpieza de memoria para evitar leaks en el test
    // Aunque el SO limpia al terminar, es buena práctica en C++
    while (first != nullptr) {
        aux = first->next;
        delete first;
        first = aux;
    }
}
