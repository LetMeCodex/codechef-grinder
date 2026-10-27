#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to check if a character is a vowel
bool is_vowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        string target = "CODETOWN";

        bool possible = true;
        for (int i = 0; i < 8; ++i) {
            // If the character at the current position is different in S and target
            if (s[i] != target[i]) {
                // Check if both characters are of the same type (both vowels or both consonants)
                if (is_vowel(s[i]) != is_vowel(target[i])) {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}