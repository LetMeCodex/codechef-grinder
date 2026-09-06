#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and
    // prevents synchronization overhead, making I/O faster.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer T to store the number of test cases.
    cin >> T; // Read the total number of test cases.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B; // Declare two integers A and B for the current test case.
        cin >> A >> B; // Read the two integers A and B.

        // Calculate the remainder when A is divided by B using the modulo operator (%).
        // Print the result followed by a newline character.
        cout << (A % B) << "\n";
    }

    return 0; // Indicate successful execution of the program.
}