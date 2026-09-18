#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int consecutive_vowels = 0;
        bool happy = false;

        for (char c : s) {
            if (is_vowel(c)) {
                consecutive_vowels++;
                if (consecutive_vowels > 2) {
                    happy = true;
                    break;
                }
            } else {
                consecutive_vowels = 0;
            }
        }

        if (happy) {
            cout << "Happy\n";
        } else {
            cout << "Sad\n";
        }
    }

    return 0;
}