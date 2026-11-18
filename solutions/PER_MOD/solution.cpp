#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Required for std::vector to store the permutation

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the integer N for the current test case

    // Declare a vector 'p' of size 'n' to store the permutation.
    // C++ vectors are 0-indexed, so p[0] corresponds to P_1, p[i-1] to P_i, etc.
    std::vector<int> p(n);

    // Implement the permutation logic: P = [2, 3, ..., N, 1]
    // P_1 = 2 corresponds to p[0] = 2
    p[0] = 2;

    // P_i = i+1 for 1 < i <= N-1
    // In 0-based indexing, this means p[j] = (j+1)+1 = j+2 for j from 1 to N-2.
    // The loop iterates for i from 1 up to n-2 (inclusive).
    // For example:
    // i=1: p[1] = 1+2 = 3 (P_2 = 3)
    // i=2: p[2] = 2+2 = 4 (P_3 = 4)
    // ...
    // i=n-2: p[n-2] = (n-2)+2 = n (P_{n-1} = n)
    for (int i = 1; i < n - 1; ++i) {
        p[i] = i + 2;
    }

    // P_N = 1 corresponds to p[n-1] = 1
    p[n - 1] = 1;

    // Print the generated permutation
    for (int i = 0; i < n; ++i) {
        std::cout << p[i] << (i == n - 1 ? "" : " "); // Print space between numbers, no space after the last
    }
    std::cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) unties std::cin from std::cout, preventing flush operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {  // Loop 't' times, decrementing 't' in each iteration
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}