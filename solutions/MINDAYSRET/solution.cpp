#include <bits/stdc++.h> // Includes iostream and other standard libraries

// Use the standard namespace as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    // Read the total number of students (N) and the capacity per day (K)
    cin >> N >> K;

    // Calculate the minimum number of days required.
    // This is equivalent to ceil(N / K).
    // Using integer division, ceil(a/b) can be calculated as (a + b - 1) / b
    int days = (N + K - 1) / K;

    // Print the result for the current test case, followed by a newline
    cout << days << "\n";
}

int main() {
    // Critical Instruction: Enable fast I/O
    // This unties cin from cout and disables synchronization with C's stdio,
    // significantly speeding up input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}