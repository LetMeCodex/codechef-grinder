#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b;
        std::cin >> a >> b;

        // Calculate the total valuation of the company by the first investor.
        // If the first investor offers A dollars for 10% of the company,
        // then the total valuation is A / 0.10 = A * 10.
        long long valuation1 = a * 10;

        // Calculate the total valuation of the company by the second investor.
        // If the second investor offers B dollars for 20% of the company,
        // then the total valuation is B / 0.20 = B * 5.
        long long valuation2 = b * 5;

        if (valuation1 > valuation2) {
            std::cout << "FIRST\n";
        } else if (valuation2 > valuation1) {
            std::cout << "SECOND\n";
        } else {
            std::cout << "ANY\n";
        }
    }
    return 0;
}