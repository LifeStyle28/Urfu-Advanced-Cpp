#include "figures.hpp"

#include <stdexcept>
#include <cmath>

using namespace std;

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

Triangle::Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

FigureType Triangle::Type() const {
    return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const {
    return a + b + c;
}

double Triangle::Area() const {
    double p = Perimeter() / 2; 
    return std::sqrt(p * (p - a) * (p - b) * (p - c)); 
}


Circle::Circle(double a) : radius(a) {}

FigureType Circle::Type() const {
    return FigureType::CIRCLE;
}

double Circle::Perimeter() const {
    return 2 * PI * radius; 
}

double Circle::Area() const {
    return PI * radius * radius; 
}

unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
    if (a < 0 || b < 0 || c < 0) {
        throw LessThanZeroParam("Sides must be greater than zero.");
    }
        
    if (type == FigureType::RECTANGLE) 
    {
        return make_unique<Rect>(a, b);
    } 
    else if (type == FigureType::CIRCLE) 
    {
        return make_unique<Circle>(a);
    } 
    else if (type == FigureType::TRIANGLE) 
    {
        if (a + b <= c || a + c <= b || b + c <= a) 
        {
            throw WrongTriangle("");
        }
        return make_unique<Triangle>(a, b, c);
    }
    else
    {
        return nullptr;
    }
}
