#include <bits/stdc++.h> // Includes all standard libraries, as requested

using namespace std; // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the number of problems
    // solved in each of the four weeks.
    int p1, p2, p3, p4;

    // Read the four integers from a single line of input.
    cin >> p1 >> p2 >> p3 >> p4;

    // Initialize a counter to keep track of how many weeks Chef met his target.
    int weeks_met_target = 0;

    // Check if Chef solved at least 10 problems in the first week.
    if (p1 >= 10) {
        weeks_met_target++; // If yes, increment the counter.
    }

    // Check for the second week.
    if (p2 >= 10) {
        weeks_met_target++;
    }

    // Check for the third week.
    if (p3 >= 10) {
        weeks_met_target++;
    }

    // Check for the fourth week.
    if (p4 >= 10) {
        weeks_met_target++;
    }

    // Output the final count of weeks where the target was met,
    // followed by a newline character.
    cout << weeks_met_target << "\n";

    return 0; // Indicate successful program execution.
}