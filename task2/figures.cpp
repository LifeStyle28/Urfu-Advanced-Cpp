#include "figures.hpp"

static constexpr double PI = 3.14;

//Triangle
Triangle::Triangle(int a, int b, int c) : A(a), B(b), C(c) 
{
    if (A <= 0 || B <= 0 || C <= 0) 
    {
        throw LessThanZeroParam("Стороны треугольника должны быть больше нуля");
    }

    if (A + B < C || C + B < A || A + C < B)
    {
        throw WrongTriangle("Треугольника не существует");
    } 
    
}

double Triangle::Perimeter() const
{
    return A + B + C;
}

double Triangle::Area() const
{
    double p = 0.5 * Perimeter();
    return sqrt(p * (p - A) * (p - B) * (p - C));
}

FigureType Triangle::Type() const
{
    return FigureType::TRIANGLE;
}

//Circle
Circle::Circle(int r, int /*unused_b*/, int /*unused_c*/) : R(r)
{
    if (R <= 0) 
    {
        throw LessThanZeroParam("Радиус окуржности должен быть больше нуля");
    }
}

double Circle::Perimeter() const
{
    return 2*PI*R;
}

double Circle::Area() const
{
    return PI*R*R;
}

FigureType Circle::Type() const
{
    return FigureType::CIRCLE;
}

//Rectangle
Rect::Rect(int a, int b, int /*unused_c*/) : A(a), B(b)
{
    if (A <= 0 || B <= 0) 
    {
        throw LessThanZeroParam("Стороны прямоугольника должны быть больше нуля");
    }
}

double Rect::Perimeter() const
{
    return 2*(A + B);
}

double Rect::Area() const
{
    return A*B;
}

FigureType Rect::Type() const
{
    return FigureType::RECTANGLE;
}

//make_figure realization
std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) 
{   
    switch (type) 
    {
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(static_cast<int>(a), static_cast<int>(b), static_cast<int>(c));
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(static_cast<int>(a), static_cast<int>(b), static_cast<int>(c));
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(static_cast<int>(a), static_cast<int>(b), static_cast<int>(c));
        default:
            throw std::invalid_argument("Неизвестный тип фигуры");
    }
}