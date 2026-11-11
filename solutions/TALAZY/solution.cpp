#include <iostream> // Required for std::cin, std::cout

// Function to solve a single test case
void solve() {
    long long N, B, M; // Use long long for N, B, M to handle large inputs and intermediate calculations
    std::cin >> N >> B >> M;

    long long current_N = N; // Remaining problems
    long long current_M = M; // Time per problem for the current phase
    long long total_time = 0; // Accumulator for total time

    // Loop until all problems are solved
    while (current_N > 0) {
        long long problems_to_solve_in_phase;

        // Determine how many problems to solve in this phase
        // If N is even, solve N/2 problems.
        // If N is odd, solve (N+1)/2 problems.
        if (current_N % 2 == 0) {
            problems_to_solve_in_phase = current_N / 2;
        } else {
            problems_to_solve_in_phase = (current_N + 1) / 2;
        }

        // Add time spent solving problems in this phase
        total_time += problems_to_solve_in_phase * current_M;

        // Update remaining problems
        current_N -= problems_to_solve_in_phase;

        // If there are still problems left, take a break and double the time per problem
        // No break is taken after the very last problem is finished.
        if (current_N > 0) {
            total_time += B; // Add break time
            current_M *= 2;   // Double time per problem for the next phase
        }
    }

    // Output the total time for the current test case
    std::cout << total_time << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        solve();
    }

    return 0; // Indicate successful execution
}