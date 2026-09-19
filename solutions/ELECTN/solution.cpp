#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N; // Declare N for the number of people
        int X; // Declare X for the minimum voting age
        cin >> N >> X; // Read N and X for the current test case

        int eligible_voters_count = 0; // Initialize a counter for eligible voters

        // Loop N times to read the age of each person
        for (int i = 0; i < N; ++i) {
            int age; // Declare a variable to store the current person's age
            cin >> age; // Read the age of the current person

            // Check if the person's age meets the minimum requirement
            // A person needs to be "at least X years old", which means age >= X
            if (age >= X) {
                eligible_voters_count++; // If eligible, increment the counter
            }
        }

        // Output the total number of eligible voters for the current test case
        // Each output should be on a new line, as indicated by "\n"
        cout << eligible_voters_count << "\n";
    }

    return 0; // Indicate successful program execution
}