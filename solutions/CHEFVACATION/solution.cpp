#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

// Main function where the program execution begins
int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable 'T' to store the number of test cases.
    int T;
    // Read the number of test cases from standard input.
    cin >> T;

    // Loop 'T' times, processing one test case in each iteration.
    while (T--) {
        // Declare three integer variables X, Y, and Z.
        // X: duration of the family trip.
        // Y: duration of the friends trip.
        // Z: total duration of the vacation.
        int X, Y, Z;
        // Read the values of X, Y, and Z for the current test case.
        cin >> X >> Y >> Z;

        // The Chef can go on both trips if and only if the total days required for both trips
        // (X + Y) is less than or equal to the total available vacation days (Z).
        // This is because the trips cannot overlap, so the minimum total time needed is the sum of their durations.
        if (X + Y <= Z) {
            // If the condition is met, Chef can go on both trips. Print "YES".
            cout << "YES\n";
        } else {
            // Otherwise, Chef cannot go on both trips as there aren't enough days. Print "NO".
            cout << "NO\n";
        }
    }

    // Return 0 to indicate successful program execution.
    return 0;
}