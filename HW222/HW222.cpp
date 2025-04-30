#include <iostream>

using namespace std;

class Shape {
protected:

    double x, y;

public:

    Shape(double x, double y) : x(x), y(y) {}

    virtual void getCoordinates() const {
        cout << "Center coordinates: (" << x << ", " << y << ")" << endl;
    }

    virtual double getArea() const = 0;

    virtual ~Shape() {}

};

class Circle : public Shape {
private:

    double radius;

public:

    Circle(double x, double y, double r) : Shape(x, y), radius(r) {}

    void getCoordinates() const override {

        cout << "Circle ";
        Shape::getCoordinates();
    }

    double getArea() const override {

        return 3.14159265358979323846 * radius * radius;

    }
};

class Rectangle : public Shape {
private:

    double length, width;

public:
    Rectangle(double x, double y, double l, double w) : Shape(x, y), length(l), width(w) {}

    void getCoordinates() const override {
        cout << "Rectangle ";
        Shape::getCoordinates();
    }

    double getArea() const override {
        return length * width;
    }
};


class Triangle : public Shape {
private:
    double length, height;

public:
    Triangle(double x, double y, double l, double h) : Shape(x, y), length(l), height(h) {}

    void getCoordinates() const override {
        cout << "Triangle ";
        Shape::getCoordinates();
    }

    double getArea() const override {
        return 0.5 * length * height;
    }
};


// Operator overloading for the + operator to sum the areas of two shapes.........

double operator+(const Shape& shape1, const Shape& shape2) {
    return shape1.getArea() + shape2.getArea();
}

// Non-member function to get the area of any shape

double getShapeArea(const Shape& shape) {
    return shape.getArea();
}

int main() {

    // Set center coordinates based on university ID (e.g., 12219814)........

    Circle circle(1, 4, 3);

    Rectangle rectangle(1, 4, 6, 7);

    Triangle triangle(1, 4, 10, 11);

    circle.getCoordinates();

    cout << "Circle area: " << circle.getArea() << endl;

    rectangle.getCoordinates();
    cout << "Rectangle area: " << rectangle.getArea() << endl;

    triangle.getCoordinates();
    cout << "Triangle area: " << triangle.getArea() << endl;

    double totalArea = circle.getArea() + rectangle.getArea() + triangle.getArea();
    cout << "Total area of all shapes: " << totalArea << endl;

    return 0;
}

