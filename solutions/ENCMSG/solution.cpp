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
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;

        // Step 1: Swap characters in pairs
        for (int i = 0; i < n - 1; i += 2) {
            std::swap(s[i], s[i + 1]);
        }

        // Step 2: Replace characters
        for (int i = 0; i < n; ++i) {
            // 'a' becomes 'z', 'b' becomes 'y', ..., 'z' becomes 'a'
            // The mapping is: char_code(new_char) = char_code('a') + (char_code('z') - char_code(original_char))
            s[i] = 'a' + ('z' - s[i]);
        }

        std::cout << s << "\n";
    }
    return 0;
}