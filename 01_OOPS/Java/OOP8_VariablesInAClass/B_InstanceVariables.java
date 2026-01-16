// 1. Instance Variables (Non-static fields): These variables are defined at the class level but outside any method, constructor, or block.
//                                            Each instance (object) of the class will have its own copy of these variables.

class Car {
    // Instance variable
    private String model;

    // Constructor
    public Car(String model) {
        this.model = model;   // 'this.model' refers to the instance variable 'model'
    }

    public void showModel() {
        System.out.println("Car model: " + model);
    }
}


public class B_InstanceVariables {
    public static void main(String[] args) {
        Car c1 = new Car("Scorpio Classic");
        Car c2 = new Car("Scorpio N");
        c1.showModel();   // o/p: Car model: Scorpio Classic
        c2.showModel();   // o/p: Car model: Scorpio N
    }
}
