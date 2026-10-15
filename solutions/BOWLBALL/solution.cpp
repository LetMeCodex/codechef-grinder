#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, y;
        std::cin >> n >> x >> y;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            int weight;
            std::cin >> weight;
            if (weight >= x && weight <= y) {
                count++;
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}