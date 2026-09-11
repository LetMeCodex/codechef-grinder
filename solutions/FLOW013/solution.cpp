#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Valid Triangles
 * Logic: A triangle is valid if and only if the sum of its three interior angles is exactly 180 degrees.
 * Time Complexity: O(T), where T is the number of test cases.
 * Space Complexity: O(1), as we only use a few integer variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        // Check if the sum of angles equals 180
        if (a + b + c == 180) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}