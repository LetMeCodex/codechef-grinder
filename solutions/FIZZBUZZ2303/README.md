# [Chef Fantasy 11 (FIZZBUZZ2303)](https://www.codechef.com/problems/FIZZBUZZ2303)
- **Difficulty Rating**: 739
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to pick a captain and a vice-captain for his fantasy eleven team. He has a total of $N$ players in his team. The task is to determine the number of distinct ways to choose a captain and a vice-captain from these $N$ players.

Key constraints/details:
1. A player cannot be both captain and vice-captain.
2. A pair (Captain A, Vice-captain B) is considered different from (Captain B, Vice-captain A). This implies that the order of selection matters.

## Intuition & Mathematical Observation

The problem asks us to select two distinct players from a group of $N$ players and assign them specific roles (captain and vice-captain), where the order of assignment matters. This is a classic permutation problem.

Let's break down the selection process:

1.  **Choosing the Captain**: We have $N$ players available. Any of these $N$ players can be chosen as the captain. So, there are $N$ choices for the captain.

2.  **Choosing the Vice-Captain**: Once a captain has been chosen, that player cannot be the vice-captain (as per the problem statement: "a player cannot be both captain and vice-captain"). This leaves us with $N-1$ players remaining. Any of these $N-1$ players can be chosen as the vice-captain. So, there are $N-1$ choices for the vice-captain.

Since these two choices are sequential and independent (the choice for captain affects the pool for vice-captain, but the number of choices for vice-captain is fixed once captain is chosen), the total number of ways to pick a captain and a vice-captain is the product of the number of choices at each step:

Total ways = (Number of choices for Captain) $\times$ (Number of choices for Vice-captain)
Total ways = $N \times (N-1)$

This is also formally known as the number of permutations of $N$ items taken 2 at a time, denoted as $P(N, 2)$, which is calculated as $\frac{N!}{(N-2)!} = N \times (N-1)$.

The solution simply needs to read $N$ and output $N \times (N-1)$. We use `long long` for the result to prevent potential integer overflow, as $N$ can be up to $10^9$, making $N \times (N-1)$ approximately $10^{18}$, which exceeds the capacity of a 32-bit integer.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    The solution involves reading an integer $N$, performing a single multiplication and a single subtraction, and then printing the result. All these operations take constant time. Since there are $T$ test cases, the total time complexity will be $O(T)$.

-   **Space Complexity**: $O(1)$
    The solution uses a few variables (`t`, `n`, `choices`) to store input and intermediate results. The amount of memory used does not depend on the input size $N$. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Variable to store the number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int n; // Variable to store the number of players
        std::cin >> n; // Read the number of players for the current test case

        // The problem asks for the number of ways to choose a captain and a vice-captain
        // from a group of N players.
        // This is a permutation problem: P(N, 2) = N * (N - 1).
        // For the captain, there are N choices.
        // Once the captain is chosen, there are N-1 remaining players for the vice-captain.
        // So, the total number of choices is N * (N - 1).
        // We cast 'n' to 'long long' before multiplication to prevent potential integer overflow,
        // as N can be large (up to 10^9), making N*(N-1) exceed the capacity of a 32-bit int.
        long long choices = (long long)n * (n - 1);

        std::cout << choices << "\n"; // Print the calculated number of choices followed by a newline
    }

    return 0; // Indicate successful execution
}

```