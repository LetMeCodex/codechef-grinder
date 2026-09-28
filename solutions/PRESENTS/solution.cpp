#include <bits/stdc++.h> // Required by problem statement to include most standard libraries
using namespace std;     // Required by problem statement to use standard namespace

void solve() {
    int N; // Declare N to store the number of gifts
    cin >> N; // Read the number of gifts for the current test case

    // Calculate the minimum number of coins required.
    // For every 5 gifts, Chef gets 1 free.
    // So, the number of free gifts is N / 5 (integer division).
    // The number of gifts Chef actually pays for is N - (number of free gifts).
    // Since each paid gift costs 1 coin, this is the total coins needed.
    int coins_needed = N - (N / 5);
    
    cout << coins_needed << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and disables synchronization
    // with C stdio, making I/O operations faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare T to store the number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}