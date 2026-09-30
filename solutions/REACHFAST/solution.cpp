#include <bits/stdc++.h> // Required header by problem statement

// Required namespace by problem statement
using namespace std;

int main() {
    // Fast I/O as requested by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        int A, B, K; // Chef's coordinate, Chefina's coordinate, max move per step
        cin >> A >> B >> K;

        // Calculate the absolute distance Chef needs to cover.
        // abs() is from <cmath> or <cstdlib> (included by <bits/stdc++.h>).
        int distance = abs(A - B);

        // Calculate the minimum number of steps.
        // This is equivalent to ceil(distance / K) using integer division.
        // For positive integers X, Y, ceil(X/Y) can be computed as (X + Y - 1) / Y.
        // This formula correctly handles distance = 0 (resulting in 0 steps)
        // and distance > 0 (resulting in the smallest integer >= distance/K steps).
        int steps = (distance + K - 1) / K;

        cout << steps << "\n";
    }

    return 0;
}