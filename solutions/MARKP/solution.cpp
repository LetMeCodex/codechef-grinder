#include <iostream>
#include <vector>
#include <string>
#include <numeric> // Not strictly necessary for this solution

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    // actual_marked_S_str will store the state of points after applying all consistent operations.
    // Initialize all points as unmarked ('0').
    std::string actual_marked_S_str(n, '0');

    // Iterate through all possible centers for an operation (0-indexed).
    // A 1-indexed X such that 1 < X < N means 0-indexed x_idx such that 0 < x_idx < N-1.
    // So, x_idx can range from 1 to N-2.
    for (int x_center_0_indexed = 1; x_center_0_indexed <= n - 2; ++x_center_0_indexed) {
        // An operation centered at x_center_0_indexed marks points:
        // (x_center_0_indexed - 1), x_center_0_indexed, (x_center_0_indexed + 1).
        // For this operation to be consistent with the target string S,
        // all three points must be '1' in S.
        if (s[x_center_0_indexed - 1] == '1' && 
            s[x_center_0_indexed] == '1' && 
            s[x_center_0_indexed + 1] == '1') {
            
            // If all three points are '1' in S, we can perform this operation.
            // Mark these points in our actual_marked_S_str.
            actual_marked_S_str[x_center_0_indexed - 1] = '1';
            actual_marked_S_str[x_center_0_indexed] = '1';
            actual_marked_S_str[x_center_0_indexed + 1] = '1';
        }
    }

    // After applying all consistent operations, compare actual_marked_S_str with the target string S.
    // The problem states S_i = 1 if and only if you marked point i.
    // Our logic ensures actual_marked_S_str[i] is never '1' if s[i] is '0'.
    // So, we only need to check if actual_marked_S_str is exactly equal to s.
    if (actual_marked_S_str == s) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}