// 3. Local Variables (Inside methods): These are defined inside methods and are only accessible within the method where they are declared.

class Car {
    public void startEngine() {
        // Local variable, only exists within this method
        String engineStatus = "Engine started";
        System.out.println(engineStatus);
    }
}


public class D_LocalVariables {
    public static void main(String[] args) {
        Car c = new Car();
        c.startEngine();   // o/p: Engine started
    }
}
