#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a1, a2, b1, b2;
        std::cin >> a1 >> a2 >> b1 >> b2;
        
        // Net export of country A = exports of A - imports of A
        long long net_export_a = a1 - a2;
        
        // Net export of country B = exports of B - imports of B
        long long net_export_b = b1 - b2;
        
        // The total trade in the system must balance.
        // If A and B have a combined net export, this must be balanced by C's net import.
        // Conversely, if A and B have a combined net import, this must be balanced by C's net export.
        // Total exports = A1 + B1 + C1
        // Total imports = A2 + B2 + C2
        // For the system to balance: Total exports = Total imports
        // A1 + B1 + C1 = A2 + B2 + C2
        // Rearranging for C's net export (C1 - C2):
        // C1 - C2 = (A2 - A1) + (B2 - B1)
        // C1 - C2 = -(A1 - A2) - (B1 - B2)
        // C1 - C2 = -(net_export_a) - (net_export_b)
        // C1 - C2 = -(net_export_a + net_export_b)
        
        long long net_export_c = -(net_export_a + net_export_b);
        
        // A trade surplus occurs when a country exports strictly more than it imports.
        // This means net export > 0.
        if (net_export_c > 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}