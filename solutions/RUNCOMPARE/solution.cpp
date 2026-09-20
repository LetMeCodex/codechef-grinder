#include <bits/stdc++.h> // Includes iostream, vector, etc.

// It's common practice in competitive programming to use the entire std namespace
// for brevity in single-file solutions.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of days

    // Vectors to store distances for Alice and Bob
    vector<int> A(N);
    vector<int> B(N);

    // Read Alice's distances
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // Read Bob's distances
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int happy_days_count = 0; // Initialize counter for days both are happy

    // Iterate through each day to check happiness conditions
    for (int i = 0; i < N; ++i) {
        // Alice is happy if Bob's distance is NOT strictly more than twice her distance.
        // This means B[i] <= 2 * A[i]
        bool alice_happy = (B[i] <= 2 * A[i]);
        
        // Bob is happy if Alice's distance is NOT strictly more than twice his distance.
        // This means A[i] <= 2 * B[i]
        bool bob_happy = (A[i] <= 2 * B[i]);

        // If both are happy on this day, increment the counter
        if (alice_happy && bob_happy) {
            happy_days_count++;
        }
    }

    // Output the total count of days where both were happy
    cout << happy_days_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}