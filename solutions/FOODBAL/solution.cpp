#include <bits/stdc++.h> // Includes common headers like iostream, cmath, etc.

// Using namespace std; is common in competitive programming to avoid prefixing standard library elements with std::
using namespace std; 

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare four integer variables to store the fat and protein quantities for two dishes.
    int F1, P1, F2, P2;

    // Read the four space-separated integers from the standard input.
    // F1, P1 are for the first dish; F2, P2 are for the second dish.
    cin >> F1 >> P1 >> F2 >> P2;

    // Calculate the absolute difference between fat and protein for the first dish.
    // The abs() function (from <cmath> or <cstdlib>) returns the absolute value.
    int diff1 = abs(F1 - P1);

    // Calculate the absolute difference between fat and protein for the second dish.
    int diff2 = abs(F2 - P2);

    // Compare the calculated differences to determine Chef's choice.
    if (diff1 < diff2) {
        // If the first dish has a smaller difference, Chef chooses the first dish.
        cout << "First\n";
    } else if (diff2 < diff1) {
        // If the second dish has a smaller difference, Chef chooses the second dish.
        cout << "Second\n";
    } else { // This condition implies diff1 == diff2
        // If both dishes have the same difference, Chef considers them equivalent.
        cout << "Both\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}