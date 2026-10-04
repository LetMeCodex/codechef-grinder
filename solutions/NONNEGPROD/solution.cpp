#include <bits/stdc++.h> // Includes iostream for input/output

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of elements in the array

    int neg_count = 0; // Counter for negative numbers
    bool has_zero = false; // Flag to check if any zero is present

    // Iterate through the array elements
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the current element

        if (A_i < 0) {
            neg_count++; // Increment count if the element is negative
        } else if (A_i == 0) {
            has_zero = true; // Set flag if the element is zero
        }
    }

    // Determine the minimum removals based on the collected information
    if (has_zero) {
        // If there's any zero, the product will be 0, which is non-negative.
        // No removals needed.
        cout << 0 << "\n";
    } else {
        // If there are no zeros, the product's sign depends on neg_count.
        if (neg_count % 2 == 0) {
            // Even number of negative numbers means the product is positive.
            // No removals needed.
            cout << 0 << "\n";
        } else {
            // Odd number of negative numbers means the product is negative.
            // To make it non-negative (positive), we must remove one negative number.
            // This is the minimum removal required.
            cout << 1 << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}