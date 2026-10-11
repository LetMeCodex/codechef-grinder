#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the string
    std::string S;
    std::cin >> S; // Read the string S

    // A boolean vector to keep track of characters encountered so far.
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    // Initialize all elements to false, meaning no character has been seen yet.
    std::vector<bool> seen(26, false); 
    bool found_duplicate = false; // Flag to indicate if any character appears at least twice

    // Iterate through each character in the string S
    for (char c : S) {
        // Calculate the index for the current character 'c' in the 'seen' array.
        // For example, 'a' - 'a' = 0, 'b' - 'a' = 1, etc.
        int char_idx = c - 'a';

        // Check if the current character 'c' has been seen before
        if (seen[char_idx]) {
            found_duplicate = true; // If yes, we found a character that appears at least twice
            break; // No need to check further, we've found what we need to determine the answer
        }
        // Mark the current character 'c' as seen
        seen[char_idx] = true;
    }

    // After checking all characters (or breaking early if a duplicate was found):
    if (found_duplicate) {
        // If a character appears at least twice, we can form a palindrome of length 2 (e.g., "cc").
        // This is the shortest possible palindrome of length greater than 1.
        // To maximize the length of the deleted subsequence, we must minimize the length
        // of the remaining palindrome. The minimum possible length for a palindrome > 1 is 2.
        // So, the length of the deleted subsequence will be N - 2.
        std::cout << N - 2 << "\n";
    } else {
        // If no duplicate character was found, it means all characters in S are unique.
        // A palindrome of length greater than 1 must contain at least one character that appears twice within itself.
        // For example, "aa", "aba", "racecar" all have characters appearing multiple times.
        // If all characters in S are unique, it's impossible to form such a palindrome as a subsequence,
        // because S itself does not contain any character twice.
        // Therefore, it's impossible to satisfy the conditions.
        std::cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation,
    // further improving I/O performance.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}