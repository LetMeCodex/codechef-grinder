#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Adheres to the instruction to use namespace std

void solve() {
    int N;
    cin >> N; // Read N for the current test case

    // Calculate the number of 2 kg weights.
    // We want to maximize the use of 2 kg weights because they are cheaper per kg.
    // N / 2 (integer division) gives the maximum number of 2 kg weights we can use.
    int num_2kg = N / 2;

    // Calculate the number of 1 kg weights.
    // The remaining weight after using num_2kg two-kilogram weights is N - (num_2kg * 2).
    // This is equivalent to N % 2 for positive N.
    int num_1kg = N % 2;

    // Calculate the total cost.
    // Using long long for total_cost to be safe against potential overflow,
    // although for N <= 100, int would suffice (max cost 1500).
    long long total_cost = (long long)num_1kg * 20 + (long long)num_2kg * 30;

    cout << total_cost << "\n"; // Output the minimum total cost
}

int main() {
    // Fast I/O setup as per critical instructions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}