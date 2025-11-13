#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"

class Rectangle : public Shape {
protected:
    Point2D* vs;
public:
    static const int N_VERTICES = 4;

private:
    static bool check(Point2D* vertices);

public:
    // Constructores
    Rectangle();
    Rectangle(std::string color, Point2D* vertices);
    Rectangle(const Rectangle &r);

    // Destructor
    ~Rectangle();

    // Getters y Setters
    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;
    virtual void set_vertices(Point2D* vertices);

    // Sobrecarga del operador de asignación
    Rectangle& operator=(const Rectangle &r);

    // Implementación de los métodos abstractos de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

#endif

