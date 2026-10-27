#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

void solve() {
    int n;
    cin >> n; // Read the length of the binary string S
    string s;
    cin >> s; // Read the binary string S

    // Iterate through each character of S
    for (int i = 0; i < n; ++i) {
        // If the character is '0', its opposite is '1'
        if (s[i] == '0') {
            cout << '1';
        } 
        // If the character is '1', its opposite is '0'
        else { // Since S is a binary string, s[i] must be '1' if not '0'
            cout << '0';
        }
    }
    cout << "\n"; // Print a newline after generating T for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}