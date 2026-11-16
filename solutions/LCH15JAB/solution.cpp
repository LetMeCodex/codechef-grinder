#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions
using namespace std; // Uses the standard namespace, as per problem instructions

// Function to solve a single test case
void solve() {
    string s;
    cin >> s; // Read the input string S

    // A vector to store frequencies of lowercase Latin letters.
    // 'a' maps to index 0, 'b' to 1, ..., 'z' to 25.
    // Initialized with all zeros.
    vector<int> freq(26, 0); 

    // Iterate through the string to calculate character frequencies
    for (char c : s) {
        freq[c - 'a']++; // Increment count for the corresponding character
    }

    int total_length = s.length(); // Get the total length of the string

    // The condition "count of one character equals sum of counts of others"
    // implies that total_length = count_of_that_char + count_of_that_char
    // i.e., total_length = 2 * count_of_that_char.
    // This means total_length must be an even number.
    // If total_length is odd, no such character can exist.
    if (total_length % 2 != 0) {
        cout << "NO\n"; // Output "NO" and return for this test case
        return;
    }

    // If total_length is even, the target count for a character
    // to satisfy the condition is exactly half of the total length.
    int target_count = total_length / 2;

    // Check if any character's frequency matches the target_count
    bool found = false;
    for (int count : freq) { // Iterate through all 26 possible character counts
        if (count == target_count) {
            found = true; // Found a character that satisfies the condition
            break;        // No need to check further, we found one
        }
    }

    // Output "YES" or "NO" based on whether such a character was found
    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}