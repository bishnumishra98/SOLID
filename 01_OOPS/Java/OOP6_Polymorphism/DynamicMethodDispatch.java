// Dynamic Method Dispatch, also known as method upcasting, enables method calls to be resolved at runtime
// based on the actual object type, allowing for flexible and dynamic method invocation.
class Animal {
    public void makeSound() {
        System.out.println("Some sound...");
    }
}

class Dog extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Bark");
    }
}

class Cat extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow");
    }
}

public class DynamicMethodDispatch {
    public static void main(String[] args) {
        Animal myAnimal = new Animal();   // Create an instance of Animal
        hearSound(myAnimal);   // Pass the Animal object to hearSound method

        Dog myDog = new Dog();   // Create an instance of Dog
        hearSound(myDog);   // Pass the Dog object to hearSound method

        Cat myCat = new Cat();   // Create an instance of Cat
        hearSound(myCat);   // Pass the Cat object to hearSound method
    }

    public static void hearSound(Animal a) {
        // The makeSound() method is called on the Animal reference 'a', but due to dynamic method dispatch, 
        // the actual method that gets executed is determined by the runtime type of the object being referenced 
        // (e.g., Dog, Cat). This is also known as upcasting, where the parent class reference (Animal) can hold 
        // a reference to any of its child classes (Dog, Cat).
        a.makeSound();  // Output will depend on the actual object type (Animal, Dog, or Cat)
    }

    // Extra info: In Java, you can only call static methods directly from another static method. Thus, it is necessary
    //             to use the 'static' keyword in hearSound() method if you want to call it directly from the main() method.
}

// o/p:
// Some sound...
// Bark
// Meow
