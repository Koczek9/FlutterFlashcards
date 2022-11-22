#include <iostream>
#include <memory>
#include <cmath>

class AbstractFigure {
    public:
    virtual double circumference() = 0;
    virtual double area() = 0;
    void print_circumference()
    {
        std::cout << "Circumference is equal to " << circumference() << std::endl;
    };
    void print_area()
    {
        std::cout << "Area is equal to " << area() << std::endl;
    }

};

class Circle : public AbstractFigure 
{
    public:
    double radius;

    Circle(double radius) 
    {
        this->radius = radius;
    }
    
    double circumference() 
    {
        return 2 * 3.14 * radius;
    }

    double area() 
    {
        return 3.14 * radius * radius;
    }
};

class Square : public AbstractFigure 
{
    public:
    double length;

    Square(double length) 
    {
        this->length = length;
    }

    double circumference() 
    {
        return 4 * length;
    }

    double area() 
    {
        return length * length;
    }
};

class Triangle : public AbstractFigure 
{
    public:
    double a;
    double b;
    double c;

    Triangle(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
 
    double circumference(){
        return a+ b +c;
    }
    double area() {
        double p = circumference() / 2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
};

int main() 
{
    Circle circle1 = Circle(4);
    Circle circle2 = Circle(5);
    Square square1 = Square(6);
    Square square2 = Square(2);
    Triangle triangle1 = Triangle(3,4,5);

    circle1.print_circumference();
    circle1.print_area();

    square1.print_circumference();
    square1.print_area();

    triangle1.print_area();

    return 0;
}