#include <bits/stdc++.h> // Includes iostream, vector, numeric, etc.
using namespace std;     // Use standard namespace

void solve() {
    int N, Y;
    cin >> N >> Y;

    int or_A = 0;
    for (int i = 0; i < N; ++i) {
        int a_i;
        cin >> a_i;
        or_A |= a_i; // Compute bitwise OR of all elements in A
    }

    // Condition 1: Every bit set in or_A must also be set in Y.
    // This is equivalent to (or_A | Y) == Y.
    // If this condition is not met, no solution exists.
    if ((or_A | Y) != Y) {
        cout << -1 << "\n";
        return;
    }

    // Condition 2: Find the minimum non-negative X such that (or_A | X) = Y.
    //
    // For each bit position k:
    // We need (or_A_k | X_k) = Y_k.
    //
    // If Y_k = 0:
    //   (or_A_k | X_k) must be 0. This implies or_A_k = 0 AND X_k = 0.
    //   (If or_A_k was 1 and Y_k was 0, Condition 1 would have failed).
    //   So, if Y_k = 0, we must set X_k = 0.
    //
    // If Y_k = 1:
    //   (or_A_k | X_k) must be 1.
    //   To minimize X, we want to set X_k = 0 if possible.
    //   - If or_A_k = 1: (1 | X_k) = 1 is true for both X_k = 0 and X_k = 1.
    //     To minimize X, we choose X_k = 0.
    //   - If or_A_k = 0: (0 | X_k) = 1 implies X_k MUST be 1.
    //
    // Summary for minimum X:
    // X_k is 1 if and only if Y_k is 1 AND or_A_k is 0.
    // This logic is compactly expressed as X = Y & (~or_A).
    // The bitwise NOT operator (~) in C++ operates on all bits of the integer type.
    // However, since Y values are less than 2^20, Y will have 0s for bits 20 and higher.
    // Therefore, Y & (~or_A) will correctly produce 0s for bits 20 and higher in X,
    // effectively masking ~or_A to the relevant bit range (0-19).
    int X = Y & (~or_A);

    cout << X << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}