#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        // Declare six integer variables to store medal counts for two countries
        int G1, S1, B1; // Gold, Silver, Bronze for Country 1
        int G2, S2, B2; // Gold, Silver, Bronze for Country 2

        // Read the medal counts for both countries
        cin >> G1 >> S1 >> B1 >> G2 >> S2 >> B2;

        // Calculate the total number of medals for Country 1
        int total_medals_1 = G1 + S1 + B1;

        // Calculate the total number of medals for Country 2
        int total_medals_2 = G2 + S2 + B2;

        // Compare the total medals to determine which country is ranked better
        // The problem guarantees there will not be a tie.
        if (total_medals_1 > total_medals_2) {
            // If Country 1 has more medals, print "1"
            cout << "1\n";
        } else {
            // Otherwise (Country 2 must have more medals), print "2"
            cout << "2\n";
        }
    }

    return 0; // Indicate successful execution
}