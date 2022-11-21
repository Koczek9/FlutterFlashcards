#include <iostream>
#include <memory>

class AbstractFigure {
    public:
    virtual void circumference() = 0;
    virtual void area() = 0;
    void print_circumference(double circumference)
    {
        std::cout << "Circumference is equal to " << circumference << std::endl;
    };
    void print_area(double area)
    {
        std::cout << "Area is equal to " << area << std::endl;
    }

};

class Circle : AbstractFigure 
{
    public:
    double radius;

    Circle(double radius) 
    {
        this->radius = radius;
    }
    
    void circumference() 
    {
        double circumference = 2 * 3.14 * radius;
        print_circumference(circumference);
    }

    void area() 
    {
        double area = 3.14 * radius * radius;
        print_area(area);
    }
};

class Square : AbstractFigure 
{
    public:
    double length;

    Square(double length) 
    {
        this->length = length;
    }

    void circumference() 
    {
        double circumference = 4 * length;
        print_circumference(circumference);
    }

    void area() 
    {
        double area = length * length;
        print_area(area);
    }
};


int main() 
{
    Circle circle1 = Circle(4);
    Circle circle2 = Circle(5);
    Square square1 = Square(6);
    Square square2 = Square(2);

    circle1.circumference();
    circle1.area();

    square1.circumference();
    square1.area();


    return 0;
}