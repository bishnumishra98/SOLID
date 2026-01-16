class Person {
    // Private variables to encapsulate the properties of the class
    private String name;
    private int age;
    private String address;

    // Constructor to initialize the Person object
    public Person(String name, int age, String address) {
        this.name = name;
        this.age = age;
        this.address = address;
    }

    // Getter for name
    public String getName() {
        return name;
    }

    // Setter for name
    public void setName(String name) {
        this.name = name;
    }

    // Getter for age
    public int getAge() {
        return age;
    }

    // Setter for age
    public void setAge(int age) {
        this.age = age;
    }

    // Getter for address
    public String getAddress() {
        return address;
    }

    // Setter for address
    public void setAddress(String address) {
        this.address = address;
    }

    // Method to display person's info
    public void displayPersonInfo() {
        System.out.println("Name: " + name + ", Age: " + age + ", Address: " + address);
    }
}

public class App {
    public static void main(String[] args) {
        // Create a new Person object
        Person person = new Person("John Doe", 30, "123 Main St");

        // Display initial details
        person.displayPersonInfo();

        // Modify the details using setter methods
        person.setName("Jane Doe");
        person.setAge(25);
        person.setAddress("456 Elm St");

        // Display modified details
        person.displayPersonInfo();
    }
}
