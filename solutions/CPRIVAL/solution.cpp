#include <bits/stdc++.h> // Includes iostream and many other useful headers

using namespace std; // Brings all names from std namespace into global scope

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare integer variables to store Dominater's and Everule's initial ratings.
    int R1, R2;
    // Read the initial ratings from the first line of input.
    cin >> R1 >> R2;

    // Declare integer variables to store Dominater's and Everule's rating changes.
    int D1, D2;
    // Read the rating changes from the second line of input.
    cin >> D1 >> D2;

    // Calculate Dominater's final rating after the contest.
    // Final rating = Initial rating + Rating change.
    int final_R1 = R1 + D1;

    // Calculate Everule's final rating after the contest.
    // Final rating = Initial rating + Rating change.
    int final_R2 = R2 + D2;

    // Compare the final ratings to determine who has a higher rating.
    // The problem guarantees that their final ratings will not be equal.
    if (final_R1 > final_R2) {
        // If Dominater's final rating is higher, print "Dominater".
        cout << "Dominater\n";
    } else {
        // Otherwise (if Everule's final rating is higher), print "Everule".
        cout << "Everule\n";
    }

    return 0; // Indicate successful execution of the program.
}