#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long x;
        std::cin >> n >> x;
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int max_streak = 0;

        // Case 1: No operation is performed
        int current_streak = 0;
        if (n > 0) {
            current_streak = 1;
            for (int i = 1; i < n; ++i) {
                if (a[i] >= a[i - 1]) {
                    current_streak++;
                } else {
                    max_streak = std::max(max_streak, current_streak);
                    current_streak = 1;
                }
            }
            max_streak = std::max(max_streak, current_streak);
        } else {
            max_streak = 0;
        }
        
        // Case 2: Perform operation at most once
        for (int i = 0; i < n; ++i) {
            std::vector<long long> b = a;
            b[i] *= x;

            current_streak = 0;
            if (n > 0) {
                current_streak = 1;
                for (int j = 1; j < n; ++j) {
                    if (b[j] >= b[j - 1]) {
                        current_streak++;
                    } else {
                        max_streak = std::max(max_streak, current_streak);
                        current_streak = 1;
                    }
                }
                max_streak = std::max(max_streak, current_streak);
            }
        }
        
        std::cout << max_streak << "\n";
    }
    return 0;
}