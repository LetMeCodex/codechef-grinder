#include <iostream> // For standard input/output operations
#include <vector>   // For std::vector
#include <algorithm> // For std::max

// Function to solve a single test case
void solve() {
    int N;
    long long K; // K can be up to 10^9, so long long is appropriate
    std::cin >> N >> K;
    std::vector<int> A(N); // Item costs
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    long long current_sum = 0; // Sum of costs of items A[0]...A[i], can be up to 2*10^9
    int ans = 0; // Maximum number of items that can be bought
    int max_val_in_prefix = 0; // Stores the maximum cost among A[0]...A[i]

    for (int i = 0; i < N; ++i) {
        current_sum += A[i]; // Add current item's cost to the running sum

        // Update the maximum value seen so far in the prefix A[0]...A[i]
        // Since A_i >= 1, initializing max_val_in_prefix to 0 is safe.
        max_val_in_prefix = std::max(max_val_in_prefix, A[i]);
        
        // Calculate the effective cost: total sum minus the cost of the most expensive item (which is made free)
        long long effective_cost = current_sum - max_val_in_prefix;

        if (effective_cost <= K) {
            // If we can afford these i+1 items, update the answer.
            // i is 0-indexed, so i+1 gives the count of items.
            ans = i + 1;
        } else {
            // If we cannot afford these i+1 items, we cannot afford any more items
            // because the effective cost is non-decreasing. So, we break the loop.
            break;
        }
    }
    std::cout << ans << "\n"; // Output the maximum number of items
}

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        solve(); // Solve each test case
    }
    return 0;
}