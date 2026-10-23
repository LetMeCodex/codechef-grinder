#include <iostream>
#include <algorithm>
#include <cmath> // For sqrt

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y, p;
        std::cin >> x >> y >> p;

        if (x * y >= p) {
            std::cout << 0 << "\n";
            continue;
        }

        long long min_moves = -1;

        // The function to minimize is f(moves_x) = moves_x + max(0LL, ceil(P / (X + moves_x)) - Y)
        // The term ceil(P / (X + moves_x)) decreases as moves_x increases.
        // The term moves_x increases as moves_x increases.
        // The minimum of such a function typically occurs when moves_x is around sqrt(P).
        // A safe upper bound for moves_x to check is around 2 * sqrt(P).
        // If moves_x becomes very large, ceil(P / (X + moves_x)) becomes 1.
        // Then f(moves_x) = moves_x + max(0LL, 1 - Y). This is minimized when moves_x is minimized.
        // The minimum in this regime occurs when X + moves_x >= P, i.e., moves_x >= P - X.
        // The smallest such moves_x is P - X.
        // So, we need to check moves_x from 0 up to roughly sqrt(P) and also consider the case where moves_x is large.
        // A bound of 2 * sqrt(P) + a small constant should be sufficient.
        // Maximum P is 10^4, sqrt(P) is 100. So, 2*100 + 2 = 202 iterations.
        // This is much better than P iterations.

        long long limit = 2 * static_cast<long long>(sqrt(p)) + 2;
        // Ensure limit is at least 1 to cover cases where P is small.
        if (limit < 1) limit = 1;
        // Also, consider the case where X is already large, and we might need to increment Y.
        // If X+moves_x >= P, then target_y = 1. moves_y = max(0, 1-Y).
        // Total moves = moves_x + max(0, 1-Y). This is minimized when moves_x is minimal, i.e., P-X.
        // So, we should also consider moves_x up to P-X if P-X is large.
        // However, if P-X is large, then moves_x + max(0, 1-Y) will be large.
        // The minimum is likely to be found when moves_x is around sqrt(P).
        // Let's cap the limit to P just to be absolutely safe, though it should not be necessary.
        // The theoretical bound for moves_x where the minimum occurs is related to sqrt(P).
        // If P is very small, e.g., P=1, sqrt(P)=1, limit=4.
        // If P=10000, sqrt(P)=100, limit=202.
        // The maximum value of P is 10^4.
        // The maximum value of X is 50.
        // If P-X is very large, e.g., P=10000, X=1, P-X=9999.
        // But the minimum for X=1, Y=1, P=10000 is 198.
        // So, the sqrt(P) based limit is indeed the correct one.

        for (long long moves_x = 0; moves_x <= limit; ++moves_x) {
            long long current_x = x + moves_x;
            // Calculate ceil(p / current_x) using integer division
            // This is equivalent to (p + current_x - 1) / current_x for positive integers.
            long long target_y = (p + current_x - 1) / current_x;
            
            long long moves_y = std::max(0LL, target_y - y);
            
            long long total_moves = moves_x + moves_y;
            
            if (min_moves == -1 || total_moves < min_moves) {
                min_moves = total_moves;
            }
        }
        
        // We also need to consider the case where we only increment Y.
        // This is covered by moves_x = 0 in the loop.
        // The loop limit is chosen such that it covers the region where the minimum is expected.
        // If P is very large and X, Y are small, the minimum is around 2*sqrt(P).
        // If P is small, the limit is small.
        // The logic is that the function f(moves_x) = moves_x + C/(X+moves_x) has its minimum around sqrt(C).
        // The max(0, ...) term doesn't change the location of the minimum significantly.

        std::cout << min_moves << "\n";
    }
    return 0;
}