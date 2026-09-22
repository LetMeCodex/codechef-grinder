#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n, m;
    cin >> x >> n >> m;

    // Om has X rupees.
    // The laptop costs N rupees.
    // The Gymkhana fund has M rupees.
    // Om can use the fund as much as he wants.

    // The total amount Om can gather is his own money (X) plus
    // whatever he takes from the Gymkhana fund (up to M).
    // The maximum amount he can have is X + M.
    // If this maximum amount is greater than or equal to the laptop cost (N),
    // then he can buy the laptop.

    if (x + m >= n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}