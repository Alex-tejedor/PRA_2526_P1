#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
    protected:
      // Puntero al array de vertices
        Point2D* vs;

    public:
        static const int N_VERTICES = 4;

        // Constructores
        Rectangle();
        Rectangle(std::string color, Point2D* vertices);
        Rectangle(const Rectangle &r); // Constructor de copia

        // Destructor
        ~Rectangle();

        // Geter y Operadores
        Point2D get_vertex(int ind) const;
        Point2D operator[](int ind) const;
        Rectangle& operator=(const Rectangle &r); // Operador de asignación

        // Método modificador
        virtual void set_vertices(Point2D* vertices);

        // Métodos virtuales heredados de Shape
        double area() const override;
        double perimeter() const override;
        void translate(double incX, double incY) override;
        void print() override;

        friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);

    private:
        // Método auxiliar estático
        static bool check(Point2D* vertices);
};

#endif
