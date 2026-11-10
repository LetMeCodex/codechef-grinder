#include <bits/stdc++.h> 

using namespace std; // Explicitly requested by problem instructions

// Function to calculate the sum of digits of a number
// Assumes n is non-negative. For this problem, products are always positive.
int sum_digits(int n) {
    int sum = 0;
    // The smallest product is 1*1 = 1, so n will always be > 0.
    while (n > 0) {
        sum += n % 10; // Add the last digit to the sum
        n /= 10;       // Remove the last digit
    }
    return sum;
}

void solve() {
    int N;
    cin >> N; // Read N, the number of elements in the sequence
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read elements into vector A
    }

    int max_digit_sum = 0; // Initialize the maximum sum of digits found

    // Iterate through all unique pairs of indices (i, j) such that i < j
    // This ensures we pick two *different* elements from the sequence.
    // The values A[i] and A[j] can be the same, as long as their indices are different.
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            // Calculate the product of the two elements
            // A_i <= 10^4, so product <= 10^4 * 10^4 = 10^8.
            // An 'int' type in C++ is typically 32-bit, capable of storing values up to ~2*10^9,
            // so 10^8 fits comfortably without overflow.
            int product = A[i] * A[j];
            
            // Calculate the sum of digits of the product
            int current_digit_sum = sum_digits(product);
            
            // Update the maximum sum of digits found so far
            if (current_digit_sum > max_digit_sum) {
                max_digit_sum = current_digit_sum;
            }
        }
    }
    cout << max_digit_sum << "\n"; // Print the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times for each test case
        solve(); // Solve a single test case
    }

    return 0;
}