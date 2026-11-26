#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <algorithm> // Required for std::count (though a manual loop is also fine)

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the binary string
    std::string S;
    std::cin >> S; // Read the binary string

    // Count the number of '1's in the binary string S
    int ones_count = 0;
    for (char c : S) {
        if (c == '1') {
            ones_count++;
        }
    }
    // Alternatively, using std::count:
    // int ones_count = std::count(S.begin(), S.end(), '1');

    // Apply the derived rules based on the count of '1's (popcount)
    if (ones_count == 1) {
        // If the number X has only one '1' in its binary representation,
        // it means X is a power of two (X = 2^k).
        // We need to represent X as 2^a + 2^b + 2^c.
        // The smallest possible sum of three non-negative powers of two is 2^0 + 2^0 + 2^0 = 1 + 1 + 1 = 3.
        // So, if X is 1 (S="1", k=0) or 2 (S="10", k=1), it cannot be represented.
        // For X = 2^k where k >= 2 (e.g., 4, 8, 16, ...), it can be represented.
        // For example, 4 = 2^2 = 2^1 + 2^0 + 2^0.
        // In general, 2^k = 2^{k-1} + 2^{k-2} + 2^{k-2} for k >= 2.
        if (S == "1" || S == "10") {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
        }
    } else if (ones_count == 2) {
        // If X has two '1's in its binary representation, X = 2^k + 2^j where k > j >= 0.
        // This can always be represented as a sum of three powers of two.
        // Since k > j >= 0, k must be at least 1.
        // We can split 2^k into 2^{k-1} + 2^{k-1}.
        // So, X = 2^{k-1} + 2^{k-1} + 2^j. These are three non-negative powers.
        // Example: 9 (1001_2) = 2^3 + 2^0 = 2^2 + 2^2 + 2^0.
        // Example: 3 (11_2) = 2^1 + 2^0 = 2^0 + 2^0 + 2^0.
        std::cout << "YES\n";
    } else if (ones_count == 3) {
        // If X has three '1's in its binary representation, X = 2^k + 2^j + 2^m where k > j > m >= 0.
        // This is already a sum of three distinct non-negative powers of two.
        // Example: 25 (11001_2) = 2^4 + 2^3 + 2^0.
        std::cout << "YES\n";
    } else { // ones_count > 3
        // It's a known property that for any positive integers A, B, C,
        // popcount(A + B + C) <= popcount(A) + popcount(B) + popcount(C).
        // If A=2^a, B=2^b, C=2^c, then popcount(A)=1, popcount(B)=1, popcount(C)=1.
        // So, popcount(2^a + 2^b + 2^c) <= 1 + 1 + 1 = 3.
        // Therefore, if the given number X has more than 3 '1's in its binary representation,
        // it cannot be represented as a sum of exactly three powers of two.
        // Example: 15 (1111_2) has 4 '1's. It cannot be represented.
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}