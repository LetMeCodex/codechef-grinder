#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid typing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the time taken to write one page.
           // X is constrained between 1 and 1000, so 'int' is sufficient.
    
    // Read the value of X from standard input.
    cin >> X;

    // Calculate the total time Rahul needs to complete the 5-page assignment.
    // Total pages = 5. Time per page = X minutes.
    // Total time needed = 5 * X minutes.
    int total_time_needed = 5 * X;

    // The assignment is due in 60 minutes.
    // Check if the total time Rahul needs is less than or equal to the available time.
    if (total_time_needed <= 60) {
        // If Rahul can complete the assignment within 60 minutes, print "YES".
        cout << "YES\n";
    } else {
        // Otherwise, Rahul cannot complete the assignment in time, so print "NO".
        cout << "NO\n";
    }

    return 0; // Indicate successful program execution.
}