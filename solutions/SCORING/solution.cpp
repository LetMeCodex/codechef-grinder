#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        // Let Alice's score be A and Bob's score be B.
        // We are given two equations:
        // 1. A - B = X (Alice scored X more points than Bob)
        // 2. A + B = Y (Total points scored by both was Y)

        // We can solve this system of linear equations.
        // Adding equation 1 and equation 2:
        // (A - B) + (A + B) = X + Y
        // 2A = X + Y
        // A = (X + Y) / 2

        // Substituting A back into equation 2:
        // ((X + Y) / 2) + B = Y
        // B = Y - ((X + Y) / 2)
        // B = (2Y - (X + Y)) / 2
        // B = (2Y - X - Y) / 2
        // B = (Y - X) / 2

        // Since the problem guarantees a valid solution, (X + Y) and (Y - X) will always be even.
        // This is because X and Y have the same parity.
        // If A and B are integers, then A-B and A+B must have the same parity.
        // X = A-B, Y = A+B. So X and Y must have the same parity.
        // If X and Y have the same parity, then X+Y is even and Y-X is even.

        int alice_score = (x + y) / 2;
        int bob_score = (y - x) / 2;

        cout << alice_score << " " << bob_score << "\n";
    }
    return 0;
}