#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        // The operation is:
        // 1. A' = A + d, B' = B - d
        // 2. A' = A - d, B' = B + d
        //
        // In both cases, the sum A' + B' remains constant:
        // Case 1: (A + d) + (B - d) = A + B
        // Case 2: (A - d) + (B + d) = A + B
        //
        // If A and B can be made equal, let the final equal value be X.
        // So, A' = X and B' = X.
        // This means A' + B' = X + X = 2X.
        //
        // Since the sum A + B is invariant, we must have A + B = 2X.
        // This implies that A + B must be an even number.
        // If A + B is odd, it's impossible to make A and B equal.
        //
        // If A + B is even, let S = A + B. Then X = S / 2.
        // We need to check if we can reach X from A and B.
        //
        // Consider the difference:
        // Case 1: A' - B' = (A + d) - (B - d) = A - B + 2d
        // Case 2: A' - B' = (A - d) - (B + d) = A - B - 2d
        //
        // In both cases, the difference A' - B' changes by an even number (2d or -2d).
        // This means the parity of the difference A - B is invariant.
        //
        // If A and B are to be made equal, their final difference must be 0.
        // So, A' - B' = 0.
        //
        // If A and B are initially equal (A = B), their difference is 0.
        // If A and B are not equal, their difference is non-zero.
        //
        // Let's re-examine the sum condition.
        // If A + B is even, then A and B have the same parity.
        // If A and B have the same parity, their difference A - B is even.
        //
        // If A + B is even, we can always make them equal.
        // Let the target value be X = (A + B) / 2.
        // We need to reach A' = X and B' = X.
        //
        // If A > B:
        // We need to decrease A and increase B.
        // We can use the operation: A' = A - d, B' = B + d.
        // We want A - d = (A + B) / 2.
        // So, d = A - (A + B) / 2 = (2A - A - B) / 2 = (A - B) / 2.
        // Since A and B have the same parity, A - B is even, so d is an integer.
        // With this d, A' = A - (A - B) / 2 = (2A - A + B) / 2 = (A + B) / 2.
        // And B' = B + (A - B) / 2 = (2B + A - B) / 2 = (A + B) / 2.
        // So A' = B' = (A + B) / 2.
        //
        // If B > A:
        // We need to increase A and decrease B.
        // We can use the operation: A' = A + d, B' = B - d.
        // We want A + d = (A + B) / 2.
        // So, d = (A + B) / 2 - A = (A + B - 2A) / 2 = (B - A) / 2.
        // Since A and B have the same parity, B - A is even, so d is an integer.
        // With this d, A' = A + (B - A) / 2 = (2A + B - A) / 2 = (A + B) / 2.
        // And B' = B - (B - A) / 2 = (2B - B + A) / 2 = (A + B) / 2.
        // So A' = B' = (A + B) / 2.
        //
        // If A = B, they are already equal.
        //
        // Therefore, the condition for making A and B equal is that their sum (A + B) must be even.
        // This is equivalent to A and B having the same parity.
        // A and B have the same parity if (A % 2) == (B % 2).
        // Or, equivalently, (A + B) % 2 == 0.

        if ((a + b) % 2 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}