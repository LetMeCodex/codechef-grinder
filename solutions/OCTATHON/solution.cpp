#include <bits/stdc++.h> // Standard header for competitive programming
using namespace std;     // Using the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the time taken by Chefina.
    int X;

    // Read the input value for X.
    cin >> X;

    // Apply the conditional logic to determine the medal type based on X.
    // The conditions are checked in order:
    // 1. If X is less than 3 hours, it's a GOLD medal.
    if (X < 3) {
        cout << "GOLD\n";
    }
    // 2. Else if X is less than 6 hours (and we already know it's >= 3 hours from the previous check),
    //    it's a SILVER medal.
    else if (X < 6) { // This implicitly means X >= 3 and X < 6
        cout << "SILVER\n";
    }
    // 3. Else (if X is not less than 3 and not less than 6, meaning X is greater than or equal to 6 hours),
    //    it's a BRONZE medal.
    else { // This implicitly means X >= 6
        cout << "BRONZE\n";
    }

    // Return 0 to indicate successful execution of the program.
    return 0;
}