# [Conveyor Belt (CONVEYOR)](https://www.codechef.com/problems/CONVEYOR)
- **Difficulty Rating**: 1034
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given `N` slots, numbered from 1 to `N`. An object starts at a specific slot `P` (1-indexed). There are two collection points: one at position 0 (left of slot 1) and another at position `N+1` (right of slot `N`). Each slot `i` has a direction, either 'L' (left) or 'R' (right), indicating which way an object at that slot will move. If an object is at slot `i` and `s[i-1]` is 'L', it moves to `i-1`. If `s[i-1]` is 'R', it moves to `i+1`. The object continues moving until it reaches a collection point.

You can reverse the direction of any slot (change 'L' to 'R' or 'R' to 'L') at a cost of 1 reversal. The goal is to find the minimum number of reversals required to make the object reach *either* collection point 0 *or* collection point `N+1`.

## Intuition & Mathematical Observation

The key insight is that once the object starts moving in a particular direction (left or right) and we want it to reach a collection point in that direction, *all* slots it traverses must consistently direct it towards that collection point. If any slot along its path directs it the other way, it will stop or reverse course, preventing it from reaching the desired collection point without further changes.

Let's consider the two possible scenarios:

1.  **Reaching Collection Point 0 (moving left):**
    *   The object starts at position `P`. To reach 0, it must move from `P` to `P-1`, then `P-1` to `P-2`, and so on, until it moves from `1` to `0`.
    *   This means every slot from `P` down to `1` must direct the object to the left.
    *   In 0-indexed terms (since the input string `s` is 0-indexed), this means `s[P-1]` must be 'L', `s[P-2]` must be 'L', ..., `s[0]` must be 'L'.
    *   We iterate through these slots (`s[P-1]` down to `s[0]`) and count how many of them are currently 'R'. Each 'R' encountered needs to be reversed to 'L', incurring one reversal cost.

2.  **Reaching Collection Point `N+1` (moving right):**
    *   The object starts at position `P`. To reach `N+1`, it must move from `P` to `P+1`, then `P+1` to `P+2`, and so on, until it moves from `N` to `N+1`.
    *   This means every slot from `P` up to `N` must direct the object to the right.
    *   In 0-indexed terms, this means `s[P-1]` must be 'R', `s[P]` must be 'R', ..., `s[N-1]` must be 'R'.
    *   We iterate through these slots (`s[P-1]` up to `s[N-1]`) and count how many of them are currently 'L'. Each 'L' encountered needs to be reversed to 'R', incurring one reversal cost.

Finally, since we want the *minimum* number of reversals, we calculate the costs for both options (reaching 0 and reaching `N+1`) and take the smaller of the two values.

The problem simplifies to two independent counting loops and a `min` operation.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   Reading input `N`, `P`, and string `s` takes $O(N)$ time.
    *   The loop to calculate `reversals_to_left` iterates at most `P` times, which is at most `N` times. This is $O(N)$.
    *   The loop to calculate `reversals_to_right` iterates at most `N - P + 1` times, which is at most `N` times. This is $O(N)$.
    *   The `std::min` operation is $O(1)$.
    *   Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given $N \le 10^5$ and $T \le 10$, this is approximately $10 \cdot 10^5 = 10^6$ operations, which is well within typical time limits.

*   **Space Complexity**: $O(N)$ per test case.
    *   Storing the input string `s` requires $O(N)$ space.
    *   All other variables (`n`, `p`, `t`, `reversals_to_left`, `reversals_to_right`) use constant $O(1)$ auxiliary space.
    *   Thus, the total space complexity is dominated by the string storage, $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n, p; // n: number of slots, p: starting position (1-indexed)
        std::cin >> n >> p;
        std::string s; // String representing directions of slots (0-indexed)
        std::cin >> s;

        // The object starts at position P (1-indexed).
        // Collection points are at 0 and N+1.

        // Option 1: Try to reach collection point 0 (move left)
        // To reach 0, the object must move left from P, P-1, ..., 1.
        // This means all slots from P down to 1 must be 'L'.
        // In 0-indexed string 's', these are s[p-1], s[p-2], ..., s[0].
        int reversals_to_left = 0;
        for (int i = p - 1; i >= 0; --i) {
            if (s[i] == 'R') {
                reversals_to_left++; // If it's 'R', we need to reverse it to 'L'
            }
        }

        // Option 2: Try to reach collection point N+1 (move right)
        // To reach N+1, the object must move right from P, P+1, ..., N.
        // This means all slots from P up to N must be 'R'.
        // In 0-indexed string 's', these are s[p-1], s[p], ..., s[n-1].
        int reversals_to_right = 0;
        for (int i = p - 1; i < n; ++i) {
            if (s[i] == 'L') {
                reversals_to_right++; // If it's 'L', we need to reverse it to 'R'
            }
        }

        // The minimum number of reversals is the minimum of the two options.
        std::cout << std::min(reversals_to_left, reversals_to_right) << "\n";
    }
    return 0;
}

```