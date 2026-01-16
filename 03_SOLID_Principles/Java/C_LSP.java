// 3. Liskov Substitution Principle (LSP): Subtypes should be substitutable for their base types
//                                         without altering the correctness of the program.

// Violation of LSP
class Bird_ {
    public void fly() {
        System.out.println("Flying...");
    }
}

class Ostrich_ extends Bird_ {
    @Override
    public void fly() {
        throw new UnsupportedOperationException("Ostrich_ can't fly");
    }
}

// Problem: The base class Bird_ has a method 'fly', which assumes that all birds can fly. Ostrich_, being a non-flying bird,
//          violates this assumption by throwing an exception, breaking the substitutability principle. Thus, the Ostrich_ class
//          cannot fully substitute Bird_, as it can't fulfill the behavior of flying. This leads to unexpected behavior in
//          client code when Ostrich_ is treated as a Bird_.
// Solution: Refactor the code by separating birds that can fly from those that can't. This avoids assigning unsupported
//           behaviors to subclasses, ensuring LSP compliance.

abstract class Bird {
    // Birds may have other behaviors common to all types
    public abstract void display();
}

class FlyingBird extends Bird {
    // Only birds that can fly have this method
    public void fly() {
        System.out.println("Flying...");
    }

    @Override
    public void display() {
        System.out.println("I am a flying bird.");
    }
}

class Sparrow extends FlyingBird {
    @Override
    public void display() {
        System.out.println("I am a Sparrow.");
    }
}

class Ostrich extends Bird {
    // Ostrich doesn't override 'fly' since it cannot fly and inherits only Bird
    @Override
    public void display() {
        System.out.println("I am an Ostrich.");
    }
}


// Driver code
public class C_LSP {
    public static void main(String[] args) {
        // LSP-compliant code: Ostrich is treated as Bird without issue
        Bird sparrow = new Sparrow();  // substituting Sparrow for Bird
        sparrow.display();         // o/p: I am a Sparrow.
        // Downcasting sparrow to FlyingBird to access the fly() method present in it.
        ((FlyingBird) sparrow).fly();  // o/p: Flying...

        Bird ostrich = new Ostrich();  // substituting Ostrich for Bird
        ostrich.display();         // o/p: I am an Ostrich.

        // Ostrich doesn't support flying, so no attempt to call 'fly' on Ostrich.
    }
}
