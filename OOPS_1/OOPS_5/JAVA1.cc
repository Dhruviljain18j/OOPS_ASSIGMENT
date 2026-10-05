class PaymentProcessor {

    // Method 1: only amount
    void processPayment(double amount) {
        System.out.println("processPayment(amount) called");
        System.out.println("Final Amount: ₹" + amount);
    }

    // Method 2: amount + coupon
    void processPayment(double amount, String couponCode) {
        System.out.println("processPayment(amount, couponCode) called");

        double finalAmount = amount;

        if (couponCode.equals("SAVE10")) {
            finalAmount = amount - (amount * 0.10);
        }

        System.out.println("Coupon: " + couponCode);
        System.out.println("Final Amount: ₹" + finalAmount);
    }
}

public class Main {
    public static void main(String[] args) {

        PaymentProcessor payment = new PaymentProcessor();

        payment.processPayment(1000);

        System.out.println();

        payment.processPayment(1000, "SAVE10");
    }
}
