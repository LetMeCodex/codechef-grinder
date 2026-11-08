#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the array

    int odd_count = 0; // Counter for odd numbers in the array

    // Loop N times to read each element and determine its parity
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read an element
        if (A_i % 2 != 0) { // Check if A_i is odd (remainder is not 0 when divided by 2)
            odd_count++; // Increment the odd_count if the number is odd
        }
    }

    // Based on the parity analysis:
    // For all prefix sums to be odd, the first element (B_1) must be odd,
    // and all subsequent elements (B_2, ..., B_N) must be even.
    // This implies that the original array A must contain exactly one odd number
    // and N-1 even numbers.
    // If odd_count is 1, it means there is exactly one odd number available for B_1.
    // Since odd_count + even_count = N, if odd_count = 1, then even_count must be N-1.
    // This perfectly satisfies the required distribution of parities.
    // If odd_count is 0, we cannot make B_1 odd.
    // If odd_count > 1, we will have remaining odd numbers that must be placed
    // in positions B_i (for i > 1), but those positions require even numbers.
    if (odd_count == 1) {
        cout << "Yes\n"; // It is possible to rearrange the array
    } else {
        cout << "No\n"; // It is not possible
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}