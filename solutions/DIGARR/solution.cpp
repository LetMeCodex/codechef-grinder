#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int d;
        std::cin >> d;
        std::string n;
        std::cin >> n;

        bool found_zero_or_five = false;
        for (char digit : n) {
            if (digit == '0' || digit == '5') {
                found_zero_or_five = true;
                break;
            }
        }

        if (found_zero_or_five) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}