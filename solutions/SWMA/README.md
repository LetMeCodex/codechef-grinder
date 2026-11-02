# [Swapping Marks Digits (SWMA)](https://www.codechef.com/problems/SWMA)
- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary

Alice and Bob receive marks, both of which are two-digit numbers. They each have the option to either keep their original mark or reverse the digits of their mark. Alice wins if, after they both make their choice, her final mark is strictly greater than Bob's final mark. We need to determine if Alice can make choices such that she wins.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the choices available to Alice and Bob, and how to reverse a two-digit number.

1.  **Two-Digit Numbers**: The problem explicitly states that marks are two-digit numbers. This simplifies the digit reversal process. For any two-digit number `N`, let its tens digit be `d1` and its units digit be `d0`. So, `N = 10 * d1 + d0`. Reversing its digits results in `10 * d0 + d1`.
    *   Example: If `N = 37`, `d1 = 3`, `d0 = 7`. Reversed `N` is `10 * 7 + 3 = 73`.

2.  **Available Marks**:
    *   Alice has two possible marks: her original mark `A`, or the reversed version of `A`, let's call it `reverse(A)`.
    *   Bob also has two possible marks: his original mark `B`, or the reversed version of `B`, `reverse(B)`.

3.  **Winning Condition**: Alice wins if her chosen mark is *strictly greater* than Bob's chosen mark.

4.  **Finding if Alice Can Win**: Since Alice wants to win, she will try to maximize her score, and Bob's score is irrelevant to her choice (she just needs to beat *some* version of Bob's score). We need to check if there exists *any* combination of choices (one for Alice, one for Bob) where Alice's mark is strictly greater than Bob's.
    This means we must consider all four possible pairings:
    *   Alice's original mark (`A`) vs. Bob's original mark (`B`)
    *   Alice's original mark (`A`) vs. Bob's reversed mark (`reverse(B)`)
    *   Alice's reversed mark (`reverse(A)`) vs. Bob's original mark (`B`)
    *   Alice's reversed mark (`reverse(A)`) vs. Bob's reversed mark (`reverse(B)`)

    If *any* of these four comparisons results in Alice's mark being strictly greater, then Alice can win, and we output "Yes". If none of these combinations work, then Alice cannot win, and we output "No".

The solution implements a helper function `reverse_two_digit` to handle the digit reversal and then checks these four conditions using a simple `if` statement with logical OR (`||`).

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    *   The `reverse_two_digit` function performs a few arithmetic operations (division, modulo, multiplication, addition), all of which take constant time.
    *   Inside the `solve` function, we call `reverse_two_digit` twice and then perform a fixed number of comparisons. All these operations are constant time.
    *   Since the `main` function iterates `T` times, calling `solve` for each test case, the total time complexity is $O(T)$. Given $T \le 10^5$, this is highly efficient.

*   **Space Complexity**: $O(1)$.
    *   The program uses a fixed number of integer variables to store marks and their reversed versions. The memory usage does not scale with the input values or the number of test cases.

## Solution Code

```cpp
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
```