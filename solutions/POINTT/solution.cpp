#include <bits/stdc++.h> // Includes iostream and many other useful headers

// Using namespace std as requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables for scores
    int X, Y, A, B;

    // Read input: Alice's primary (X) and secondary (Y) scores,
    // Bob's primary (A) and secondary (B) scores.
    cin >> X >> Y >> A >> B;

    // Determine the winner based on the rules:
    // 1. Compare primary scores
    if (X > A) {
        // Alice's primary score is strictly greater than Bob's. Alice wins.
        cout << "Alice\n";
    } else if (A > X) {
        // Bob's primary score is strictly greater than Alice's. Bob wins.
        cout << "Bob\n";
    } else {
        // Primary scores are equal (X == A). Proceed to compare secondary scores.
        // 2. Compare secondary scores
        if (Y > B) {
            // Alice's secondary score is strictly greater than Bob's. Alice wins.
            cout << "Alice\n";
        } else if (B > Y) {
            // Bob's secondary score is strictly greater than Alice's. Bob wins.
            cout << "Bob\n";
        } else {
            // Both primary and secondary scores are equal (X == A and Y == B).
            // 3. Apply tiebreaker rule: Alice wins.
            cout << "Alice\n";
        }
    }

    return 0;
}