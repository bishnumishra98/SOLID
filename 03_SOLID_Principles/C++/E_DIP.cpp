#include <iostream>
using namespace std;

// 5. Dependency Inversion Principle (DIP): High-level modules (like business logic) should not depend directly on
//                                          low-level modules (like specific details of data access, logging, etc.).
//                                          Both should depend on abstractions (like interfaces or abstract classes).
//                                          Abstractions should not depend on details, but details should depend on abstractions.
// -> Why DIP is important ?
//    Without DIP, if a high-level module depends on the details of a low-level module, any changes in the low-level module will
//    affect the high-level one. This tight coupling makes the code hard to change, extend, or test.
//    By making both the high-level and low-level modules depend on an abstraction, you can change the implementation of the
//    low-level module (like using a different database) without affecting the high-level module.


// Violation of DIP
// Low-level class
class Lamp_ {
public:
    void turnOn() {
        cout << "Lamp_ is turned on." << endl;
    }
};

// High-level class
class Switch_ {
private:
    Lamp_ lamp;

public:
    Switch_() {
        // directly depends on Lamp_
    }

    void operate() {
        lamp.turnOn();   // can only control a Lamp_
    }
};

// Problem: The Switch class is tightly coupled to the Lamp class. If you later want the switch to control a Fan instead,
//          you would need to modify the Switch class. This makes it hard to extend the system.
// Solution: Let's refactor this using DIP. We'll introduce an abstraction called SwitchableDevice that the Switch will
//           depend on. Now the Switch doesn't care whether it's controlling a Lamp, a Fan, or any other device — it just
//           controls something that is "switchable."


// Abstraction (interface)
class SwitchableDevice {
public:
    virtual ~SwitchableDevice() = default;
    virtual void turnOn() = 0;
};

// Low-level class 1
class Lamp : public SwitchableDevice {
public:
    void turnOn() override {
        cout << "Lamp is turned on." << endl;
    }
};

// Low-level class 2
class Fan : public SwitchableDevice {
public:
    void turnOn() override {
        cout << "Fan is turned on." << endl;
    }
};

// High-level class now depends on abstraction (SwitchableDevice)
class Switch {
private:
    SwitchableDevice* device;   // device can point to any object that implements SwitchableDevice

public:
    // ctor
    Switch(SwitchableDevice* device) {
        this->device = device;
    }

    void operate() {
        device->turnOn();   // works with any device that implements SwitchableDevice
    }
};

// Driver code
int main() {
    // Use switch with Lamp
    SwitchableDevice* lamp = new Lamp();
    Switch switch1(lamp);
    switch1.operate();   // Lamp is turned on.

    // Use switch with Fan
    SwitchableDevice* fan = new Fan();
    Switch switch2(fan);
    switch2.operate();   // Fan is turned on.

    delete lamp;
    delete fan;

    return 0;
}
