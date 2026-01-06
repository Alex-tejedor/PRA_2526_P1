#include "Rectangle.h"
#include <cmath>

// Método para validar si es rectángulo
bool Rectangle::check(Point2D* vertices) {
    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    return (d01 == d23 && d12 == d30);
}

// Constructor por defecto
Rectangle::Rectangle() : Shape("red") {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

// Constructor paramétrico
Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }
    
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Constructor de Copia
Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw std::invalid_argument("Provided vertices do not build a valid rectangle!");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

// Operador de Asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        delete[] vs;
        
        this->color = r.color;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

double Rectangle::area() const {
    return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const {
    return 2 * (Point2D::distance(vs[0], vs[1]) + Point2D::distance(vs[1], vs[2]));
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() {
    std::cout << *this;
}

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "[Rectangle: color = " << r.color << "; v0 = " << r.vs[0] 
        << "; v1 = " << r.vs[1] << "; v2 = " << r.vs[2] 
        << "; v3 = " << r.vs[3] << "]";
    return out;
}
