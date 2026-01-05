#include "Point2D.h"
#include <cmath>

// Constructor

Point2D::Point2D(double x, double y) {
    this->x = x;
    this->y = y;
}

// Distancia Euclídea: d = sqrt((x1-x2)^2 + (y1-y2)^2)

double Point2D::distance(const Point2D &a, const Point2D &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

// Operador de igualdad

bool operator==(const Point2D &a, const Point2D &b) {
    return (a.x == b.x && a.y == b.y);
}

// Operador de desigualdad

bool operator!=(const Point2D &a, const Point2D &b) {
    return !(a == b);
}

// Operador de flujo de salida 

std::ostream& operator<<(std::ostream &out, const Point2D &p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}
