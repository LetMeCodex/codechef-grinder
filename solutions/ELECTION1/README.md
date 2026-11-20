# [Election (ELECTION1)](https://www.codechef.com/problems/ELECTION1)
- **Difficulty Rating**: 241
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the minimum number of additional seats Chef's party needs to win to form a government. We are given the total number of seats in the parliament, `N`, and the number of seats Chef's party has already won, `K`. A party forms a government if it wins a strict majority of the seats. A strict majority means winning more than half of the total seats.

## Intuition & Mathematical Observation
1.  **Defining a Strict Majority**:
    For a total of `N` seats, a strict majority means winning `X` seats such that `X > N / 2`.
    *   If `N` is an even number (e.g., `N=10`), half is `5`. To win a strict majority, a party needs `6` seats (`10/2 + 1`).
    *   If `N` is an odd number (e.g., `N=11`), half is `5.5`. To win a strict majority, a party needs `6` seats. In integer arithmetic, `11/2` evaluates to `5`. So, `11/2 + 1` also gives `6`.
    *   In general, for any positive integer `N`, the minimum number of seats required for a strict majority is `floor(N / 2) + 1`. In C++ integer division, `N / 2` automatically computes `floor(N / 2)`. Therefore, the `required_seats` can be calculated as `N / 2 + 1`.

2.  **Calculating Additional Seats Needed**:
    *   Let `required_seats = N / 2 + 1`.
    *   Chef's party currently has `K` seats.
    *   If `K` is already greater than or equal to `required_seats`, Chef's party has enough seats to form the government, so they need `0` additional seats.
    *   If `K` is less than `required_seats`, Chef's party needs `required_seats - K` more seats.
    *   This logic can be concisely expressed using the `max` function: `max(0, required_seats - K)`. This ensures that the result is never negative.

## Complexity Analysis
*   **Time Complexity**: $O(1)$
    The solution involves reading two integers, performing a few constant-time arithmetic operations (division, addition, subtraction, `max`), and printing one integer. All these operations take a constant amount of time, regardless of the input values `N` and `K`.
*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`N`, `K`, `required_seats`, `additional_seats_needed`) to store data. The memory usage does not scale with the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the total number of seats (N)
    // and the number of seats Chef's party has won (K).
    int N, K;

    // Read N and K from standard input.
    cin >> N >> K;

    // Calculate the minimum number of seats required to form the government.
    // A strict majority is defined as floor(N / 2) + 1 seats.
    // In C++, integer division `N / 2` automatically computes `floor(N / 2)`
    // for positive integer N.
    int required_seats = N / 2 + 1;

    // Calculate the number of additional seats Chef's party needs.
    // If Chef's party already has K seats, and K is less than required_seats,
    // they need `required_seats - K` more seats.
    // If K is already greater than or equal to required_seats, they need 0 additional seats.
    // The `max(0, ...)` function handles this condition concisely.
    int additional_seats_needed = max(0, required_seats - K);

    // Output the minimum number of additional seats required, followed by a newline.
    cout << additional_seats_needed << "\n";

    return 0;
}
```