#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the input.
    cin >> N; // Read the integer N from standard input.

    // Calculate the remainder when N is divided by 3.
    // This remainder determines how far N is from the nearest multiple of 3.
    int remainder = N % 3;

    // Based on the remainder, determine the nearest multiple of 3.
    if (remainder == 0) {
        // If N is already a multiple of 3 (remainder is 0),
        // N itself is the nearest multiple of 3.
        cout << N << "\n";
    } else if (remainder == 1) {
        // If N has a remainder of 1 when divided by 3 (e.g., 1, 4, 7, 10),
        // then N-1 is a multiple of 3 and is 1 unit away from N.
        // The next multiple of 3, N+2, would be 2 units away.
        // Thus, N-1 is the nearest multiple of 3.
        cout << N - 1 << "\n";
    } else { // remainder == 2
        // If N has a remainder of 2 when divided by 3 (e.g., 2, 5, 8),
        // then N+1 is a multiple of 3 and is 1 unit away from N.
        // The previous multiple of 3, N-2, would be 2 units away.
        // Thus, N+1 is the nearest multiple of 3.
        cout << N + 1 << "\n";
    }

    return 0; // Indicate successful program execution.
}