#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, p;
        std::cin >> n >> p;
        std::string s;
        std::cin >> s;

        // The object starts at position P (1-indexed).
        // Collection points are at 0 and N+1.

        // Option 1: Try to reach collection point 0 (move left)
        // We need to reverse slots until the object reaches position 0.
        // This means all slots from P down to 1 must be 'L'.
        int reversals_to_left = 0;
        for (int i = p - 1; i >= 0; --i) {
            if (s[i] == 'R') {
                reversals_to_left++;
            }
        }

        // Option 2: Try to reach collection point N+1 (move right)
        // We need to reverse slots until the object reaches position N+1.
        // This means all slots from P up to N must be 'R'.
        int reversals_to_right = 0;
        for (int i = p - 1; i < n; ++i) {
            if (s[i] == 'L') {
                reversals_to_right++;
            }
        }

        // The minimum number of reversals is the minimum of the two options.
        std::cout << std::min(reversals_to_left, reversals_to_right) << "\n";
    }
    return 0;
}