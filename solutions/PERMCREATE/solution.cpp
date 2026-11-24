#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read N for the current test case

        if (n == 2 || n == 3) {
            // It can be proven that no such permutation exists for N=2 or N=3.
            std::cout << "-1\n";
        } else if (n == 4) {
            // Special case for N=4. The general strategy (evens then odds) fails.
            // A valid permutation for N=4 is [2, 4, 1, 3].
            // Differences: |4-2|=2, |1-4|=3, |3-1|=2. All are >= 2.
            std::cout << "2 4 1 3\n";
        } else {
            // General strategy for N >= 5:
            // Print all even numbers in descending order, then all odd numbers in descending order.
            // This ensures that:
            // 1. Adjacent evens (e.g., 6, 4) have a difference of 2.
            // 2. Adjacent odds (e.g., 5, 3) have a difference of 2.
            // 3. The transition from the last even number (which is 2) to the first odd number:
            //    - If N is odd (e.g., N=5), first odd is N=5. Difference |5-2|=3 >= 2.
            //    - If N is even (e.g., N=6), first odd is N-1=5. Difference |5-2|=3 >= 2.
            // In both cases for N >= 5, the difference is >= 2.

            // Print even numbers in descending order
            // Start from N if N is even, or N-1 if N is odd.
            for (int i = (n % 2 == 0 ? n : n - 1); i >= 2; i -= 2) {
                std::cout << i << " ";
            }

            // Print odd numbers in descending order
            // Start from N-1 if N is even, or N if N is odd.
            for (int i = (n % 2 == 0 ? n - 1 : n); i >= 1; i -= 2) {
                std::cout << i << (i == 1 ? "" : " "); // No trailing space after the last number
            }
            std::cout << "\n"; // Newline after each test case output
        }
    }
    return 0;
}