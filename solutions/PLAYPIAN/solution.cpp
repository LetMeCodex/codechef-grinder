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
        bool possible = true;
        // The problem states that each person plays exactly once per day.
        // The log entries are given in sequence.
        // Since |s| is even, we can group the entries into pairs representing days.
        // Each day's log must consist of one 'A' and one 'B'.
        // This means that for any pair of consecutive characters that form a day's log,
        // they must be different.
        // The string s is a concatenation of these daily logs.
        // So, we need to check pairs s[0]s[1], s[2]s[3], s[4]s[5], etc.
        // For each pair s[i]s[i+1] (where i is even), we must have s[i] != s[i+1].
        for (int i = 0; i < s.length(); i += 2) {
            // Check the pair s[i] and s[i+1]
            if (s[i] == s[i+1]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    return 0;
}