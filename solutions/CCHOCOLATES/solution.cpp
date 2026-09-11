#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y, z;
        std::cin >> x >> y >> z;
        long long total_rupees = x * 5 + y * 10;
        long long max_chocolates = total_rupees / z;
        std::cout << max_chocolates << "\n";
    }
    return 0;
}