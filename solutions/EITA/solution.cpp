#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int d, x, y, z;
        std::cin >> d >> x >> y >> z;
        
        // Strategy 1: x units of work every day for 7 days
        long long strategy1_work = (long long)x * 7;
        
        // Strategy 2: y units of work for the first d days, then z units for the remaining days
        // Number of remaining days = 7 - d
        long long strategy2_work = (long long)y * d + (long long)z * (7 - d);
        
        // The maximum work is the maximum of the two strategies
        long long max_work = std::max(strategy1_work, strategy2_work);
        
        std::cout << max_work << "\n";
    }
    return 0;
}