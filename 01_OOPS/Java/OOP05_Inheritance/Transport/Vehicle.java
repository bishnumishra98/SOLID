
public class Vehicle {
    // Attributes
    public String name;
    public int noOfTyres;

    // Constructors
    public Vehicle() {
        name = "";
        noOfTyres = 0;
    }
    public Vehicle(String name, int noOfTyres) {
        this.name = name;
        this.noOfTyres = noOfTyres;
    }

    // Methods
    public void start() {
        System.out.println("Engine of " + name + " started");
    }

    public void stop() {
        System.out.println("Engine of " + name + " stopped");
    }
}
