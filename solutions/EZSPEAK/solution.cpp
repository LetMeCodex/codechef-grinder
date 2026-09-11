#include <bits/stdc++.h> // Includes iostream, string, etc.

using namespace std; // Use standard namespace for convenience

// Function to check if a character is a vowel
// Vowels are 'a', 'e', 'i', 'o', 'u'
bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the string
    string S;
    cin >> S; // Read the string

    int consecutive_consonants = 0; // Counter for consecutive consonants
    bool hard_to_pronounce = false; // Flag to indicate if the word is hard to pronounce

    // Iterate through each character of the string
    for (int i = 0; i < N; ++i) {
        if (is_vowel(S[i])) {
            // If it's a vowel, reset the consecutive consonant count
            consecutive_consonants = 0;
        } else {
            // If it's a consonant, increment the count
            consecutive_consonants++;
        }

        // Check if we have found 4 or more consecutive consonants
        if (consecutive_consonants >= 4) {
            hard_to_pronounce = true; // Mark as hard to pronounce
            break; // No need to check further, we found the condition
        }
    }

    // Output the result based on the flag
    if (hard_to_pronounce) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}