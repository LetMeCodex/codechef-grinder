#include <bits/stdc++.h> // Includes most standard libraries, including iostream and algorithm

// Use the standard namespace to avoid prefixing std::
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k; // Read N and K for the current test case

    int max_coins_for_tuzik = 0; // Initialize the maximum coins Tuzik can get

    // Iterate through all possible numbers of people Tuzik can call
    // P ranges from 1 to K, inclusive.
    for (int p = 1; p <= k; ++p) {
        // Calculate the number of coins Tuzik gets if P people are called
        // This is simply the remainder when N is divided by P.
        int current_coins = n % p;
        
        // Update max_coins_for_tuzik if the current remainder is greater
        max_coins_for_tuzik = max(max_coins_for_tuzik, current_coins);
    }

    // Output the maximum coins Tuzik can get, followed by a newline
    cout << max_coins_for_tuzik << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases

    // Loop through each test case
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}