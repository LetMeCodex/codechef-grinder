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
        std::vector<int> a(n);
        long long current_sum = 0;
        std::vector<int> gains;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            current_sum += a[i];
            // The gain from flipping a die with value x is (7-x) - x = 7 - 2x.
            // We want to maximize the sum, so we should prioritize flips that give the largest positive gain.
            // A flip is beneficial if 7 - 2x > 0, which means 2x < 7, or x < 3.5.
            // So, dice with values 1, 2, and 3 can potentially be flipped to increase the sum.
            // The gain for 1 is 7-2*1 = 5.
            // The gain for 2 is 7-2*2 = 3.
            // The gain for 3 is 7-2*3 = 1.
            // Dice with values 4, 5, 6 will result in a loss or no change if flipped.
            // For 4: 7-2*4 = -1.
            // For 5: 7-2*5 = -3.
            // For 6: 7-2*6 = -5.
            // We only consider flips that increase the sum.
            if (a[i] < 4) {
                gains.push_back(7 - 2 * a[i]);
            }
        }

        // Sort the potential gains in descending order to pick the largest ones first.
        std::sort(gains.rbegin(), gains.rend());

        // Apply the top K beneficial flips.
        for (int i = 0; i < std::min((int)gains.size(), k); ++i) {
            current_sum += gains[i];
        }

        std::cout << current_sum << "\n";
    }
    return 0;
}