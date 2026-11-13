#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    bool has_even_one = false; // True if a '1' is found at an even index
    bool has_odd_one = false;  // True if a '1' is found at an odd index

    // Iterate through the string to find '1's and check their index parities
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (i % 2 == 0) { // Index is even
                has_even_one = true;
            } else { // Index is odd
                has_odd_one = true;
            }
            // Optimization: If we've found both types, we can stop early
            if (has_even_one && has_odd_one) {
                break;
            }
        }
    }

    // Determine the minimum distance based on the parities of '1's found
    if (has_even_one && has_odd_one) {
        // If there's at least one '1' at an even index and one at an odd index,
        // we can move them to be adjacent (e.g., at indices 0 and 1).
        // The minimum distance is 1.
        std::cout << 1 << "\n";
    } else {
        // This 'else' branch is reached if:
        // 1. All '1's are at even indices (has_even_one is true, has_odd_one is false)
        // 2. All '1's are at odd indices (has_even_one is false, has_odd_one is true)
        // In both scenarios, any two '1's will always be at positions of the same parity.
        // The distance between two positions of the same parity is always an even number.
        // The smallest possible positive even distance is 2.
        // We can always achieve a distance of 2 by moving two '1's to positions like k and k+2
        // (e.g., 0 and 2 for even, or 1 and 3 for odd), given N >= 2 and at least two '1's.
        // The minimum distance is 2.
        std::cout << 2 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}