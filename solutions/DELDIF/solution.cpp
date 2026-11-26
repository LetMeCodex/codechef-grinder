#include <iostream> // Required for input/output operations (cin, cout)
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the array

    // Use a frequency array to store counts of elements.
    // Since A_i can be up to N, an array of size N+1 is needed to cover indices 0 to N.
    // Initialize all counts to 0.
    std::vector<int> freq(N + 1, 0); 
    
    // Read array elements and populate the frequency array
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        freq[val]++;
    }

    // K_non_zero: Number of operations performed using non-zero elements.
    // Each pair of identical non-zero elements (X, X) is removed and a 0 is added.
    // This counts as one operation, reducing array length by 1.
    long long K_non_zero = 0; 
    // Iterate for values from 1 to N (non-zero elements)
    for (int v = 1; v <= N; ++v) { 
        K_non_zero += freq[v] / 2; // Each pair (freq[v]/2) contributes one operation
    }

    // current_zeros: Total number of 0s available after processing all non-zero elements.
    // This includes original 0s (freq[0]) and 0s generated from K_non_zero operations.
    long long current_zeros = freq[0] + K_non_zero; 
    
    // K_zero: Number of operations performed using 0s.
    // If there are 'k' zeros, we can perform 'k-1' operations to reduce them to a single 0 (if k >= 1).
    // If k=0, 0 operations. If k=1, 0 operations. If k=2, 1 operation. If k=3, 2 operations.
    // This is correctly captured by std::max(0LL, current_zeros - 1).
    long long K_zero = std::max(0LL, current_zeros - 1); 

    // total_operations: Sum of operations from non-zero elements and zero elements.
    // Each operation reduces the array length by 1.
    long long total_operations = K_non_zero + K_zero;

    // The minimum possible length of the array is the initial length minus the total operations performed.
    long long min_length = N - total_operations;

    std::cout << min_length << "\n"; // Output the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}