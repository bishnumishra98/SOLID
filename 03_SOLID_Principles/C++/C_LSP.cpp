#include <iostream>
using namespace std;

// 3. Liskov Substitution Principle (LSP): Subtypes should be substitutable for their base types
//                                         without altering the correctness of the program.

// Violation of LSP
class Bird_ {
public:
    virtual void fly() {
        cout << "Flying..." << endl;
    }
};

class Ostrich_ : public Bird_ {
public:
    void fly() override {
        throw runtime_error("Ostrich_ can't fly");
    }
};

// Problem: The base class Bird_ has a method 'fly', which assumes that all birds can fly. Ostrich_, being a non-flying bird,
//          violates this assumption by throwing an exception, breaking the substitutability principle. Thus, the Ostrich_ class
//          cannot fully substitute Bird_, as it can't fulfill the behavior of flying. This leads to unexpected behavior in
//          client code when Ostrich_ is treated as a Bird_.
// Solution: Refactor the code by separating birds that can fly from those that can't. This avoids assigning unsupported
//           behaviors to subclasses, ensuring LSP compliance.

class Bird {
public:
    virtual ~Bird() = default;
    virtual void display() = 0;
};

class FlyingBird : public Bird {
public:
    void fly() {
        cout << "Flying..." << endl;
    }

    void display() override {
        cout << "I am a flying bird." << endl;
    }
};

class Sparrow : public FlyingBird {
public:
    void display() override {
        cout << "I am a Sparrow." << endl;
    }
};

class Ostrich : public Bird {
public:
    void display() override {
        cout << "I am an Ostrich." << endl;
    }
};

// Driver code
int main() {
    // LSP-compliant code: Ostrich is treated as Bird without issue
    Bird* sparrow = new Sparrow();   // substituting Sparrow for Bird
    sparrow->display();              // I am a Sparrow.
    // Downcasting sparrow to FlyingBird to access the fly() method present in it.
    dynamic_cast<FlyingBird*>(sparrow)->fly();  // Flying...

    Bird* ostrich = new Ostrich();   // substituting Ostrich for Bird
    ostrich->display();              // I am an Ostrich.

    delete sparrow;
    delete ostrich;

    return 0;
}
