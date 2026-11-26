#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::string a, b;
        std::cin >> a >> b;

        std::set<char> distinct_target_chars;

        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                distinct_target_chars.insert(b[i]);
            }
        }
        
        std::cout << distinct_target_chars.size() << "\n";
    }
    return 0;
}