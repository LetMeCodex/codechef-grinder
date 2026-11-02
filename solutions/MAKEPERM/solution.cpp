#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array A
    std::vector<int> A(N); // Declare a vector A of size N
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read elements of array A
    }

    // Sort array A in non-decreasing order.
    // This is a critical step for the greedy strategy to work correctly.
    // By processing smaller A_i values first, we leave larger target values
    // available for larger A_i values, maximizing the chances of success.
    std::sort(A.begin(), A.end());

    // `used` array to keep track of numbers from 1 to N that have been assigned to C_i.
    // `used[0]` is intentionally unused (to allow 1-based indexing for values 1 to N).
    // `used[k]` will be true if the value `k` has already been assigned.
    std::vector<bool> used(N + 1, false);

    bool possible = true; // Flag to track if a permutation can be formed
    for (int i = 0; i < N; ++i) {
        // For the current A[i] (which is the smallest unassigned A_j due to sorting),
        // we need to find the smallest possible C_i such that:
        // 1. C_i >= A[i] (because B_i must be non-negative)
        // 2. C_i is in the range [1, N] (definition of a permutation of size N)
        // 3. C_i has not been used yet by a previous A_j (j < i)
        
        bool found_target = false; // Flag to check if a suitable C_i was found for A[i]
        // Iterate from A[i] up to N to find the smallest available target value
        for (int k = A[i]; k <= N; ++k) {
            if (!used[k]) {
                // Found the smallest available target value k for A[i]
                used[k] = true; // Mark k as used
                found_target = true;
                break; // Move to the next A[i] as we've assigned a value for the current one
            }
        }

        if (!found_target) {
            // If no suitable k was found for A[i] (meaning all numbers from A[i] to N
            // are already used), then it's impossible to form a permutation.
            possible = false;
            break; // No need to check further elements, the answer is NO
        }
    }

    // Output the result for the current test case
    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
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

    return 0; // Indicate successful execution
}