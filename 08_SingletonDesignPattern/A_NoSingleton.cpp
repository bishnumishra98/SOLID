// ● What is Singleton Design Pattern ?
// The Singleton Design Pattern is a software design pattern that restricts the instantiation of a class
// to a single instance and provides a global point of access to that instance. This is useful when exactly
// one object is needed to coordinate actions across the system, such as in logging, configuration management,
// or resource sharing.
//
// ● When to use Singleton Design Pattern ?
// 1. When only one instance of a class is required throughout the application.
// 2. When you want to provide a global point of access to that instance.
// 3. When you want to control access to shared resources, such as database connections or configuration settings.
//
// ● Benefits of Singleton Design Pattern ?
// 1. Controlled Access to the sole instance.
// 2. Reduced namespace pollution since the singleton instance is accessed through a class method.
// 3. Flexibility in changing the implementation of the singleton class without affecting the rest of
//    the application.
//
// ● Drawbacks of Singleton Design Pattern ?
// 1. Global State: Singletons can introduce global state into an application, making it harder to reason about
//    and test.
// 2. Hidden Dependencies: Code that uses singletons may have hidden dependencies, making it difficult to understand
//    the relationships between classes.
// 3. Difficulty in Testing: Singletons can make unit testing challenging, as they can introduce tight coupling between
//    classes and make it hard to isolate components for testing.
//
// ● Real World Examples of Singleton Design Pattern
// 1. Logger Classes: A logging class that ensures only one instance is used to log messages throughout an application.
// 2. Configuration Managers: A configuration manager that provides a single point of access to application settings.
// 3. Thread Pools: A thread pool manager that ensures only one instance manages the pool
//    of threads used for concurrent tasks.
// 4. Database Connection Pools: A database connection pool that provides a single instance to manage
//    and reuse database connections.
// 5. Caches: A caching mechanism that ensures only one instance is used to store and retrieve cached data.
// 6. Window Managers: In GUI applications, a window manager that ensures only one instance controls
//    the creation and management of application windows.
// 7. Print Spoolers: A print spooler that manages print jobs and ensures only one instance handles
//    communication with the printer.
//
// ● Note: Below code is an example without Singleton Design Pattern implemented.
//          Hence multiple objects can be created. 


#include<iostream>
using namespace std;

class NoSingleton {
public:
    NoSingleton() {
        cout << "Singleton Constructor called. New Object created." << endl;
    }
};

int main() {
    NoSingleton* s1 = new NoSingleton();
    NoSingleton* s2 = new NoSingleton();

    cout << (s1 == s2) << endl;   // o/p: 0 (false)
}
