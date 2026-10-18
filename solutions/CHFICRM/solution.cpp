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
        int count5 = 0;
        int count10 = 0;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            int coin;
            std::cin >> coin;
            if (coin == 5) {
                count5++;
            } else if (coin == 10) {
                if (count5 > 0) {
                    count5--;
                    count10++;
                } else {
                    possible = false;
                    // Consume remaining input for this test case
                    for (int j = i + 1; j < n; ++j) {
                        int dummy;
                        std::cin >> dummy;
                    }
                    break;
                }
            } else if (coin == 15) { // coin == 15
                if (count10 > 0) {
                    count10--;
                } else if (count5 >= 2) {
                    count5 -= 2;
                } else {
                    possible = false;
                    // Consume remaining input for this test case
                    for (int j = i + 1; j < n; ++j) {
                        int dummy;
                        std::cin >> dummy;
                    }
                    break;
                }
            }
        }

        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}