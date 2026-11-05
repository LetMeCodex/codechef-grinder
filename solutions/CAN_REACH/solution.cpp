#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        // The student starts at (0, 0).
        // In one move, the student can change either the x-coordinate or the y-coordinate
        // by exactly K (either +K or -K).
        // This means that any reachable coordinate (x', y') must satisfy:
        // x' = m * K for some integer m
        // y' = n * K for some integer n
        // This is because each move adds or subtracts K to one of the coordinates.
        // Starting from 0, any reachable coordinate will be a multiple of K.
        // Therefore, to reach (x, y), both x and y must be divisible by K.

        if (x % k == 0 && y % k == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}