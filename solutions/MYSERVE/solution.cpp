#include <bits/stdc++.h> // Includes iostream and other standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int P, Q; // Declare integer variables P and Q for Alice's and Bob's scores
        cin >> P >> Q; // Read Alice's and Bob's scores for the current test case

        // Calculate the total number of points scored so far.
        int total_points_scored = P + Q;

        // The problem asks whose serve it is *now*, which means who will make the *next* serve.
        // If 'total_points_scored' points have been completed, the next serve will be the
        // (total_points_scored + 1)-th serve in the match sequence.
        int next_serve_index = total_points_scored + 1;

        // The serving pattern is: Alice (1st, 2nd), Bob (3rd, 4th), Alice (5th, 6th), Bob (7th, 8th), etc.
        // This is a cycle of 4 serves.
        // We can determine the server by looking at (next_serve_index - 1) modulo 4.
        // (next_serve_index - 1) is used to make it 0-indexed for modulo operation.
        //
        // If (next_serve_index - 1) % 4 is:
        // 0: Corresponds to 1st, 5th, 9th serves (Alice)
        // 1: Corresponds to 2nd, 6th, 10th serves (Alice)
        // 2: Corresponds to 3rd, 7th, 11th serves (Bob)
        // 3: Corresponds to 4th, 8th, 12th serves (Bob)
        
        int remainder = (next_serve_index - 1) % 4;

        // If the remainder is 0 or 1, it's Alice's serve.
        if (remainder == 0 || remainder == 1) {
            cout << "Alice\n";
        } else { // Otherwise, the remainder must be 2 or 3, so it's Bob's serve.
            cout << "Bob\n";
        }
    }

    return 0; // Indicate successful execution
}