#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        double base = 0.143 * n;
        double result = std::pow(base, n);
        // Round to the nearest integer
        // If result - floor(result) < 0.5, print floor(result)
        // Otherwise, print floor(result) + 1
        long long rounded_result = static_cast<long long>(result + 0.5);
        std::cout << rounded_result << "\n";
    }
    return 0;
}