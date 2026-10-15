#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        int groups = 0;
        bool in_group = false;
        for (char c : s) {
            if (c == '1') {
                if (!in_group) {
                    groups++;
                    in_group = true;
                }
            } else {
                in_group = false;
            }
        }
        std::cout << groups << "\n";
    }
    return 0;
}