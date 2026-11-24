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

        bool unique = true; // Assume unique initially
        for (int i = 0; i < n / 2; ++i) {
            int j = n - 1 - i;
            if (s[i] == '?' && s[j] == '?') {
                // If both mirrored positions are '?', they can be filled with any character.
                // This leads to multiple possibilities.
                unique = false;
                break; // Found ambiguity, no need to check further for this test case.
            }
            // If one is '?' and the other is a letter, that '?' is fixed.
            // If both are letters and they match, it's fixed.
            // If both are letters and they don't match, it's impossible (guaranteed not to happen).
            // So, only the case where both are '?' introduces ambiguity for pairs.
        }

        // For odd length strings, the middle character (n/2) mirrors itself.
        // If it's '?', it can be any character, leading to multiple possibilities.
        if (unique && n % 2 == 1 && s[n / 2] == '?') { // Added 'unique &&' to avoid redundant check if already false
            unique = false;
        }

        if (unique) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}