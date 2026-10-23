#include <iostream> // Use iostream specifically for minimal includes

// It's generally good practice to avoid 'using namespace std;' in headers
// or large projects, but for competitive programming, it's common and acceptable.
// For this minimal code, we can explicitly use std:: for clarity.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a crucial competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int R1, W1, C1; // Stats for player A: Runs, Wickets, Catches
        std::cin >> R1 >> W1 >> C1; // Read player A's stats

        int R2, W2, C2; // Stats for player B: Runs, Wickets, Catches
        std::cin >> R2 >> W2 >> C2; // Read player B's stats

        int a_wins = 0; // Counter for how many stats player A is better in

        // Compare Runs
        if (R1 > R2) {
            a_wins++; // Player A is better in runs
        }
        // Since R1 != R2 is guaranteed, if R1 is not greater than R2, then R2 must be greater than R1.
        // We don't need to explicitly count B's wins; we can infer it from A's wins.

        // Compare Wickets
        if (W1 > W2) {
            a_wins++; // Player A is better in wickets
        }
        // Since W1 != W2 is guaranteed, if W1 is not greater than W2, then W2 must be greater than W1.

        // Compare Catches
        if (C1 > C2) {
            a_wins++; // Player A is better in catches
        }
        // Since C1 != C2 is guaranteed, if C1 is not greater than C2, then C2 must be greater than C1.

        // Determine the overall better player based on the majority of stats
        // There are 3 stats. If A wins 2 or 3 stats, A is better.
        // If A wins 0 or 1 stats, B is better.
        if (a_wins >= 2) { // Player A is better in 2 or 3 stats
            std::cout << "A\n"; // Player A is better overall
        } else { // Player A is better in 0 or 1 stats, meaning B is better in 2 or 3 stats
            std::cout << "B\n"; // Player B is better overall
        }
    }

    return 0; // Indicate successful execution
}