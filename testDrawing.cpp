#include <iostream>
#include "Drawing.h"
#include "Square.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Point2D.h"

int main() {
    Drawing d;

    // Creo figuras dinámicamente

    // Un Círculo (Rojo por defecto)
    d.add_front(new Circle()); 
    
    // Un Cuadrado (Rojo por defecto) añadido al frente
    d.add_front(new Square());

    // Un Rectángulo (Rojo por defecto) añadido al fondo
    d.add_back(new Rectangle());

    // Mostramos todo
    d.print_all();
    std::cout << std::endl;

    // Calculo el área de los círculos
    std::cout << "Area (all circles) = " << d.get_area_all_circles() << std::endl;
    std::cout << std::endl;

    // Muevo solo los cuadrados
    std::cout << "Calling move_squares(10, 10)..." << std::endl;
    d.move_squares(10, 10);

    // Volvo a mostrar para ver que el cuadrado se ha movido
    d.print_all();
    std::cout << std::endl;

    return 0;
}
