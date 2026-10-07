#include <bits/stdc++.h> // Includes all standard libraries as requested

using namespace std; // Uses the standard namespace as requested

void solve() {
    int x;
    cin >> x; // Read the number of seconds, X

    // Calculate the remainder when X is divided by 4.
    // This remainder determines the final direction due to the 4-direction cycle.
    int remainder = x % 4;

    // Based on the remainder, output the corresponding direction.
    if (remainder == 0) {
        cout << "North\n";
    } else if (remainder == 1) {
        cout << "East\n";
    } else if (remainder == 2) {
        cout << "South\n";
    } else { // remainder == 3
        cout << "West\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of testcases

    // Loop through each testcase
    while (t--) {
        solve(); // Call the solve function for the current testcase
    }

    return 0; // Indicate successful execution
}