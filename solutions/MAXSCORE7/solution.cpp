#include <bits/stdc++.h> // Includes most standard library headers, including iostream and algorithm.

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the array

    int count0 = 0; // Counter for the number of zeros
    int count1 = 0; // Counter for the number of ones

    // Iterate through the array elements to count zeros and ones
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val; // Read each element of the array
        if (val == 0) {
            count0++; // If the element is 0, increment count0
        } else {
            count1++; // If the element is 1, increment count1
        }
    }

    // The maximum score is the minimum of the total counts of zeros and ones.
    // This is because each operation that yields a score of 1 consumes one 0 and one 1.
    // We can always perform min(count0, count1) such operations.
    // After these operations, all remaining elements will be identical (either all 0s or all 1s),
    // so any subsequent operations will yield a score of 0.
    std::cout << std::min(count0, count1) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}