// 2. Class Variables (static variables): These are shared among all instances of the class. There is only one copy of a static variable,
//                      and it belongs to the class itself rather than any specific object.

class Car {
    // Static variable shared by all Car objects
    static int numberOfCars = 0;

    public Car() {
        numberOfCars++;
    }

    // Static method to access the static variable. However, even a non-static method could have accessed static class variable;
    // but its a good practice to use static method to access static variable, so that the static variables can be accessed
    // directly via class, without needing any object.
    public static void showNumberOfCars() {
        System.out.println("Total cars: " + numberOfCars);
    }
}

public class C_ClassVariables {
    public static void main(String[] args) {
        // Creating Car objects
        Car c1 = new Car();
        Car c2 = new Car();
        Car c3 = new Car();

        // Calling static method to show the total number of cars created
        // c1.showNumberOfCars();   // this would be appropriate if showNumberOfCars() was a non-static method.
        Car.showNumberOfCars();   // o/p: Total cars: 3
    }
}
