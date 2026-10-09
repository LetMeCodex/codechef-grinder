#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        bool possible = false;

        // Let x be the number of type 1 operations and y be the number of type 2 operations.
        // We want to find non-negative integers x and y such that:
        // A - x = 0  => x = A
        // B - 2x - y = 0 => y = B - 2x
        // C - 3y = 0 => C = 3y

        // From the first equation, x must be equal to A.
        // Since x must be non-negative, this is always true given the constraints (A >= 1).
        int x = a;

        // Substitute x into the second equation:
        // y = B - 2*A
        // For y to be a valid number of operations, it must be non-negative.
        // So, B - 2*A >= 0, which means B >= 2*A.
        if (b < 2 * a) {
            cout << "No\n";
            continue;
        }

        // Now calculate y:
        int y = b - 2 * a;

        // Substitute y into the third equation:
        // C - 3*y = 0
        // This means C must be exactly 3 times y.
        // So, C = 3 * (B - 2*A).
        if (c == 3 * y) {
            possible = true;
        }

        if (possible) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}