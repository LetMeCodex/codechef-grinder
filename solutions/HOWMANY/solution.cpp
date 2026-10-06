#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input number.
    // The problem constraints state 0 <= N <= 1000000, which fits within a standard 'int'.
    int N;

    // Read the number N from standard input.
    cin >> N;

    // Use a series of if-else if statements to determine the number of digits.
    // The conditions are ordered from smallest to largest number of digits.

    // If N is between 0 and 9 (inclusive), it's a 1-digit number.
    // The condition N <= 9 covers this, as N is guaranteed to be non-negative by constraints.
    if (N <= 9) {
        cout << "1\n";
    }
    // If N is not <= 9, it means N >= 10.
    // If N is also <= 99, then it's a 2-digit number (10 to 99).
    else if (N <= 99) {
        cout << "2\n";
    }
    // If N is not <= 99, it means N >= 100.
    // If N is also <= 999, then it's a 3-digit number (100 to 999).
    else if (N <= 999) {
        cout << "3\n";
    }
    // If none of the above conditions are met, it means N is greater than 999.
    // According to the problem, such numbers have "More than 3 digits".
    // This covers numbers from 1000 up to the maximum constraint of 1000000.
    else {
        cout << "More than 3 digits\n";
    }

    return 0; // Indicate successful program execution.
}