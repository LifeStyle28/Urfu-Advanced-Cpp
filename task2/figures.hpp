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
};


class Rect : public Figure
{
public:
    Rect(int a, int b, int c);
    double Perimeter() const override;
    double Area()const override;
    FigureType Type() const override;
private:
    int A, B;
};



class Triangle : public Figure
{
public:
    Triangle(int a, int b, int c);
    double Perimeter() const override;
    double Area()const override;
    FigureType Type() const override;
private:
    int A, B, C;
};


class Circle : public Figure
{
public:
    Circle(int r, int b, int c);
    double Perimeter() const override;
    double Area()const override;
    FigureType Type() const override;
private:
    int R;
};


class WrongTriangle : public std::invalid_argument 
{
public:
    explicit WrongTriangle(const std::string& message)
        : std::invalid_argument(message) {}
};

class LessThanZeroParam : public std::invalid_argument
{
public:
    explicit LessThanZeroParam(const std::string& message)
        : std::invalid_argument(message) {}
};


std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0);