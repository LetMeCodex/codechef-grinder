#include <bits/stdc++.h> // Includes most standard library headers

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, Z; // Variables for gym cost, trainer cost, and budget
        cin >> X >> Y >> Z; // Read X, Y, Z for the current test case

        // Condition 1: Can Chef afford both the gym membership and a personal trainer?
        // The total cost for both is X (gym) + Y (trainer).
        if (X + Y <= Z) {
            cout << 2 << "\n"; // If affordable, output 2
        } 
        // Condition 2: If Chef cannot afford both, can he at least afford only the gym membership?
        // This 'else if' block is reached only if X + Y > Z (meaning trainer is too expensive).
        else if (X <= Z) {
            cout << 1 << "\n"; // If only gym is affordable, output 1
        } 
        // Condition 3: If Chef cannot even afford the gym membership (X > Z).
        // This 'else' block is reached only if X > Z (meaning even the gym is too expensive).
        else {
            cout << 0 << "\n"; // If nothing is affordable, output 0
        }
    }

    return 0; // Indicate successful program execution
}