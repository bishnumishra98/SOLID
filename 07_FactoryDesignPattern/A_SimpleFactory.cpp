// ● What is Factory Design Pattern ?
//   The Factory Design Pattern is a creational design pattern that provides an interface for creating objects without specifying
//   their exact classes. It allows the creation of objects based on a common interface, making the code more flexible and easier
//   to maintain.
//
// ● When to use Factory Design Pattern ?
//   1. When the exact type of the object to be created is determined at runtime.
//   2. When you want to encapsulate the object creation logic to promote code reusability and maintainability.
//   3. When you want to adhere to the Open/Closed Principle by allowing new object types to be added without modifying
//      existing code.
//
// ● Benefits of Factory Design Pattern ?
//   1. Flexibility: The pattern allows for easy addition of new object types without changing existing code.
//   2. Encapsulation: Object creation logic is encapsulated within the factory, promoting cleaner code.
//   3. Maintainability: Changes to object creation logic can be made in one place (the factory) rather than throughout the codebase.
//   4. Abstraction: Clients interact with interfaces rather than concrete classes, reducing dependencies.
//
// ● Drawbacks of Factory Design Pattern ?
//   1. Increased Complexity: The pattern can introduce additional layers of abstraction, making the code more complex.
//   2. Overhead: There may be a slight performance overhead due to the indirection of factory methods.
//   3. Proliferation of Classes: The pattern can lead to a proliferation of factory classes if not managed properly.
//
// ● Real-world examples of Factory Design Pattern ?
//   1. GUI Frameworks: A GUI framework may use a factory to create different types of UI components (buttons, text fields, etc.)
//      based on the platform.
//   2. Database Connections: A database connection factory can create different types of database connections
//      (MySQL, PostgreSQL, SQLite) based on configuration.
//   3. Document Creation: A document editor application may use a factory to create different types of documents (Word, PDF, Text)
//      based on user selection.
//
// ● Types of Factory Design Pattern
//   1. Simple Factory Pattern: A single factory class with a method that creates and returns different types of objects based
//      on input parameters.
//   2. Factory Method Pattern: Defines an interface for creating an object, but lets subclasses decide which class to instantiate.
//   3. Abstract Factory Pattern: Provides an interface for creating families of related or dependent objects without specifying
//      their concrete classes.
//
// ● C++ Code Example of Simple Factory Design Pattern
//   In the below example, we have a Burger class with multiple subclasses representing different types of burgers.
//   The BurgerFactory class contains a method createBurger that takes a string parameter to determine which type of burger to create.
//   The main function demonstrates how to use the BurgerFactory to create and prepare different types of burgers.
//   Compile and run the code to see how the Simple Factory Design Pattern works in C++.


#include <iostream>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;  // Pure virtual function
    virtual ~Burger() {}  // Virtual destructor
};

class BasicBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BurgerFactory {
public:
    Burger* createBurger(string& type) {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "standard";

    BurgerFactory* myBurgerFactory = new BurgerFactory();

    Burger* burger = myBurgerFactory->createBurger(type);

    burger->prepare();   // o/p: Preparing Standard Burger with bun, patty, cheese, and lettuce!

    return 0;
}
