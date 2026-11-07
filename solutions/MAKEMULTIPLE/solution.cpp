#include <bits/stdc++.h> // Includes all standard libraries, common in competitive programming
using namespace std;       // Brings all names from std namespace into the global scope

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams
    cin.tie(NULL);                     // Untie cin from cout, preventing flush operations

    int t; // Variable to store the number of test cases
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        long long a, b; // Declare A and B as long long to handle values up to 10^9
                          // and potential intermediate calculations like 2*A without overflow.
        cin >> a >> b; // Read A and B for the current test case

        // The core logic derived from the analysis:
        // The answer is YES if (A = B) OR (B >= 2A).
        // Otherwise, the answer is NO.
        if (a == b || b >= 2 * a) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful execution
}