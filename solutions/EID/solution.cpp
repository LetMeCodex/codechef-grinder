#include <bits/stdc++.h> // Includes iostream, vector, algorithm, climits etc.

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of coins

    std::vector<int> v(N); // Create a vector to store coin values
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i]; // Read each coin value
    }

    // Sort the coin values in non-decreasing order.
    // This is the crucial step for O(N log N) efficiency.
    std::sort(v.begin(), v.end());

    // Initialize min_diff with a very large value.
    // Since v_i are up to 10^6, the maximum possible difference is 10^6 - 1.
    // INT_MAX (from <climits>) is a safe upper bound.
    int min_diff = INT_MAX; 

    // Iterate through the sorted array and calculate differences between adjacent elements.
    // The minimum difference between any two elements will always be found between adjacent elements
    // in a sorted array.
    for (int i = 0; i < N - 1; ++i) {
        // Calculate the difference between the current coin and the next coin.
        // Since the array is sorted, v[i+1] >= v[i], so v[i+1] - v[i] is already non-negative.
        int diff = v[i+1] - v[i];
        
        // Update min_diff if the current difference is smaller.
        if (diff < min_diff) {
            min_diff = diff;
        }
        
        // Optimization: If min_diff becomes 0, we can't get a smaller non-negative difference.
        // So, we can break early.
        if (min_diff == 0) {
            break;
        }
    }

    // Print the minimum possible difference.
    std::cout << min_diff << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}