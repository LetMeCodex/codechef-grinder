#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std; 

// Function to solve a single test case
void solve() {
    int N; // N: number of changes, 0 <= N <= 10^9. Fits in a 32-bit signed int.
    int K; // K: initial state (0 for Off, 1 for On). Fits in int.
    
    // Read N and K for the current test case
    cin >> N >> K;

    // Calculate N modulo 4. This determines the position in the 4-level cycle.
    int rem = N % 4;

    // Case 1: Initial state is Off (K = 0)
    if (K == 0) {
        // If initial state is Off, the torch must be at Level 4.
        // The cycle is 4 -> 1 -> 2 -> 3 -> 4 -> ...
        // After N changes:
        // If N is a multiple of 4 (rem == 0), it returns to Level 4.
        // Level 4 corresponds to Off state.
        if (rem == 0) {
            cout << "Off\n";
        } 
        // If N is not a multiple of 4 (rem != 0), it will be at Level 1, 2, or 3.
        // (e.g., N=1: 4->1; N=2: 4->2; N=3: 4->3)
        // Levels 1, 2, 3 correspond to On state.
        else {
            cout << "On\n";
        }
    } 
    // Case 2: Initial state is On (K = 1)
    else { // K == 1
        // If initial state is On, the torch could be at Level 1, 2, or 3.
        // We need to check if all possible starting levels lead to the same final state.
        // The cycle is 1 -> 2 -> 3 -> 4 -> 1 -> ...
        // If N is a multiple of 4 (rem == 0):
        //   - From Level 1, N changes lead to Level 1 (On).
        //   - From Level 2, N changes lead to Level 2 (On).
        //   - From Level 3, N changes lead to Level 3 (On).
        // In this case, all possible initial levels lead to an On state.
        if (rem == 0) {
            cout << "On\n";
        } 
        // If N is not a multiple of 4 (rem != 0):
        //   - If rem = 1: initial 3 -> final 4 (Off)
        //   - If rem = 2: initial 2 -> final 4 (Off)
        //   - If rem = 3: initial 1 -> final 4 (Off)
        // In all these cases, at least one of the possible initial levels (1, 2, or 3)
        // will lead to Level 4 (Off), while others lead to On.
        // Thus, the final state cannot be determined.
        else {
            cout << "Ambiguous\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // T: number of test cases, 1 <= T <= 10^5
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}