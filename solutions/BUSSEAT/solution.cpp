#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Fast I/O setup to speed up input and output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, processing each test case
        int N, K;
        cin >> N >> K; // Read N (number of rows) and K (number of people) for the current test case

        // Apply the derived logic:
        // If K (number of people) is less than or equal to N (number of rows),
        // every person can find an empty row and sit alone.
        // In this scenario, no one ends up sitting next to somebody else.
        if (K <= N) {
            cout << 0 << "\n"; // Output 0 as the count
        } 
        // If K (number of people) is greater than N (number of rows),
        // the first N people will occupy N distinct rows, making them half-full.
        // The remaining (K - N) people will not find any empty rows.
        // They must sit next to someone in an already occupied row.
        // Each time a person sits next to someone, two people (the new person and their seatmate)
        // are now sitting next to somebody else.
        // So, the total count is 2 times the number of people who were forced to sit next to someone.
        else {
            cout << 2 * (K - N) << "\n"; // Output 2 * (K - N) as the count
        }
    }

    return 0; // Indicate successful program execution
}