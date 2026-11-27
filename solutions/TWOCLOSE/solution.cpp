#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate (though a manual loop is used here)
#include <algorithm> // For std::swap

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        std::cin >> A[i];
    }

    // A[N] corresponds to A_{N+1} in the 1-indexed problem statement.
    // A[0]...A[N-1] correspond to A_1...A_N in the 1-indexed problem statement.

    while (true) {
        int max_eligible_val = -1; // Stores the largest A_i that can be swapped
        int idx_to_swap = -1;      // Stores the index of max_eligible_val

        // Iterate through the first N elements (A[0] to A[N-1])
        for (int i = 0; i < N; ++i) {
            // Condition for a valid swap: A[i] <= 2 * A[N]
            // Additionally, we only want to swap if A[i] is strictly greater than A[N]
            // to ensure A[N] increases and we make progress towards minimizing the sum.
            if (A[i] > A[N] && A[i] <= 2 * A[N]) {
                if (A[i] > max_eligible_val) {
                    max_eligible_val = A[i];
                    idx_to_swap = i;
                }
            }
        }

        if (idx_to_swap != -1) { // If an eligible element was found
            std::swap(A[idx_to_swap], A[N]); // Perform the swap
        } else { // No element found that can increase A[N] further
            break; // Terminate the process
        }
    }

    // Calculate the sum of the first N elements (A[0] to A[N-1])
    long long total_sum = 0; // Use long long for sum to be safe, though int might suffice
    for (int i = 0; i < N; ++i) {
        total_sum += A[i];
    }
    std::cout << total_sum << "\n";
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