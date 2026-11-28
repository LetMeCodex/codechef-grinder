Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the Disabled King problem:

# [Disabled King (DISABLEDKING)](https://www.codechef.com/problems/DISABLEDKING)
- **Difficulty Rating**: 1237
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks for the minimum number of moves a "Disabled King" needs to travel from cell (1,1) to cell (N,1) on an N x N chessboard. A Disabled King can move one step in any of the 8 directions (horizontally, vertically, or diagonally), just like a standard chess king.

## Intuition & Mathematical Observation

The key to solving this problem lies in understanding the constraints imposed by the starting and ending coordinates, particularly their parity, and how each move affects them.

1.  **X-coordinate Change**: We need to move from `x=1` to `x=N`. This requires a net change of `N-1` in the x-coordinate. Since a king can change its x-coordinate by at most 1 in a single move (i.e., `x` becomes `x-1`, `x`, or `x+1`), we need at least `N-1` moves to cover this horizontal distance.

2.  **Y-coordinate Change and Parity**: We start at `y=1` and need to end at `y=1`. This means the net change in the y-coordinate must be zero. More importantly, consider the parity of the y-coordinate:
    *   Starting `y=1` is odd.
    *   Ending `y=1` is odd.
    *   Each move changes the y-coordinate by `-1`, `0`, or `+1`.
    *   A move that changes `y` by `-1` or `+1` flips the parity of `y`.
    *   A move that changes `y` by `0` preserves the parity of `y`.
    *   To start with an odd `y` and end with an odd `y`, the total number of times the y-coordinate's parity is flipped must be **even**.

Now, let's combine these observations based on the parity of `N`:

### Case 1: `N` is odd

*   If `N` is odd, then `N-1` is even.
*   We need at least `N-1` moves to cover the horizontal distance.
*   If we make exactly `N-1` moves, and `N-1` is even, we can construct a path where each move changes the x-coordinate by `+1` and simultaneously flips the y-coordinate's parity. For example, a sequence of diagonal moves like `(x,y) -> (x+1, y+1)` or `(x+1, y-1)`.
*   Since `N-1` is an even number of moves, the y-coordinate's parity will be flipped an even number of times. Starting with an odd `y` (1), after an even number of flips, the y-coordinate will still have odd parity. We can strategically choose diagonal moves to ensure we land on `y=1` at `x=N`.
*   **Example for N=3**:
    *   (1,1) -> (2,2) (1 move, x increased by 1, y parity flipped)
    *   (2,2) -> (3,1) (1 move, x increased by 1, y parity flipped)
    *   Total moves: 2. Here, `N-1 = 3-1 = 2`.
*   Thus, `N-1` moves are sufficient and minimal when `N` is odd.

### Case 2: `N` is even

*   If `N` is even, then `N-1` is odd.
*   We still need at least `N-1` moves to cover the horizontal distance.
*   If we make exactly `N-1` moves, and `N-1` is an odd number of moves, the y-coordinate's parity will be flipped an odd number of times. Starting with an odd `y` (1), after an odd number of flips, the y-coordinate will have **even** parity. This means we would end up at `(N, even_y_coordinate)`, not `(N,1)`.
*   To correct the y-coordinate's parity back to odd (to reach `y=1`), we need at least one more move that flips the y-parity again. This extra move can be a vertical move (e.g., `(N, even_y) -> (N, even_y-1)`) which does not change the x-coordinate.
*   So, we need `N-1` moves to cover the x-distance and reach an even y-coordinate, plus one additional move to correct the y-coordinate's parity.
*   Total moves: `(N-1) + 1 = N`.
*   **Example for N=2**:
    *   (1,1) -> (2,2) (1 move, x increased by 1, y parity flipped). Now at `(2,2)`, y is even. `N-1 = 1` move.
    *   (2,2) -> (2,1) (1 move, y parity flipped). Now at `(2,1)`, y is odd.
    *   Total moves: 2. Here, `N = 2`.
*   Thus, `N` moves are sufficient and minimal when `N` is even.

**Conclusion**:
The minimum number of moves is `N-1` if `N` is odd, and `N` if `N` is even. This can be implemented with a simple `if-else` condition based on `N % 2`.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The solution processes `T` test cases. For each test case, it reads an integer `N`, performs a constant number of operations (modulo, comparison, print), which takes $O(1)$ time. Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a few integer variables (`T`, `N`) to store input and loop counters. The memory usage remains constant regardless of the input value of `N` or `T`. Hence, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N; // Variable to store the size of the chessboard
        std::cin >> N; // Read the value of N for the current test case

        // Determine the minimum moves based on N's parity.
        // The logic is as follows:
        // 1. Every move changes the y-coordinate. To start at y=1 and end at y=1,
        //    the total number of moves must be even.
        // 2. To change x from 1 to N, a net change of N-1 in x is required.
        //    Each move can change x by at most 1. So, at least N-1 moves are needed.
        //
        // If N is odd:
        //   N-1 is even. We need an even number of moves.
        //   We can make N-1 moves, each increasing x by 1 and changing y.
        //   Example for N=3: (1,1) -> (2,2) -> (3,1). This takes 2 moves (N-1).
        //   Since N-1 moves are made, and N-1 is even, the y-coordinate parity
        //   flips an even number of times, ending up with the same parity as start (odd).
        //   So, N-1 moves are sufficient and minimal.
        //
        // If N is even:
        //   N-1 is odd. If we make N-1 moves, the y-coordinate parity will flip
        //   an odd number of times, ending up with the opposite parity as start (even).
        //   To reach y=1 (odd), we need one more move to flip the y-parity again.
        //   This extra move can be a vertical move (x, y+/-1) which doesn't change x.
        //   Example for N=2: (1,1) -> (2,2) (1 move, y is even).
        //   Then (2,2) -> (2,1) (1 more move, y is odd). Total 2 moves (N).
        //   So, N moves are sufficient and minimal.
        //
        // This logic is consistent with the sample cases and general path construction.
        if (N % 2 == 0) {
            std::cout << N << "\n";
        } else {
            std::cout << N - 1 << "\n";
        }
    }

    return 0; // Indicate successful execution
}
```