#include <bits/stdc++.h> // Includes most standard libraries, including iostream
using namespace std;     // Brings all names from std namespace into global scope

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, K, Y;
    // Read the three space-separated integers X, K, and Y.
    cin >> X >> K >> Y;

    // A number Y can be shown by the die if two conditions are met:
    // 1. Y must be a multiple of the base multiplier K.
    //    This is checked by Y % K == 0.
    // 2. If Y is a multiple of K, let Y = K * i. Then 'i' must be
    //    between 1 and X (inclusive), because the faces are K*1, K*2, ..., K*X.
    //    Since Y, K >= 1, if Y % K == 0, then Y/K will be at least 1.
    //    So we only need to check if Y/K is less than or equal to X.
    if (Y % K == 0 && (Y / K) <= X) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}