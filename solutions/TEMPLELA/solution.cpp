#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector

// Using namespace std; is common practice in competitive programming.
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n; // Read the length of the strip
    vector<int> h(n); // Create a vector to store heights
    for (int i = 0; i < n; ++i) {
        cin >> h[i]; // Read heights into the vector
    }

    bool is_valid = true; // Flag to track if the strip is valid

    // Condition 1: The strip must have an odd number of parts to have a unique center.
    if (n % 2 == 0) {
        is_valid = false;
    }

    // Proceed with other checks only if the strip length is valid so far
    if (is_valid) {
        int center_idx = (n - 1) / 2; // Calculate the 0-indexed center position

        // Condition 2: The first height must be 1.
        if (h[0] != 1) {
            is_valid = false;
        }

        // Condition 3: Heights must increase by exactly 1 from the start to the center.
        // Loop from the second element (index 1) up to the center_idx (inclusive).
        if (is_valid) {
            for (int i = 1; i <= center_idx; ++i) {
                if (h[i] != h[i-1] + 1) {
                    is_valid = false;
                    break; // No need to check further if a condition is violated
                }
            }
        }

        // Condition 4: Heights must decrease by exactly 1 from the center to the end.
        // Loop from the element after the center (center_idx + 1) up to the last element (n-1).
        if (is_valid) {
            for (int i = center_idx + 1; i < n; ++i) {
                if (h[i] != h[i-1] - 1) {
                    is_valid = false;
                    break; // No need to check further if a condition is violated
                }
            }
        }
    }

    // Output the result for the current strip
    if (is_valid) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    cin >> s; // Read the number of strips (test cases)
    while (s--) { // Loop through each test case
        solve(); // Call the solve function for each strip
    }

    return 0; // Indicate successful execution
}