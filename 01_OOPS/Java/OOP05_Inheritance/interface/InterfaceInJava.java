// What is interface ?
// An interface in Java is a blueprint for a class. Interfaces provide a way to achieve abstraction and support multiple inheritance.
// They define methods that must be implemented by any class that implements the interface.

// interface of Java is conceptually similar to abstract class of C++.
// abstract method of Java is conceptually similar to pure virtual functions of C++.
interface LivingBeing {
    void breathe();   // Abstract method: is a method that is declared without an implementation. The implementation
                     // of an abstract method is provided by subclasses or implementing classes.
}

interface Animal {
    void sound();   // abstract method
}

// Dog class implements only LivingBeing
class Dog implements LivingBeing {
    public void breathe() {
        System.out.println("Dog is breathing.");
    }
}

// Cat class implements method from both interfaces LivingBeing & Animal. This is how to achieve multiple inheritance in Java.
class Cat implements LivingBeing, Animal {
    public void breathe() {
        System.out.println("Cat is breathing.");
    }

    public void sound() {
        System.out.println("Meow");
    }
}

public class InterfaceInJava {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        Cat myCat = new Cat();
        
        myDog.breathe();   // O/p: Dog is breathing.
        myCat.breathe();   // O/p: Cat is breathing.
        myCat.sound();   // o/p: Meow
    }
}
