#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::min
#include <limits>   // Required for std::numeric_limits<int>::max()

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the array
    std::vector<int> A(N); // Declare a vector of size N
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read array elements
    }

    // Initialize min_len to a very large value.
    // If it remains this value, no good subarray was found.
    int min_len = std::numeric_limits<int>::max();

    // Iterate over all possible starting points of subarrays
    for (int i = 0; i < N; ++i) {
        // For each starting point i, iterate through all possible ending points j
        // and maintain distinct elements for the current subarray A[i...j]
        
        // `seen` array to keep track of distinct elements in the current subarray A[i...j].
        // A_i values are between 1 and 100, so an array of size 101 is sufficient.
        // Initialize all to false for each new starting point `i`.
        std::vector<bool> seen(101, false); 
        int distinct_count = 0; // Count of distinct elements in A[i...j]

        for (int j = i; j < N; ++j) {
            // If the current element A[j] has not been seen before in A[i...j],
            // mark it as seen and increment the distinct count.
            if (!seen[A[j]]) {
                seen[A[j]] = true;
                distinct_count++;
            }

            // Check if the current subarray A[i...j] is "good".
            // A good subarray has exactly 2 distinct elements.
            if (distinct_count == 2) {
                // If it's good, update min_len with the length of this subarray.
                // The length is (j - i + 1).
                min_len = std::min(min_len, j - i + 1);
            } 
            // Optimization: If distinct_count becomes greater than 2,
            // any further extension of this subarray (A[i...k] where k > j)
            // will also have more than 2 distinct elements (at least the current `distinct_count`).
            // Therefore, it cannot be a "good" subarray. We can stop extending from `i`.
            else if (distinct_count > 2) {
                break; // Move to the next starting point `i`
            }
        }
    }

    // After checking all possible subarrays, print the result.
    if (min_len == std::numeric_limits<int>::max()) {
        // If min_len is still its initial large value, no good subarray was found.
        std::cout << -1 << "\n";
    } else {
        // Otherwise, print the shortest length found.
        std::cout << min_len << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}