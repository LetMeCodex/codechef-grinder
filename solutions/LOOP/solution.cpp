#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, m;
        std::cin >> a >> b >> m;
        
        // Ensure a is the smaller checkpoint for easier calculation
        if (a > b) {
            std::swap(a, b);
        }
        
        // Distance in one direction (clockwise from a to b)
        long long dist1 = b - a;
        
        // Distance in the other direction (counter-clockwise from a to b)
        // This is equivalent to going from a to M, then M to 1, then 1 to b
        // Or more simply, the total length M minus the distance in the first direction.
        long long dist2 = m - dist1;
        
        // The minimum distance is the smaller of the two
        std::cout << std::min(dist1, dist2) << "\n";
    }
    return 0;
}