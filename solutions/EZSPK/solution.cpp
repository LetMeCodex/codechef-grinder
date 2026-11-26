#include <bits/stdc++.h> // Includes all standard libraries as requested

// Using namespace std; as requested
using namespace std;

// Function to check if a character is a vowel
// Returns true if 'c' is 'a', 'e', 'i', 'o', or 'u', false otherwise.
bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the word
    string s;
    cin >> s; // Read the word itself

    int consecutive_consonants_count = 0; // Counter for consecutive consonants
    bool hard_to_pronounce = false;       // Flag to indicate if the word is hard to pronounce

    // Iterate through each character of the string
    for (char c : s) {
        if (is_vowel(c)) {
            // If a vowel is encountered, the sequence of consonants is broken.
            // Reset the counter.
            consecutive_consonants_count = 0;
        } else {
            // If a consonant is encountered, increment the counter.
            consecutive_consonants_count++;
        }

        // After updating the count, check if we have found at least 4 consecutive consonants.
        if (consecutive_consonants_count >= 4) {
            hard_to_pronounce = true; // Set the flag
            break;                   // No need to check further characters, we found the condition
        }
    }

    // Output the result for the current test case
    if (hard_to_pronounce) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O setup as requested for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}