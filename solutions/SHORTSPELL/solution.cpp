#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common in competitive programming

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    int delete_idx = -1;

    // Iterate from the beginning of the string to find the first character S[i]
    // that is greater than the character immediately following it, S[i+1].
    // If such an 'i' is found, deleting S[i] will result in the lexicographically smallest string.
    // This is because replacing S[i] with S[i+1] (which is smaller) at the earliest possible position
    // makes the string lexicographically smaller than any other deletion strategy.
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] > s[i+1]) {
            delete_idx = i;
            break; // Found the optimal character to delete, no need to check further
        }
    }

    // If the loop completes and delete_idx is still -1, it means the string was
    // already sorted in non-decreasing order (e.g., "aab", "xxyy").
    // In this case, to obtain the lexicographically smallest string, we should
    // delete the last character. This preserves the longest possible lexicographically
    // smallest prefix (S[0...N-2]).
    if (delete_idx == -1) {
        delete_idx = n - 1;
    }

    // Print the resulting string by skipping the character at delete_idx.
    for (int i = 0; i < n; ++i) {
        if (i != delete_idx) {
            std::cout << s[i];
        }
    }
    std::cout << "\n"; // Newline after each test case output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}