#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        string D;
        cin >> D; // Read the binary string D

        int count0 = 0; // Counter for '0's
        int count1 = 0; // Counter for '1's

        // Iterate through each character of the string D
        for (char c : D) {
            if (c == '0') {
                count0++; // Increment count0 if the character is '0'
            } else { // The problem states D contains only '0's and '1's, so if not '0', it must be '1'
                count1++; // Increment count1 if the character is '1'
            }
        }

        // Check the condition:
        // If there is exactly one '0' (it can be flipped to '1' to make all '1's)
        // OR if there is exactly one '1' (it can be flipped to '0' to make all '0's)
        if (count0 == 1 || count1 == 1) {
            cout << "Yes\n"; // Output "Yes" if possible
        } else {
            cout << "No\n"; // Output "No" otherwise
        }
    }

    return 0; // Indicate successful execution
}