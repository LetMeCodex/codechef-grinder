# [Friends Meetup (FRIMEET)](https://www.codechef.com/problems/FRIMEET)
- **Difficulty Rating**: 1098
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario where Chef and his friend are moving along a straight line in the positive direction.
- Chef starts at position `X1` and moves 1 unit per second.
- His friend starts at position `X2` and moves 2 units per second.
We need to determine if Chef and his friend will ever meet at the same position at the same time.

## Intuition & Mathematical Observation

Let's denote the time elapsed in seconds as `t`.
- Chef's position after `t` seconds will be `P_chef(t) = X1 + t`.
- Friend's position after `t` seconds will be `P_friend(t) = X2 + 2t`.

For them to meet, their positions must be equal at some non-negative time `t`.
So, we set `P_chef(t) = P_friend(t)`:
`X1 + t = X2 + 2t`

Now, we solve for `t`:
`X1 - X2 = 2t - t`
`X1 - X2 = t`

For a meeting to occur, the time `t` must be non-negative (since time cannot go backward).
Therefore, we must have `t >= 0`.
Substituting `t = X1 - X2` into this inequality, we get:
`X1 - X2 >= 0`
Which simplifies to:
`X1 >= X2`

This condition tells us:
1.  **If `X1 > X2`**: Chef starts ahead of his friend. Since the friend moves faster (2 units/sec) than Chef (1 unit/sec), the friend will eventually catch up to Chef. They will meet at time `t = X1 - X2`.
2.  **If `X1 = X2`**: They start at the same position. They meet immediately at `t = 0`.
3.  **If `X1 < X2`**: Chef starts behind his friend. Since the friend is already ahead and also moves faster than Chef, the distance between them will only increase over time. They will never meet.

Thus, the condition for them to meet is simply `X1 >= X2`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of operations: reading two integers and one comparison. If there are `T` test cases, the total time complexity will be proportional to `T`.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables (`t`, `x1`, `x2`) to store input and loop counters. This amount of memory is constant and does not depend on the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    std::cin >> t; // Read the number of test cases from standard input.

    // Loop through each test case.
    while (t--) {
        int x1, x2; // Declare integer variables for Chef's and friend's initial positions.
        std::cin >> x1 >> x2; // Read X1 and X2 for the current test case.

        // Chef's position after 't_seconds': X1 + t_seconds
        // Friend's position after 't_seconds': X2 + 2 * t_seconds
        // They meet if X1 + t_seconds = X2 + 2 * t_seconds
        // Solving for t_seconds: t_seconds = X1 - X2
        // For a meeting to occur, t_seconds must be non-negative (t_seconds >= 0).
        // Thus, X1 - X2 >= 0, which simplifies to X1 >= X2.

        if (x1 >= x2) {
            // If Chef's initial position is greater than or equal to his friend's, they will meet.
            std::cout << "YES\n";
        } else {
            // Otherwise, Chef starts behind and moves slower, so they will never meet.
            std::cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}
```