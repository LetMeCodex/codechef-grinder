#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        long long X, Y, M; // Declare X, Y, M as long long to safely handle values up to 10^8
                           // and their product (X*M) which can also be up to 10^8.
        std::cin >> X >> Y >> M; // Read the values of X, Y, and M for the current test case.

        // Calculate the total cost of renting the cooler for M months.
        // The product X * M is stored in a long long variable to prevent potential overflow,
        // although for the given constraints (10^4 * 10^4 = 10^8), int would technically suffice.
        long long total_rent_cost = X * M;

        // Check Chef's decision condition: rent only if total_rent_cost is strictly less than Y.
        if (total_rent_cost < Y) {
            std::cout << "YES\n"; // If true, Chef should rent. Print "YES" followed by a newline.
        } else {
            std::cout << "NO\n"; // Otherwise, Chef should purchase. Print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}