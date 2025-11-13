#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"
#include "Point2D.h"

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices);

public:
    // Constructores
    Square();
    Square(std::string color, Point2D* vertices);

    // Sobrescribir set_vertices de Rectangle
    void set_vertices(Point2D* vertices) override;

    // Sobrescribir print()
    void print() const override;

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream &out, const Square &square);
};

#endif

