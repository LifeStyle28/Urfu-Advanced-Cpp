#pragma once

#include <memory>
#include <stdexcept>
#include <cmath>

enum class FigureType
{
    TRIANGLE,
    CIRCLE,
    RECTANGLE,
};

class Figure {
public:
    virtual FigureType Type() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
    virtual ~Figure() = default; // Виртуальный деструктор
};

class Rect : public Figure {
public:
    Rect(double width, double height) : width(width), height(height) {}

    FigureType Type() const override { return FigureType::RECTANGLE; }
    double Perimeter() const override { return 2 * (width + height); }
    double Area() const override { return width * height; }

private:
    double width;
    double height;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw LessThanZeroParam("Sides must be greater than zero");
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw WrongTriangle("Invalid triangle sides");
        }
    }

    FigureType Type() const override { return FigureType::TRIANGLE; }
    double Perimeter() const override { return a + b + c; }
    double Area() const override {
        double s = Perimeter() / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

private:
    double a;
    double b;
    double c;
};

class Circle : public Figure {
public:
    Circle(double radius) : radius(radius) {
        if (radius <= 0) {
            throw LessThanZeroParam("Radius must be greater than zero");
        }
    }

    FigureType Type() const override { return FigureType::CIRCLE; }
    double Perimeter() const override { return 2 * PI * radius; }
    double Area() const override { return PI * radius * radius; }

private:
    double radius;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public std::invalid_argument {
public:
    explicit WrongTriangle(const std::string& message) : std::invalid_argument(message) {}
};

class LessThanZeroParam : public std::invalid_argument {
public:
    explicit LessThanZeroParam(const std::string& message) : std::invalid_argument(message) {}
};
