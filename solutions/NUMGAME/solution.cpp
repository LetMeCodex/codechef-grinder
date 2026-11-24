#include <bits/stdc++.h> // As requested

// Using namespace std; as requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        cin >> n; // Read N for each test case

        // The game outcome depends only on the parity of N.
        //
        // If N is even:
        // Alice can always subtract 1 (which is a proper divisor for any N > 1).
        // This move leads to N-1, which is an odd number.
        // As proven by induction, all odd numbers are losing positions.
        // Since Alice can move to a losing position, N is a winning position for Alice.
        // (For N=2, Alice subtracts 1 to get 1. 1 is a losing position. Alice wins.)
        //
        // If N is odd:
        // Any proper divisor 'd' of an odd number N must also be odd.
        // Subtracting an odd divisor 'd' from an odd N results in N-d, which is an even number.
        // As proven by induction, all even numbers are winning positions.
        // Since all possible moves from N lead to winning positions, N is a losing position for Alice.
        // (For N=1, Alice cannot make a move and loses. Bob wins.)
        //
        // Therefore:
        // If N is even, Alice wins.
        // If N is odd, Bob wins.

        if (n % 2 == 0) {
            cout << "ALICE\n";
        } else {
            cout << "BOB\n";
        }
    }

    return 0;
}