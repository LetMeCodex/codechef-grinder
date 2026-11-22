#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    long long total_smileys = 0; // Use long long for safety, though int is sufficient for N <= 10^5
    int last_colon_pos = -1; // Stores the index of the last encountered colon.
                             // -1 indicates no active starting colon (e.g., after an '(').
    int current_right_parentheses_count = 0; // Counts consecutive ')' characters
                                             // immediately following 'last_colon_pos'.

    for (int i = 0; i < N; ++i) {
        if (S[i] == '(') {
            // An opening parenthesis breaks any potential smiley sequence.
            // Reset last_colon_pos to indicate no active starting colon.
            last_colon_pos = -1;
            current_right_parentheses_count = 0;
        } else if (S[i] == ')') {
            // A closing parenthesis can be part of a smiley.
            // Only count it if there's an active starting colon.
            if (last_colon_pos != -1) {
                current_right_parentheses_count++;
            }
            // If last_colon_pos is -1, this ')' is not preceded by a colon
            // that could start a smiley, so current_right_parentheses_count remains 0.
        } else if (S[i] == ':') {
            // A colon can be the end of a Schrödinger's Smiley.
            // Check if there's an active starting colon and a positive number of ')'s in between.
            if (last_colon_pos != -1 && current_right_parentheses_count > 0) {
                total_smileys++;
            }
            
            // This current colon now becomes the new potential starting colon.
            last_colon_pos = i;
            // Reset the count of ')' because any ')'s after this colon would start a new sequence.
            current_right_parentheses_count = 0;
        }
    }

    std::cout << total_smileys << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}