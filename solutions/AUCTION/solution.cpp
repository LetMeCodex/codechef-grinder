#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B, C; // Declare integer variables for Alice's, Bob's, and Charlie's bids.
        cin >> A >> B >> C; // Read the three bids for the current test case.

        // Determine the winner based on the highest bid.
        // Since A, B, C are distinct, there will always be a unique highest bid.
        if (A > B && A > C) {
            // If Alice's bid is greater than both Bob's and Charlie's, Alice wins.
            cout << "Alice\n";
        } else if (B > A && B > C) {
            // Else if Bob's bid is greater than both Alice's and Charlie's, Bob wins.
            cout << "Bob\n";
        } else {
            // Otherwise (if neither Alice nor Bob has the highest bid), Charlie must have the highest bid.
            cout << "Charlie\n";
        }
    }

    return 0; // Indicate successful program execution.
}