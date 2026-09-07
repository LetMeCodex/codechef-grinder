#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X; // Declare variable for the amount of water Chef drank
        cin >> X; // Read the amount of water X

        // The doctor advised Chef to drink at least 2000 ml of water.
        // We check if the amount X Chef drank is greater than or equal to 2000.
        if (X >= 2000) {
            cout << "YES\n"; // If Chef drank 2000 ml or more, print YES
        } else {
            cout << "NO\n"; // Otherwise (if Chef drank less than 2000 ml), print NO
        }
    }

    return 0; // Indicate successful execution
}