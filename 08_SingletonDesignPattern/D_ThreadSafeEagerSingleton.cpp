// ● What is Thread-Safe Eager Singleton Design Pattern ?
//   The Thread-Safe Eager Singleton Design Pattern is a variation of the Singleton Design Pattern
//   where the singleton instance is created at the time of class loading. This ensures that the instance
//   is available for use in a thread-safe manner without the need for additional synchronization mechanisms.
//   Note: This approach may lead to resource wastage if the singleton instance is never used.

#include<iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;   // o/p: 1 (true)
}
