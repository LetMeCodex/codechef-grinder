#include <iostream> // Required for std::cin, std::cout

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the integer N for the current test case

    // The permutation [1, 2, ..., N] always satisfies the condition.
    // This is because for any i (1 <= i < N), i and i+1 are coprime.
    // For their product i * (i+1) to be a perfect square, both i and i+1 must be perfect squares.
    // The only consecutive non-negative integers that are both perfect squares are 0 and 1.
    // Since i >= 1, i cannot be 0. Thus, i and i+1 can never both be perfect squares.
    // Therefore, i * (i+1) is never a perfect square for i >= 1.
    // So, simply printing numbers from 1 to N in increasing order is a valid solution.
    for (int i = 1; i <= n; ++i) {
        std::cout << i << (i == n ? "" : " "); // Print number, followed by a space unless it's the last number
    }
    std::cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}