#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        long long current_pos = n;
        for (int i = 1; i <= n - 1; ++i) {
            int jump_distance = n - i;
            if (i % 2 == 1) { // Odd jump number, move left
                current_pos -= jump_distance;
            } else { // Even jump number, move right
                current_pos += jump_distance;
            }
        }
        std::cout << current_pos << "\n";
    }
    return 0;
}