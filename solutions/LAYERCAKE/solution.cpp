#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
#include <numeric>  // Not strictly needed for this solution, but often useful

// Function to solve a single test case
void solve() {
    int N, M;
    std::cin >> N >> M; // Read N and M

    // Use frequency arrays because A_i, B_i values are small (1 to 100).
    // freqA[x] stores the count of value x in array A.
    // freqB[x] stores the count of value x in array B.
    // Size 101 is used to cover values from 0 to 100.
    std::vector<int> freqA(101, 0);
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        freqA[val]++;
    }

    std::vector<int> freqB(101, 0);
    for (int i = 0; i < M; ++i) {
        int val;
        std::cin >> val;
        freqB[val]++;
    }

    // Create a prefix sum array for freqB.
    // prefix_sum_B[x] will store the total count of elements in B that are less than or equal to x.
    // This allows us to quickly find the count of elements strictly smaller than a given value.
    std::vector<int> prefix_sum_B(101, 0);
    // prefix_sum_B[0] is 0 because all B_i are >= 1.
    for (int val = 1; val <= 100; ++val) {
        prefix_sum_B[val] = prefix_sum_B[val - 1] + freqB[val];
    }

    long long count = 0; // Initialize count of valid cakes. Use long long for safety.
    
    // Iterate through each possible size for the first layer (from 1 to 100)
    for (int val_A = 1; val_A <= 100; ++val_A) {
        // If there are any first layers of size val_A
        if (freqA[val_A] > 0) {
            // We need to find how many second layers B_j are strictly smaller than val_A.
            // This is equivalent to finding the count of B_j such that B_j <= (val_A - 1).
            // This count is directly available from prefix_sum_B[val_A - 1].
            int num_B_smaller = prefix_sum_B[val_A - 1];
            
            // Each of the freqA[val_A] first layers of size val_A can be paired
            // with each of the num_B_smaller second layers.
            count += (long long)freqA[val_A] * num_B_smaller;
        }
    }
    
    // Output the total number of valid layered cakes for this test case
    std::cout << count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, once for each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}