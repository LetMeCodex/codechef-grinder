#include <bits/stdc++.h> // Includes most standard libraries
using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int A, B, C; // Declare three integer variables for the digits of the lottery ticket
        cin >> A >> B >> C; // Read the three digits A, B, and C from standard input

        // Check if any of the digits A, B, or C is equal to 7.
        // The problem states Chef wins if AT LEAST ONE of the digits is 7.
        if (A == 7 || B == 7 || C == 7) {
            // If the condition is true, Chef wins, so print "YES"
            cout << "YES\n";
        } else {
            // If the condition is false (none of the digits are 7), Chef does not win, so print "NO"
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution
}