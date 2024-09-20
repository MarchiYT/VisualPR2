#include "areacalculator.h"
#include <cmath>

double AreaCalculator::square(double side) {
    return side * side;
}

double AreaCalculator::rectangle(double length, double width) {
    return length * width;
}

double AreaCalculator::parallelogram(double base, double height) {
    return base * height;
}

double AreaCalculator::rhombus(double diag1, double diag2) {
    return 0.5 * diag1 * diag2;
}

double AreaCalculator::triangle(double base, double height) {
    return 0.5 * base * height;
}

double AreaCalculator::trapezoid(double base1, double base2, double height) {
    return 0.5 * (base1 + base2) * height;
}

double AreaCalculator::circle(double radius) {
    return M_PI * radius * radius;
}

double AreaCalculator::sector(double radius, double angle) {
    return 0.5 * radius * radius * angle;
}
