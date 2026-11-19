#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of races

    // Process Alice's times
    // We need to calculate the sum of her times and find her maximum time.
    // Alice will optimally discard her largest time.
    long long sumA = 0; // Use long long for sums to be safe, though int is sufficient for given constraints (max 100*1000 = 100,000)
    int maxA = 0;       // Stores the maximum time for Alice. Initialized to 0 as times are >= 1.
    for (int i = 0; i < N; ++i) {
        int time;
        cin >> time; // Read Alice's time for the current race
        sumA += time; // Add to total sum
        if (time > maxA) {
            maxA = time; // Update maximum time if current time is greater
        }
    }

    // Process Bob's times
    // Similar to Alice, calculate sum and find maximum time for Bob.
    long long sumB = 0;
    int maxB = 0;
    for (int i = 0; i < N; ++i) {
        int time;
        cin >> time; // Read Bob's time for the current race
        sumB += time; // Add to total sum
        if (time > maxB) {
            maxB = time; // Update maximum time if current time is greater
        }
    }

    // Calculate optimal scores for Alice and Bob
    // Each player's effective score is their total sum minus their largest single race time.
    long long alice_score = sumA - maxA;
    long long bob_score = sumB - maxB;

    // Compare the optimal scores to determine the winner
    if (alice_score < bob_score) {
        cout << "Alice\n"; // Alice wins if her score is smaller
    } else if (bob_score < alice_score) {
        cout << "Bob\n";   // Bob wins if his score is smaller
    } else {
        cout << "Draw\n";  // It's a draw if scores are equal
    }
}

int main() {
    // Fast I/O setup for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}