#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of players

    // Create a vector to store the messages received by each person.
    // A[i] corresponds to the message received by player (i+1).
    // Messages can be up to 10^9, so 'int' is sufficient (typically 32-bit, max ~2*10^9).
    std::vector<int> A(N); 
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Create a boolean vector to keep track of players who are potentially faulty.
    // is_faulty[i] will be true if player (i+1) is potentially faulty.
    // Initialize all to false.
    std::vector<bool> is_faulty(N, false);
    int faulty_players_count = 0; // Counter for the total number of unique faulty players

    // Iterate through adjacent pairs of messages.
    // A[i] is the message received by player (i+1).
    // A[i+1] is the message received by player (i+2).
    // The loop runs from i = 0 to N-2, covering all pairs (A[0],A[1]) through (A[N-2],A[N-1]).
    for (int i = 0; i < N - 1; ++i) {
        // If the message received by player (i+1) is different from
        // the message received by player (i+2), a discrepancy occurred.
        if (A[i] != A[i+1]) {
            // This discrepancy means either:
            // 1. Player (i+1) (0-indexed 'i') whispered wrongly.
            // 2. Player (i+2) (0-indexed 'i+1') misheard.
            // In either case, both players are potentially faulty.

            // Mark player (i+1) as faulty if not already marked.
            if (!is_faulty[i]) {
                is_faulty[i] = true;
                faulty_players_count++;
            }
            // Mark player (i+2) as faulty if not already marked.
            if (!is_faulty[i+1]) {
                is_faulty[i+1] = true;
                faulty_players_count++;
            }
        }
    }

    // Output the total count of unique players that could be faulty.
    std::cout << faulty_players_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}