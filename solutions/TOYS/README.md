# [Playing with Toys (TOYS)](https://www.codechef.com/problems/TOYS)
- **Difficulty Rating**: 206
- **Solved in**: 1 attempt(s)

## Problem Summary
The Chef has $N$ toys. He decides to play with one toy each day for $M$ days. Each day he plays with a toy, he breaks it. The Chef continues this process for $M$ days or until he runs out of toys, whichever comes first. We need to find the number of toys remaining after this process.

## Intuition & Mathematical Observation
The core of the problem lies in understanding how many toys the Chef will actually break. The Chef plays with one toy per day and breaks it. This means that the number of toys broken is directly related to the number of days he plays.

However, there's a constraint: the Chef cannot break more toys than he initially possesses.

Let $N$ be the initial number of toys and $M$ be the number of days the Chef intends to play.

1.  **Scenario 1: $N \le M$**
    If the Chef has fewer toys than the number of days he wants to play, he will play with one toy each day until he runs out of toys. After $N$ days, he will have no toys left. So, he will break all $N$ toys. The number of toys broken will be $N$.

2.  **Scenario 2: $N > M$**
    If the Chef has more toys than the number of days he wants to play, he will play with one toy each day for all $M$ days. After $M$ days, he will have broken $M$ toys. He will still have toys remaining because he started with more than $M$. The number of toys broken will be $M$.

Combining these two scenarios, the number of toys broken is the minimum of the initial number of toys ($N$) and the number of days the Chef plays ($M$).
Mathematically, `toys_broken = min(N, M)`.

The number of toys remaining is simply the initial number of toys minus the number of toys broken.
`toys_left = N - toys_broken`
`toys_left = N - min(N, M)`

This can be further simplified:
- If $N \le M$, then $\min(N, M) = N$. So, `toys_left = N - N = 0`.
- If $N > M$, then $\min(N, M) = M$. So, `toys_left = N - M`.

This is equivalent to `max(0, N - M)`. However, the direct calculation `N - min(N, M)` is also perfectly valid and perhaps more directly derived from the problem statement.

The problem involves multiple test cases, so the solution needs to handle reading $N$ and $M$ repeatedly until the end of input.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case.
    The solution involves a constant number of arithmetic operations (`std::min`, subtraction) and input/output operations per test case. Since the number of test cases is not specified but is handled by the `while (std::cin >> n >> m)` loop, the total time complexity depends on the number of test cases. If there are $T$ test cases, the total time complexity is $O(T)$. However, for a single execution of the program with a given input, the complexity per test case is constant.

- **Space Complexity**: $O(1)$.
    The solution uses a fixed amount of memory to store variables like `n`, `m`, `toys_broken`, and `toys_left`, regardless of the input size.

## Solution Code
```cpp
#include <iostream>
#include <algorithm> // Required for std::min

int main() {
    // Optimize C++ standard streams for competitive programming
    // Disables synchronization with C's stdio and unties cin from cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m; // n: initial number of toys, m: number of days to play

    // Read input until end-of-file
    while (std::cin >> n >> m) {
        // The Chef plays with one toy per day and breaks it.
        // He plays for M days, but cannot play with more toys than he has.
        // Therefore, the number of toys broken is the minimum of the
        // initial number of toys (n) and the number of days (m).
        int toys_broken = std::min(n, m);

        // The number of toys left is the initial number of toys minus
        // the number of toys that were broken.
        int toys_left = n - toys_broken;

        // Output the result for the current test case, followed by a newline.
        std::cout << toys_left << "\n";
    }

    return 0; // Indicate successful execution
}
```