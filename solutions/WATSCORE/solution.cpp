#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int N; // Number of submissions
    std::cin >> N;

    // Create a vector to store the maximum score for each problem.
    // Problems are 1-indexed (1 to 11). Scorable problems are 1 to 8.
    // We'll use an array of size 9, where index 0 is unused, and indices 1-8
    // store the max scores for problems 1-8 respectively.
    // Initialize all scores to 0.
    std::vector<int> max_scores(9, 0); 

    // Process each submission
    for (int i = 0; i < N; ++i) {
        int p, s; // Problem number and score
        std::cin >> p >> s;

        // Check if the problem is scorable (problems 1 through 8)
        if (p >= 1 && p <= 8) {
            // Update the maximum score for this problem if the current submission's score is higher
            max_scores[p] = std::max(max_scores[p], s);
        }
        // Submissions for problems 9, 10, 11 are ignored as they are non-scorable.
    }

    // Calculate the total score by summing up the best scores for scorable problems
    long long total_score = 0; // Use long long for total_score, though int is sufficient given constraints (max 8*100 = 800)
    for (int i = 1; i <= 8; ++i) { // Iterate through scorable problems (1 to 8)
        total_score += max_scores[i];
    }

    // Print the total score for the current test case
    std::cout << total_score << std::endl;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) { // Loop T times, decrementing T each time
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}