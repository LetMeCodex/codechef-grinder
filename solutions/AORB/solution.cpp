#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the time required to solve problems A and B
    std::cin >> X >> Y;

    // Calculate points if Chef attempts Problem A first, then Problem B.
    // Problem A is submitted after X minutes. Points: 500 - (X * 2)
    // Problem B is submitted after X + Y minutes. Points: 1000 - ((X + Y) * 4)
    // Total points for this order: (500 - 2*X) + (1000 - 4*(X + Y))
    // Simplified formula: 1500 - 6*X - 4*Y
    int score_A_first = 1500 - 6 * X - 4 * Y;

    // Calculate points if Chef attempts Problem B first, then Problem A.
    // Problem B is submitted after Y minutes. Points: 1000 - (Y * 4)
    // Problem A is submitted after Y + X minutes. Points: 500 - ((Y + X) * 2)
    // Total points for this order: (1000 - 4*Y) + (500 - 2*(Y + X))
    // Simplified formula: 1500 - 2*X - 6*Y
    int score_B_first = 1500 - 2 * X - 6 * Y;

    // The maximum points Chef can score is the maximum of these two possibilities.
    std::cout << std::max(score_A_first, score_B_first) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}