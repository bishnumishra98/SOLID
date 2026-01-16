// In Java, the super keyword is used to refer to the immediate parent class of the current class. The super keyword is used to
// access members (constructors, methods, or variables) of the parent class It can be used in various contexts:

// 1. Calling Parent Class Constructor: super() can be used to invoke the constructor of the parent class from the child class.
//                                      If a parent class constructor takes parameters, they can be passed using super(parameters).
class Parent1 {
    Parent1() {
        System.out.println("Parent Constructor");
    }
}

class Child1 extends Parent1 {
    Child1() {
        super();   // Calls the parent class constructor
        System.out.println("Child Constructor");
    }
}


// 2. Accessing Parent Class Methods: super can be used to call a method from the parent class.
class Parent2 {
    void display() {
        System.out.println("Parent Display");
    }
}

class Child2 extends Parent2 {
    void fun() {
        super.display();   // Calls the parent class display method
        System.out.println("Child Display");
    }
}


// 3. Accessing Parent Class Variables: super can be used to refer an attribute from the parent class.
class Parent3 {
    int x = 10;
}

class Child3 extends Parent3 {
    int x = 20;

    void fun() {
        System.out.println(super.x);   // Refers to x in Parent3 class
        System.out.println(x);   // Refers to x in Child3 class
    }
}



public class superKeyword {
    public static void main(String[] args) {
        Child1 c1 = new Child1();   // o/p: Parent Constructor
                                   //       Child Constructor
        
        Child2 c2 = new Child2();
        c2.fun();   // o/p: Parent Constructor
                   //       Child Constructor

        Child3 c3 = new Child3();
        c3.fun();   // o/p: 10
                   //       20
    }
}
