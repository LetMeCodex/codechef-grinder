#include <iostream> // For standard input/output operations (cin, cout)
#include <vector>   // For using std::vector to store the array elements
#include <algorithm> // For std::min

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of elements

    std::vector<int> A(N); // Declare a vector of size N to store the elements
    int total_xor = 0;     // Initialize total_xor to 0 (identity for XOR)

    // Read elements and compute their total XOR sum
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        total_xor ^= A[i]; // Accumulate XOR sum
    }

    // Initialize the minimum final XOR with the XOR sum of all elements.
    // This covers the case where we choose not to remove any element.
    int min_final_xor = total_xor;

    // Iterate through each element to consider removing it.
    // If element A[i] is removed, the new XOR sum is total_xor ^ A[i].
    // This is derived from the property: (XOR_sum_without_A_i) ^ A_i = total_xor,
    // which implies XOR_sum_without_A_i = total_xor ^ A_i.
    for (int i = 0; i < N; ++i) {
        min_final_xor = std::min(min_final_xor, total_xor ^ A[i]);
    }

    // Output the minimum XOR sum found
    std::cout << min_final_xor << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times for each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}