#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    // The prize money for rank i is 1000 * 2^(4 - i)
    // Rank 1: 1000 * 2^(4 - 1) = 1000 * 2^3 = 1000 * 8 = 8000
    // Rank 2: 1000 * 2^(4 - 2) = 1000 * 2^2 = 1000 * 4 = 4000
    // Rank 3: 1000 * 2^(4 - 3) = 1000 * 2^1 = 1000 * 2 = 2000
    // Rank 4: 1000 * 2^(4 - 4) = 1000 * 2^0 = 1000 * 1 = 1000

    // We can use a direct mapping or calculate it.
    // Since the constraints are very small (1 <= X <= 4), a direct mapping is simplest and most efficient.
    
    if (x == 1) {
        cout << 8000 << "\n";
    } else if (x == 2) {
        cout << 4000 << "\n";
    } else if (x == 3) {
        cout << 2000 << "\n";
    } else if (x == 4) {
        cout << 1000 << "\n";
    }

    return 0;
}