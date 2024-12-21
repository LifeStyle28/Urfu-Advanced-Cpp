#include "figures.hpp"

static constexpr double PI = 3.14;

//Triangle
Triangle::Triangle(int a, int b, int c) : A(a), B(b), C(c) 
{
    if (A + B <= C || C + B <= A || A + C <= B)
    {
        throw WrongTriangle("Треугольник не существует");
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
Circle::Circle(int r, int /*unused_b*/, int /*unused_c*/) : R(r) {}

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
Rect::Rect(int a, int b, int /*unused_c*/) : A(a), B(b) {}

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
{   if (a < 0 || b < 0 || c < 0) 
    {
        throw LessThanZeroParam("Параметры фигуры должны быть больше нуля");
    }
    switch (type) 
    {
        case FigureType::TRIANGLE:
            return std::make_unique<Triangle>(static_cast<int>(a), static_cast<int>(b), static_cast<int>(c));
        case FigureType::CIRCLE:
            return std::make_unique<Circle>(static_cast<int>(a), static_cast<int>(b), static_cast<int>(c));
        case FigureType::RECTANGLE:
            return std::make_unique<Rect>(static_cast<int>(a), static_cast<int>(b), static_cast<int>(c));
        default:
            return nullptr;
    }
}