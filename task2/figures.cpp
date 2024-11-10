#include "figures.hpp"

static constexpr double PI = 3.14;

#include <iostream>
#include <memory>
#include <stdexcept>
#include <cmath>

enum class FigureType {
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual ~Figure() = default; 
};

class Rect : public Figure {
private:
    double length;
    double height;

public:
    Rect(double a, double b) : length(a), height(b) 
{ 
    if (width < 0 || height < 0) {
            throw LessThanZeroParam("Width or height can't be less than zero.");
}

    FigureType Type() const override {
        return FigureType::RECTANGLE;
    }

    double Perimeter() const override {
        return 2 * (length + height);
    }

    double Area() const override {
        return length * height;
    }
};

class Triangle : public Figure {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw LessThanZeroParam("Sides must be greater than zero.");
        }
        
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw WrongTriangle("Triangle does not exist.");
        }
    }

    FigureType Type() const override {
        return FigureType::TRIANGLE;
    }

    double Perimeter() const override {
        return a + b + c;
    }

    double Area() const override {
        double s = Perimeter() / 2; 
        return std::sqrt(s * (s - a) * (s - b) * (s - c)); 
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double a) : radius(a) {
        if (a < 0) {
            throw LessThanZeroParam("Radius must be non-negative.");
        }
    }

    FigureType Type() const override {
        return FigureType::CIRCLE;
    }

    double Perimeter() const override {
        return 2 * 3.14 * radius; 
    }

    double Area() const override {
        return 3.14 * radius * radius; 
    }
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0) {
    switch (type) {
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(a, b, c);
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(a);
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(a, b);
        default:
            throw std::invalid_argument("Unknown figure type");
    }
}

class WrongTriangle : public std::invalid_argument {
public:
    explicit WrongTriangle(const std::string& message) : std::invalid_argument(message) {}
};

class LessThanZeroParam : public std::invalid_argument {
public:
    explicit LessThanZeroParam(const std::string& message) : std::invalid_argument(message) {}
};
