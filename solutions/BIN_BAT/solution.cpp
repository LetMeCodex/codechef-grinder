#include <bits/stdc++.h> // Includes iostream, cmath, etc.

// Using namespace std as requested by the problem statement.
using namespace std;

// Function to solve a single test case
void solve() {
    int N, A, B;
    cin >> N >> A >> B; // Read N, A, B using cin

    // N is guaranteed to be a power of 2. The number of rounds is log2(N).
    // For a power of 2, N = 2^k, __builtin_ctz(N) returns k.
    // This is equivalent to log2(N) and is very efficient (a single CPU instruction).
    // Since N >= 2, num_rounds will be at least 1.
    int num_rounds = __builtin_ctz(N); 
    
    // Calculate the total time:
    // 1. Time for all rounds: num_rounds * A
    // 2. Time for breaks: (num_rounds - 1) * B (no break after the last round)
    // The maximum possible total time (for N=2^20, A=100, B=100) is 3900,
    // which fits within an 'int'. However, using 'long long' for total_time
    // is a good practice to prevent potential overflow in similar problems
    // with slightly larger constraints.
    long long total_time = (long long)num_rounds * A + (long long)(num_rounds - 1) * B;
    
    cout << total_time << "\n"; // Output the total time followed by a newline
}

int main() {
    // Fast I/O setup as recommended by the problem statement.
    // This unties cin from cout and disables synchronization with C's stdio,
    // significantly speeding up input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {  // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}