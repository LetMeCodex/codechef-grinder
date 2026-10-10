#include <bits/stdc++.h> // Includes most standard libraries, as requested by the problem statement.

using namespace std; // Uses the standard namespace, as requested by the problem statement.

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to avoid TLE (Time Limit Exceeded) on large inputs.
    ios_base::sync_with_stdio(false); // Unties C++ streams from C standard streams.
    cin.tie(NULL); // Unties cin from cout, preventing flushing of cout before each cin.

    int T;
    cin >> T; // Read the number of testcases.

    while (T--) { // Loop T times, processing each testcase.
        int N, X, Y;
        cin >> N >> X >> Y; // Read the three integers N, X, Y for the current testcase.

        // Calculate the total number of people going to the gold mine.
        // Chef + N friends = N + 1 people.
        int total_people = N + 1;

        // Calculate the maximum total amount of gold all people can carry together.
        // Each person can carry at most Y kg.
        // So, total_carrying_capacity = (total_people) * Y.
        // Given N, X, Y <= 1000, the maximum value for (N+1)*Y would be (1000+1)*1000 = 1,001,000.
        // This value fits comfortably within a standard 32-bit signed integer type (like 'int' in C++),
        // which typically holds values up to ~2 * 10^9. So, 'long long' is not strictly necessary but harmless.
        int total_carrying_capacity = total_people * Y;

        // Check if the total carrying capacity is sufficient to carry all the gold (X kg).
        if (total_carrying_capacity >= X) {
            cout << "YES\n"; // If capacity is enough or more, output "YES".
        } else {
            cout << "NO\n"; // Otherwise, output "NO".
        }
    }

    return 0; // Indicate successful program execution.
}