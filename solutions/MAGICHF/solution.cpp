#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, s;
        std::cin >> n >> x >> s;
        int current_coin_pos = x;
        for (int i = 0; i < s; ++i) {
            int a, b;
            std::cin >> a >> b;
            if (current_coin_pos == a) {
                current_coin_pos = b;
            } else if (current_coin_pos == b) {
                current_coin_pos = a;
            }
        }
        std::cout << current_coin_pos << "\n";
    }
    return 0;
}