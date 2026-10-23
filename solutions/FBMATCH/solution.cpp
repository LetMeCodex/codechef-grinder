#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the string
    string S;
    cin >> S; // Read the string S

    // Create a vector to store character frequencies.
    // There are 26 lowercase English letters ('a' through 'z').
    // counts[0] will store frequency of 'a', counts[1] for 'b', and so on.
    vector<int> counts(26, 0); 

    // Iterate through each character in the string S
    for (char c : S) {
        // Increment the count for the corresponding character.
        // 'c - 'a'' converts a character like 'a' to 0, 'b' to 1, etc.
        counts[c - 'a']++; 
    }

    bool possible = false; // Flag to track if a suitable character is found

    // Iterate through the frequency counts
    for (int count : counts) {
        // If any character appears 2 or more times, it's possible
        if (count >= 2) {
            possible = true; // Set flag to true
            break;           // No need to check further, we found one
        }
    }

    // Output the result based on the 'possible' flag
    if (possible) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}