#include <iostream> // Required for standard input/output operations (cin, cout)

// It's good practice to use `long long` for scores to prevent potential overflow,
// although for N up to 10^5, the maximum score (649993) fits within a 32-bit signed integer.

void solve() {
    int N;
    std::cin >> N; // Read the number of rounds for the current test case
    
    long long score = 0; // Initialize score to 0. Using long long for safety.
    
    // The optimal strategy is to alternate between rolling a 1 and a 6.
    // A sequence like [1, 6] yields a score of 1 (for the first roll) + 2*6 (for the second roll, since previous was 1) = 1 + 12 = 13.
    // This pair [1, 6] is the most efficient way to get points per two rolls.
    // Any other pair [A, B]:
    // - If A=1, B!=6: [1, B] gives 1 + 2*B. Max B is 5, gives 1+10=11. Less than 13.
    // - If A!=1: [A, B] gives A + B. Max A=6, B=6, gives 6+6=12. Less than 13.
    // So, [1, 6] is indeed the best 2-roll sequence.
    
    // Calculate how many full [1, 6] pairs can be formed.
    int num_pairs = N / 2;
    
    // Each pair contributes 13 to the score.
    score = (long long)num_pairs * 13;
    
    // If N is odd, there's one roll remaining after forming all possible [1, 6] pairs.
    // The sequence would look like [1, 6, 1, 6, ..., 1, 6, X].
    // The last roll X would be preceded by a 6 (the second roll of the last [1, 6] pair).
    // Since the previous roll was 6 (not 1), the last roll X will contribute X to the score, not 2*X.
    // To maximize this, we choose X=6.
    if (N % 2 == 1) {
        score += 6; // Add 6 for the last remaining roll
    }
    
    std::cout << score << "\n"; // Output the maximum possible score
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}