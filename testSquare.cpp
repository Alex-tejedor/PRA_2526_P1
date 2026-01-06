#include <iostream>
#include "Square.h"
#include "Point2D.h"

int main() {
    // Test Constructor por defecto
    Square r1;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r1.area() => " << r1.area() << "; r1.perimeter() => " << r1.perimeter() << std::endl;
    std::cout << std::endl;

    // Test Constructor paramétrico
    Point2D v_r2[4] = { Point2D(-2, 2), Point2D(2, 2), Point2D(2, -2), Point2D(-2, -2) };
    Square r2("green", v_r2);
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r2.area() => " << r2.area() << "; r2.perimeter() => " << r2.perimeter() << std::endl;
    std::cout << std::endl;

    // Test Excepción (Vertices inválidos para un cuadrado, aunque sean válidos para un rectángulo)
    Point2D v_bad[4] = { Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, 0) }; // Último punto rompe el cuadrado
    
    try {
        std::cout << "r2.set_vertices(...) => ";
        r2.set_vertices(v_bad);
    } catch (std::invalid_argument &e) {
        std::cout << "std::invalid_argument: " << e.what() << std::endl;
    }

    return 0;
}
