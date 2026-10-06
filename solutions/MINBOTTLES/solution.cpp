#include <iostream> // Required for standard input/output operations (cin, cout)

void solve() {
    int N; // Number of bottles
    int X; // Capacity of each bottle in liters
    std::cin >> N >> X;

    long long total_water = 0; // Variable to store the sum of water from all bottles.
                               // Using long long to be safe, although 'int' would suffice
                               // given the problem constraints (max total_water = 100 * 1000 = 100,000).

    // Read the amount of water in each bottle and sum it up.
    for (int i = 0; i < N; ++i) {
        int A_i; // Water in the i-th bottle
        std::cin >> A_i;
        total_water += A_i;
    }

    // To find the minimum number of bottles, we need to divide the total water
    // by the capacity of a single bottle and round up to the nearest integer.
    // This is known as ceiling division.
    // For positive integers 'a' and 'b', ceil(a / b) can be calculated using
    // integer division as (a + b - 1) / b.
    long long min_bottles = (total_water + X - 1) / X;

    // Output the result for the current test case, followed by a newline.
    std::cout << min_bottles << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}