#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Use the standard namespace to avoid prefixing std:: to every standard library component.
using namespace std;

void solve() {
    int n;
    cin >> n; // Read the length of the string
    string a;
    cin >> a; // Read the binary string

    int count0 = 0;
    // Iterate through the string to count the number of '0's
    for (char c : a) {
        if (c == '0') {
            count0++;
        }
    }

    // The number of '1's is simply the total length N minus the count of '0's
    int count1 = n - count0;

    // To achieve the lexicographically smallest string, all '0's must come first,
    // followed by all '1's.
    // Print '0' count0 times
    for (int i = 0; i < count0; ++i) {
        cout << '0';
    }

    // Print '1' count1 times
    for (int i = 0; i < count1; ++i) {
        cout << '1';
    }
    cout << "\n"; // Newline after each test case output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {  // Loop through each test case
        solve();   // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}