#include <bits/stdc++.h> // Includes most standard library headers for competitive programming

// Use the standard namespace to avoid prefixing std:: to standard library elements
using namespace std;

// Function to reverse a two-digit number.
// For a number N = 10*d1 + d0, its reverse is 10*d0 + d1.
// Example: reverse_two_digit(37) -> 73
// Example: reverse_two_digit(14) -> 41
int reverse_two_digit(int n) {
    int tens_digit = n / 10;   // Extract the tens digit (e.g., 37 / 10 = 3)
    int units_digit = n % 10;  // Extract the units digit (e.g., 37 % 10 = 7)
    return units_digit * 10 + tens_digit; // Form the reversed number (e.g., 7 * 10 + 3 = 73)
}

// Function to solve a single test case
void solve() {
    int A, B; // Alice's and Bob's scores
    cin >> A >> B; // Read the scores from standard input

    // Calculate all possible scores for Alice
    int alice_score_original = A;                 // Alice's score without reversal
    int alice_score_reversed = reverse_two_digit(A); // Alice's score with reversal

    // Calculate all possible scores for Bob
    int bob_score_original = B;                   // Bob's score without reversal
    int bob_score_reversed = reverse_two_digit(B);   // Bob's score with reversal

    // Check if Alice can make her score strictly higher than Bob's
    // We need to check all four combinations of scores:
    // 1. Alice's original vs Bob's original
    // 2. Alice's original vs Bob's reversed
    // 3. Alice's reversed vs Bob's original
    // 4. Alice's reversed vs Bob's reversed
    if (alice_score_original > bob_score_original ||
        alice_score_original > bob_score_reversed ||
        alice_score_reversed > bob_score_original ||
        alice_score_reversed > bob_score_reversed) {
        cout << "Yes\n"; // If any combination works, print "Yes" followed by a newline
    } else {
        cout << "No\n"; // If no combination works, print "No" followed by a newline
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further improving performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}