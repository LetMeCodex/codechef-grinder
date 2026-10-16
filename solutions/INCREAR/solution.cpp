#include <iostream> // Required for std::cin, std::cout

void solve() {
    long long X, Y; // Using long long for X and Y to safely handle values up to 10^9
    std::cin >> X >> Y;

    if (X <= Y) {
        // If X is less than or equal to Y, the most efficient way to make them equal
        // is to only increment X. Each X := X + 1 operation costs 1.
        // We need to increment X by (Y - X) to make it equal to Y.
        // The number of operations will be Y - X.
        std::cout << Y - X << "\n";
    } else { // X > Y
        // If X is greater than Y, we must increase Y (and possibly X) to make them equal.
        // Let 'b' be the number of Y := Y + 2 operations.
        // Let 'a' be the number of X := X + 1 operations.
        // We want to reach a state where X + a = Y + 2b, minimizing a + b.

        // The final value Y + 2b must be at least X.
        // So, Y + 2b >= X  =>  2b >= X - Y.
        // Let diff = X - Y. We need 2b >= diff.
        // The minimum integer 'b' satisfying this is ceil(diff / 2.0).
        // For any positive integer D, ceil(D / 2.0) can be calculated using integer division
        // as (D + 1) / 2.
        long long diff = X - Y;
        long long b = (diff + 1) / 2; // Minimum Y := Y+2 operations

        // After 'b' operations, Y will become Y_final = Y + 2 * b.
        // Now, X needs to be incremented to match Y_final.
        // The number of X := X + 1 operations needed is 'a' = Y_final - X.
        // Since b was chosen such that Y_final >= X, 'a' will be non-negative.
        long long Y_final = Y + 2 * b;
        long long a = Y_final - X;
        
        // The total minimum operations is the sum of 'a' and 'b'.
        std::cout << a + b << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input,
    // further speeding up I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times, solving each test case
        solve();
    }

    return 0;
}