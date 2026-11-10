#include <bits/stdc++.h> // Includes common headers like iostream, etc.

using namespace std; // Use the standard namespace

void solve() {
    int N;
    cin >> N; // Read the number of candy packs

    int sum_candies = 0; // Initialize total candies to 0
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the number of candies in the current pack
        sum_candies += A_i; // Add to the total sum
    }

    // If the total sum of candies is odd, it's possible to make both happy.
    // Otherwise, it's not possible.
    if (sum_candies % 2 == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}