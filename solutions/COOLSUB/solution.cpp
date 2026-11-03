#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map> // Changed to unordered_map for better average time complexity

void solve() {
    int N;
    std::cin >> N;
    std::unordered_map<int, int> counts; // Using unordered_map for O(1) average time complexity
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        counts[val]++;
    }

    // Constraint: 1 <= K < N.
    // If N=1, it's impossible to satisfy K < N.
    if (N == 1) {
        std::cout << -1 << "\n";
        return;
    }

    // We look for the simplest cool subsequence: S = [X] (length K=1).
    // For S=[X] to be cool, its only non-empty subsequence [X] must have its average (which is X)
    // present in the complement subsequence S^c.
    // This means that if we pick one X for S, there must be at least one other X remaining in the array A
    // to be part of S^c.
    // In other words, X must appear at least twice in the original array A.

    int cool_element = -1;
    for (auto const& [val, count] : counts) {
        if (count >= 2) {
            cool_element = val; // Found a number that appears at least twice
            break;             // We only need one such number
        }
    }

    if (cool_element != -1) {
        // If we found such an X, then S=[X] is a cool subsequence.
        // Its length is 1, which satisfies 1 <= K < N (since N >= 2).
        std::cout << 1 << "\n";
        std::cout << cool_element << "\n";
    } else {
        // If no number appears at least twice, it means all elements in A are distinct.
        // As reasoned above, for any element s_i chosen for S, s_i must also be present in S^c.
        // If all elements in A are distinct, then each s_i appears only once in A.
        // If s_i is chosen for S, it cannot be in S^c.
        // Therefore, if all elements are distinct, no cool subsequence can exist.
        std::cout << -1 << "\n";
    }
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