
public class Main {
    public static void main(String[] args) {
        Bike b = new Bike("Honda", 2, "z-bar");
        b.start();
        b.wheelie();
        b.stop();

        Car c = new Car("Toyota", 4, 4);
        c.start();
        c.startAC();
        c.stop();    
    }
}
