
public class Car extends Vehicle {
    public int noOfDoors;

    public Car(String name, int noOfTyres, int noOfDoors) {
        super(name, noOfTyres);
        this.noOfDoors = noOfDoors;
    }

    public void startAC() {
        System.out.println("AC started in " + name);
    }
}
