#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void solve() {
    int N;
    std::cin >> N; // Read the length of the permutation

    // We need to find the maximum value P_i such that P_i != i.
    // If all P_i == i, then max_misplaced_val will remain 0.
    int max_misplaced_val = 0; 
    bool is_sorted = true; // Flag to check if the permutation is sorted

    // Read the permutation and find max_misplaced_val
    // Using 1-based indexing for P_i == i comparison
    for (int i = 1; i <= N; ++i) {
        int P_val;
        std::cin >> P_val;
        if (P_val != i) {
            is_sorted = false;
            if (P_val > max_misplaced_val) {
                max_misplaced_val = P_val;
            }
        }
    }

    if (is_sorted) {
        // If the permutation is already sorted, no operations are needed.
        // The minimum non-negative K is 0.
        std::cout << 0 << "\n";
    } else {
        // If the permutation is not sorted, we need to connect all elements
        // that are not in their correct positions.
        // Let M be the maximum value P_i such that P_i != i.
        // To connect all such elements, we need to ensure that M can be moved.
        // The smallest value M can swap with is 1. So we need K >= M + 1.
        // If K = M + 1, then any value X (where X <= M) can swap with 1 (since X+1 <= M+1 = K).
        // This means all misplaced values are connected to 1 (which is either a misplaced value itself
        // or a fixed point available as a hub), and thus all misplaced values are connected to each other.
        // This is sufficient to sort the permutation.
        std::cout << max_misplaced_val + 1 << "\n";
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