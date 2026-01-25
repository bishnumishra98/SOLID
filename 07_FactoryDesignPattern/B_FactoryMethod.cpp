// ● C++ Code Example of Factory Method Design Pattern
//   In the below example, we have a Burger class with multiple subclasses representing different types of burgers.
//   The BurgerFactory is an abstract factory class that declares a method createBurger for creating burgers.
//   We have two concrete factory classes, SinghBurger and KingBurger, that implement the createBurger method to produce
//   different types of burgers.
//   The main function demonstrates how to use these factories to create and prepare different types of burgers.


#include <iostream>
using namespace std;

// Product Class and subclasses
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

class BasicWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Basic Wheat Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Standard Wheat Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare() override {
        cout << "Preparing Premium Wheat Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};


// Factory and its concretions
class BurgerFactory {
public:
    virtual Burger* createBurger(string& type) = 0;
};

class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
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

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string& type) override {
        if (type == "basic") {
            return new BasicWheatBurger();
        } else if (type == "standard") {
            return new StandardWheatBurger();
        } else if (type == "premium") {
            return new PremiumWheatBurger();
        } else {
            cout << "Invalid burger type! " << endl;
            return nullptr;
        }
    }
};

int main() {
    string type = "basic";

    BurgerFactory* myFactory = new SinghBurger();

    Burger* burger = myFactory->createBurger(type);

    burger->prepare();   // o/p: Preparing Basic Burger with bun, patty, and ketchup!

    return 0;
}
