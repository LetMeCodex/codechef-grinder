#include <bits/stdc++.h> // Includes most standard libraries

// It's common in competitive programming to use the entire std namespace
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X; // Read N and X

    int result;
    if (X % 2 == 0) { // If X is an even number
        // For the sum (chosen_card + X) to be even, chosen_card must also be even.
        // We need to count the number of even cards remaining in the deck.
        // Total even cards in the range [1, N] is N / 2 (integer division).
        // Since X is an even card and it's removed, the count of available even cards decreases by 1.
        result = (N / 2) - 1;
    } else { // If X is an odd number
        // For the sum (chosen_card + X) to be even, chosen_card must also be odd.
        // We need to count the number of odd cards remaining in the deck.
        // Total odd cards in the range [1, N] is (N + 1) / 2 (integer division).
        // Since X is an odd card and it's removed, the count of available odd cards decreases by 1.
        result = ((N + 1) / 2) - 1;
    }
    cout << result << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}