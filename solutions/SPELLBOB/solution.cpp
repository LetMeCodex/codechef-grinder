#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace for convenience

void solve() {
    string s1, s2; // s1 for top faces, s2 for bottom faces
    cin >> s1 >> s2;

    bool possible = false; // Flag to track if "bob" can be spelled

    // Iterate through all 2^3 = 8 combinations of flipping cards.
    // Each integer 'i' from 0 to 7 represents a unique flip configuration.
    // The k-th bit of 'i' determines whether to use the top (0) or bottom (1)
    // face for the k-th card.
    for (int i = 0; i < (1 << 3); ++i) {
        int count_b = 0; // Count of 'b' characters
        int count_o = 0; // Count of 'o' characters

        // Determine the visible character for Card 0
        // If the 0-th bit of 'i' is 1, use s2[0] (bottom face); otherwise, use s1[0] (top face).
        char c0 = ((i >> 0) & 1) ? s2[0] : s1[0];
        if (c0 == 'b') {
            count_b++;
        } else if (c0 == 'o') {
            count_o++;
        }

        // Determine the visible character for Card 1
        // If the 1-st bit of 'i' is 1, use s2[1]; otherwise, use s1[1].
        char c1 = ((i >> 1) & 1) ? s2[1] : s1[1];
        if (c1 == 'b') {
            count_b++;
        } else if (c1 == 'o') {
            count_o++;
        }

        // Determine the visible character for Card 2
        // If the 2-nd bit of 'i' is 1, use s2[2]; otherwise, use s1[2].
        char c2 = ((i >> 2) & 1) ? s2[2] : s1[2];
        if (c2 == 'b') {
            count_b++;
        } else if (c2 == 'o') {
            count_o++;
        }

        // Check if the current combination of visible letters can spell "bob".
        // This means we need exactly two 'b's and one 'o'.
        if (count_b == 2 && count_o == 1) {
            possible = true; // Found a valid combination
            break;           // No need to check further combinations
        }
    }

    // Output the result for the current test case
    if (possible) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}