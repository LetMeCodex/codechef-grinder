#include <iostream>
#include <string>
#include <vector>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        std::string s, guess;
        std::cin >> s >> guess; // Read the hidden word and the guess word

        std::string m = ""; // Initialize the result string M
        for (int i = 0; i < 5; ++i) {
            if (s[i] == guess[i]) {
                m += 'G'; // If characters match, append 'G'
            } else {
                m += 'B'; // If characters don't match, append 'B'
            }
        }
        std::cout << m << "\n"; // Print the resulting string M
    }
    return 0;
}