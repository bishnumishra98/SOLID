// ● What is Thread-Safe Locking Singleton Design Pattern ?
//   The Thread-Safe Locking Singleton Design Pattern is a variation of the Singleton Design Pattern
//   that ensures thread safety by using locking mechanisms to control access to the singleton instance.
//   This approach prevents multiple threads from creating separate instances of the singleton class
//   simultaneously.

#include<iostream>
#include <mutex>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx); // Lock for thread safety
        if (instance == nullptr) {
            instance = new Singleton();
        }
         return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;   // o/p: 1 (true)
}
