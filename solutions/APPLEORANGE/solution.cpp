#include <bits/stdc++.h> // Includes iostream, numeric, and other standard libraries as requested

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, processing each test case.
    while (T--) {
        long long N, M; // Declare two long long variables for N (number of apples)
                        // and M (number of oranges).
                        // 'long long' is used to safely handle input values up to 10^9.
        cin >> N >> M; // Read N and M for the current test case.

        // Calculate the Greatest Common Divisor (GCD) of N and M.
        // The std::gcd function is part of the C++ Standard Library (available since C++17)
        // and is typically found in the <numeric> header.
        // The GCD represents the maximum number of contestants such that
        // both N apples and M oranges can be divided equally among them.
        long long result = std::gcd(N, M);

        // Print the calculated result followed by a newline character.
        // Using "\n" instead of std::endl is generally preferred in competitive programming
        // for performance, as "\n" only adds a newline character, while std::endl also
        // forces a flush of the output buffer, which can be slower.
        cout << result << "\n";
    }

    return 0; // Indicate successful program execution.
}