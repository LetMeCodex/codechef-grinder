#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    string s;
    cin >> s; // Read the string of balloon colors

    int count_a = 0; // Counter for 'a' (amber) balloons
    int count_b = 0; // Counter for 'b' (brass) balloons

    // Iterate through the string to count 'a's and 'b's
    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else { // The problem statement guarantees characters are either 'a' or 'b'
            count_b++;
        }
    }

    // The minimum number of flips is the smaller of the two counts.
    // If we want all 'a', we flip 'b's. If we want all 'b', we flip 'a's.
    // We choose the option that requires fewer flips.
    cout << min(count_a, count_b) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}