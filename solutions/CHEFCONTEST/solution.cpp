#include <iostream> // Required for standard input/output operations

// It's common in competitive programming to include <bits/stdc++.h>
// which includes most standard library headers.
// For this problem, <iostream> is sufficient.
// #include <bits/stdc++.h> 

// Using the standard namespace to avoid repeatedly typing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, P, Q; // Variables to store Chef's time, Chefina's time, Chef's wrong submissions, Chefina's wrong submissions
        cin >> X >> Y >> P >> Q; // Read the four integers for the current test case

        // Calculate Chef's total penalty
        // Base time penalty is X minutes.
        // Each wrong submission (P) adds 10 minutes penalty.
        int chef_penalty = X + (P * 10);

        // Calculate Chefina's total penalty
        // Base time penalty is Y minutes.
        // Each wrong submission (Q) adds 10 minutes penalty.
        int chefina_penalty = Y + (Q * 10);

        // Compare the penalties to determine the winner or a draw
        if (chef_penalty < chefina_penalty) {
            // If Chef's penalty is less, Chef wins
            cout << "Chef\n";
        } else if (chefina_penalty < chef_penalty) {
            // If Chefina's penalty is less, Chefina wins
            cout << "Chefina\n";
        } else {
            // If both penalties are equal, it's a draw
            cout << "Draw\n";
        }
    }

    return 0; // Indicate successful execution
}