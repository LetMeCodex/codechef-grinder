#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        int k;
        std::cin >> n >> k;

        // To have K distinct islands, we need K blocks of 0s.
        // The smallest possible distinct lengths for these K islands are 1, 2, ..., K.
        // The sum of these lengths is S = 1 + 2 + ... + K = K * (K + 1) / 2.
        // To separate K islands, we need at least K-1 separators (the character '1').
        // Therefore, the minimum total length of the string required is the sum of minimum zeros
        // plus the minimum number of ones.
        // Minimum length = (sum of minimum island lengths) + (minimum separators)
        // Minimum length = K * (K + 1) / 2 + (K - 1).
        //
        // We use long long for the calculation to avoid potential overflow, although for K <= 500,
        // int might suffice for intermediate products. However, using long long is safer.

        long long min_zeros_sum = (long long)k * (k + 1) / 2;
        long long min_separators = k - 1;
        long long required_length = min_zeros_sum + min_separators;

        // If the given length N is less than the minimum required length, it's impossible.
        // Otherwise, it's possible to construct such a string.
        if (n >= required_length) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}