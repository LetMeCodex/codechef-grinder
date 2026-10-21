#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<int> a(10);
        int score1 = 0;
        int score2 = 0;
        for (int i = 0; i < 10; ++i) {
            std::cin >> a[i];
            if (i % 2 == 0) { // Team 1 shots (indices 0, 2, 4, 6, 8)
                if (a[i] == 1) {
                    score1++;
                }
            } else { // Team 2 shots (indices 1, 3, 5, 7, 9)
                if (a[i] == 1) {
                    score2++;
                }
            }
        }

        if (score1 > score2) {
            std::cout << 1 << "\n";
        } else if (score2 > score1) {
            std::cout << 2 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}