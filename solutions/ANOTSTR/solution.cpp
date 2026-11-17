#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An operation consists of choosing indices i and j, swapping A[i] and A[j],
 * and flipping both.
 * Let's see what happens to the number of 1s in the string:
 * - If we pick (0, 0): they become (1, 1). Number of 1s increases by 2.
 * - If we pick (1, 1): they become (0, 0). Number of 1s decreases by 2.
 * - If we pick (0, 1): they become (0, 1). Number of 1s remains the same.
 * 
 * In all cases, the parity of the number of 1s in the string remains invariant.
 * 
 * Additionally, consider the parity of the number of 1s at odd positions vs even positions.
 * Let O be the count of 1s at odd indices, E be the count of 1s at even indices.
 * - Picking (odd, odd): O changes by +2, 0, or -2. Parity of O is invariant.
 * - Picking (even, even): E changes by +2, 0, or -2. Parity of E is invariant.
 * - Picking (odd, even): O changes by +1 or -1, E changes by +1 or -1.
 *   (O + E) parity is invariant.
 * 
 * Actually, the operation is equivalent to:
 * 1. Swap A[i], A[j]
 * 2. Flip A[i], A[j]
 * 
 * Let's track the parity of the number of 1s.
 * Since we can perform operations on any two indices, we can change the number of 1s
 * by 2 at a time. Thus, the parity of the total number of 1s must be the same
 * for A and B.
 * 
 * Is that sufficient?
 * With N >= 3, we have enough freedom to move 1s around and change their count by 2.
 * The only invariant is the parity of the total number of 1s.
 */

void solve() {
    int N;
    cin >> N;
    string A, B;
    cin >> A >> B;

    int countA = 0;
    for (char c : A) if (c == '1') countA++;

    int countB = 0;
    for (char c : B) if (c == '1') countB++;

    if (countA % 2 == countB % 2) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}