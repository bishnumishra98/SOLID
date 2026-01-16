// What is a class ?
// A class in Java is a blueprint for creating objects.

public class Person {
    // Fields (Attributes)
    String name;
    int age;

    // The 'this' keyword is used to refer to the current object's fields. It is optional if the instance member variable name
    // is different from the formal argument name. The 'this' keyword is primarily used to resolve ambiguity between instance
    // variables (fields) and parameters (formal arguments) when they have the same name.

    // Default Constructor
    public Person() {
        this.name = "Dummy";   // 'this' keyword is optional here
        this.age = 0;   // 'this' keyword is optional here
    }

    // Parameterized Constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Copy constructor (used to initialize an object with attributes copied from another objects)
    public Person(Person srcObj) {
        this.name = srcObj.name;   // 'this' keyword is optional here
        this.age = srcObj.age;   // 'this' keyword is optional here
    }

    // Method (Behavior)
    public void introduce() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }
}

