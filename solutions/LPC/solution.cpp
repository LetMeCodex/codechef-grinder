#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, algorithm

// Function to calculate the minimum moves to change digit d1 to d2
// Digits are cyclic (0-9).
int calculate_cost(char d1_char, char d2_char) {
    // Convert character digits to integer digits
    int d1 = d1_char - '0';
    int d2 = d2_char - '0';

    // Calculate the absolute difference
    int diff = abs(d1 - d2);

    // The cost is the minimum of moving directly (diff) or cyclically (10 - diff)
    return std::min(diff, 10 - diff);
}

// Function to solve a single test case
void solve() {
    int N, M;
    std::cin >> N >> M; // Read lengths of S and K
    std::string S, K;
    std::cin >> S >> K; // Read strings S and K

    // Initialize minimum total moves to a very large value.
    // The maximum possible moves for M=10 is 10 * 5 = 50, so 1e9 is a safe upper bound.
    int min_total_moves = 1e9; 

    // Iterate through all possible starting positions for K in S.
    // A substring of length M starting at index i will occupy S[i] through S[i + M - 1].
    // The last possible starting index i is when i + M - 1 = N - 1,
    // which means i = N - M.
    for (int i = 0; i <= N - M; ++i) {
        int current_total_moves = 0; // Moves for the current substring S[i...i+M-1]

        // Calculate moves required to transform S[i...i+M-1] into K
        for (int j = 0; j < M; ++j) {
            // S[i+j] is the j-th character of the current substring of S
            // K[j] is the j-th character of the secret code K
            current_total_moves += calculate_cost(S[i + j], K[j]);
        }
        
        // Update the overall minimum total moves found so far
        min_total_moves = std::min(min_total_moves, current_total_moves);
    }

    // Output the minimum number of moves for this test case
    std::cout << min_total_moves << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}