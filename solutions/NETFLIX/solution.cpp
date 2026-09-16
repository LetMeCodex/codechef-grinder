#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int A, B, C, X; // Variables to store Alice's, Bob's, Charlie's money and Netflix cost
        cin >> A >> B >> C >> X; // Read the four integers for the current test case

        // Check if any two of them can contribute enough money to buy the subscription.
        // There are three possible pairs: (Alice, Bob), (Alice, Charlie), (Bob, Charlie).
        // If the sum of money for any pair is greater than or equal to the subscription cost X,
        // then they can afford it.
        if ((A + B >= X) || (A + C >= X) || (B + C >= X)) {
            cout << "YES\n"; // Output YES if at least one pair can afford it
        } else {
            cout << "NO\n"; // Output NO otherwise
        }
    }

    return 0; // Indicate successful execution
}