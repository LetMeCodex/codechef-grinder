#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested by problem instructions
using namespace std;

void solve() {
    long long A, B, N;
    // Read A, B, N for the current test case
    cin >> A >> B >> N;

    // Check if N is odd or even to determine the effective multipliers
    if (N % 2 == 1) {
        // If N is odd, Alice gets one more turn than Bob.
        // This means Alice's number is effectively multiplied by an extra 2
        // compared to Bob's number, before common factors of 2 are considered.
        // So, we effectively compare (A * 2) with B.
        A *= 2; 
    }
    
    // After the potential adjustment to A (if N was odd),
    // both numbers (A and B) have been effectively multiplied by the same
    // power of 2. This common power of 2 will cancel out when we take
    // the ratio max(C, D) / min(C, D).
    // Therefore, we just need to calculate max(current_A, B) / min(current_A, B).
    // Note: A now holds the potentially modified value (A or 2*A).
    long long result = max(A, B) / min(A, B);
    
    // Output the result followed by a newline
    cout << result << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0;
}