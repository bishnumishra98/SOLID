// Thread-Safe Double-Checked Locking Singleton Design Pattern in C++
// ● This implementation is thread-safe and efficient.
// ● It minimizes locking overhead by only locking when the instance is not yet created.
// ● Suitable for multi-threaded applications.
//
// Note: Double-checked locking can be tricky and may not be safe in all programming languages
//       due to compiler optimizations and CPU instruction reordering. However, in C++11 and later,
//       the memory model ensures that this pattern works correctly.
//       Make sure to compile with C++11 or later standards.

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
    // Double check locking..
    static Singleton* getInstance() {
        if (instance == nullptr) {  // First check (no locking)
            lock_guard<mutex> lock(mtx);  // Lock only if needed
            if (instance == nullptr) {  // Second check (after acquiring lock)
                instance = new Singleton();
            }
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
