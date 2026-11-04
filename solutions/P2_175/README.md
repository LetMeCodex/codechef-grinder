# [Technex Tickets (P2_175)](https://www.codechef.com/problems/P2_175)
- **Difficulty Rating**: 954
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total time (in seconds) for a person, initially at position `N` in a queue, to obtain a ticket. The movement rules and ticket acquisition time are specific and depend on the current position's parity.

The rules, as interpreted from the provided solution code and its comments, are:
1.  **Movement Rule for Odd Position `P` (`P > 1`)**: The person moves from `P` to `P-2` in 1 second.
2.  **Movement Rule for Even Position `P` (`P > 1`)**: The person moves from `P` to `P-1` in 1 second.
3.  **Ticket Acquisition Rule**:
    *   If the person is initially at `N=1`, they get the ticket in 1 second.
    *   If the person reaches position 1 from an *odd* initial position `N` (or an odd intermediate position), they get the ticket *in the same second* they reach position 1.
    *   If the person reaches position 1 from an *even* initial position `N` (after the first `P -> P-1` step), they take *one additional second* to get the ticket after reaching position 1.

## Intuition & Mathematical Observation

We can derive the time taken by analyzing the movement patterns based on the initial position `N` and the rules described above.

1.  **Case 1: `N = 1`**
    *   The person is already at position 1.
    *   According to the solution's logic, it takes `1` second for them to get the ticket. This serves as a base case.

2.  **Case 2: `N` is odd and `N >= 3`**
    *   The person starts at an odd position `N`.
    *   According to Rule 1, if at an odd position `P > 1`, they move to `P-2` in 1 second.
    *   The person's position will change in a sequence like: `N -> N-2 -> N-4 -> ... -> 3 -> 1`.
    *   Each step `P -> P-2` takes 1 second.
    *   The total number of such steps required to reach position 1 from `N` is `(N-1)/2`.
    *   The solution implies that once the person reaches position 1 (having started from an odd `N`), they get the ticket *in that same second*.
    *   Therefore, the total time taken is `(N-1)/2` seconds.
    *   For any odd integer `N`, integer division `N / 2` correctly computes `(N-1)/2`. For example, for `N=5`, `5 / 2 = 2`, and `(5-1)/2 = 2`. For `N=3`, `3 / 2 = 1`, and `(3-1)/2 = 1`.
    *   So, for odd `N >= 3`, the time is `N / 2`.

3.  **Case 3: `N` is even and `N >= 2`**
    *   The person starts at an even position `N`.
    *   According to Rule 2, if at an even position `P > 1`, they move to `P-1` in 1 second.
    *   So, in the first second, the person moves from `N` to `N-1`. This takes `1` second.
    *   Now, the person is at position `N-1`, which is an odd position.
    *   From `N-1` (an odd position), the logic from Case 2 applies: it takes `((N-1)-1)/2 = (N-2)/2` seconds to reach position 1.
    *   The solution implies that after reaching position 1 (having started from an even `N`), it takes *one additional second* to get the ticket.
    *   Combining these steps, the total time is:
        *   `1` second (for `N -> N-1`)
        *   `+ (N-2)/2` seconds (for `N-1 -> ... -> 1`)
        *   `+ 1` second (for getting the ticket from position 1)
    *   Total time = `1 + (N-2)/2 + 1 = 2 + (N-2)/2`.
    *   To simplify: `2 + (N-2)/2 = (4 + N - 2) / 2 = (N + 2) / 2`.
    *   This can be further simplified to `N / 2 + 1`.
    *   For example, if `N=4`:
        *   Sec 0: Pos 4
        *   Sec 1: Pos 3 (4 -> 4-1)
        *   Sec 2: Pos 1 (3 -> 3-2)
        *   Sec 3: Gets ticket (from 1, takes 1 additional second)
        *   Total time = 3 seconds. The formula `4 / 2 + 1 = 2 + 1 = 3` matches.
    *   So, for even `N >= 2`, the time is `N / 2 + 1`.

These derived formulas cover all possible values of `N` and are directly implemented in the provided solution code.

## Complexity Analysis
-   **Time Complexity**: The solution involves reading an integer `N` and performing a few constant-time arithmetic operations (division, addition) and a conditional check (if-else if-else). These operations take a fixed amount of time, regardless of the value of `N`. Therefore, the time complexity for each test case is $O(1)$. Since there are `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution only uses a few integer variables (`N`, `T`) to store input and loop counters. The amount of memory used does not depend on the input size `N`. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

// Use the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read initial position N

    // Apply the derived formulas based on N's parity
    if (N == 1) {
        // Special case for N=1: The person is at position 1 initially
        // and gets tickets in the first second.
        cout << 1 << "\n";
    } else if (N % 2 == 1) { // N is odd and N >= 3
        // For odd N (N >= 3), the person's position effectively decreases by 2 each second
        // until it reaches position 1. The ticket is obtained in the same second it reaches 1.
        // The number of seconds is (N-1)/2.
        // Integer division N/2 correctly computes (N-1)/2 for odd N.
        cout << N / 2 << "\n";
    } else { // N is even
        // For even N, the person first moves from N to N-1 (1 second).
        // Then, from N-1 (odd), it takes (N-1-1)/2 = (N-2)/2 seconds to reach position 1.
        // Finally, after reaching position 1, it takes 1 more second to get the ticket.
        // Total seconds = 1 + (N-2)/2 + 1 = N/2 + 1.
        cout << N / 2 + 1 << "\n";
    }
}

int main() {
    // Enable fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```