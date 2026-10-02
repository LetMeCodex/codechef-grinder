#include <bits/stdc++.h> // Includes necessary headers like iostream and algorithm

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Declare variables to store the scores for each attempt in the three rounds.
    int A1, A2, B1, B2, C1, C2;

    // Read the six scores from the standard input.
    std::cin >> A1 >> A2 >> B1 >> B2 >> C1 >> C2;

    // Calculate the best score for Round 1 (Squat) by taking the maximum of A1 and A2.
    int round1_score = std::max(A1, A2);

    // Calculate the best score for Round 2 (Bench Press) by taking the maximum of B1 and B2.
    int round2_score = std::max(B1, B2);

    // Calculate the best score for Round 3 (Deadlift) by taking the maximum of C1 and C2.
    int round3_score = std::max(C1, C2);

    // Calculate the total score by summing the best scores from all three rounds.
    int total_score = round1_score + round2_score + round3_score;

    // Print the calculated total score to the standard output, followed by a newline character.
    std::cout << total_score << "\n";

    return 0; // Indicate successful execution.
}