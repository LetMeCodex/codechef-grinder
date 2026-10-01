#include <bits/stdc++.h> // Includes most standard libraries, providing access to common functions and data structures.

using namespace std; // Uses the standard namespace to avoid repeatedly writing std::.

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables to store the number of votes obtained by Dhoni, Rohit, and Kohli.
    // A for Dhoni, B for Rohit, C for Kohli.
    int A, B, C;

    // Read the three space-separated integers (vote counts) from standard input.
    cin >> A >> B >> C;

    // To determine if Dhoni won the poll, we need to check if his votes (A) are strictly
    // greater than the votes of both other players (B and C).
    // The problem guarantees that no two players received the same number of votes,
    // so we don't need to consider equality (e.g., A >= B).
    if (A > B && A > C) {
        // If Dhoni's votes are greater than both Rohit's and Kohli's votes, Dhoni won.
        // Print "Yes" followed by a newline character.
        cout << "Yes\n";
    } else {
        // Otherwise, Dhoni did not receive the maximum number of votes.
        // Print "No" followed by a newline character.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}