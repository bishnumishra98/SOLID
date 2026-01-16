#include <iostream>
#include <string>
using namespace std;

// 2. Open/Closed Principle (OCP): Software entities (classes, modules, functions, etc.) should be
//                                 open for extension but closed for modification.

// Violation of OCP
class Discount_ {
public:
    double calculate(double amount, const string& type) {
        if (type == "CHRISTMAS") {
            return amount * 0.1;
        } else if (type == "NEWYEAR") {
            return amount * 0.15;
        }
        return 0;
    }
};

// Problem: The calculate() method is tightly coupled with discount types (CHRISTMAS, NEWYEAR), and every time a new
//          discount type is introduced (e.g., "EASTER", "BLACKFRIDAY"), you'd have to edit the calculate() method,
//          increasing the chances of breaking existing functionality or introducing bugs.
// Solution: Use inheritance (OR) interface to extend without modifying existing code. Below is illustration using inheritance:

class Discount {   // Abstract base class
public:
    virtual ~Discount() = default;
    virtual double calculate(double amount) const = 0;
};

class ChristmasDiscount : public Discount {
public:
    double calculate(double amount) const override {
        return amount * 0.1;
    }
};

class NewYearDiscount : public Discount {
public:
    double calculate(double amount) const override {
        return amount * 0.15;
    }
};

// You can add more discounts without modifying existing code.
class EasterDiscount : public Discount {
public:
    double calculate(double amount) const override {
        return amount * 0.2;
    }
};

// This class is designed to apply different types of discounts in a flexible
// and extensible way, adhering to the Open/Closed Principle (OCP).
class DiscountService {
public:
    double applyDiscount(const Discount& discount, double amount) {
        return discount.calculate(amount);
    }
};


// Driver code
int main() {
    DiscountService discountService;

    Discount* christmasDiscount = new ChristmasDiscount();
    double christmasDiscountedAmount =
        discountService.applyDiscount(*christmasDiscount, 100.0);
    cout << "Christmas Discounted Amount: "
         << christmasDiscountedAmount << endl;

    Discount* newYearDiscount = new NewYearDiscount();
    double newYearDiscountedAmount =
        discountService.applyDiscount(*newYearDiscount, 100.0);
    cout << "New Year Discounted Amount: "
         << newYearDiscountedAmount << endl;

    Discount* easterDiscount = new EasterDiscount();
    double easterDiscountedAmount =
        discountService.applyDiscount(*easterDiscount, 100.0);
    cout << "Easter Discounted Amount: "
         << easterDiscountedAmount << endl;

    delete christmasDiscount;
    delete newYearDiscount;
    delete easterDiscount;

    return 0;
}
