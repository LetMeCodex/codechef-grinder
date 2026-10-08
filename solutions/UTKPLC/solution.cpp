#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        char first, second, third;
        std::cin >> first >> second >> third;
        char offer1, offer2;
        std::cin >> offer1 >> offer2;

        if (offer1 == first || offer2 == first) {
            std::cout << first << "\n";
        } else if (offer1 == second || offer2 == second) {
            std::cout << second << "\n";
        } else {
            std::cout << third << "\n";
        }
    }
    return 0;
}