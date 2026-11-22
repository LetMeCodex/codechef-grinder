#include <bits/stdc++.h> // Includes all standard libraries as per instructions
using namespace std;     // Uses the standard namespace as per instructions

void solve() {
    int X;
    cin >> X; // Read the number of slices Chef wants to cut

    // Find the largest power of 2 (pow2) such that pow2 <= X.
    // This represents the state where Chef has cut the pizza into pow2 equal slices,
    // and these are the largest possible equal slices that fit within X.
    int pow2 = 1;
    while ((pow2 << 1) <= X) { // (pow2 << 1) is equivalent to pow2 * 2
        pow2 <<= 1;            // Double pow2
    }

    // The number of additional cuts made beyond the 'pow2' state is (X - pow2).
    // Each additional cut takes one of the current largest slices and divides it into two smaller slices.
    // Therefore, (X - pow2) large slices have been converted into 2 * (X - pow2) smaller slices.
    // These 2 * (X - pow2) slices are the ones that are smaller than the rest.
    cout << 2 * (X - pow2) << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}