#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

void solve() {
    int K;
    cin >> K; // Read the number of people playing
    
    const int total_cards = 52; // Alice starts with 52 cards
    
    // The minimum number of cards to discard is the remainder when total_cards is divided by K.
    // This remainder represents the 'excess' cards that cannot be distributed equally.
    int discarded_cards = total_cards % K;
    
    cout << discarded_cards << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times for each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}