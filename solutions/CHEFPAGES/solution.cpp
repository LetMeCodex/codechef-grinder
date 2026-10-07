#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations by not synchronizing with C's stdio.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O, especially in interactive problems or those with
    // mixed input and output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables, A and B, to store the input values.
    // A represents whether the user has submitted on the practice page (1 for yes, 0 for no).
    // B represents whether the user has participated in a contest (1 for yes, 0 for no).
    int A, B;

    // Read the two space-separated integers A and B from standard input.
    cin >> A >> B;

    // The problem defines three conditions based on A and B to determine
    // which URL to output. We implement these conditions using if-else if-else statements.

    // Condition 1: If the user has never submitted on the practice page (A = 0).
    // This condition takes precedence. If A is 0, it doesn't matter what B is.
    if (A == 0) {
        // Output the link to the practice page.
        cout << "https://www.codechef.com/practice\n";
    }
    // If A is not 0, it must be 1 (since A is constrained to be 0 or 1).
    // This means the user HAS submitted on the practice page.
    else { // A == 1
        // Now we check the second condition: if the user has submitted on the practice page (A=1)
        // but has never participated in a contest (B = 0).
        if (B == 0) {
            // Output the link to the contests page.
            cout << "https://www.codechef.com/contests\n";
        }
        // If B is not 0, it must be 1 (since B is constrained to be 0 or 1).
        // This implies that A=1 AND B=1, meaning the user has submitted on the practice page
        // AND has participated in a contest.
        else { // B == 1
            // Output the link to the discuss forum.
            cout << "https://discuss.codechef.com\n";
        }
    }

    // The program successfully completes after printing the required output.
    return 0;
}