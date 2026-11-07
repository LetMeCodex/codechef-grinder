#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // Not strictly needed, but useful for max_element if not sorting

// Function to check if a given attack stat A is sufficient
// H_sorted_desc: vector of monster HPs sorted in decreasing order
bool can(long long A, int N, long long X, const std::vector<long long>& H_sorted_desc) {
    for (int i = 0; i < N; ++i) {
        long long current_H = H_sorted_desc[i];
        
        // If A is less than current_H, this monster cannot be killed even on day 1.
        // This also handles cases where A - current_H would be negative,
        // preventing incorrect floor division behavior for negative numbers.
        if (A < current_H) {
            return false;
        }
        
        // Calculate the maximum (0-indexed) day multiplier (k-1)
        // such that H_i + (k-1)*X <= A
        // (k-1)*X <= A - H_i
        // k-1 <= (A - H_i) / X
        // Integer division in C++ for non-negative numbers correctly computes floor.
        long long max_day_multiplier = (A - current_H) / X;
        
        // The i-th monster (0-indexed) in the sorted list is assigned to be killed on day (i+1).
        // For this to be possible, the maximum allowed day multiplier for this monster
        // must be at least 'i' (since day 'i+1' corresponds to multiplier 'i').
        // If max_day_multiplier < i, it means this monster cannot be killed on day (i+1)
        // or any later day, which is required by its position in the sorted list.
        if (max_day_multiplier < i) {
            return false;
        }
    }
    return true;
}

void solve() {
    int N;
    long long X;
    std::cin >> N >> X;
    std::vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i];
    }

    // Sort HPs in decreasing order.
    // This is crucial for the `can` function's greedy assignment logic.
    // H_sorted_desc[i] will be the (i+1)-th monster to be killed.
    std::sort(H.rbegin(), H.rend()); // Sorts in reverse (decreasing) order

    long long low = H[0]; // Minimum possible A is the largest initial HP
    // A safe upper bound for A.
    // Max H_i + (N-1)*X. Max H_i = 10^9, Max N = 2*10^5, Max X = 10^9.
    // 10^9 + (2*10^5 - 1) * 10^9 approx 2 * 10^14.
    long long high = 200000000000000LL + 7; // A bit more than 2 * 10^14 for safety
    long long ans = high; // Initialize answer with a value that is definitely possible (or higher)

    // Binary search for the minimum A
    while (low <= high) {
        long long mid = low + (high - low) / 2; // Prevent overflow for (low+high)
        if (can(mid, N, X, H)) {
            ans = mid;         // mid is a possible answer, try for a smaller one
            high = mid - 1;
        } else {
            low = mid + 1;     // mid is too small, need a larger A
        }
    }
    std::cout << ans << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }
    return 0;
}