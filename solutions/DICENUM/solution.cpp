#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector, algorithm

// Using namespace std; is common in competitive programming to avoid std:: prefix
using namespace std;

// Function to solve a single test case
void solve() {
    // Declare vectors to store Alice's and Bob's dice rolls
    vector<int> alice_rolls(3);
    vector<int> bob_rolls(3);

    // Read Alice's three dice rolls
    cin >> alice_rolls[0] >> alice_rolls[1] >> alice_rolls[2];
    // Read Bob's three dice rolls
    cin >> bob_rolls[0] >> bob_rolls[1] >> bob_rolls[2];

    // Sort Alice's rolls in descending order to form the largest possible number.
    // rbegin() and rend() provide reverse iterators, which makes std::sort
    // arrange elements from largest to smallest.
    sort(alice_rolls.rbegin(), alice_rolls.rend());
    // Calculate Alice's score: The largest digit goes to the hundreds place,
    // the second largest to the tens place, and the smallest to the units place.
    int alice_score = alice_rolls[0] * 100 + alice_rolls[1] * 10 + alice_rolls[2];

    // Sort Bob's rolls in descending order using the same logic.
    sort(bob_rolls.rbegin(), bob_rolls.rend());
    // Calculate Bob's score.
    int bob_score = bob_rolls[0] * 100 + bob_rolls[1] * 10 + bob_rolls[2];

    // Compare the calculated scores to determine the winner or a tie.
    if (alice_score > bob_score) {
        cout << "Alice\n"; // Alice wins if her score is higher
    } else if (bob_score > alice_score) {
        cout << "Bob\n";   // Bob wins if his score is higher
    } else {
        cout << "Tie\n";   // It's a tie if scores are equal
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) disables synchronization with C's stdio library,
    // which can speed up I/O operations.
    // cin.tie(NULL) unties cin from cout, meaning cin will not flush cout before reading input,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}