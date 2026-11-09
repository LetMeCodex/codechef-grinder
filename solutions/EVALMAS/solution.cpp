#include <iostream>
#include <string>
#include <vector>
#include <numeric> // Not strictly needed, but often included in competitive programming

void solve() {
    int N;
    long long X; // X can be negative, using long long for safety, though int is sufficient for given constraints.
    std::cin >> N >> X;

    bool found = false;
    // Iterate through possible number of '*' operators (k)
    for (int k = 0; k <= N; ++k) {
        // M is the effective number of '1's remaining after all multiplications.
        // Each '*' operator reduces the count of '1's by one.
        long long M = (long long)N + 1 - k;

        // Check if X is within the possible range for M '1's using only '+' and '-' operators.
        // Minimum value achievable: 1 - (M-1) = 2-M (e.g., 1-1-1...-1)
        // Maximum value achievable: 1 + (M-1) = M (e.g., 1+1+1...+1)
        if (X < 2 - M || X > M) {
            continue; // X is out of range for this M
        }

        // Check parity: The sum of M terms (1 +/- 1 +/- ... +/- 1) must have the same parity as M.
        // (val % 2 + 2) % 2 is a common way to get a positive remainder for negative numbers in C++.
        if ((X % 2 + 2) % 2 != (M % 2 + 2) % 2) {
            continue; // Parity mismatch
        }

        // If both range and parity conditions are met, a solution exists for this k.
        // Calculate P (number of '+' operators) and Q (number of '-' operators).
        // We need to achieve X-1 using M-1 operators on the remaining M-1 '1's.
        // P + Q = M-1
        // P - Q = X-1
        // Solving these equations:
        long long P = (M + X - 2) / 2; // Number of '+' operators
        long long Q = (M - X) / 2;     // Number of '-' operators

        // P and Q are guaranteed to be non-negative integers by the range and parity checks.

        // Construct the string S.
        // A simple construction is to place all '*' first, then all '+'s, then all '-'s.
        // The problem allows any valid string.
        std::string S = "";
        S.reserve(N); // Pre-allocate memory for efficiency

        for (int i = 0; i < k; ++i) {
            S += '*';
        }
        for (int i = 0; i < P; ++i) {
            S += '+';
        }
        for (int i = 0; i < Q; ++i) {
            S += '-';
        }

        std::cout << S << "\n";
        found = true;
        break; // Found a solution, print it and exit the loop for this test case.
    }

    if (!found) {
        std::cout << -1 << "\n"; // No solution found after checking all possible k values.
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}