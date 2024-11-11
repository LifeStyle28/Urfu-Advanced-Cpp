#include "figures.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cmath>

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
    virtual ~Figure() = default; // Виртуальный деструктор
};

class Rect : public Figure {
public:
    Rect(double width, double height) : width_(width), height_(height) {
        if (width < 0 || height < 0) {
            throw LessThanZeroParam("Width or height can't be less than zero.");
        }
    }

    FigureType Type() const override {
        return FigureType::RECTANGLE;
    }

    double Perimeter() const override {
        return 2 * (width_ + height_);
    }

    double Area() const override {
        return width_ * height_;
    }

private:
    double width_, height_;
};

class Triangle : public Figure {
public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            throw LessThanZeroParam("Sides must be greater than zero.");
        }
        if (!IsTriangle(a, b, c)) {
            throw WrongTriangle("The provided sides do not form a valid triangle.");
        }
    }

    FigureType Type() const override {
        return FigureType::TRIANGLE;
    }

    double Perimeter() const override {
        return a_ + b_ + c_;
    }

    double Area() const override {
        double s = Perimeter() / 2;
        return std::sqrt(s * (s - a_) * (s - b_) * (s - c_));
    }

private:
    double a_, b_, c_;

    bool IsTriangle(double a, double b, double c) const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }
};

class Circle : public Figure {
public:
    Circle(double radius) : radius_(radius) {
        if (radius < 0) {
            throw LessThanZeroParam("Radius can't be less than zero.");
        }
    }

    FigureType Type() const override {
        return FigureType::CIRCLE;
    }

    double Perimeter() const override {
        return 2 * PI * radius_;
    }

    double Area() const override {
        return PI * radius_ * radius_;
    }

private:
    double radius_;
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
            throw std::invalid_argument("Unknown figure type.");
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
