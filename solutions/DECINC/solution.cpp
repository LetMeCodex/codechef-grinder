#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input number.
    // The constraints (0 <= N <= 1000) ensure that 'int' is sufficient
    // to store N and its modified value (N-1 or N+1) without overflow.
    int N;

    // Read the integer N from standard input.
    cin >> N;

    // Check if N is divisible by 4.
    // The modulo operator (%) returns the remainder of a division.
    // If N % 4 is 0, it means N is perfectly divisible by 4.
    if (N % 4 == 0) {
        // If N is divisible by 4, increment its value by 1.
        // Then print the new value followed by a newline character.
        cout << N + 1 << "\n";
    } else {
        // If N is not divisible by 4, decrement its value by 1.
        // Then print the new value followed by a newline character.
        cout << N - 1 << "\n";
    }

    // Return 0 to indicate successful program execution.
    return 0;
}