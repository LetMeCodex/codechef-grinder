#include <iostream> // Required for cin and cout

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of testcases
    std::cin >> T; // Read the number of testcases

    while (T--) { // Loop T times for each testcase
        int N, X, P; // Declare variables for total questions, correct answers, and passing marks
        std::cin >> N >> X >> P; // Read N, X, P for the current testcase

        // Calculate Chef's total score
        // Score from correct answers: X * 3
        // Score from incorrect answers: (N - X) * (-1)
        // Total Score = (X * 3) + ((N - X) * -1)
        // Simplified: Total Score = 3X - N + X = 4X - N
        int chef_score = (X * 3) - ((N - X) * 1); 
        // Alternatively, using the simplified formula: int chef_score = (4 * X) - N;

        // Check if Chef's score is greater than or equal to the passing marks P
        if (chef_score >= P) {
            std::cout << "PASS\n"; // If score is sufficient, print PASS
        } else {
            std::cout << "FAIL\n"; // Otherwise, print FAIL
        }
    }

    return 0; // Indicate successful execution
}