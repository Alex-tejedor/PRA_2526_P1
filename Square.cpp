#include "Square.h"
#include <cmath>

// Comprueba que los 4 lados sean iguales
bool Square::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d12 && d12 == d23 && d23 == d30);
}

// Constructor por defecto
Square::Square() : Rectangle() {
    // Rectangle() ya ha reservado memoria para 'vs' y puesto color 'red'.
    // Sobreescribimos los vértices para que formen el cuadrado por defecto.
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
}

// Constructor paramétrico
Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    // Rectangle(color, vertices) ya ha validado que sea un rectángulo
    // Ahora validamos que sea específicamente un cuadrado
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid square!");
    }
    // Llamamos al método del padre para hacer la copia real
    Rectangle::set_vertices(vertices);
}

void Square::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "[Square: color = " << square.color << "; v0 = " << square.vs[0] 
        << "; v1 = " << square.vs[1] << "; v2 = " << square.vs[2] 
        << "; v3 = " << square.vs[3] << "]";
    return out;
}
