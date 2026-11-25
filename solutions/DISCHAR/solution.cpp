#include <iostream>
#include <string>
#include <set>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        std::string s;
        std::cin >> s;
        std::set<char> distinct_chars;
        for (char c : s) {
            distinct_chars.insert(c);
        }
        std::cout << distinct_chars.size() << "\n";
    }
    return 0;
}