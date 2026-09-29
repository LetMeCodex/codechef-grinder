#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions
using namespace std;       // Uses the standard namespace, as per problem instructions

// Function to calculate a player's score based on three dice rolls
int calculate_player_score(int r1, int r2, int r3) {
    // The score is the sum of the two highest rolls.
    // This can be calculated by summing all three rolls and subtracting the minimum roll.
    int total_sum = r1 + r2 + r3;
    int min_roll = min({r1, r2, r3}); // Using initializer list for min (C++11 feature)
    return total_sum - min_roll;
}

void solve() {
    int A1, A2, A3, B1, B2, B3;
    // Read Alice's three rolls and Bob's three rolls
    cin >> A1 >> A2 >> A3 >> B1 >> B2 >> B3;

    // Calculate Alice's score
    int alice_score = calculate_player_score(A1, A2, A3);

    // Calculate Bob's score
    int bob_score = calculate_player_score(B1, B2, B3);

    // Determine the winner or if it's a tie
    if (alice_score > bob_score) {
        cout << "Alice\n";
    } else if (bob_score > alice_score) {
        cout << "Bob\n";
    } else {
        cout << "Tie\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}