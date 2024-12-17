#include "figures.hpp"

static constexpr double PI = 3.14;

Rect::Rect(double a, double b)
{
	if (a < 0 || b < 0)
	{
		throw LessThanZeroParam{ "ERR_RECTANGLE_LESS_THAN_ZERO_PARAM" };
	}
	s1 = a;
	s2 = b;
}

FigureType Rect::Type() const
{
	return FigureType::RECTANGLE;
}

double Rect::Perimeter() const
{
	return s1 * 2.0 + s2 * 2.0;
}

double Rect::Area() const
{
	return s1 * s2;
}

Triangle::Triangle(double a, double b, double c)
{
	if (a + b <= c || a + c <= b || b + c <= a)
	{
		throw WrongTriangle{ "ERR_WRONG_TRIANGLE" };
	}
	if (a < 0 || b < 0 || c < 0)
	{
		throw LessThanZeroParam{ "ERR_TRIANGLE_LESS_THAN_ZERO_PARAM" };
	}
	s1 = a;
	s2 = b;
	s3 = c;
}

FigureType Triangle::Type() const
{
	return FigureType::TRIANGLE;
}

double Triangle::Perimeter() const
{
	return s1 + s2 + s3;
}

double Triangle::Area() const
{
	return sqrt((this->Perimeter() / 2) * (this->Perimeter() / 2 - s1) * (this->Perimeter() / 2 - s2) * (this->Perimeter() / 2 - s3));
}

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b = 0, double c = 0)
{

	switch (type)
	{
		case FigureType::RECTANGLE:
			std::make_unique<Rect>(a, b);
			break;
		case FigureType::TRIANGLE:
			std::make_unique<Triangle>(a, b, c);
			break;
		case FigureType::CIRCLE:
			std::make_unique<Circle>(a);
			break;
	}	
}

Circle::Circle(double a)
{
	if (a < 0)
	{
		throw LessThanZeroParam{ "ERR_CIRCLE_LESS_THAN_ZERO_PARAM" };
	}
	r = a;
}

FigureType Circle::Type() const
{
	return FigureType::CIRCLE;
}

double Circle::Perimeter() const
{
	return 2 * PI * r;
}

double Circle::Area() const
{
	return r * r * PI;
}
