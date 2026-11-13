#include <bits/stdc++.h> // Includes all standard libraries

// It's common practice in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::
using namespace std;

void solve() {
    int N; // Number of moves
    cin >> N;
    string s; // String of moves
    cin >> s;

    int x = 0; // Current x-coordinate, robot starts at (0,0)
    int y = 0; // Current y-coordinate

    // Calculate the final position (x, y) after all original moves
    for (char move : s) {
        if (move == 'U') {
            y++;
        } else if (move == 'D') {
            y--;
        } else if (move == 'L') {
            x--;
        } else if (move == 'R') {
            x++;
        }
    }

    // We need to check if changing exactly one move can lead to (0,0).
    // Let the original final position be (X_orig, Y_orig), which is (x, y) here.
    //
    // The possible target (X_orig, Y_orig) values that allow reaching (0,0)
    // by changing exactly one move are:
    // 1. (0, 2): If X_orig=0 and Y_orig=2, changing a 'U' to 'D' results in (0, 2-2) = (0,0).
    // 2. (0, -2): If X_orig=0 and Y_orig=-2, changing a 'D' to 'U' results in (0, -2+2) = (0,0).
    // 3. (-2, 0): If X_orig=-2 and Y_orig=0, changing an 'L' to 'R' results in (-2+2, 0) = (0,0).
    // 4. (2, 0): If X_orig=2 and Y_orig=0, changing an 'R' to 'L' results in (2-2, 0) = (0,0).
    //
    // In all these cases, the existence of the specific move type (U, D, L, or R)
    // is guaranteed by the fact that the coordinate is non-zero in that direction.
    // For example, if Y_orig = 2, it means there were more 'U' moves than 'D' moves,
    // so there must be at least one 'U' to change.

    // Check if the calculated final position (x, y) matches any of these conditions
    if ((x == 0 && y == 2) ||    // Condition for changing U to D
        (x == 0 && y == -2) ||   // Condition for changing D to U
        (x == -2 && y == 0) ||   // Condition for changing L to R
        (x == 2 && y == 0)) {    // Condition for changing R to L
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to speed up I/O operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}