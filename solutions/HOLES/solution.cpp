#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    string s; // Declare a string to store the input text
    cin >> s; // Read the input text

    int holes = 0; // Initialize a counter for total holes

    // Iterate through each character in the string
    for (char c : s) {
        // Use a switch statement to efficiently check the character and add holes
        switch (c) {
            case 'A':
            case 'D':
            case 'O':
            case 'P':
            case 'Q': // Added 'Q' here, as it's commonly considered to have 1 hole
            case 'R':
                holes += 1; // These letters have 1 hole
                break;
            case 'B':
                holes += 2; // Letter 'B' has 2 holes
                break;
            default:
                // All other letters (C, E, F, G, H, I, J, K, L, M, N, S, T, U, V, W, X, Y, Z)
                // have 0 holes, so we do nothing.
                break;
        }
    }

    // Output the total number of holes for the current test case, followed by a newline
    cout << holes << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}