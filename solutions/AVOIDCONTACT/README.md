# Avoid Contact (AVOIDCONTACT)

- **Difficulty Rating**: 907
- **Solved in**: 1 attempt(s)

## Problem Summary

We are given $X$ people in total and $Y$ infected people. We need to find the minimum number of rooms required to house all $X$ people such that no two infected people are in adjacent rooms. Uninfected people can be placed anywhere.

## Intuition & Mathematical Observation

The core constraint is that infected people must be separated by at least one room. This means if we have $Y$ infected people, we can visualize their placement as follows:

`I _ I _ I _ ... _ I`

where `I` represents an infected person and `_` represents a room that must be empty to separate the infected individuals.

Let's consider the different cases:

1.  **No infected people ($Y = 0$)**:
    If there are no infected people, there are no restrictions. All $X$ people are uninfected. They can be placed in $X$ contiguous rooms.
    Minimum rooms = $X$.

2.  **There are infected people ($Y > 0$)**:
    We need to place $Y$ infected people such that they are separated. The most compact arrangement for $Y$ infected people is to place them in rooms $1, 3, 5, \ldots, 2Y-1$. This arrangement uses $2Y-1$ rooms.
    `I _ I _ I ... _ I` (Y infected people, Y-1 empty rooms between them)

    Now, we need to consider the uninfected people ($X-Y$).

    *   **All people are infected ($X = Y$)**:
        In this scenario, we only have infected people. The arrangement `I _ I _ ... _ I` is sufficient. The last infected person is at room $2Y-1$. No further rooms are needed for uninfected people.
        Minimum rooms = $2Y - 1$.

    *   **There are uninfected people ($X > Y$)**:
        We have $Y$ infected people and $X-Y$ uninfected people.
        The arrangement for infected people is `I _ I _ ... _ I`. This uses $2Y-1$ rooms.
        However, the problem states that infected people must be separated by *at least one* empty room. This implies that the room immediately *after* the last infected person must also be empty to ensure separation if we consider a linear arrangement.
        Consider the arrangement: `I _ I _ ... _ I _`
        This arrangement uses $2Y$ rooms. The last `_` is the room immediately following the last infected person. This room is effectively "blocked" from housing an infected person.
        After these $2Y$ rooms, the $(2Y+1)^{th}$ room is safe to place an uninfected person.
        We have $X-Y$ uninfected people to place. We can place them contiguously starting from room $2Y+1$.
        The total number of rooms will be the rooms occupied by the infected block (including the mandatory empty room after the last infected person) plus the rooms for the uninfected people.
        Total rooms = $(2Y) + (X-Y) = X + Y$.

Let's summarize the logic:

*   If $Y = 0$: $N = X$
*   If $Y > 0$:
    *   If $X = Y$: $N = 2Y - 1$
    *   If $X > Y$: $N = X + Y$

This can be simplified:
If $Y=0$, $N=X$.
If $Y>0$, the minimum rooms needed to house $Y$ infected people with separation is $2Y-1$. If $X=Y$, this is the answer. If $X>Y$, we have $X-Y$ uninfected people. The arrangement $I\_I\_\dots\_I$ uses $2Y-1$ rooms. To ensure separation, the room after the last $I$ must be empty. So, we effectively need $2Y$ rooms for the infected block. Then we can place the $X-Y$ uninfected people. Total rooms = $2Y + (X-Y) = X+Y$.

This logic covers all cases.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a few conditional checks and arithmetic operations based on the input values $X$ and $Y$. The time taken does not depend on the magnitude of $X$ or $Y$ in a way that scales linearly or logarithmically. It's a constant number of operations per test case.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables ($X, Y, N, T$) regardless of the input size. No additional data structures are used that grow with the input.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations

void solve() {
    int X, Y; // X: total people, Y: infected people
    std::cin >> X >> Y; // Read X and Y for the current test case
    
    int N; // Minimum number of rooms
    
    if (Y == 0) {
        // Case 1: No infected people.
        // All X people are uninfected. They can be placed in X contiguous rooms.
        // Example: N N N N for X=4, Y=0.
        N = X;
    } else {
        // Case 2: There are infected people (Y > 0).
        // Infected people must be separated by at least one empty room.
        // The most compact arrangement for Y infected people is C _ C _ ... _ C.
        // This arrangement uses 2*Y - 1 rooms.
        // Rooms occupied by C: 1, 3, ..., 2*Y-1
        // Rooms occupied by _: 2, 4, ..., 2*Y-2 (these are adjacent to C, so no U can be here)
        // All 2*Y - 1 rooms in this arrangement are effectively "blocked" for uninfected people
        // if we consider the strict separation.
        
        if (X == Y) {
            // Subcase 2a: All people are infected (no uninfected people).
            // The arrangement C _ C _ ... _ C is sufficient.
            // Example for X=3, Y=3: C _ C _ C (5 rooms).
            N = 2 * Y - 1;
        } else { // X > Y, meaning there are uninfected people (X - Y > 0).
            // Subcase 2b: There are uninfected people.
            // The last infected person (at room 2*Y-1 in the C _ C ... _ C block)
            // requires room 2*Y to be empty to maintain separation.
            // So, the infected block effectively needs to be C _ C _ ... _ C _
            // This uses 2*Y rooms.
            // After these 2*Y rooms, room 2*Y+1 is safe for an uninfected person.
            // We place the remaining (X - Y) uninfected people contiguously starting from room 2*Y+1.
            // Total rooms = (rooms for infected block with trailing empty room) + (rooms for uninfected)
            // N = 2*Y + (X - Y) = X + Y.
            // Example for X=5, Y=3: C _ C _ C _ U U (8 rooms).
            N = X + Y;
        }
    }
    
    std::cout << N << "\n"; // Output the minimum number of rooms
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }
    
    return 0; // Indicate successful execution
}
```