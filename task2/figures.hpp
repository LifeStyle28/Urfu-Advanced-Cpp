#pragma once
#include <memory>
#include <stdexcept>

static constexpr double PI = 3.14;

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
public:
    Rect(double width, double height);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double width;
    double height;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double a, b, c;
};

class Circle : public Figure {
public:
    Circle(double radius);
    FigureType Type() const override;
    double Perimeter() const override;
    double Area() const override;

private:
    double radius;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public std::invalid_argument {
public:
    WrongTriangle() : std::invalid_argument("") {}
};

class LessThanZeroParam : public std::invalid_argument {
public:
    LessThanZeroParam() : std::invalid_argument("") {}
};
