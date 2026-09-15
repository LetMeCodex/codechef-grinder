#include <iostream> // Required for input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B, C, D; // Declare integer variables for prices and discounts.
        // Read the marked price of the first TV (A), second TV (B),
        // discount for the first TV (C), and discount for the second TV (D).
        std::cin >> A >> B >> C >> D;

        // Calculate the final price of the first TV after discount.
        int final_price_A = A - C;
        // Calculate the final price of the second TV after discount.
        int final_price_B = B - D;

        // Compare the final prices to determine which TV is cheaper.
        if (final_price_A < final_price_B) {
            // If the first TV is cheaper, print "First".
            std::cout << "First\n";
        } else if (final_price_B < final_price_A) {
            // If the second TV is cheaper, print "Second".
            std::cout << "Second\n";
        } else {
            // If both TVs cost the same, print "Any".
            std::cout << "Any\n";
        }
    }

    return 0; // Indicate successful program execution.
}