#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x;
    std::cin >> x;
    
    // Calculate the total cost for the first payment scheme
    // Immediate payment: 100 coins
    // Weekly payment: X coins for 4 weeks
    long long cost_scheme1 = 100LL + 4LL * x;
    
    // Cost for the second payment scheme
    // Immediate payment: 300 coins
    long long cost_scheme2 = 300LL;
    
    // Output the minimum of the two costs
    std::cout << std::min(cost_scheme1, cost_scheme2) << "\n";
    
    return 0;
}