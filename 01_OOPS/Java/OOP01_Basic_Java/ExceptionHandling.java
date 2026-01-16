public class ExceptionHandling {

    public static void main(String[] args) {
        try {
            // Code that may throw an exception
            int divideByZero = 5 / 0;
        } catch (ArithmeticException e) {
            // This block handles the ArithmeticException
            System.out.println("ArithmeticException caught: " + e.getMessage());
        } finally {
            // This block always executes
            System.out.println("Finally block executed.");
        }

        try {
            validateAge(15);
        } catch (InvalidAgeException e) {
            System.out.println("InvalidAgeException caught: " + e.getMessage());
        }
    }

    static void validateAge(int age) throws InvalidAgeException {
        if (age < 18) {
            throw new InvalidAgeException("Age is not valid, must be at least 18");
        }
    }
}

// Custom exception class
class InvalidAgeException extends Exception {
    public InvalidAgeException(String message) {
        super(message);
    }
}

// public InvalidAgeException(String message): This is a constructor for the InvalidAgeException class. It allows creating
//                                             an instance of InvalidAgeException with a custom error message.
// super(message): This calls the constructor of the superclass (Exception) with the provided message. The Exception class has
//                 a constructor that accepts a String parameter, which represents the detail message of the exception. By
//                 passing the message to the superclass constructor, the custom exception InvalidAgeException can store this
//                 detail message, which can later be retrieved using the getMessage() method inherited from the Throwable class.
