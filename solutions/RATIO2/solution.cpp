#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min, std::abs
#include <climits>   // Required for INT_MAX

// Using namespace std; as requested by problem instructions
using namespace std;

void solve() {
    int X, Y;
    cin >> X >> Y;

    // Check if the condition is already met
    if (X >= 2 * Y || Y >= 2 * X) {
        cout << 0 << "\n";
        return;
    }

    // Initialize minimum operations to a very large value
    int min_ops = INT_MAX;

    // Option 1: Achieve X' >= 2Y' by changing X and/or Y
    // Iterate through possible target values for Y'
    // Since X, Y <= 10, the optimal Y' will not exceed 10.
    // Values of Y' beyond 10 would result in higher operation counts.
    for (int target_Y = 1; target_Y <= 10; ++target_Y) {
        // To satisfy X' >= 2*target_Y, the minimum X' is 2*target_Y.
        // Operations needed: |X - (2*target_Y)| + |Y - target_Y|
        int current_ops = abs(X - (2 * target_Y)) + abs(Y - target_Y);
        min_ops = min(min_ops, current_ops);
    }

    // Option 2: Achieve Y' >= 2X' by changing X and/or Y
    // Iterate through possible target values for X'
    // Similar reasoning as above, X' from 1 to 10 is sufficient.
    for (int target_X = 1; target_X <= 10; ++target_X) {
        // To satisfy Y' >= 2*target_X, the minimum Y' is 2*target_X.
        // Operations needed: |X - target_X| + |Y - (2*target_X)|
        int current_ops = abs(X - target_X) + abs(Y - (2 * target_X));
        min_ops = min(min_ops, current_ops);
    }

    cout << min_ops << "\n";
}

int main() {
    // Fast I/O as requested by problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}