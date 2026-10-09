#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        int A, B;
        cin >> A >> B; // Read the two numbers A and B

        int diff = B - A; // Calculate the difference B - A

        // Chef can make A equal to B if the difference (B-A)
        // is not congruent to 2 modulo 3.
        // This means (B-A) % 3 must be either 0 or 1.
        if (diff % 3 == 2) {
            cout << "NO\n"; // If diff % 3 is 2, it's impossible
        } else {
            cout << "YES\n"; // Otherwise (diff % 3 is 0 or 1), it's possible
        }
    }

    return 0; // Indicate successful execution
}