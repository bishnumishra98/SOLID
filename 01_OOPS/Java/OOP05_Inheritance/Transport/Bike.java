
public class Bike extends Vehicle {
    public String handlebar;

    Bike(String name, int noOfTyres, String handlebar) {
        super(name, noOfTyres);
        this.handlebar = handlebar;
    }

    public void wheelie() {
        System.out.println(name + " is doing wheelie");
    }
}
