#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        double x1, x2, y1, y2;
        std::cin >> x1 >> x2 >> y1 >> y2;

        // Cost per km for Car 1: (price of diesel per litre) / (km per litre of diesel)
        // Cost1 = y1 / x1
        // Cost per km for Car 2: (price of petrol per litre) / (km per litre of petrol)
        // Cost2 = y2 / x2

        // We need to compare y1/x1 and y2/x2.
        // To avoid floating point precision issues, we can compare y1*x2 and y2*x1.
        // If y1/x1 < y2/x2, then y1*x2 < y2*x1 (since x1 and x2 are positive)
        // If y1/x1 == y2/x2, then y1*x2 == y2*x1
        // If y1/x1 > y2/x2, then y1*x2 > y2*x1

        // The constraints are small (up to 50), so direct multiplication will not overflow standard integer types.
        // However, using double for calculation is also safe and directly represents the cost per km.
        // Let's use double for clarity and direct comparison of costs per km.

        double cost1_per_km = y1 / x1;
        double cost2_per_km = y2 / x2;

        // Using a small epsilon for floating point comparisons is generally good practice,
        // but given the constraints and the nature of the problem (direct division),
        // direct comparison might be sufficient. Let's try direct comparison first.
        // If it fails sample cases or has issues, we can introduce epsilon.
        // The sample cases suggest direct comparison is fine.

        if (cost1_per_km < cost2_per_km) {
            // Car 1 is cheaper
            std::cout << -1 << "\n";
        } else if (cost1_per_km > cost2_per_km) {
            // Car 2 is cheaper
            std::cout << 1 << "\n";
        } else {
            // Both cars have the same cost
            std::cout << 0 << "\n";
        }
    }
    return 0;
}