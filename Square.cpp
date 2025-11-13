#include "Square.h"
#include <cmath>
#include <iostream>

// Función privada para comprobar si los vértices forman un cuadrado
bool Square::check(Point2D* vertices) {
    if (!vertices) return false;

    double d01 = Point2D::distance(vertices[0], vertices[1]);
    double d12 = Point2D::distance(vertices[1], vertices[2]);
    double d23 = Point2D::distance(vertices[2], vertices[3]);
    double d30 = Point2D::distance(vertices[3], vertices[0]);

    const double EPS = 1e-9;

    // Todos los lados deben tener la misma longitud
    return (std::abs(d01 - d12) < EPS &&
            std::abs(d12 - d23) < EPS &&
            std::abs(d23 - d30) < EPS);
}

// Constructores
Square::Square() : Rectangle() {
    delete[] vs; // eliminamos los vértices del Rectangle por defecto
    vs = new Point2D[N_VERTICES]{
        Point2D(-1, 1), Point2D(1, 1),
        Point2D(1, -1), Point2D(-1, -1)
    };
}

Square::Square(std::string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices))
        throw std::invalid_argument("Vértices no forman un cuadrado válido");
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// Sobrescribir set_vertices
void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices))
        throw std::invalid_argument("Vértices no forman un cuadrado válido");
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// Sobrescribir print()
void Square::print() const {
    std::cout << "Cuadrado de color " << color << ", vértices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << "(" << vs[i].x << "," << vs[i].y << ")";
        if (i != N_VERTICES - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

// Sobrecarga operador <<
std::ostream& operator<<(std::ostream &out, const Square &square) {
    out << "Square[color=" << square.color << ", vertices=[";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << "(" << square.vs[i].x << "," << square.vs[i].y << ")";
        if (i != Rectangle::N_VERTICES - 1) out << ", ";
    }
    out << "]]";
    return out;
}


