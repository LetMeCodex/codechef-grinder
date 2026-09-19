#include <bits/stdc++.h> // Required header as per problem instructions

using namespace std; // Required as per problem instructions

void solve() {
    int L, R;
    cin >> L >> R; // Read L and R for the current test case

    int pretty_count = 0; // Initialize a counter for pretty numbers

    // Iterate through all numbers from L to R (inclusive)
    for (int i = L; i <= R; ++i) {
        // Get the last digit of the current number i
        int last_digit = i % 10;

        // Check if the last digit is 2, 3, or 9
        if (last_digit == 2 || last_digit == 3 || last_digit == 9) {
            pretty_count++; // If it is, increment the counter
        }
    }

    // Print the total count of pretty numbers for this test case
    cout << pretty_count << "\n";
}

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}