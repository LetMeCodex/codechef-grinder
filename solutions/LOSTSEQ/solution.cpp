#include <iostream> // Required for standard input/output operations (cin, cout)

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length N

    int odd_count = 0; // Initialize a counter for odd numbers

    // Loop 2*N times to read all elements of sequence B
    for (int i = 0; i < 2 * N; ++i) {
        int B_val;
        std::cin >> B_val; // Read an element from B

        // Check if the current element is odd.
        // B_val % 2 != 0 correctly identifies odd numbers for both positive and negative integers.
        // For example, -1 % 2 is -1 (non-zero), -2 % 2 is 0.
        if (B_val % 2 != 0) {
            odd_count++; // Increment count if it's odd
        }
    }

    // If the total count of odd numbers is even, then B can be formed.
    // Otherwise, it cannot.
    if (odd_count % 2 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}