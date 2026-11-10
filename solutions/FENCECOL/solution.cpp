#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::min, std::max

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the number of fences

    // freq vector to store the frequency of each colour.
    // Since colours are 1-indexed up to N, size N+1 is appropriate.
    // Initialized to all zeros.
    std::vector<int> freq(n + 1, 0); 
    
    int count_not_1 = 0; // Counts fences that are not colour 1 in the target array A
    int max_freq = 0;    // Stores the maximum frequency of any colour in A

    // Loop through each fence to read its target colour A_i
    for (int i = 0; i < n; ++i) {
        int color_ai;
        std::cin >> color_ai; // Read A_i

        // If the target colour is not 1, we need to change it from the initial state (all 1s).
        if (color_ai != 1) {
            count_not_1++;
        }

        // Increment the frequency for the current colour
        freq[color_ai]++;
        
        // Update max_freq if the current colour's frequency is higher
        if (freq[color_ai] > max_freq) {
            max_freq = freq[color_ai];
        }
    }

    // Case 1: All fences are already colour 1 in the target state.
    // This means count_not_1 will be 0. No operations needed.
    if (count_not_1 == 0) {
        std::cout << 0 << "\n";
    } else {
        // Case 2: At least one fence needs to change from colour 1.
        // We need at least one operation.

        // Option A: Only use individual fence colouring operations.
        // Starting from all fences being colour 1, we change each fence i
        // where A_i is not 1. This costs 1 minute per such fence.
        // Total cost for Option A: count_not_1.
        
        // Option B: Use one global operation first, then individual operations.
        // The global operation changes all N fences to some colour K. This costs 1 minute.
        // To minimize subsequent individual operations, K should be chosen as the
        // most frequent colour in the target array A (which is represented by max_freq).
        // After the global operation to colour K, we need to individually colour
        // all fences whose target colour A_i is not K. The number of such fences is N - max_freq.
        // Total cost for Option B: 1 (for global op) + (N - max_freq) (for individual ops).
        
        int ans = std::min(count_not_1, 1 + (n - max_freq));
        std::cout << ans << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}