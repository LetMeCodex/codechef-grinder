#include <bits/stdc++.h> // Includes most standard libraries, common in competitive programming

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        long long X, Y; // Declare X and Y as long long to handle large values.
                        // X can be up to 10^9, Y up to 10^18.
                        // X*X can be up to (10^9)^2 = 10^18, which fits in long long.
                        // 2*Y can be up to 2*10^18, which also fits in long long.
        std::cin >> X >> Y; // Read X and Y for the current test case

        // The given equation is: X^4 + 4 * Y^2 = 4 * X^2 * Y
        // Let's rearrange the equation to identify a pattern:
        // X^4 - 4 * X^2 * Y + 4 * Y^2 = 0
        // This expression is a perfect square trinomial of the form (A - B)^2 = A^2 - 2AB + B^2.
        // Let A = X^2 and B = 2*Y.
        // Then:
        // A^2 = (X^2)^2 = X^4
        // B^2 = (2*Y)^2 = 4*Y^2
        // 2*A*B = 2 * (X^2) * (2*Y) = 4 * X^2 * Y
        // Substituting these into the rearranged equation:
        // (X^2)^2 - 2 * (X^2) * (2*Y) + (2*Y)^2 = 0
        // This simplifies to:
        // (X^2 - 2*Y)^2 = 0
        // For a square of a real number to be zero, the number itself must be zero:
        // X^2 - 2*Y = 0
        // Which further simplifies to:
        // X^2 = 2*Y

        // So, the problem reduces to checking if X*X is equal to 2*Y.
        if (X * X == 2 * Y) {
            std::cout << "YES\n"; // If the condition holds, print YES
        } else {
            std::cout << "NO\n"; // Otherwise, print NO
        }
    }

    return 0; // Indicate successful program execution
}