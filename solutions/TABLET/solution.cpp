#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        long long b;
        std::cin >> n >> b;
        long long max_area = -1;
        for (int i = 0; i < n; ++i) {
            long long w, h, p;
            std::cin >> w >> h >> p;
            if (p <= b) {
                max_area = std::max(max_area, w * h);
            }
        }
        if (max_area == -1) {
            std::cout << "no tablet\n";
        } else {
            std::cout << max_area << "\n";
        }
    }
    return 0;
}