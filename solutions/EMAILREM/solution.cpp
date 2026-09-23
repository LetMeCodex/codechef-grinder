#include <bits/stdc++.h> // Includes all standard libraries, common in competitive programming

using namespace std; // Uses the standard namespace to avoid prefixing std::

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables, N and U.
    // N will store the total number of participants.
    // U will store the number of participants who do not want to receive emails.
    int N, U;

    // Read the two space-separated integers N and U from standard input.
    cin >> N >> U;

    // The problem asks for the number of participants MoEngage should send emails to.
    // This is simply the total number of participants (N) minus those who opted out (U).
    int participants_to_email = N - U;

    // Output the calculated number of participants to standard output,
    // followed by a newline character as required.
    cout << participants_to_email << "\n";

    // Return 0 to indicate successful program execution.
    return 0;
}