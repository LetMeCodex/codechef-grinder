#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks us to compare two integers X (threshold) and Y (current speed).
 * If Y > X, Chef is prone to errors (YES).
 * Otherwise, Chef is not prone to errors (NO).
 * 
 * Constraints: 1 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Read the threshold limit X and current speed Y
    if (cin >> X >> Y) {
        // Check if current speed is strictly greater than the threshold
        if (Y > X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}