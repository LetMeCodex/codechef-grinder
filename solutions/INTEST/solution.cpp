#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can significantly speed up input-heavy programs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    // Read the two positive integers n and k from the first line of input.
    // n represents the number of subsequent integers, and k is the divisor.
    cin >> n >> k;

    int count = 0; // Initialize a counter for numbers divisible by k.

    // Loop n times to read each of the n subsequent integers.
    for (int i = 0; i < n; ++i) {
        int ti;
        // Read the current integer ti.
        cin >> ti;

        // Check if ti is divisible by k.
        // The modulo operator (%) returns the remainder of a division.
        // If the remainder is 0, ti is divisible by k.
        if (ti % k == 0) {
            count++; // Increment the counter if ti is divisible by k.
        }
    }

    // Print the total count of integers divisible by k, followed by a newline.
    cout << count << "\n";

    return 0; // Indicate successful execution.
}