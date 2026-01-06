#include <iostream>
#include "Rectangle.h"
#include "Point2D.h"

int main() {
    // Test Constructor por defecto
    Rectangle r1;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r1.area() => " << r1.area() << "; r1.perimeter() => " << r1.perimeter() << std::endl;

    // Test Constructor paramétrico
    Point2D v_r2[4] = { Point2D(-1, 1), Point2D(1, 1), Point2D(1, -1), Point2D(-1, -1) };
    Rectangle r2("green", v_r2);
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r2.area() => " << r2.area() << "; r2.perimeter() => " << r2.perimeter() << std::endl;
    std::cout << std::endl;

    // Test de acceso a vértices
    std::cout << "r1.get_vertex(0) => " << r1.get_vertex(0) << "; r1[0] => " << r1[0] << std::endl;
    std::cout << "r1.get_vertex(3) => " << r1.get_vertex(3) << "; r1[3] => " << r1[3] << std::endl;
    std::cout << std::endl;

    // Test Translate
    r2.translate(10, 10);
    std::cout << "r2.translate(10,10) => " << std::endl;
    std::cout << "    r2 = " << r2 << std::endl;
    std::cout << std::endl;

    // Test Excepciones (set_vertices inválidos)
    Point2D v_bad[4] = { Point2D(0,0), Point2D(1,1), Point2D(0,0), Point2D(1,1) }; // No es rectángulo válido
    try {
        std::cout << "r2.set_vertices(...) => ";
        r2.set_vertices(v_bad);
    } catch (std::invalid_argument &e) {
        std::cout << "std::invalid_argument: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test Copia profunda
    Rectangle r3 = r1; // Constructor de copia
    std::cout << "Rectangle r3 = r1; Aleshores..." << std::endl;
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;
    
    r3.translate(100, 100);
    std::cout << "r3.translate(100, 100); Aleshores..." << std::endl;
    // Si la copia fuera superficial, r1 también cambiaría (error). 
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;

    return 0;
}
