#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::max and std::min

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N;
    std::string A, B;
    std::cin >> A >> B;

    // Use arrays for character counts as the alphabet size is fixed (26 lowercase English letters).
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    std::vector<int> countA(26, 0);
    std::vector<int> countB(26, 0);

    // Count character frequencies for string A
    for (char c : A) {
        countA[c - 'a']++;
    }
    // Count character frequencies for string B
    for (char c : B) {
        countB[c - 'a']++;
    }

    // The minimum LCS length is the maximum of min(countA[c], countB[c]) for all characters c.
    int min_lcs_length = 0;
    for (int i = 0; i < 26; ++i) {
        min_lcs_length = std::max(min_lcs_length, std::min(countA[i], countB[i]));
    }

    std::cout << min_lcs_length << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}