#include <iostream> // Required for standard input/output operations (cin, cout)

// Function to solve a single test case
void solve() {
    int A, B, C, P, Q, R;
    // Read the six integers for the current test case
    std::cin >> A >> B >> C >> P >> Q >> R;

    // Calculate the total number of votes cast across all three cities.
    // This value remains constant regardless of hacking.
    int total_votes_cast = P + Q + R;

    // --- Scenario 1: Chef hacks no EVM ---
    // Chef's votes are the sum of initial votes from all cities.
    int chef_votes_no_hack = A + B + C;
    // Check if Chef wins in this scenario: strictly more than half total votes.
    // Using 2 * chef_votes > total_votes_cast avoids floating-point arithmetic.
    if (2 * chef_votes_no_hack > total_votes_cast) {
        std::cout << "YES\n"; // If Chef wins, print YES and we are done for this test case.
        return;
    }

    // --- Scenario 2: Chef hacks EVM 1 ---
    // Chef gets all votes from city 1 (P), plus initial votes from city 2 (B) and city 3 (C).
    int chef_votes_hack_1 = P + B + C;
    if (2 * chef_votes_hack_1 > total_votes_cast) {
        std::cout << "YES\n";
        return;
    }

    // --- Scenario 3: Chef hacks EVM 2 ---
    // Chef gets initial votes from city 1 (A), all votes from city 2 (Q), and initial votes from city 3 (C).
    int chef_votes_hack_2 = A + Q + C;
    if (2 * chef_votes_hack_2 > total_votes_cast) {
        std::cout << "YES\n";
        return;
    }

    // --- Scenario 4: Chef hacks EVM 3 ---
    // Chef gets initial votes from city 1 (A), initial votes from city 2 (B), and all votes from city 3 (R).
    int chef_votes_hack_3 = A + B + R;
    if (2 * chef_votes_hack_3 > total_votes_cast) {
        std::cout << "YES\n";
        return;
    }

    // If none of the above scenarios resulted in Chef winning, then Chef cannot win.
    std::cout << "NO\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful program execution
}