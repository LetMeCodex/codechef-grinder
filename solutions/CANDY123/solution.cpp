#include <bits/stdc++.h> // Includes iostream and other standard libraries

// Using namespace std; for convenience as requested
using namespace std;

void solve() {
    int A, B;
    cin >> A >> B; // Read A (Limak's capacity) and B (Bob's capacity) for the current test case

    int current_limak_candies = 0; // Total candies Limak has eaten so far
    int current_bob_candies = 0;   // Total candies Bob has eaten so far
    int turn = 1;                  // Current turn number (1, 2, 3, ...)

    while (true) { // The game continues until a player loses
        if (turn % 2 != 0) { // Limak's turn (odd turn number: 1, 3, 5, ...)
            // Check if Limak can eat 'turn' candies without exceeding his total capacity A
            if (current_limak_candies + turn <= A) {
                current_limak_candies += turn; // Limak eats the candies
            } else {
                // Limak cannot eat 'turn' candies, so he loses. Bob wins.
                cout << "Bob\n";
                return; // End the game for this test case
            }
        } else { // Bob's turn (even turn number: 2, 4, 6, ...)
            // Check if Bob can eat 'turn' candies without exceeding his total capacity B
            if (current_bob_candies + turn <= B) {
                current_bob_candies += turn; // Bob eats the candies
            } else {
                // Bob cannot eat 'turn' candies, so he loses. Limak wins.
                cout << "Limak\n";
                return; // End the game for this test case
            }
        }
        turn++; // Move to the next turn
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}