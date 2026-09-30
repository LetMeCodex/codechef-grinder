#include <bits/stdc++.h> // Includes iostream, string, etc.

using namespace std; // Use standard namespace

void solve() {
    string s;
    cin >> s; // Read the input string
    int n = s.length(); // Get the length of the string
    int pairs = 0; // Initialize the count of pairs
    int i = 0; // Initialize the pointer for iterating through students

    // Iterate while there are at least two students remaining to potentially form a pair
    while (i < n - 1) {
        // Check if students at index i and i+1 can form a boy-girl pair
        // This means one is 'x' and the other is 'y'
        if ((s[i] == 'x' && s[i+1] == 'y') || (s[i] == 'y' && s[i+1] == 'x')) {
            pairs++; // Increment the pair count
            i += 2; // If a pair is formed, both students i and i+1 are used.
                    // So, skip both and move to student i+2 for the next potential pair.
        } else {
            // If no valid pair can be formed with students i and i+1 (either same gender or i+1 is out of bounds),
            // student i cannot be part of a pair starting at i.
            // Move to student i+1 to see if they can start a new pair.
            i += 1;
        }
    }
    cout << pairs << "\n"; // Print the maximum number of pairs
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}