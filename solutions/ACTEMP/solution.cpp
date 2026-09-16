#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        // Alice wants temperature >= a
        // Bob wants temperature <= b
        // Charlie wants temperature >= c
        
        // For a temperature T to satisfy all conditions:
        // T >= a
        // T <= b
        // T >= c
        
        // Combining the lower bounds: T must be >= max(a, c)
        // So, we need a temperature T such that:
        // max(a, c) <= T <= b
        
        // Such a temperature T exists if and only if the lower bound is less than or equal to the upper bound.
        // That is, max(a, c) <= b
        
        if (std::max(a, c) <= b) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}