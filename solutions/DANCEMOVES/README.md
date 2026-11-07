# [Dance Moves (DANCEMOVES)](https://www.codechef.com/problems/DANCEMOVES)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at an initial position `X` on a number line, and his partner is at position `Y`. Chef wants to reach his partner's position `Y` using the minimum number of moves. There are two types of moves available:
1.  **Moonwalk**: From position `k`, Chef can move to `k+2`.
2.  **Slide**: From position `k`, Chef can move to `k-1`.

We need to determine the minimum number of moves required for Chef to reach position `Y` from `X`.

## Intuition & Mathematical Observation

The problem asks for the minimum number of moves. Let's analyze the effect of each move on Chef's position and its parity:
*   **Moonwalk (`k -> k+2`)**: Increases position by 2. This move preserves the parity of the current position (even remains even, odd remains odd).
*   **Slide (`k -> k-1`)**: Decreases position by 1. This move changes the parity of the current position (even becomes odd, odd becomes even).

We can break down the problem into three main cases based on the relationship between `X` and `Y`.

### Case 1: `X == Y`
If Chef is already at the partner's position, no moves are needed.
*   **Minimum Moves: 0**

### Case 2: `Y < X` (Chef needs to move to a lower position)
In this scenario, Chef needs to decrease his position.
*   The Moonwalk move (`k -> k+2`) would increase Chef's position, moving him further away from `Y`. Using it would necessitate more Slide moves later to compensate, thus increasing the total number of moves.
*   Therefore, the optimal strategy is to *only* use Slide moves (`k -> k-1`).
*   Each Slide move decreases the position by 1. To cover a difference of `X - Y` units, `X - Y` Slide moves are required.
*   **Minimum Moves: `X - Y`**

### Case 3: `Y > X` (Chef needs to move to a higher position)
In this scenario, Chef needs to increase his position. Let `diff = Y - X`. This `diff` is a positive integer representing the distance Chef needs to cover.

#### Subcase 3a: `diff` is even
If `diff` is an even number, it means `Y - X` is even. Since Moonwalks increase position by 2 (an even amount), Chef can reach `Y` purely by using Moonwalks.
*   Each Moonwalk covers 2 units.
*   The number of Moonwalks needed is `diff / 2`.
*   Example: `X=3, Y=7`. `diff = 4`. Moves = `4 / 2 = 2`. (Path: `3 -> 5 -> 7`)
*   **Minimum Moves: `diff / 2`**

#### Subcase 3b: `diff` is odd
If `diff` is an odd number, it means `Y - X` is odd. This implies that `X` and `Y` have different parities.
*   Since Moonwalks preserve parity, Chef cannot reach `Y` from `X` using only Moonwalks if `X` and `Y` have different parities.
*   To change parity, at least one Slide move (`k -> k-1`) must be used, as it's the only move that changes parity.
*   We need to find the minimum number of moves, which will involve a combination of Moonwalks and at least one Slide.

Consider two optimal strategies that incorporate a single Slide move (since we need at least one to change parity):

1.  **Strategy A: Slide first, then Moonwalks.**
    *   Perform one Slide move: `X -> X-1`. (1 move)
    *   Now, Chef is at `X-1`, and needs to reach `Y`. The new difference to cover is `Y - (X-1) = (Y - X) + 1 = diff + 1`.
    *   Since `diff` is odd, `diff + 1` is an even number.
    *   Chef can cover this even difference `diff + 1` using `(diff + 1) / 2` Moonwalks.
    *   Total moves = `1` (Slide) + `(diff + 1) / 2` (Moonwalks).
    *   Example: `X=3, Y=8`. `diff = 5`.
        *   Slide: `3 -> 2` (1 move).
        *   New target: `Y=8` from `X=2`. New `diff = 6`.
        *   Moonwalks: `2 -> 4 -> 6 -> 8` (3 moves).
        *   Total moves = `1 + 3 = 4`.

2.  **Strategy B: Moonwalk past `Y`, then Slide back.**
    *   Perform Moonwalks until Chef reaches `Y+1`. The difference to cover is `(Y+1) - X = (Y - X) + 1 = diff + 1`.
    *   Since `diff` is odd, `diff + 1` is an even number.
    *   This requires `(diff + 1) / 2` Moonwalks to reach `Y+1`.
    *   From `Y+1`, perform one Slide move to reach `Y`. (1 move)
    *   Total moves = `(diff + 1) / 2` (Moonwalks) + `1` (Slide).
    *   Example: `X=3, Y=8`. `diff = 5`.
        *   Moonwalk to `Y+1 = 9`: `3 -> 5 -> 7 -> 9` (3 moves).
        *   Slide: `9 -> 8` (1 move).
        *   Total moves = `3 + 1 = 4`.

Both strategies yield the same minimum number of moves. Using integer division, `(diff + 1) / 2` can also be expressed as `diff / 2 + 1`.
So, the total moves = `1 + (diff / 2 + 1) = diff / 2 + 2`.
*   **Minimum Moves: `diff / 2 + 2`**

Combining these observations, the solution involves simple conditional logic and arithmetic operations.

## Complexity Analysis
-   **Time Complexity**: For each test case, the solution performs a few arithmetic operations (subtraction, division, addition) and comparisons. These operations take constant time. Therefore, the time complexity per test case is $O(1)$. Given $T$ test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution uses a few integer variables to store `T`, `X`, `Y`, and `diff`. This amount of memory is constant and does not depend on the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; is common in competitive programming.
using namespace std;

int main() {
    // Fast I/O to speed up input and output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of testcases
    cin >> T;
    while (T--) {
        int X, Y; // Initial position of Chef and partner
        cin >> X >> Y;

        if (X == Y) {
            // If Chef is already at the partner's position, 0 moves are needed.
            cout << 0 << "\n";
        } else if (Y > X) {
            // Chef needs to move to a higher position.
            // The Moonwalk move (k -> k+2) is generally efficient for increasing position.
            // The Slide move (k -> k-1) decreases position.

            int diff = Y - X; // The positive difference Chef needs to cover.

            if (diff % 2 == 0) {
                // If the difference is even, Chef can reach Y purely by Moonwalks.
                // Each Moonwalk covers 2 units. So, diff / 2 Moonwalks are needed.
                // Example: X=3, Y=7. diff=4. Moves = 4/2 = 2. (3->5->7)
                cout << diff / 2 << "\n";
            } else {
                // If the difference is odd, Chef cannot reach Y purely by Moonwalks.
                // This means Chef must use at least one Slide move to change parity.
                // The optimal strategy involves one Slide move and the rest Moonwalks.
                //
                // Strategy 1: Slide once to X-1, then Moonwalk to Y.
                //    This takes 1 Slide. The new difference is (Y-(X-1)) = (Y-X)+1 = diff+1.
                //    Since diff is odd, diff+1 is even. So (diff+1)/2 Moonwalks are needed.
                //    Total moves = 1 + (diff+1)/2.
                //    Example: X=3, Y=8. diff=5. Moves = 1 + (5+1)/2 = 1 + 3 = 4. (3->2->4->6->8)
                //
                // Strategy 2: Moonwalk until Y+1, then slide once.
                //    This takes (diff/2 + 1) Moonwalks to reach Y+1 (since diff+1 is even,
                //    (diff+1)/2 = diff/2 + 1 using integer division), and 1 Slide to Y.
                //    Total moves = (diff/2 + 1) + 1 = diff/2 + 2.
                //    Example: X=3, Y=8. diff=5. Moves = 2+2 = 4. (3->5->7->9->8)
                //
                // Both strategies yield the same minimum moves: diff / 2 + 2.
                cout << diff / 2 + 2 << "\n";
            }
        } else { // Y < X
            // Chef needs to move to a lower position.
            // The Slide move (k -> k-1) is the only move that decreases position.
            // Using a Moonwalk (k -> k+2) would move Chef further away from Y,
            // requiring even more Slide moves later, thus increasing total moves.
            // So, the optimal strategy is to only use Slide moves.
            // The number of moves is simply the absolute difference X - Y.
            // Example: X=8, Y=3. Moves = 8-3 = 5. (8->7->6->5->4->3)
            cout << X - Y << "\n";
        }
    }

    return 0;
}
```