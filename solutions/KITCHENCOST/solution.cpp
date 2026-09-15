#include <iostream>
#include <vector>
// The <numeric> header is not strictly necessary for this problem's logic.

class Solution {
public:
    // This method will be called by the platform's main function.
    // The arguments match the types seen in the error message: n, x, a, b.
    // The return type is long long, as used for total_cost in your original code.
    long long compute(int n, int x, const std::vector<int>& a, const std::vector<int>& b) {
        long long total_cost = 0;
        for (int i = 0; i < n; ++i) {
            // Chef purchases items with freshness value greater than or equal to X.
            if (a[i] >= x) {
                total_cost += b[i];
            }
        }
        return total_cost;
    }
};

// The platform will provide its own main function, similar to this (hypothetical example):
/*
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> a(n);
        std::vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }

        Solution s;
        std::cout << s.compute(n, x, a, b) << "\n";
    }
    return 0;
}
*/