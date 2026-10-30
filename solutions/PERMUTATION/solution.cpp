#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the size of the array

    std::vector<int> A(N); // Declare a vector of size N
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i]; // Read elements into the vector
    }

    // Sort the array A in non-decreasing order.
    // This is crucial for the greedy strategy to work.
    std::sort(A.begin(), A.end());

    long long operations = 0; // Variable to store the total number of operations.
                              // Using long long to be safe, though int would suffice for given constraints.
    bool possible = true;     // Flag to track if it's possible to form a permutation.

    // Iterate through the sorted array.
    // For each element A[i] (0-indexed), its ideal target value in the permutation
    // is (i+1) (1-indexed).
    for (int i = 0; i < N; ++i) {
        // If the current element A[i] is greater than its ideal target value (i+1),
        // it's impossible to form a permutation.
        // (Refer to the "Proof of Necessity" in the explanation above for details).
        if (A[i] > (i + 1)) {
            possible = false; // Mark as impossible
            break;            // No need to check further
        }
        // If A[i] <= (i+1), we can transform A[i] into (i+1).
        // The number of operations required for this element is (i+1) - A[i].
        operations += ((i + 1) - A[i]);
    }

    // Output the result based on whether it was possible or not.
    if (possible) {
        std::cout << operations << "\n";
    } else {
        std::cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}