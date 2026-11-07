#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common in competitive programming

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;

    int fixed_parity_sum = 0; // Stores the parity of the sum of '1's from positions where A_i == B_i == '1'
                              // 0 for even sum, 1 for odd sum.
    bool can_flip_parity = false; // True if there's at least one position where A_i != B_i

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1' && b[i] == '1') {
            // Both are '1'. This position always adds 1 to the score.
            // It flips the current fixed_parity_sum.
            fixed_parity_sum = 1 - fixed_parity_sum; // Equivalent to fixed_parity_sum = (fixed_parity_sum + 1) % 2
        } else if (a[i] == '0' && b[i] == '0') {
            // Both are '0'. This position always adds 0 to the score.
            // It does not change the current fixed_parity_sum.
        } else {
            // One is '0' and the other is '1' (e.g., A_i='0', B_i='1' or A_i='1', B_i='0').
            // This means we can choose to add either 0 or 1 at this position.
            // This gives us the flexibility to flip the overall score's parity if needed.
            can_flip_parity = true;
        }
    }

    if (can_flip_parity) {
        // If we have at least one position where we can choose to add 0 or 1,
        // we can always make the final score odd.
        // If fixed_parity_sum is 0 (even), we choose to add 1 at a flexible position. Total parity becomes 1.
        // If fixed_parity_sum is 1 (odd), we choose to add 0 at a flexible position. Total parity remains 1.
        std::cout << "YES\n";
    } else {
        // If there are no positions where A_i != B_i, then for all i, A_i == B_i.
        // The total score will be exactly the count of positions where A_i == B_i == '1'.
        // The parity of this count is stored in fixed_parity_sum.
        // We need this score to be odd.
        if (fixed_parity_sum == 1) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}