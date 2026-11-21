#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace, as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of elements in the sequence

    long long count0 = 0; // Counter for occurrences of 0. Using long long to be safe.
    long long count2 = 0; // Counter for occurrences of 2. Using long long to be safe.

    // Iterate through the sequence to count 0s and 2s
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read each element
        if (A_i == 0) {
            count0++; // Increment count for 0
        } else if (A_i == 2) {
            count2++; // Increment count for 2
        }
    }

    // Calculate the total number of valid pairs.
    // The formula k * (k - 1) / 2 correctly handles cases where k < 2 (resulting in 0 pairs).
    long long ans = count0 * (count0 - 1) / 2 + count2 * (count2 - 1) / 2;

    cout << ans << "\n"; // Print the total number of valid pairs
}

int main() {
    // Enable fast I/O, as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}