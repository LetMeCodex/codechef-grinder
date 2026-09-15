#include <bits/stdc++.h> // Required by problem statement

// Use standard namespace as required by problem statement
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X; // Read N (number of children) and X (candies Chef already has)

    // Calculate how many more candies Chef needs.
    // If N - X is positive, Chef needs more candies.
    // If N - X is zero or negative, Chef already has enough or more candies.
    int needed_candies = N - X;

    if (needed_candies <= 0) {
        // Chef already has enough or more candies than required.
        // No packets need to be bought.
        cout << 0 << "\n";
    } else {
        // Chef needs 'needed_candies' more candies.
        // Candies are available in packets of 4.
        // To find the minimum number of packets, we need to perform a ceiling division.
        // For positive integers 'a' and 'b', ceil(a/b) can be calculated using integer arithmetic
        // as (a + b - 1) / b. Here, 'a' is needed_candies and 'b' is 4.
        int packets_to_buy = (needed_candies + 4 - 1) / 4;
        cout << packets_to_buy << "\n";
    }
}

int main() {
    // Enable fast I/O as required by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, calling solve() for each test case
        solve();
    }

    return 0;
}