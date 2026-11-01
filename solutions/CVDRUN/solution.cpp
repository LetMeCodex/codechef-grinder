#include <bits/stdc++.h> // Includes iostream, numeric, etc.

// Using namespace std; as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;

    // Calculate gcd(K, N)
    // std::gcd is available in C++17 and is in <numeric> or <bits/stdc++.h>
    // The set of cities reachable from X by jumps of K is
    // { (X + i * common_divisor) % N | i >= 0 }.
    // So, Y is reachable if and only if Y has the same remainder as X
    // when divided by common_divisor.
    int common_divisor = std::gcd(K, N);

    // Check if X and Y have the same remainder modulo common_divisor.
    if (X % common_divisor == Y % common_divisor) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}