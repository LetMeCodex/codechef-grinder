#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::string sa, sb;
        std::cin >> sa >> sb;

        std::set<char> chars_sa;
        for (char c : sa) {
            chars_sa.insert(c);
        }

        std::set<char> chars_sb;
        for (char c : sb) {
            chars_sb.insert(c);
        }

        bool possible = false;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (chars_sa.find(c) == chars_sa.end() && chars_sb.find(c) == chars_sb.end()) {
                possible = true;
                break;
            }
        }

        if (possible) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}