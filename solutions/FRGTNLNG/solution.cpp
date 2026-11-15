#include <bits/stdc++.h> // Includes iostream, vector, string, unordered_map, etc.

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K;

    // forgotten_words stores the dictionary words in their input order.
    // This is needed to output "YES/NO" for the i-th word correctly.
    std::vector<std::string> forgotten_words(N);
    
    // word_to_indices maps each unique forgotten word to a list of its indices
    // in the forgotten_words vector. This handles cases where the same word
    // might appear multiple times in the dictionary and each instance needs
    // to be tracked.
    std::unordered_map<std::string, std::vector<int>> word_to_indices;

    for (int i = 0; i < N; ++i) {
        std::cin >> forgotten_words[i];
        word_to_indices[forgotten_words[i]].push_back(i);
    }

    // found_status tracks whether the word at a specific index in forgotten_words
    // has been found in any modern phrase. Initialized to false.
    std::vector<bool> found_status(N, false);

    // Process K modern phrases
    for (int i = 0; i < K; ++i) {
        int L;
        std::cin >> L; // Number of words in the current phrase
        for (int j = 0; j < L; ++j) {
            std::string modern_word;
            std::cin >> modern_word;
            
            // Check if this modern word exists in our map of forgotten words
            auto it = word_to_indices.find(modern_word);
            if (it != word_to_indices.end()) {
                // If the modern_word is a forgotten word, mark all its occurrences
                // in the original dictionary as found.
                for (int idx : it->second) {
                    found_status[idx] = true;
                }
            }
        }
    }

    // Output the results for this test case
    for (int i = 0; i < N; ++i) {
        if (found_status[i]) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
        // Print a space after each token except the last one
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}