#include <iostream>
using namespace std;

// 4. Interface Segregation Principle (ISP): Clients should not be forced to implement interfaces they don’t use. It's better to
//                                           have smaller, more specific interfaces than one large, general-purpose interface.

// Violation of ISP
class Worker {
public:
    virtual ~Worker() = default;
    virtual void work() = 0;
    virtual void eat() = 0;
};

class Robot_ : public Worker {
public:
    void work() override {
        cout << "Robot_ working..." << endl;
    }

    void eat() override {
        // Robots don't eat, so this method doesn't make sense here
        throw runtime_error("Robot_ can't eat");
    }
};

// Problem: The 'Worker' interface forces every class that implements it to provide implementations for both `work()` and `eat()` methods.
//          This violates the ISP because not all workers (like robots) need to implement the `eat()` method.
// Solution: Create smaller, more specific interfaces (`Workable` and `Eatable`). This allows classes to implement only the methods
//           that are relevant to them.

class Workable {
public:
    virtual ~Workable() = default;
    virtual void work() = 0;
};

class Eatable {
public:
    virtual ~Eatable() = default;
    virtual void eat() = 0;
};

class Robot : public Workable {
public:
    void work() override {
        cout << "Robot working..." << endl;
    }
};

class Human : public Workable, public Eatable {
public:
    void work() override {
        cout << "Human working..." << endl;
    }

    void eat() override {
        cout << "Human eating..." << endl;
    }
};

// Driver code
int main() {
    // Create a Robot instance and call the work method
    Robot robot;
    robot.work();  // Robot working...

    // Create a Human instance and call both work and eat methods
    Human human;
    human.work();  // Human working...
    human.eat();   // Human eating...

    return 0;
}
