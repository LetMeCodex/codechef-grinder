#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int N; // Declare an integer variable N for the year
        cin >> N; // Read the year N for the current test case

        // Check if the year N is one of the years SnackDown was hosted.
        // The problem statement lists these specific years: 2010, 2015, 2016, 2017, 2019.
        if (N == 2010 || N == 2015 || N == 2016 || N == 2017 || N == 2019) {
            // If N matches any of the hosted years, print "HOSTED"
            cout << "HOSTED\n";
        } else {
            // Otherwise (if N is not one of the hosted years), print "NOT HOSTED"
            cout << "NOT HOSTED\n";
        }
    }

    return 0; // Indicate successful program execution
}