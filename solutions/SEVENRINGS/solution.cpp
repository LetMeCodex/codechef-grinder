#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n, x;
        std::cin >> n >> x;
        long long total_bill = n * x;
        std::string s = std::to_string(total_bill);
        if (s.length() == 5 && s[0] != '0') {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}