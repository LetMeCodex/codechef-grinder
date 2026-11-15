#include <bits/stdc++.h> 

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int S, W1, W2, W3;
    cin >> S >> W1 >> W2 >> W3;

    // Case 1: All three bricks break in 1 hit
    // Sum of all widths must be less than or equal to strength S.
    if (W1 + W2 + W3 <= S) {
        cout << 1 << "\n";
        return;
    }

    // Case 2: All three bricks break in 2 hits
    // If not 1 hit, we check if 2 hits are possible.
    // Ada can choose to hit the stack (W1, W2, W3) or (W3, W2, W1) (reversed).
    // The goal is to break a contiguous block of bricks in the first hit,
    // leaving another contiguous block that can be broken in the second hit.

    // There are two fundamental patterns for 2 hits:
    // Pattern 1: Break two bricks from one end, then the remaining one from the other end.
    //   - This covers breaking (W1,W2) then (W3) from the original stack,
    //     OR breaking (W3,W2) then (W1) from the reversed stack.
    //     Both are covered by the condition: (W1 + W2 <= S && W3 <= S)
    //     (since W1+W2 is equivalent to W2+W1 for sum, and W3 is equivalent to W3)

    // Pattern 2: Break one brick from one end, then the remaining two from the other end.
    //   - This covers breaking (W1) then (W2,W3) from the original stack,
    //     OR breaking (W3) then (W2,W1) from the reversed stack.
    //     Both are covered by the condition: (W1 <= S && W2 + W3 <= S)
    //     (since W2+W3 is equivalent to W3+W2 for sum, and W1 is equivalent to W1)

    // If either of these patterns is possible, then 2 hits are sufficient.
    if ((W1 + W2 <= S && W3 <= S) || 
        (W1 <= S && W2 + W3 <= S)) { 
        cout << 2 << "\n";
        return;
    }

    // Case 3: If not 1 hit and not 2 hits, it must be 3 hits.
    // This is always possible by breaking one brick at a time, as the problem guarantees
    // that Ada can break all bricks. Given W_i <= 2 and S >= 1, this implies that
    // any single brick can be broken if it's the only one left.
    cout << 3 << "\n";
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}