#include <iostream> // Required for std::cin, std::cout, std::endl
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int N, S;
    // Read N and S for the current test case
    std::cin >> N >> S;

    // k_min represents the minimum number of dice that must have chosen '6'
    // in the first step (for replacement).
    // To minimize k, we want to maximize the sum from the (N-k) dice
    // that are NOT '6'. The maximum value for these dice is '5'.
    // So, the total sum S must satisfy:
    // S <= k * 6 (from k dice chosen as 6) + (N - k) * 5 (from N-k dice chosen as max 5)
    // S <= 6k + 5N - 5k
    // S <= k + 5N
    // This implies k >= S - 5N.
    // Also, k cannot be negative, so k >= 0.
    // Thus, k_min is the maximum of 0 and (S - 5N).
    int k_min = std::max(0, S - 5 * N);

    // The score in the second step is maximized by picking '6' from dice
    // where the original chosen value x_i was not '6', and '5' from dice
    // where the original chosen value x_i was '6'.
    // If k dice had x_i = 6, they contribute 5*k to the score.
    // If (N-k) dice had x_i < 6, they contribute 6*(N-k) to the score.
    // Total score = (k * 5) + ((N - k) * 6)
    //             = 5k + 6N - 6k
    //             = 6N - k.
    // To maximize this score, we need to minimize k.
    // So, we use k_min to calculate the maximum possible score.
    int max_score = 6 * N - k_min;

    // Output the maximum score for the current test case
    std::cout << max_score << std::endl;
}

int main() {
    // Optimize C++ standard streams for competitive programming
    // This unties cin from cout and disables synchronization with C stdio,
    // leading to faster input/output operations.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    // Read the number of test cases
    std::cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}