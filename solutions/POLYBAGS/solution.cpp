#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which speeds up I/O operations significantly.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int N; // Declare an integer variable N for the number of items
        cin >> N; // Read the number of items for the current test case

        // Calculate the minimum number of polybags needed.
        // Each polybag can contain at most 10 items.
        // This is a classic ceiling division problem: ceil(N / 10).
        // In integer arithmetic, for positive integers 'a' and 'b',
        // ceil(a / b) can be calculated as (a + b - 1) / b.
        // Here, 'a' is N and 'b' is 10.
        // So, the formula becomes (N + 10 - 1) / 10, which simplifies to (N + 9) / 10.
        //
        // Example:
        // N = 20: (20 + 9) / 10 = 29 / 10 = 2. (2 polybags)
        // N = 24: (24 + 9) / 10 = 33 / 10 = 3. (3 polybags)
        // N = 99: (99 + 9) / 10 = 108 / 10 = 10. (10 polybags)
        // N = 1: (1 + 9) / 10 = 10 / 10 = 1. (1 polybag)
        int polybags_needed = (N + 9) / 10;

        // Output the result for the current test case, followed by a newline character.
        // Using "\n" is generally faster than endl in competitive programming
        // because endl also forces a flush of the output buffer.
        cout << polybags_needed << "\n";
    }

    return 0; // Indicate successful program execution
}