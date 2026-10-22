#include <iostream>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int x, y;
        std::cin >> x >> y; // Read X and Y for each test case

        // Case 1: X is an even number.
        // If X is even, all its multiples (X, 2X, 3X, ...) are also even.
        // This means S_odd will be 0.
        // Since Y >= X >= 1, there is at least one multiple (X itself), so S_even will be positive.
        // Therefore, S_even >= S_odd (S_even >= 0) is always true. Alice is happy.
        if (x % 2 == 0) {
            std::cout << "YES\n";
        } 
        // Case 2: X is an odd number.
        // If X is odd, the parity of a multiple (m*X) depends on the parity of m.
        // m*X is odd if m is odd.
        // m*X is even if m is even.
        // We need to compare the sum of (odd m * X) with the sum of (even m * X).
        // This is equivalent to comparing the sum of odd m's with the sum of even m's.
        // Let k be the largest integer such that k*X <= Y. So k = floor(Y/X).
        else {
            int k = y / x; // Calculate k = floor(Y/X)

            // If k is even:
            // The sequence of m's is 1, 2, ..., k.
            // Sum of even m's (2+4+...+k) will be greater than sum of odd m's (1+3+...+(k-1)).
            // Example: k=4. Even m's: 2, 4. Sum = 6. Odd m's: 1, 3. Sum = 4. 6 >= 4. Alice is happy.
            if (k % 2 == 0) {
                std::cout << "YES\n";
            } 
            // If k is odd:
            // The sequence of m's is 1, 2, ..., k.
            // Sum of even m's (2+4+...+ (k-1)) will be less than sum of odd m's (1+3+...+k).
            // Example: k=3. Even m's: 2. Sum = 2. Odd m's: 1, 3. Sum = 4. 2 < 4. Alice is sad.
            else {
                std::cout << "NO\n";
            }
        }
    }
    return 0;
}