#include <bits/stdc++.h> // Includes most standard libraries, as per problem instructions

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

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
        int N; // Declare an integer variable N to store the number of candies.
        cin >> N; // Read the number of candies for the current test case.

        // To distribute N candies equally among three friends such that all candies
        // are used and each friend gets an integer number of candies, N must be
        // perfectly divisible by 3.
        // If N % 3 == 0, then each friend gets N/3 candies.
        // Otherwise, it's impossible to distribute them equally.
        if (N % 3 == 0) {
            cout << "YES\n"; // If N is divisible by 3, output "YES".
        } else {
            cout << "NO\n"; // Otherwise, output "NO".
        }
    }

    return 0; // Indicate successful program execution.
}