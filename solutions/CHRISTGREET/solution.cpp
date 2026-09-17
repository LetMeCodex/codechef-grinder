#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Christmas Greetings
 * Logic: Check if the input integer X is equal to 25.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input X, 
    // but standard competitive programming practice often involves 
    // handling a single test case unless specified otherwise.
    // Based on the problem description, we read one integer X.
    
    long long X;
    if (cin >> X) {
        if (X == 25) {
            cout << "CHRISTMAS" << "\n";
        } else {
            cout << "ORDINARY" << "\n";
        }
    }

    return 0;
}