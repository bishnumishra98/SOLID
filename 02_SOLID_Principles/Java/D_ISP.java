// 4. Interface Segregation Principle (ISP): Clients should not be forced to implement interfaces they don’t use. It's better to
//                                           have smaller, more specific interfaces than one large, general-purpose interface.

// Violation of ISP
interface Worker {
    void work();

    void eat();
}

class Robot_ implements Worker {
    @Override
    public void work() {
        System.out.println("Robot_ working...");
    }

    @Override
    public void eat() {
        // Robots don't eat, so this method doesn't make sense here
        throw new UnsupportedOperationException();
    }
}

// Problem: The 'Worker' interface forces every class that implements it to provide implementations for both `work()` and `eat()` methods.
//          This violates the ISP because not all workers (like robots) need to implement the `eat()` method.
// Solution: Create smaller, more specific interfaces (`Workable` and `Eatable`). This allows classes to implement only the methods
//           that are relevant to them.

interface Workable {
    void work();
}

interface Eatable {
    void eat();
}

class Robot implements Workable {
    @Override
    public void work() {
        System.out.println("Robot working...");
    }
}

class Human implements Workable, Eatable {
    @Override
    public void work() {
        System.out.println("Human working...");
    }

    @Override
    public void eat() {
        System.out.println("Human eating...");
    }
}


// Driver code
public class D_ISP {
    public static void main(String[] args) {
        // Create a Robot instance and call the work method
        Robot robot = new Robot();
        robot.work();  // o/p: Robot working...

        // Create a Human instance and call both work and eat methods
        Human human = new Human();
        human.work();  // o/p: Human working...
        human.eat();   // o/p: Human eating...
    }
}
