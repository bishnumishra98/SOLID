#include <iostream>
using namespace std;

// Q1) What is a pure virtual function ?
// Answer: A pure virtual function is a virtual function that is declared in a base class and
//         has no implementation. It is denoted by adding " = 0" to the declaration.
//         Syntax of pure virtual function: virtual return_type function_name() const(optional) = 0;
//         Example: virtual void draw() = 0;

// Q2) What is an abstract class ?
// Answer: A class containing at least one pure virtual function is called an abstract class in C++.
//         An abstract class can also have regular member functions with implementations.
//         Abstract classes cannot be instantiated directly; they are intended to be inherited by
//         derived classes that provide implementations for all pure virtual functions.
//         In Java, a class declared using the 'abstract' keyword is called an abstract class.

// Abstract class Shape
class Shape {
public:
    // Pure virtual function - mandatory to be overridden by derived classes
    virtual void draw() = 0;

    // Non-pure virtual function - not mandatory to be overridden by derived classes
    virtual void printInfo() {
        cout << "This is a shape object." << endl;
    }
};

// Derived class Circle
class Circle: public Shape {
public:
    virtual void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

// Derived class Square
class Square: public Shape {
public:
    virtual void draw() override {
        cout << "Drawing a square." << endl;
    }
};

int main() {
    // Cannot create an object of an abstract class
    // Shape s; // Error

    // Creating objects of derived classes
    Circle circle;
    Shape *s = new Square();

    // Calling non-virtual function
    circle.printInfo();   // o/p: This is a shape object.
    s->printInfo();   // o/p: This is a shape object.

    // Calling virtual function
    circle.draw();   // o/p: Drawing a circle.
    s->draw();   // o/p: Drawing a square.

    return 0;
}

// Characteristics of abstract class:
// 1) It cannot be directly instantiated.
// 2) It contains at least one pure virtual function.
//    (Derived classes must override all pure virtual functions to become concrete.)
// 3) It can provide virtual and non-virtual member functions that are common to all derived classes.
// 4) It supports runtime polymorphism through dynamic binding.

// Q3) What's the use of abstract classes if we cannot make instances of it ?
// Answer: Abstract classes contain pure virtual functions that ensure derived classes
//         provide specific implementations for those functions, thereby enforcing a
//         common interface across all derived classes. They can also provide shared
//         base functionality. This helps in achieving runtime polymorphism and better
//         code organization.

// Q4) Are interface and abstract class same ?
// Answer: No, they are not the same.
//         C++ does not have a separate 'interface' keyword.
//         However, an interface can be simulated in C++ using an abstract class that contains only
//         pure virtual functions and no data members or method implementations (except a virtual destructor).
