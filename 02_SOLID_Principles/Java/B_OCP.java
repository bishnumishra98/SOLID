// 2. Open/Closed Principle (OCP): Software entities (classes, modules, functions, etc.) should be
//                                 open for extension but closed for modification.

// Violation of OCP
class Discount_ {
    public double calculate(double amount, String type) {
        if (type.equals("CHRISTMAS")) {
            return amount * 0.1;
        } else if (type.equals("NEWYEAR")) {
            return amount * 0.15;
        }
        return 0;
    }
}

// Problem: The calculate() method is tightly coupled with discount types (CHRISTMAS, NEWYEAR), and every time a new
//          discount type is introduced (e.g., "EASTER", "BLACKFRIDAY"), you'd have to edit the calculate() method,
//          increasing the chances of breaking existing functionality or introducing bugs.
// Solution: Use inheritance (OR) interface to extend without modifying existing code. Below is illustration using inheritance:

abstract class Discount {   // An abstract class is a class that cannot be instantiated directly.
    public abstract double calculate(double amount);   // abstract methods must be implemented by any non-abstract subclass.
}

class ChristmasDiscount extends Discount {
    @Override
    public double calculate(double amount) {
        return amount * 0.1;
    }
}

class NewYearDiscount extends Discount {
    @Override
    public double calculate(double amount) {
        return amount * 0.15;
    }
}

// You can add more discounts without modifying existing code.
class EasterDiscount extends Discount {
    @Override
    public double calculate(double amount) {
        return amount * 0.2;
    }
}

// This class is designed to apply different types of discounts in a flexible
// and extensible way, adhering to the Open/Closed Principle (OCP).
class DiscountService {
    public double applyDiscount(Discount discount, double amount) {
        return discount.calculate(amount);
    }
}


// driver code
public class B_OCP {
    public static void main(String[] args) {
        // Create DiscountService object
        DiscountService discountService = new DiscountService();

        // Applying Christmas Discount
        Discount christmasDiscount = new ChristmasDiscount();
        double christmasDiscountedAmount = discountService.applyDiscount(christmasDiscount, 100.0);
        System.out.println("Christmas Discounted Amount: " + christmasDiscountedAmount);  // o/p: Christmas Discounted Amount: 10.0

        // Applying New Year Discount
        Discount newYearDiscount = new NewYearDiscount();
        double newYearDiscountedAmount = discountService.applyDiscount(newYearDiscount, 100.0);
        System.out.println("New Year Discounted Amount: " + newYearDiscountedAmount);  // o/p: New Year Discounted Amount: 15.0

        // Applying Easter Discount
        Discount easterDiscount = new EasterDiscount();
        double easterDiscountedAmount = discountService.applyDiscount(easterDiscount, 100.0);
        System.out.println("Easter Discounted Amount: " + easterDiscountedAmount);  // o/p: Easter Discounted Amount: 20.0
    }
}
