#include "figures.hpp"

std::unique_ptr<Figure> make_figure(FigureType type, double a, double b, double c) {
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
