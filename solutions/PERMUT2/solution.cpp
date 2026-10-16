#include <bits/stdc++.h> // Includes iostream, vector, etc.

using namespace std; // Allowed by problem instructions

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Loop until n is 0, which signals the end of input
    while (cin >> n && n != 0) {
        // Declare vectors for the permutation P and its inverse P_inv
        // Using 1-based indexing for convenience, so size n+1
        vector<int> p(n + 1);
        vector<int> p_inv(n + 1);

        // Read the permutation P and simultaneously construct P_inv
        for (int i = 1; i <= n; ++i) {
            cin >> p[i]; // Read the i-th element of the permutation
            
            // If p[i] is the value at index i in the original permutation,
            // then the position of value p[i] is i.
            // So, in the inverse permutation, the element at index p[i] is i.
            p_inv[p[i]] = i;
        }

        bool ambiguous = true; // Assume ambiguous until a mismatch is found
        
        // Compare P with P_inv
        for (int i = 1; i <= n; ++i) {
            if (p[i] != p_inv[i]) {
                ambiguous = false; // Mismatch found, it's not ambiguous
                break;             // No need to check further, exit loop
            }
        }

        // Output the result based on the 'ambiguous' flag
        if (ambiguous) {
            cout << "ambiguous\n";
        } else {
            cout << "not ambiguous\n";
        }
    }

    return 0;
}