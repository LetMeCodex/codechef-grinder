#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y; // Declare two integer variables for runtimes

    // Read the two space-separated integers X and Y from standard input
    cin >> X >> Y;

    // Compare the runtimes to determine which system is faster
    if (Y < X) {
        // If the new system's runtime (Y) is less than the old system's (X),
        // the new system is faster.
        cout << "New\n";
    } else if (X < Y) {
        // If the old system's runtime (X) is less than the new system's (Y),
        // the old system is faster.
        cout << "Old\n";
    } else {
        // If both runtimes are equal, they are equally fast.
        cout << "Same\n";
    }

    return 0; // Indicate successful execution
}