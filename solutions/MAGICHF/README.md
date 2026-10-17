# [Magician versus Chef (MAGICHF)](https://www.codechef.com/problems/MAGICHF)
- **Difficulty Rating**: 1088
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem describes a scenario where a magician has $N$ cups arranged in a row, numbered from 1 to $N$. Initially, a coin is placed under cup $X$. The magician then performs $S$ swaps. Each swap involves two cup positions, say $A$ and $B$. If the coin is currently under cup $A$, it moves to cup $B$, and if it's under cup $B$, it moves to cup $A$. If the coin is not under either $A$ or $B$, its position remains unchanged. The goal is to determine the final position of the coin after all $S$ swaps.

## Intuition & Mathematical Observation
The core of the problem is to track the position of the coin through a series of swaps. Since the coin is only under one cup at any given time, we only need to keep track of its current position.

Let's denote the current position of the coin as `current_coin_pos`. Initially, `current_coin_pos` is given as $X$.

When a swap operation between cups $A$ and $B$ is performed, we need to check if the coin is currently at either position $A$ or position $B$.

1.  **If `current_coin_pos` is equal to $A$**: This means the coin is under cup $A$. After the swap, the coin will move to cup $B$. So, we update `current_coin_pos` to $B$.
2.  **If `current_coin_pos` is equal to $B$**: This means the coin is under cup $B$. After the swap, the coin will move to cup $A$. So, we update `current_coin_pos` to $A$.
3.  **If `current_coin_pos` is neither $A$ nor $B$**: This means the coin is under some other cup. The swap operation only affects the contents of cups $A$ and $B$. Since the coin is not at either of these positions, its position remains unchanged. We do nothing in this case.

We repeat this process for all $S$ swaps. After all swaps are processed, the final value of `current_coin_pos` will be the answer.

There's no complex mathematical formula needed here; it's a direct simulation of the process described. The key is to correctly implement the conditional logic for updating the coin's position.

## Complexity Analysis

-   **Time Complexity**: $O(S)$
    The program reads the number of test cases $T$. For each test case, it reads $N$, $X$, and $S$. Then, it iterates $S$ times to process each swap. Inside the loop, the operations (reading $A$ and $B$, and the conditional checks) take constant time. Therefore, the total time complexity for each test case is dominated by the $S$ swaps, making it $O(S)$. Since there are $T$ test cases, the overall time complexity is $O(T \cdot S)$. However, if we consider the complexity per test case, it's $O(S)$.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`n`, `x`, `s`, `current_coin_pos`, `a`, `b`, `t`) to store the input values and the current state of the coin. The amount of memory used does not depend on the input size $N$ or $S$. Thus, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of cups (not directly used in logic, but part of input)
        int x; // Initial position of the coin
        int s; // Number of swaps
        std::cin >> n >> x >> s;

        int current_coin_pos = x; // Initialize the coin's position

        // Process each swap
        for (int i = 0; i < s; ++i) {
            int a, b; // The two cup positions involved in the swap
            std::cin >> a >> b;

            // Check if the coin is at one of the positions being swapped
            if (current_coin_pos == a) {
                // If coin is at 'a', it moves to 'b'
                current_coin_pos = b;
            } else if (current_coin_pos == b) {
                // If coin is at 'b', it moves to 'a'
                current_coin_pos = a;
            }
            // If current_coin_pos is neither 'a' nor 'b', it remains unchanged.
        }

        // Output the final position of the coin
        std::cout << current_coin_pos << "\n";
    }
    return 0;
}
```