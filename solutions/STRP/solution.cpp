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

        int time = 0;
        int i = 0;
        while (i < n) {
            time++; // Always takes at least 1 unit of time for the current character(s)
            if (i + 1 < n && s[i] == s[i + 1]) {
                // If the current character is the same as the next one,
                // we can send 2 copies of this character in 1 unit of time.
                // So, we advance the index by 2.
                i += 2;
            } else {
                // Otherwise, we send 1 copy of the current character.
                // Advance the index by 1.
                i += 1;
            }
        }
        std::cout << time << "\n";
    }
    return 0;
}