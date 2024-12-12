#include "figures.hpp"
#include <cmath>
static constexpr double PI = 3.14;
Rect::Rect(double a, double b) : width(a), height(b) {}
FigureType Rect::Type() const {
    return FigureType::RECTANGLE;
}
double Rect::Perimeter() const {
    return 2 * (width + height);
}
double Rect::Area() const {
    return width * height;
}
Triangle::Triangle(double side_a, double side_b, double side_c) 
    : a(side_a), b(side_b), c(side_c) {}
FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}
double Triangle::Perimeter() const {
    return a + b + c;
}
double Triangle::Area() const {
    double s = Perimeter() / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
Circle::Circle(double r) : radius(r) {}
FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}
double Circle::Perimeter() const {
    return 2 * PI * radius;
}
double Circle::Area() const {
    return PI * radius * radius;
}
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    if (a < 0 || b < 0 || c < 0) {
        throw LessThanZeroParam("");
    }
    switch (type) {
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);
        case FigureType::TRIANGLE:
            if (a + b <= c || b + c <= a || a + c <= b) {
                throw WrongTriangle("");
            }
            return std::make_unique<Triangle>(a, b, c);
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);
        default:
            return nullptr;
    }
}
