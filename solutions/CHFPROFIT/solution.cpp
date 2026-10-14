#include <iostream> // Required for input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents synchronization overhead, making I/O faster.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X, Y, Z; // Declare integer variables X, Y, Z for each test case.
        // X: number of stocks
        // Y: price each stock was bought at
        // Z: price each stock can be sold at
        std::cin >> X >> Y >> Z; // Read X, Y, and Z for the current test case.

        // Calculate the total amount spent: X stocks * Y price/stock
        // Calculate the total amount received: X stocks * Z price/stock
        // Profit = Total amount received - Total amount spent
        // Profit = (X * Z) - (X * Y)
        // This can be simplified to: Profit = X * (Z - Y)
        // Given constraints: 1 <= X, Y <= 10^4, Y <= Z <= 10^4
        // Maximum possible value for X * Z or X * Y is 10^4 * 10^4 = 10^8.
        // An 'int' type in C++ typically handles values up to 2 * 10^9,
        // so 'int' is sufficient to store the profit without overflow.
        int profit = X * (Z - Y);

        // Print the calculated profit for the current test case,
        // followed by a newline character as required.
        std::cout << profit << "\n";
    }

    return 0; // Indicate successful program execution.
}