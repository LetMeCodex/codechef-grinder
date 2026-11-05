#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::min and std::abs

void solve() {
    int n;
    std::cin >> n;
    std::string a;
    std::cin >> a;

    int mismatches_target_0 = 0; // Count of pairs (A_k, A_{N-1-k}) where A_k='1', A_{N-1-k}='0'
    int mismatches_target_1 = 0; // Count of pairs (A_k, A_{N-1-k}) where A_k='0', A_{N-1-k}='1'

    // Iterate through the first half of the string to find mismatches
    for (int k = 0; k < n / 2; ++k) {
        if (a[k] != a[n - 1 - k]) {
            // Mismatch found
            if (a[k] == '1') { 
                mismatches_target_0++;
            } else { 
                mismatches_target_1++;
            }
        }
    }

    int operations = 0;
    
    // Step 1: Pair up mismatches of type (1,0) with mismatches of type (0,1).
    // Each such pairing fixes two mismatches in one operation.
    operations += std::min(mismatches_target_0, mismatches_target_1);
    
    // Step 2: Calculate the number of mismatches remaining after pairing different types.
    // These remaining mismatches will all be of the same type.
    int remaining_mismatches = std::abs(mismatches_target_0 - mismatches_target_1);
    
    // Step 3: Fix the remaining mismatches.
    // Two mismatches of the same type can be fixed in 1 operation.
    // One mismatch requires 1 operation.
    // This is equivalent to ceil(remaining_mismatches / 2.0).
    operations += (remaining_mismatches + 1) / 2; // Integer division for ceil

    std::cout << operations << "\n";
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