#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) {
        long long N; // N can be up to 10^9, so long long is necessary to prevent overflow
        cin >> N; // Read N for the current test case

        long long final_position;

        // Let's trace Chef's position for small values of N to find a pattern.
        // Initial position: pos = 0.

        // N = 1:
        // i=1: pos=0 (non-negative) -> pos = 0 - 1 = -1.
        // Final position for N=1: -1.

        // N = 2:
        // i=1: pos=0 (non-negative) -> pos = 0 - 1 = -1.
        // i=2: pos=-1 (negative) -> pos = -1 + 2 = 1.
        // Final position for N=2: 1.

        // N = 3:
        // i=1: pos=0 (non-negative) -> pos = -1.
        // i=2: pos=-1 (negative) -> pos = 1.
        // i=3: pos=1 (non-negative) -> pos = 1 - 3 = -2.
        // Final position for N=3: -2.

        // N = 4:
        // i=1: pos=0 (non-negative) -> pos = -1.
        // i=2: pos=-1 (negative) -> pos = 1.
        // i=3: pos=1 (non-negative) -> pos = -2.
        // i=4: pos=-2 (negative) -> pos = -2 + 4 = 2.
        // Final position for N=4: 2.

        // N = 5:
        // i=1: pos=0 (non-negative) -> pos = -1.
        // i=2: pos=-1 (negative) -> pos = 1.
        // i=3: pos=1 (non-negative) -> pos = -2.
        // i=4: pos=-2 (negative) -> pos = 2.
        // i=5: pos=2 (non-negative) -> pos = 2 - 5 = -3.
        // Final position for N=5: -3.

        // Summary of final positions:
        // N=1 -> -1
        // N=2 -> 1
        // N=3 -> -2
        // N=4 -> 2
        // N=5 -> -3

        // The pattern observed is:
        // If N is even, the final position is N / 2.
        // If N is odd, the final position is -(N / 2 + 1).
        // (Note: N/2 here uses integer division, e.g., 3/2 = 1).

        // This pattern can be formally proven by induction.
        // Let P_k be the position after k operations. P_0 = 0.
        // The rule is: if P_{i-1} >= 0, P_i = P_{i-1} - i; else P_i = P_{i-1} + i.
        //
        // We can show that P_k is negative if k is odd, and non-negative if k is even.
        // Base cases: P_0 = 0 (even, non-negative), P_1 = -1 (odd, negative), P_2 = 1 (even, non-negative).
        //
        // Assume for some k >= 0:
        // If k is even, P_k = k/2. (P_k >= 0)
        // If k is odd, P_k = -(k+1)/2. (P_k < 0)
        //
        // Consider P_{k+1}:
        // Case 1: k is even.
        //   By assumption, P_k = k/2 >= 0.
        //   For operation k+1, Chef moves backward: P_{k+1} = P_k - (k+1)
        //   P_{k+1} = k/2 - (k+1) = (k - 2k - 2)/2 = (-k - 2)/2 = -(k+2)/2.
        //   Since k is even, k+1 is odd. The pattern for odd index (k+1) is -((k+1)+1)/2 = -(k+2)/2. This matches.
        //   Also, -(k+2)/2 is negative, consistent with k+1 being odd.
        //
        // Case 2: k is odd.
        //   By assumption, P_k = -(k+1)/2 < 0.
        //   For operation k+1, Chef moves forward: P_{k+1} = P_k + (k+1)
        //   P_{k+1} = -(k+1)/2 + (k+1) = (k+1)/2.
        //   Since k is odd, k+1 is even. The pattern for even index (k+1) is (k+1)/2. This matches.
        //   Also, (k+1)/2 is non-negative (since k >= 1), consistent with k+1 being even.
        //
        // The induction holds, and the pattern is correct.

        if (N % 2 == 0) {
            // N is even
            final_position = N / 2;
        } else {
            // N is odd
            // For odd N, integer division N/2 (e.g., 3/2) truncates to (N-1)/2 (e.g., 1).
            // So, N/2 + 1 correctly calculates (N-1)/2 + 1, which simplifies to (N+1)/2.
            final_position = -(N / 2 + 1);
        }

        cout << final_position << "\n"; // Output the final position followed by a newline
    }

    return 0; // Indicate successful execution
}