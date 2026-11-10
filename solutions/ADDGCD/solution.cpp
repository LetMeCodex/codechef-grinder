#include <iostream>
#include <numeric> // For std::gcd
#include <algorithm> // Not strictly needed for this solution, but good practice for competitive programming

// Function to check if gcd(a, b) > 1
// Constraints guarantee a, b >= 1, so no need to worry about a or b being 0 or negative.
bool has_common_divisor_gt_1(long long a, long long b) {
    return std::gcd(a, b) > 1;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        long long x, y;
        std::cin >> x >> y; // Read X and Y for the current test case

        // Case 0 operations: Check if X and Y already have a common divisor > 1.
        if (has_common_divisor_gt_1(x, y)) {
            std::cout << 0 << "\n";
            continue; // Move to the next test case
        }

        // Case 1 operation: Check if we can achieve the goal with one increment.
        // This means either (X+1, Y) or (X, Y+1) has a common divisor > 1.
        if (has_common_divisor_gt_1(x + 1, y) || has_common_divisor_gt_1(x, y + 1)) {
            std::cout << 1 << "\n";
            continue; // Move to the next test case
        }

        // Case 2 operations: If 0 or 1 operation didn't work, 2 operations are always sufficient.
        // For example, incrementing both X and Y by 1 (X+1, Y+1) will make them both even if they were both odd.
        // If one was even and one was odd, the 1-operation case would have caught it.
        // So, if we reach here, X and Y must both be odd, and (X+1, Y+1) makes them both even, guaranteeing gcd >= 2.
        std::cout << 2 << "\n";
    }
    return 0;
}