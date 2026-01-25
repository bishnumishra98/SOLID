// ● What is Strategy Design Pattern ?
//   The Strategy Design Pattern is a behavioral design pattern that enables selecting an algorithm's behavior at runtime.
//   It defines a family of algorithms, encapsulates each one, and makes them interchangeable. This allows the algorithm to
//   vary independently from clients that use it.
//
// ● When to use Strategy Design Pattern ?
//   1. When you have multiple algorithms for a specific task and want to switch between them dynamically.
//   2. When you want to avoid using conditional statements to select different behaviors.
//   3. When you want to encapsulate related algorithms to promote code reusability and maintainability.
//
// ● Benefits of Strategy Design Pattern ?
//   1. Flexibility: You can change the behavior of an object at runtime by switching strategies.
//   2. Maintainability: Each strategy is encapsulated in its own class, making it easier to manage and extend.
//   3. Reusability: Strategies can be reused across different contexts without duplicating code.
//   4. Open/Closed Principle: You can introduce new strategies without modifying existing code, adhering to the open/closed principle.
//   5. Simplified Code: Reduces the complexity of code by eliminating conditional statements for behavior selection.
//
// ● Drawbacks of Strategy Design Pattern ?
//   1. Increased Number of Classes: Each strategy requires its own class, which can lead to a proliferation of classes in the codebase.
//   2. Client Awareness: Clients must be aware of different strategies to choose the appropriate one, which can complicate the client code.
//   3. Overhead: There may be a slight performance overhead due to the indirection of strategy delegation.
//   4. Complexity: The pattern can introduce additional complexity to the design, especially for simple use cases where a strategy pattern
//      might be overkill.
//
// ● Real-world examples of Strategy Design Pattern ?
//   1. Sorting Algorithms: A sorting context can use different sorting strategies (e.g., QuickSort, MergeSort, BubbleSort) based on the
//      data size or type.
//   2. Payment Methods: An e-commerce application can use different payment strategies (e.g., CreditCardPayment, PayPalPayment, BitcoinPayment)
//      based on user preference.
//   3. Compression Algorithms: A file compression tool can use different compression strategies (e.g., ZIP, RAR, TAR) based on user selection.
//   4. Navigation Systems: A navigation app can use different routing strategies (e.g., FastestRoute, ShortestRoute, ScenicRoute) based on
//      user preferences.
//
// ● C++ Code Example of Strategy Design Pattern
//   In the below example, we have a Robot class that can perform different behaviors like walking, talking, and flying.
//   Each behavior is defined as a strategy interface with multiple concrete implementations.
//   The Robot class uses these strategies to perform its actions, allowing for dynamic behavior changes at runtime.
//   We have two types of robots: CompanionRobot and WorkerRobot, each with its own projection method.
//   The main function demonstrates how to create different robot instances with various behavior strategies.
//   Compile and run the code to see how different robots exhibit different behaviors based on the strategies assigned to them.
//   This example showcases the flexibility and maintainability provided by the Strategy Design Pattern in C++.


#include <iostream>
using namespace std;

// --- Strategy Interface for Walk ---
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

// --- Concrete Strategies for walk ---
class NormalWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Walking normally..." << endl; 
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Cannot walk." << endl; 
    }
};


// --- Strategy Interface for Talk ---
class TalkableRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

// --- Concrete Strategies for Talk ---
class NormalTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Talking normally..." << endl; 
    }
};

class NoTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Cannot talk." << endl; 
    }
};

// --- Strategy Interface for Fly ---
class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};

// --- Robot Base Class ---
class Robot {
protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
       
    void walk() { 
        walkBehavior->walk(); 
    }
    void talk() { 
        talkBehavior->talk(); 
    }
    void fly() { 
        flyBehavior->fly(); 
    }

    virtual void projection() = 0; // Abstract method for subclasses
};

// --- Concrete Robot Types ---
class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

// --- Main Function ---
int main() {
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();   // o/p: Walking normally...
    robot1->talk();   // o/p: Talking normally...
    robot1->fly();   // o/p: Cannot fly...
    robot1->projection();   // o/p: Displaying friendly companion features...

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();   // o/p: Cannot walk...
    robot2->talk();   // o/p: Cannot talk...
    robot2->fly();   // o/p: Flying normally...
    robot2->projection();   // o/p: Displaying worker efficiency stats...

    return 0;
}
