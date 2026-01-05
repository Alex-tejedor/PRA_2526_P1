#ifndef POINT2D_H
#define POINT2D_H

#include <ostream>

class Point2D {
    public:
        // Atributos públicos

        double x;
        double y;

        // Constructor con valores por defecto

        Point2D(double x = 0, double y = 0);

        // Método estático para calcular la distancia
      

        static double distance(const Point2D &a, const Point2D &b);

        // Sobrecarga de operadores 
    
        friend bool operator==(const Point2D &a, const Point2D &b);
        friend bool operator!=(const Point2D &a, const Point2D &b);
        friend std::ostream& operator<<(std::ostream &out, const Point2D &p);
};

#endif
