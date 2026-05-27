#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

const double PI = 3.14159;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getLength() const { return length; }
    double getWidth() const { return width; }

    void setLength(double l) {
        if (l <= 0) std::cout << "Invalid length. Must be > 0.\n";
        else length = l;
    }
    void setWidth(double w) {
        if (w <= 0) std::cout << "Invalid width. Must be > 0.\n";
        else width = w;
    }

    double area() const { return length * width; }
    void area(double& result) const { result = length * width; }

    Rectangle& resize(double factor);
    void print() const;
};

Rectangle& Rectangle::resize(double factor) {
    this->length *= factor;
    this->width *= factor;
    return *this;
}

void Rectangle::print() const {
    std::cout << "Rectangle (Length: " << length << ", Width: " << width << ")\n";
}

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void setRadius(double r) {
        if (r <= 0) std::cout << "Invalid radius. Must be > 0.\n";
        else radius = r;
    }

    double getRadius() const { return radius; }
    double area() const { return PI * radius * radius; }
    double circumference() const { return 2 * PI * radius; }

    void print() const;
    void print(bool detailed) const;
};

void Circle::print() const {
    std::cout << "Circle (Radius: " << radius << ")\n";
    std::cout << "Area: " << area() << "\n";
    std::cout << "Circumference: " << circumference() << "\n";
}

void Circle::print(bool detailed) const {
    if (detailed) {
        std::cout << "Circle details:\n";
        std::cout << "  Radius:        " << radius << "\n";
        std::cout << "  Area:          pi x " << radius << "^2 = " << area() << "\n";
        std::cout << "  Circumference: 2 x pi x " << radius << " = " << circumference() << "\n";
    } else {
        print();
    }
}

class Triangle {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a + b <= c || a + c <= b || b + c <= a)
            std::cout << "Warning: Invalid triangle sides.\n";
    }

    double area() const {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    std::string type() const {
        if (a == b && b == c) return "equilateral";
        if (a == b || b == c || a == c) return "isosceles";
        return "scalene";
    }

    Triangle& scale(double factor) {
        a *= factor;
        b *= factor;
        c *= factor;
        return *this;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "SHAPE CALCULATOR\n";
    std::cout << "----------------\n\n";

    Rectangle rect(5.0, 3.0);
    rect.print();
    std::cout << "Area: " << rect.area() << "\n";

    double refArea;
    rect.area(refArea);
    std::cout << "Area via reference: " << refArea << "\n\n";

    Circle circ(4.0);
    circ.print();
    std::cout << "\n";
    circ.print(true);

    std::cout << "\nMethod chaining:\n";
    std::cout << "  Original:   Length = " << rect.getLength() << ", Width = " << rect.getWidth() << "\n";
    rect.resize(2.0);
    std::cout << "  After resize(2.0): Length = " << rect.getLength() << ", Width = " << rect.getWidth() << "\n";

    const Circle constCircle(7.0);
    std::cout << "\nConst Circle area: " << constCircle.area() << "\n";

    std::cout << "\nTesting invalid setter:\n";
    rect.setLength(-5);

    std::cout << "\nBonus Triangle:\n";
    Triangle tri(3.0, 4.0, 5.0);
    std::cout << "Type: " << tri.type() << "\n";
    std::cout << "Area: " << tri.area() << "\n";
    tri.scale(2.0);
    std::cout << "After scale(2.0) - Area: " << tri.area() << "\n";

    return 0;
}