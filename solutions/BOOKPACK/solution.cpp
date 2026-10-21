#include <bits/stdc++.h> // Required include for competitive programming, includes most standard libraries

using namespace std; // Required to use standard library components without the std:: prefix

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z; // Read the three integers X, Y, Z for the current test case

    // Calculate the minimum number of boxes needed for a single shelf.
    // Each shelf has Y books. Each box can hold at most Z books.
    // To minimize boxes, we fill each box to its maximum capacity Z.
    // This is equivalent to calculating ceil(Y / Z).
    // In integer arithmetic, ceil(A / B) can be efficiently calculated as (A + B - 1) / B.
    // For example:
    // If Y=9, Z=9: (9 + 9 - 1) / 9 = 17 / 9 = 1 box.
    // If Y=9, Z=7: (9 + 7 - 1) / 7 = 15 / 7 = 2 boxes (one with 7, one with 2).
    // If Y=3, Z=2: (3 + 2 - 1) / 2 = 4 / 2 = 2 boxes (one with 2, one with 1).
    int boxes_per_shelf = (Y + Z - 1) / Z;

    // The problem states that books from different shelves cannot be placed in the same box.
    // This means that the packing for each of the X shelves is independent.
    // Therefore, the total minimum number of boxes is simply the number of shelves (X)
    // multiplied by the minimum number of boxes required for a single shelf (boxes_per_shelf).

    // The maximum possible value for X, Y, Z is 1000.
    // Maximum boxes_per_shelf = (1000 + 1 - 1) / 1 = 1000 (when Y=1000, Z=1).
    // Maximum total_boxes = X * boxes_per_shelf = 1000 * 1000 = 1,000,000.
    // This value fits comfortably within a standard 32-bit integer type (int).
    // However, it's a good practice in competitive programming to use 'long long' for results
    // of multiplications to prevent potential overflow, especially if constraints were slightly larger.
    long long total_boxes = (long long)X * boxes_per_shelf;

    cout << total_boxes << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T in each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}