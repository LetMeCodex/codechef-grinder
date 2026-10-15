#include <bits/stdc++.h> // Standard header for competitive programming

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B; // Alice's and Bob's initial scores
    cin >> A >> B;

    // Alice needs to end with at least 10 points more than Bob.
    // Bob's score remains B as Alice prevents him from scoring.
    // So, Alice's final score A_final must satisfy A_final >= B + 10.
    int target_alice_score = B + 10;

    // Calculate how many additional points Alice needs to score.
    // If Alice's current score A is already >= target_alice_score,
    // then points_needed will be 0 or negative.
    int points_needed = target_alice_score - A;

    // If points_needed is 0 or negative, Alice already has a dominant victory
    // or needs no additional points. So, 0 shots are needed.
    if (points_needed <= 0) {
        cout << 0 << "\n";
    } else {
        // Alice needs to score 'points_needed' additional points.
        // To minimize the number of shots, she should maximize points per shot.
        // Each shot can score 2 or 3 points. So, she should aim for 3 points per shot.
        // The minimum number of shots 'k' required to score at least 'P' points
        // (where P = points_needed) is ceil(P / 3).
        // In integer arithmetic, ceil(X / Y) for positive integers X and Y
        // can be calculated as (X + Y - 1) / Y.
        // Here, Y = 3, so it's (points_needed + 3 - 1) / 3 = (points_needed + 2) / 3.
        int shots = (points_needed + 2) / 3;
        cout << shots << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}