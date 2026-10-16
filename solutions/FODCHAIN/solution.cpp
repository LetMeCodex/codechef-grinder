#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long e, k;
        std::cin >> e >> k;
        int foodchain_length = 0;
        while (e > 0) {
            foodchain_length++;
            e /= k;
        }
        std::cout << foodchain_length << "\n";
    }
    return 0;
}