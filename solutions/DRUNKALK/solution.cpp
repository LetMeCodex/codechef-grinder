#include <bits/stdc++.h> // Standard header for competitive programming

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop T times, once for each test case.
    while (T--) {
        int k; // Declare an integer variable k for the number of seconds.
        cin >> k; // Read the value of k for the current test case.

        // Determine Faizal's final position based on whether k is even or odd.
        if (k % 2 == 0) {
            // If k is an even number of seconds:
            // Faizal completes k/2 full cycles of movement.
            // Each cycle consists of 3 steps forward and then 1 step backward,
            // resulting in a net displacement of +2 steps per cycle.
            // So, after k/2 cycles, the total displacement is (k/2) * 2 = k.
            cout << k << "\n";
        } else {
            // If k is an odd number of seconds:
            // Faizal completes (k-1)/2 full cycles of movement,
            // and then takes one final 3 steps forward.
            // The (k-1)/2 cycles result in a displacement of ((k-1)/2) * 2 = k-1 steps.
            // The final 3 steps forward add 3 more to this displacement.
            // So, the total displacement is (k-1) + 3 = k+2.
            cout << k + 2 << "\n";
        }
    }

    return 0; // Indicate successful execution of the program.
}