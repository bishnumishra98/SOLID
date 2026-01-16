// What is an object ?
// An object is instance of a class.

public class Main {
    public static void main(String[] args) {
        // Using the default constructor
        Person p1 = new Person();
        p1.introduce();   // o/p: Hello, my name is Dummy and I am 0 years old.

        // Using the parameterized constructor
        Person p2 = new Person("Alice", 30);
        p2.introduce();   // o/p: Hello, my name is Alice and I am 30 years old.

        // Using the copy constructor
        Person p3 = new Person(p2);
        p3.introduce();   // o/p: Hello, my name is Alice and I am 30 years old.
    }
}
