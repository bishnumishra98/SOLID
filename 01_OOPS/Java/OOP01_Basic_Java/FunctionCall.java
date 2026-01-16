import java.util.Scanner;

public class FunctionCall {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        print1TonTable(n);
        sc.close();   // close the Scanner object to avoid resource leaks
    }

    public static void print1TonTable(int n) {
        for(int i=1; i<=n; i++) {
            System.out.println("2 * " + i + " = " + 2*i);
        }
    }
}
