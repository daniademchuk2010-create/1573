
#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
using namespace std;

class Shape
{
private:
    string name;

public:
    Shape() : name("no name") {}
    Shape(string n) : name(n) {}

    virtual void Show()
    {
        cout << char(186) << " Name: " << name << endl;
    }

    virtual double GetArea() = 0;

    virtual ~Shape() {}
};

// RECTANGLE
class Kvadrat : public Shape
{
private:
    double dovgina;
    double shurina;

public:
    Kvadrat() : Shape("Rectangle")
    {
        dovgina = 0;
        shurina = 0;
    }

    void WriteDaniKvadrat()
    {
        cout << char(186) << " Enter dovgina = ";
        cin >> dovgina;

        cout << char(186) << " Enter shurina = ";
        cin >> shurina;
    }

    void Show() override
    {
        Shape::Show();
        cout << char(186) << " Dovgina: " << dovgina << endl;
        cout << char(186) << " Shurina: " << shurina << endl;
        cout << char(186) << " Perimetr: "
            << (dovgina + shurina) * 2 << endl;
    }

    double GetArea() override
    {
        return dovgina * shurina;
    }
};

// CIRCLE
class Colo : public Shape
{
private:
    double radius;
    const double PI = 3.14159;

public:
    Colo() : Shape("Circle")
    {
        radius = 0;
    }

    void WriteDaniColo()
    {
        cout << char(186) << " Enter radius = ";
        cin >> radius;
    }

    void Show() override
    {
        Shape::Show();
        cout << char(186) << " Radius: " << radius << endl;
        cout << char(186) << " Diametr: " << radius * 2 << endl;
    }

    double GetArea() override
    {
        return PI * radius * radius;
    }
};

// RIGHT TRIANGLE
class RightTriangle : public Shape
{
private:
    double a;
    double b;

public:
    RightTriangle() : Shape("Right Triangle")
    {
        a = 0;
        b = 0;
    }

    void WriteDani()
    {
        cout << char(186) << " Enter a = ";
        cin >> a;

        cout << char(186) << " Enter b = ";
        cin >> b;
    }

    void Show() override
    {
        Shape::Show();
        cout << char(186) << " Cathetus a: " << a << endl;
        cout << char(186) << " Cathetus b: " << b << endl;
    }

    double GetArea() override
    {
        return (a * b) / 2;
    }
};

// TRIANGLE
class Triangle : public Shape
{
private:
    double a;
    double b;
    double c;

public:
    Triangle() : Shape("Triangle")
    {
        a = 0;
        b = 0;
        c = 0;
    }

    void WriteDaniTriangle()
    {
        cout << char(186) << " Enter a = ";
        cin >> a;

        cout << char(186) << " Enter b = ";
        cin >> b;

        cout << char(186) << " Enter c = ";
        cin >> c;
    }

    void Show() override
    {
        Shape::Show();
        cout << char(186) << " Side a: " << a << endl;
        cout << char(186) << " Side b: " << b << endl;
        cout << char(186) << " Side c: " << c << endl;
    }

    double GetArea() override
    {
        double p = (a + b + c) / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

// TRAPEZOID
class Trapezoid : public Shape
{
private:
    double a;
    double b;
    double h;

public:
    Trapezoid() : Shape("Trapezoid")
    {
        a = 0;
        b = 0;
        h = 0;
    }

    void WriteDani()
    {
        cout << char(186) << " Enter a = ";
        cin >> a;

        cout << char(186) << " Enter b = ";
        cin >> b;

        cout << char(186) << " Enter height = ";
        cin >> h;
    }

    void Show() override
    {
        Shape::Show();
        cout << char(186) << " Base a: " << a << endl;
        cout << char(186) << " Base b: " << b << endl;
        cout << char(186) << " Height: " << h << endl;
    }

    double GetArea() override
    {
        return ((a + b) * h) / 2;
    }
};

// TABLE FUNCTIONS

void PrintTop()
{
    cout << char(201);

    for (int i = 0; i < 38; i++)
        cout << char(205);

    cout << char(187) << endl;
}

void PrintMiddle()
{
    cout << char(204);

    for (int i = 0; i < 38; i++)
        cout << char(205);

    cout << char(185) << endl;
}

void PrintBottom()
{
    cout << char(200);

    for (int i = 0; i < 38; i++)
        cout << char(205);

    cout << char(188) << endl;
}

void PrintTitle(string title)
{
    PrintTop();

    int spaces = (38 - title.length()) / 2;

    cout << char(186);

    for (int i = 0; i < spaces; i++)
        cout << " ";

    cout << title;

    for (int i = 0; i < 38 - spaces - title.length(); i++)
        cout << " ";

    cout << char(186) << endl;

    PrintMiddle();
}

// TEST SHAPE

void TestShape(Shape& figura)
{
    PrintTitle("INFORMATION ABOUT FIGURA");

    figura.Show();

    PrintMiddle();

    cout << char(186) << " Area: " << figura.GetArea() << endl;

    PrintBottom();
}

// MAIN

int main()
{
    SetConsoleOutputCP(437);
    SetConsoleCP(437);

    Kvadrat kvadrat;
    Colo colo;
    RightTriangle rightTriangle;
    Triangle triangle;
    Trapezoid trapezoid;

    PrintTitle("RECTANGLE");
    kvadrat.WriteDaniKvadrat();
    PrintBottom();

    PrintTitle("CIRCLE");
    colo.WriteDaniColo();
    PrintBottom();

    PrintTitle("RIGHT TRIANGLE");
    rightTriangle.WriteDani();
    PrintBottom();

    PrintTitle("TRIANGLE");
    triangle.WriteDaniTriangle();
    PrintBottom();

    PrintTitle("TRAPEZOID");
    trapezoid.WriteDani();
    PrintBottom();

    PrintTitle("ALL RESULTS");

    TestShape(kvadrat);
    TestShape(colo);
    TestShape(rightTriangle);
    TestShape(triangle);
    TestShape(trapezoid);

    return 0;
}

