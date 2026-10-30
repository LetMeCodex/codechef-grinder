#include <iostream> // Required for input/output operations (cin, cout)
#include <cmath>    // Required for mathematical functions like sqrt
#include <iomanip>  // Required for output formatting (fixed, setprecision)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        double B, LS; // Declare B and LS as double to handle floating-point calculations
        std::cin >> B >> LS; // Read the base (B) and left side length (LS) for the current test case

        double min_rs, max_rs; // Variables to store the minimum and maximum right side lengths

        // Calculate Maximum RS:
        // The maximum length of RS occurs when the left side (LS) is vertical.
        // In this configuration, LS, B, and RS form a right-angled triangle where RS is the hypotenuse.
        // By Pythagorean theorem: RS^2 = LS^2 + B^2
        max_rs = std::sqrt(LS * LS + B * B);

        // Calculate Minimum RS:
        // There are two cases for the minimum length of RS, depending on the relationship between LS and B.
        if (LS >= B) {
            // Case 1: LS is greater than or equal to B.
            // The minimum RS occurs when the right side (RS) is vertical.
            // In this configuration, RS, B, and LS form a right-angled triangle where LS is the hypotenuse.
            // By Pythagorean theorem: LS^2 = RS^2 + B^2  =>  RS^2 = LS^2 - B^2
            min_rs = std::sqrt(LS * LS - B * B);
        } else {
            // Case 2: LS is less than B.
            // In this scenario, RS cannot be vertical because LS is not long enough to be the hypotenuse
            // of a right triangle with leg B.
            // The minimum RS occurs when the ladder is "flattest" (height H approaches 0)
            // and the apex is positioned between the feet of LS and RS.
            // This forms a degenerate triangle where the apex, foot of LS, and foot of RS are collinear.
            // The distance from the foot of LS to the apex is LS. The distance from the foot of LS to the foot of RS is B.
            // If the apex is between the feet, then LS + RS = B, which implies RS = B - LS.
            min_rs = B - LS;
        }

        // Output the minimum and maximum RS values.
        // std::fixed ensures that floating-point numbers are printed in fixed-point notation.
        // std::setprecision(5) sets the number of digits after the decimal point to 5.
        std::cout << std::fixed << std::setprecision(5) << min_rs << " " << max_rs << "\n";
    }

    return 0; // Indicate successful execution
}