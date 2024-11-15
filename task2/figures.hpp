#pragma once
#include <memory>
#include <stdexcept>

using namespace std;

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

unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public invalid_argument {
public:
    WrongTriangle(const char* msg) : invalid_argument(msg) {}
};

class LessThanZeroParam : public invalid_argument {
public:
    LessThanZeroParam(const char* msg) : invalid_argument(msg) {}
};
