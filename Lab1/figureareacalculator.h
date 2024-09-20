#ifndef FIGUREAREACALCULATOR_H
#define FIGUREAREACALCULATOR_H

class FigureAreaCalculator {
public:
    static double squareArea(double side) {
        return side * side;
    }

    static double rectangleArea(double width, double height) {
        return width * height;
    }

    static double parallelogramArea(double base, double height) {
        return base * height;
    }

    static double rhombusArea(double diagonal1, double diagonal2) {
        return (diagonal1 * diagonal2) / 2;
    }

    static double triangleArea(double base, double height) {
        return (base * height) / 2;
    }

    static double trapezoidArea(double base1, double base2, double height) {
        return ((base1 + base2) * height) / 2;
    }

    static double circleArea(double radius) {
        return 3.14159 * radius * radius;
    }

    static double sectorArea(double radius, double angle) {
        return 0.5 * radius * radius * angle;
    }
};

#endif // FIGUREAREACALCULATOR_H
