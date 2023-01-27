#include <iostream>
#include <memory>
#include <cmath>
#include <list>
#include <vector>

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

class FigureHelper
{
    public:
    std::string name;
    std::vector<std::string> inputNames;
    FigureHelper(std::string n, std::vector<std::string> names) : name(n), inputNames(names) 
    {

    }
};

int main() 
{
    /* Circle circle1 = Circle(4);
    Circle circle2 = Circle(5);
    Square square1 = Square(6);
    Square square2 = Square(2);
    Triangle triangle1 = Triangle(3,4,5);

    circle1.print_circumference();
    circle1.print_area();

    square1.print_circumference();
    square1.print_area();

    triangle1.print_area(); */

    std::vector<FigureHelper> possibleFigures;
    possibleFigures.emplace_back(FigureHelper("square", {"edge"}));
    possibleFigures.emplace_back(FigureHelper("circle", {"radius"}));
    possibleFigures.emplace_back(FigureHelper("triangle", {"A", "B", "C"}));

    std::unique_ptr<AbstractFigure> myFigure;

    std::cout << "Please choose one of the following figures to count circumference and area:" << std::endl;
    
    for (auto figure : possibleFigures)
    {
        std::cout << figure.name << std::endl;
    }

    std::string figureName;
    std::cin >> figureName;

        if(figureName == "square")
    {
        std::cout << "Enter length of " << possibleFigures[0].inputNames[0] << std::endl;
        double edge;
        std::cin >> edge;
        myFigure = std::make_unique<Square>(edge);
    }
    else if(figureName == "circle")
    {
        std::cout << "Enter length of " << possibleFigures[1].inputNames[0] << std::endl;
        double radius;
        std::cin >> radius;
        myFigure = std::make_unique<Circle>(radius);
    }
    else if(figureName == "triangle")
    {
        double a;
        double b;
        double c;

        std::cout << "Enter length of " << possibleFigures[2].inputNames[0] << std::endl;
        std::cin >> a;
        std::cout << "Enter length of " << possibleFigures[2].inputNames[1] << std::endl;
        std::cin >> b;
        std::cout << "Enter length of " << possibleFigures[2].inputNames[2] << std::endl;
        std::cin >> c;

        myFigure = std::make_unique<Triangle>(a,b,c);
    }
    
    if(myFigure != nullptr)
    {
        myFigure->print_circumference();
        myFigure->print_area();
    }
    else
    {
        std::cout << "You have not chosen any possible figure" << std::endl;
    }
    return 0;
}