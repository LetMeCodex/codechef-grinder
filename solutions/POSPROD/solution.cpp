#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long positive_count = 0;
        long long negative_count = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            std::cin >> a;
            if (a > 0) {
                positive_count++;
            } else if (a < 0) {
                negative_count++;
            }
        }

        // A_i * A_j > 0 means either both A_i and A_j are positive,
        // or both A_i and A_j are negative.
        // Pairs of positive numbers: C(positive_count, 2)
        // Pairs of negative numbers: C(negative_count, 2)
        // C(k, 2) = k * (k - 1) / 2

        long long pairs = (positive_count * (positive_count - 1) / 2) +
                          (negative_count * (negative_count - 1) / 2);
        std::cout << pairs << "\n";
    }
    return 0;
}