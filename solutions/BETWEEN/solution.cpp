#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    // The problem asks for the number of teams strictly between rank X and rank Y.
    // This means we need to count the integers between min(X, Y) and max(X, Y),
    // excluding min(X, Y) and max(X, Y) themselves.
    //
    // Let's say the ranks are A and B.
    // If A < B, the ranks strictly between them are A+1, A+2, ..., B-1.
    // The number of such ranks is (B-1) - (A+1) + 1 = B - 1 - A - 1 + 1 = B - A - 1.
    //
    // If B < A, the ranks strictly between them are B+1, B+2, ..., A-1.
    // The number of such ranks is (A-1) - (B+1) + 1 = A - 1 - B - 1 + 1 = A - B - 1.
    //
    // In both cases, the number of teams is |X - Y| - 1.
    //
    // Constraints: 1 <= X, Y <= 10, X != Y.
    // The maximum difference is |1 - 10| = 9.
    // The minimum difference is |1 - 2| = 1.
    //
    // If |X - Y| = 1, then |X - Y| - 1 = 1 - 1 = 0. This is correct, as there are no ranks strictly between consecutive ranks.
    // If |X - Y| = 9 (e.g., 1 and 10), then |X - Y| - 1 = 9 - 1 = 8. The ranks are 2, 3, 4, 5, 6, 7, 8, 9, which is 8 teams.
    //
    // The constraints are small, so simple integer arithmetic is sufficient.
    // No need for long long as X and Y are at most 10.

    cout << abs(x - y) - 1 << "\n";

    return 0;
}