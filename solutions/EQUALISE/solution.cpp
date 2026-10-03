#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace, as requested.
using namespace std;

// Function to get the largest odd divisor of a number.
// This is done by repeatedly dividing the number by 2 until it becomes odd.
int get_largest_odd_divisor(int n) {
    // Since constraints are 1 <= A, B, n will always be positive.
    // The loop continues as long as n is even.
    while (n % 2 == 0) {
        n /= 2;
    }
    return n; // The remaining n is the largest odd divisor
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T each iteration
        int A, B;
        cin >> A >> B; // Read the two numbers A and B for the current test case

        // Calculate the largest odd divisor for both A and B.
        // If A can be transformed into X and B can be transformed into X,
        // then X must have the same largest odd divisor as A, and also as B.
        // Therefore, A and B must have the same largest odd divisor initially.
        int odd_A = get_largest_odd_divisor(A);
        int odd_B = get_largest_odd_divisor(B);

        // Compare the largest odd divisors.
        if (odd_A == odd_B) {
            // If they are equal, Chef can make A and B equal.
            // For example, if A = odd_A * 2^p and B = odd_B * 2^q,
            // and odd_A == odd_B, then we can multiply the number with the smaller
            // power of 2 until its power of 2 matches the other.
            cout << "YES\n";
        } else {
            // If they are not equal, Chef cannot make A and B equal,
            // because multiplying by 2 only changes the power of 2 factor,
            // not the odd part.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful execution
}