#include <bits/stdc++.h> // Required include for competitive programming

// Required namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop through each test case. The 't--' decrements 't' after each iteration
    // and the loop continues as long as 't' is greater than 0.
    while (t--) {
        int n, m; // Declare integer variables 'n' for bikes and 'm' for cars.
        cin >> n >> m; // Read the number of bikes (N) and cars (M) for the current test case.

        // Calculate the total number of tyres.
        // Each bike has 2 tyres, so N bikes have N * 2 tyres.
        // Each car has 4 tyres, so M cars have M * 4 tyres.
        // The total is the sum of tyres from bikes and cars.
        int total_tyres = (n * 2) + (m * 4);

        // Output the calculated total number of tyres for the current test case.
        // A newline character ("\n") is appended to ensure each output is on a new line,
        // as required by the output format.
        cout << total_tyres << "\n";
    }

    return 0; // Indicate successful program execution.
}