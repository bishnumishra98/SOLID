// Compile-Time Polymorphism (method overloading): Compile-time polymorphism is achieved through method overloading, where multiple
//                                                 methods have the same name but different parameters within the same class. The
//                                                 method to be executed is determined at compile time based on the method signature.
class MathOperations {
    // Method to add two integers
    public int add(int a, int b) {
        return a + b;
    }

    // Method to add three integers
    public int add(int a, int b, int c) {
        return a + b + c;
    }

    // Method to add two doubles
    public double add(double a, double b) {
        return a + b;
    }
}


public class CompiletimePolymorphism {
    public static void main(String[] args) {
        MathOperations mathOps = new MathOperations();
        
        System.out.println(mathOps.add(10, 20));   // o/p: 30
        System.out.println(mathOps.add(10, 20, 30));   // o/p: 60
        System.out.println(mathOps.add(10.5, 20.5));   // o/p: 31.0
    }
}
