#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int g, c; // Declare integer variables g (gravity) and c (speed of light).
        cin >> g >> c; // Read g and c for the current test case.

        // Calculate c^2.
        // We cast 'c' to 'long long' before multiplication to ensure that
        // the product c*c is computed as a long long, preventing potential
        // integer overflow if 'c' were larger (though for the given constraints,
        // int would suffice for c*c).
        long long c_squared = (long long)c * c;

        // Calculate the required height H using the formula H = c^2 / (2 * g).
        // The problem guarantees that (2 * g) divides c^2, so the result will be an integer.
        long long H = c_squared / (2 * g);

        // Output the calculated height H, followed by a newline character.
        cout << H << "\n";
    }

    return 0; // Indicate successful program execution.
}