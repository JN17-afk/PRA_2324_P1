#include "Rectangle.h"
#include <cmath>
#include <iostream>

// Función privada para validar si los vértices forman un rectángulo
bool Rectangle::check(Point2D* vertices) {
    if (!vertices) return false;

    // Usamos la propiedad de los rectángulos: lados opuestos paralelos y perpendiculares
    // Comprobamos vectores de los lados consecutivos
    auto vec = [](const Point2D &a, const Point2D &b) {
        return Point2D(b.x - a.x, b.y - a.y);
    };
    auto dot = [](const Point2D &u, const Point2D &v) {
        return u.x * v.x + u.y * v.y;
    };
    Point2D v0v1 = vec(vertices[0], vertices[1]);
    Point2D v1v2 = vec(vertices[1], vertices[2]);
    Point2D v2v3 = vec(vertices[2], vertices[3]);
    Point2D v3v0 = vec(vertices[3], vertices[0]);

    // Lados opuestos iguales
    double d01 = std::hypot(v0v1.x, v0v1.y);
    double d12 = std::hypot(v1v2.x, v1v2.y);
    double d23 = std::hypot(v2v3.x, v2v3.y);
    double d30 = std::hypot(v3v0.x, v3v0.y);

    // Rectángulo: lados opuestos iguales y ángulos rectos
    if (std::abs(d01 - d23) > 1e-9) return false;
    if (std::abs(d12 - d30) > 1e-9) return false;
    if (std::abs(dot(v0v1, v1v2)) > 1e-9) return false;
    if (std::abs(dot(v1v2, v2v3)) > 1e-9) return false;
    return true;
}

// Constructores
Rectangle::Rectangle() : Shape() {
    vs = new Point2D[N_VERTICES]{
        Point2D(-1, 0.5), Point2D(1, 0.5),
        Point2D(1, -0.5), Point2D(-1, -0.5)
    };
}

Rectangle::Rectangle(std::string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices))
        throw std::invalid_argument("Vértices no forman un rectángulo válido");
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = r.vs[i];
}

// Destructor
Rectangle::~Rectangle() {
    delete[] vs;
}

// Getters y Setters
Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES)
        throw std::out_of_range("Índice de vértice fuera de rango");
    return vs[ind];
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices))
        throw std::invalid_argument("Vértices no forman un rectángulo válido");
    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// Operador de asignación
Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) {
        color = r.color;
        for (int i = 0; i < N_VERTICES; ++i)
            vs[i] = r.vs[i];
    }
    return *this;
}

// Métodos de Shape
double Rectangle::area() const {
    double width = std::hypot(vs[1].x - vs[0].x, vs[1].y - vs[0].y);
    double height = std::hypot(vs[3].x - vs[0].x, vs[3].y - vs[0].y);
    return width * height;
}

double Rectangle::perimeter() const {
    double width = std::hypot(vs[1].x - vs[0].x, vs[1].y - vs[0].y);
    double height = std::hypot(vs[3].x - vs[0].x, vs[3].y - vs[0].y);
    return 2 * (width + height);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() const {
    std::cout << "Rectángulo de color " << color << ", vértices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        std::cout << "(" << vs[i].x << "," << vs[i].y << ")";
        if (i != N_VERTICES - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    out << "Rectangle[color=" << r.color << ", vertices=[";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << "(" << r.vs[i].x << "," << r.vs[i].y << ")";
        if (i != Rectangle::N_VERTICES - 1) out << ", ";
    }
    out << "]]";
    return out;
}

