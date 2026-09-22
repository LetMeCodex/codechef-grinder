#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        // The maximum number of chocolates Chef can buy is the total amount of money
        // divided by the cost of one chocolate. Integer division automatically
        // handles the "maximum" aspect by truncating any remainder.
        // Since X and Y are at most 100, int is sufficient.
        cout << x / y << "\n";
    }

    return 0;
}