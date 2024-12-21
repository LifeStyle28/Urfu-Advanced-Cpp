#pragma once

#include <memory>
#include <stdexcept>

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
};

class Rect : public Figure
{
private:
    double s1;
    double s2;
public:
    Rect(double a, double b);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

class Triangle : public Figure
{
private:
    double s1;
    double s2;
    double s3;
public:
    Triangle(double a, double b, double c);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

class Circle : public Figure
{
private:
    double r;
public:
    Circle(double a);
    FigureType Type() const;
    double Perimeter() const;
    double Area() const;
};

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);

class WrongTriangle : public std::invalid_argument
{
public:
    WrongTriangle(const std::string& msg) : std::invalid_argument{ msg }{};
};

class LessThanZeroParam : public std::invalid_argument
{
public:
    LessThanZeroParam(const std::string& msg) : std::invalid_argument{ msg }{};
};

