# [Distinct Colors (DISTINCTCOL)](https://www.codechef.com/problems/DISTINCTCOL)
- **Difficulty Rating**: 760
- **Solved in**: 1 attempt(s)

## Problem Summary

You are given $N$ different types of colors. For each color $i$, you are provided with $A_i$ balls of that specific color. Your task is to put all these balls into boxes. The crucial rule for placing balls into boxes is that **all balls within a single box must have distinct colors**. This means a box cannot contain two balls of the same color, but it can contain one red ball, one blue ball, one green ball, and so on. The objective is to find the minimum number of boxes required to accommodate all the balls.

## Intuition & Mathematical Observation

The core constraint is that "all balls within a single box must have distinct colors". This implies that for any given color, say red, a single box can contain at most one red ball. If we have multiple red balls, they must be placed into different boxes.

Let's consider the color that has the maximum number of balls. Suppose this maximum count is $M$, and it corresponds to color $C_k$. So, we have $M$ balls of color $C_k$.
Since each box can hold at most one ball of color $C_k$, we will need at least $M$ distinct boxes to place all $M$ balls of color $C_k$. Each of these $M$ boxes will contain one ball of color $C_k$.

Now, the question is: can we achieve this with exactly $M$ boxes? And can we place all other balls (of colors $C_j$ where $j \neq k$) into these same $M$ boxes without violating the distinct color rule?

Yes, we can. Let's create $M$ boxes, labeled Box 1, Box 2, ..., Box $M$.
1.  First, place one ball of color $C_k$ into each of the $M$ boxes. So, Box 1 has one $C_k$ ball, Box 2 has one $C_k$ ball, ..., Box $M$ has one $C_k$ ball.
2.  Now, consider any other color $C_j$ (where $j \neq k$). We have $A_j$ balls of color $C_j$. By definition, $M$ is the maximum number of balls of any single color, so $A_j \le M$.
3.  We can distribute these $A_j$ balls among the $M$ boxes. For example, place one ball of color $C_j$ into Box 1, one into Box 2, ..., and one into Box $A_j$. The remaining $M - A_j$ boxes (from Box $A_j+1$ to Box $M$) will not receive a ball of color $C_j$.

By following this strategy for all colors, each of the $M$ boxes will contain at most one ball of any given color. For instance, Box 1 will contain one ball of $C_k$, and for every other color $C_j$, it will contain one ball if $A_j \ge 1$. Box 2 will contain one ball of $C_k$, and for every other color $C_j$, it will contain one ball if $A_j \ge 2$, and so on.
Crucially, within any single box, all balls will have distinct colors because we never place two balls of the same color into the same box.

Therefore, the minimum number of boxes required is simply the maximum number of balls of any single color. The solution involves iterating through the counts of balls for each color and finding the maximum value.

## Complexity Analysis

-   **Time Complexity**:
    The program reads $T$ test cases. For each test case:
    -   It reads $N$ (number of colors) in $O(1)$ time.
    -   It then iterates $N$ times to read each $A_i$ (number of balls for a color) and updates the `max_balls` variable. This loop takes $O(N)$ time.
    Thus, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**:
    The program uses a few integer variables (`N`, `max_balls`, `A_i`, `T`, loop counter `i`). These variables consume a constant amount of memory regardless of the input size $N$.
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <algorithm> // Required for std::max function

void solve() {
    int N;
    std::cin >> N; // Read the number of different types of colors

    int max_balls = 0; // Initialize a variable to store the maximum number of balls of any single color.
                       // Since A_i >= 1, initializing with 0 is safe.

    // Loop N times to read the count of balls for each color
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read the number of balls for the current color

        // Update max_balls if the current A_i is greater than the previously found maximum
        max_balls = std::max(max_balls, A_i);
    }

    // The minimum number of boxes required is the maximum number of balls of any single color.
    // This is because each ball of the most numerous color must go into a distinct box.
    std::cout << max_balls << "\n"; // Output the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded)
    // on problems with large inputs.
    std::ios_base::sync_with_stdio(false); // Untie C++ streams from C standard streams
    std::cin.tie(NULL);                   // Untie cin from cout

    int T;
    std::cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```