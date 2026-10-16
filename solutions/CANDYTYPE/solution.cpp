#include <bits/stdc++.h> // Includes all standard libraries, as requested

void solve() {
    int N;
    std::cin >> N; // Read the number of candies

    // Create a vector to store frequencies of candy colours.
    // Size N+1 to use 1-based indexing for colours (from 1 to N).
    // Initialize all counts to 0.
    std::vector<int> counts(N + 1, 0);

    // Read N candy colours and update their frequencies
    for (int i = 0; i < N; ++i) {
        int color;
        std::cin >> color;
        counts[color]++; // Increment count for the current colour
    }

    int max_freq = 0;       // Stores the maximum frequency found so far
    int result_color = -1;  // Stores the colour with the maximum frequency (smallest in case of tie)

    // Iterate through possible colours from 1 to N
    // This iteration order is crucial for correctly handling the tie-breaking rule
    // (smallest colour in case of a tie).
    for (int color = 1; color <= N; ++color) {
        if (counts[color] > max_freq) {
            // If current colour has a higher frequency, update max_freq and result_color
            max_freq = counts[color];
            result_color = color;
        }
        // If counts[color] == max_freq, we do nothing.
        // This is because we want the *smallest* colour in case of a tie.
        // Since we iterate 'color' in increasing order (1, 2, 3, ...),
        // 'result_color' will already hold the smallest colour encountered so far
        // that has 'max_freq'. Any subsequent 'color' with the same 'max_freq'
        // would be larger, so we don't update 'result_color'.
    }

    std::cout << result_color << "\n"; // Output the result
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}