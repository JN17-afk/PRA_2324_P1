#include "Drawing.h"
#include <iostream>

Drawing::Drawing() {
    shapes = new List<Shape*>();
}

Drawing::~Drawing() {
    while (!shapes->empty()) {
        delete shapes->remove(0);
    }
    delete shapes;
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);
}

void Drawing::print_all() const {
    for (int i = 0; i < shapes->size(); ++i) {
        shapes->get(i)->print();
    }
}

double Drawing::get_area_all_circles() const {
    double total = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        Circle* c = dynamic_cast<Circle*>(shapes->get(i));
        if (c != nullptr) total += c->area();
    }
    return total;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* sq = dynamic_cast<Square*>(shapes->get(i));
        if (sq != nullptr) sq->translate(incX, incY);
    }
}

