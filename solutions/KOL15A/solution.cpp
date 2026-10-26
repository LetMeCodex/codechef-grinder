#include <iostream>
#include <string>
#include <cctype> // For isdigit

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        long long sum = 0;
        for (char c : s) {
            if (std::isdigit(c)) { // Explicitly use std::
                sum += (c - '0');
            }
        }
        std::cout << sum << "\n";
    }

    return 0;
}