#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
    public:
        // Constructores
        Square();
        Square(std::string color, Point2D* vertices);

        // Métodos sobrescritos
        void set_vertices(Point2D* vertices) override;
        void print() override;

        // operador <<
        friend std::ostream& operator<<(std::ostream &out, const Square &square);

    private:
        // Método auxiliar estático para validar si es un cuadrado
        static bool check(Point2D* vertices);
};

#endif
