# [Chef And Coloring (COLOR)](https://www.codechef.com/problems/COLOR)
- **Difficulty Rating**: 1148
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of rooms that need to be repainted so that all `N` rooms end up having the same color. We are given `N`, the total number of rooms, and a string `S` of length `N` representing the initial colors of the rooms. The colors can only be 'R' (Red), 'G' (Green), or 'B' (Blue).

## Intuition & Mathematical Observation

The goal is to make all `N` rooms the same color. We have three possible target colors: Red, Green, or Blue. To minimize the number of repaints, we should choose the target color that is already present in the maximum number of rooms.

Let's say we have `countR` rooms that are initially Red, `countG` rooms that are initially Green, and `countB` rooms that are initially Blue. The total number of rooms is `N = countR + countG + countB`.

Consider the options:
1.  **Make all rooms Red**: To achieve this, we need to repaint all rooms that are currently Green or Blue. The number of repaints would be `countG + countB`. This can also be expressed as `N - countR`.
2.  **Make all rooms Green**: Similarly, we need to repaint all rooms that are currently Red or Blue. The number of repaints would be `countR + countB`, or `N - countG`.
3.  **Make all rooms Blue**: We need to repaint all rooms that are currently Red or Green. The number of repaints would be `countR + countG`, or `N - countB`.

To find the *minimum* number of repaints, we simply choose the option that requires the fewest changes. This means we should pick the target color that has the highest initial count. If `max_count` is the maximum among `countR`, `countG`, and `countB`, then the minimum number of repaints will be `N - max_count`.

For example, if `N=5` and `S="RRGBB"`:
*   `countR = 2`
*   `countG = 1`
*   `countB = 2`
*   The maximum count is `max(2, 1, 2) = 2`.
*   The minimum repaints needed is `N - max_count = 5 - 2 = 3`.
    *   (We could make all rooms Red by repainting 1 Green and 2 Blue rooms, total 3. Or make all rooms Blue by repainting 2 Red and 1 Green room, total 3. Making all rooms Green would require repainting 2 Red and 2 Blue rooms, total 4.)

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and the string `S` takes $O(N)$ time.
    *   Iterating through the string `S` once to count the occurrences of 'R', 'G', and 'B' takes $O(N)$ time.
    *   Finding the maximum of three counts and performing the final subtraction takes $O(1)$ time.
    *   Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.
*   **Space Complexity**:
    *   Storing the input string `S` requires $O(N)$ space.
    *   Variables like `N`, `countR`, `countG`, `countB`, and `max_count` use $O(1)$ auxiliary space.
    *   Therefore, the overall space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int countR = 0;
    int countG = 0;
    int countB = 0;

    // Count occurrences of each color
    for (char c : S) {
        if (c == 'R') {
            countR++;
        } else if (c == 'G') {
            countG++;
        } else { // c == 'B'
            countB++;
        }
    }

    // The minimum number of rooms to repaint is achieved by choosing the target color
    // that is already present in the maximum number of rooms.
    // The number of repaints will be N - (count of the most frequent color).
    int max_count = max({countR, countG, countB}); 

    cout << N - max_count << "\n";
}

int main() {
    // Fast I/O: Unties cin/cout from C stdio and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```