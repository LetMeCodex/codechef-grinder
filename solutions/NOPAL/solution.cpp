#include <bits/stdc++.h> // Includes iostream, string, etc.
using namespace std; // As requested by the problem statement

void solve() {
    int n;
    cin >> n; // Read the length of the string
    string s = ""; // Initialize an empty string
    for (int i = 0; i < n; ++i) {
        // Append characters 'a', 'b', 'c' in a cyclic manner
        // 'a' for i%3 == 0
        // 'b' for i%3 == 1
        // 'c' for i%3 == 2
        s += (char)('a' + (i % 3));
    }
    cout << s << "\n"; // Print the constructed string followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}