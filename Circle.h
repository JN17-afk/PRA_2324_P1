#ifndef CIRCLE_H
#define CIRCLE_H

#include <ostream>
#include "Shape.h"
#include "Point2D.h"

class Circle : public Shape {
private:
    Point2D center;
    double radius;

public:
    // Constructores
    Circle();
    Circle(std::string color, Point2D center, double radius);

    // Getters y Setters
    Point2D get_center() const;
    void set_center(Point2D p);
    double get_radius() const;
    void set_radius(double r);

    // Implementación de los métodos abstractos de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Circle &c);
};

#endif

