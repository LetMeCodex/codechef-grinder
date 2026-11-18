#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array

    long long total_sum = 0; // Stores the final sum of products, needs long long for large N
    long long current_ones_count = 0; // Stores the count of consecutive 1s in the current block

    // Iterate through the array elements
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val; // Read the current element

        if (val == 1) {
            // If the element is 1, increment the count of consecutive 1s
            current_ones_count++;
        } else { // If the element is 0
            // A block of 1s has ended (or was empty).
            // Calculate the sum of products for the just-finished block of 1s.
            // A block of k ones contributes k*(k+1)/2 to the total sum.
            total_sum += current_ones_count * (current_ones_count + 1) / 2;
            // Reset the count for the next potential block of 1s
            current_ones_count = 0;
        }
    }

    // After the loop, if the array ends with 1s, current_ones_count will be non-zero.
    // We need to add the contribution from this final block.
    total_sum += current_ones_count * (current_ones_count + 1) / 2;
    
    // Output the final result for the current test case
    cout << total_sum << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}