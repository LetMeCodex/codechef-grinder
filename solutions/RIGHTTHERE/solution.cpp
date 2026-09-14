#include <bits/stdc++.h> // Includes most standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, X; // Declare variables for the total number of people (N) and hall capacity (X)
        cin >> N >> X; // Read N and X for the current test case

        // Chef can host the party if the number of people N is less than or equal to the hall's capacity X.
        if (N <= X) {
            cout << "YES\n"; // If N is less than or equal to X, output YES
        } else {
            cout << "NO\n"; // Otherwise (if N is greater than X), output NO
        }
    }

    return 0; // Indicate successful execution
}