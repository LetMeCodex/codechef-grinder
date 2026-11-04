# [Movie Hype (MOVHYPE)](https://www.codechef.com/problems/MOVHYPE)
- **Difficulty Rating**: 921
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a movie theater with $2N+1$ seats in a single row. The odd-numbered seats ($1, 3, 5, \dots, 2N+1$) are occupied by people, each having a specific "hype level" ($A_1, A_2, \dots, A_{N+1}$ respectively). The even-numbered seats ($2, 4, 6, \dots, 2N$) are empty.

Chef wants to sit in one of these empty seats. If Chef chooses to sit in seat $2i$, their "loudness level" will be determined by the maximum of the hype levels of the two people sitting in the adjacent seats, $2i-1$ and $2i+1$. Specifically, the loudness for seat $2i$ is $\max(\text{hype level of person in seat } 2i-1, \text{hype level of person in seat } 2i+1)$.

Chef wants to choose an empty seat such that their resulting loudness level is minimized. The task is to find and output this minimum possible loudness level.

## Intuition & Mathematical Observation

Let's break down the problem statement to understand the relationships between seats, hype levels, and loudness.

1.  **Occupied Seats and Hype Levels:**
    *   Seat $1$ has hype level $A_1$.
    *   Seat $3$ has hype level $A_2$.
    *   Seat $5$ has hype level $A_3$.
    *   ...
    *   In general, seat $2k-1$ has hype level $A_k$.
    *   The input provides $N+1$ hype levels, $A_1, \dots, A_{N+1}$. In the C++ solution, these are typically stored in a 0-indexed array or vector `a` of size `N+1`. So, `a[0]` corresponds to $A_1$, `a[1]` to $A_2$, ..., and `a[k]` to $A_{k+1}$.

2.  **Empty Seats and Loudness Calculation:**
    *   The empty seats are $2, 4, \dots, 2N$.
    *   If Chef sits in seat $2i$ (where $i$ ranges from $1$ to $N$):
        *   The person in seat $2i-1$ has hype level $A_i$.
        *   The person in seat $2i+1$ has hype level $A_{i+1}$.
        *   Therefore, the loudness for seat $2i$ is $\max(A_i, A_{i+1})$.

3.  **Translating to 0-indexed array `a`:**
    *   Using our mapping from step 1, $A_i$ is stored in `a[i-1]`, and $A_{i+1}$ is stored in `a[i]`.
    *   So, for an empty seat $2i$, the loudness is $\max(a[i-1], a[i])$.
    *   The possible values for $i$ are $1, 2, \dots, N$.
    *   This means we need to calculate the maximums for the following pairs:
        *   For $i=1$ (seat $2$): $\max(a[0], a[1])$
        *   For $i=2$ (seat $4$): $\max(a[1], a[2])$
        *   ...
        *   For $i=N$ (seat $2N$): $\max(a[N-1], a[N])$

4.  **Finding the Minimum Loudness:**
    *   Chef wants to minimize their loudness. This means we need to calculate all possible loudness values (as derived in step 3) and then find the minimum among them.
    *   We can initialize a variable `min_loudness` to a very large value (e.g., 101, since hype levels are between 1 and 100).
    *   Then, we iterate through all possible pairs `(a[k], a[k+1])` for $k$ from $0$ to $N-1$.
    *   For each pair, we calculate `current_loudness = std::max(a[k], a[k+1])`.
    *   We update `min_loudness = std::min(min_loudness, current_loudness)`.
    *   After checking all possible empty seats, `min_loudness` will hold the answer.

The provided solution correctly implements this logic: it reads the $N+1$ hype levels into a vector `a`, then iterates from `i = 0` to `N-1` to consider all adjacent pairs `(a[i], a[i+1])`, calculates their maximum, and keeps track of the minimum such maximum found.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Reading $N+1$ integers into the vector `a`: $O(N)$.
        *   Iterating through the `N` possible empty seats (from `i=0` to `N-1` in the loop): $O(N)$ operations. Inside the loop, `std::max` and `std::min` are constant time operations.
    *   Therefore, the total time complexity per test case is $O(N)$.
    *   Given $T$ test cases, the overall time complexity is $O(T \cdot N)$. With $T \le 100$ and $N \le 100$, this is at most $100 \times 100 = 10^4$ operations, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   For each test case:
        *   A `std::vector<int> a` of size `N+1` is used to store the hype levels. This requires $O(N)$ space.
        *   Other variables (`t`, `n`, `min_loudness`, `current_loudness`) use a constant amount of space, $O(1)$.
    *   Thus, the total space complexity per test case is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::max and std::min

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        int n; // N as described in the problem (2N+1 seats, N+1 hype levels)
        std::cin >> n;

        // Create a vector to store the hype levels.
        // The problem states N+1 hype levels (A_1 to A_{N+1}).
        // Using 0-based indexing, a[0] will store A_1, a[1] will store A_2, ..., a[N] will store A_{N+1}.
        std::vector<int> a(n + 1);
        for (int i = 0; i <= n; ++i) {
            std::cin >> a[i];
        }

        // Initialize min_loudness to a value greater than any possible hype level.
        // Constraints state 1 <= A_i <= 100, so 101 is a safe initial maximum.
        int min_loudness = 101; 

        // Chef can sit in empty seats: 2, 4, 6, ..., 2N.
        // Let's analyze the loudness for each empty seat:
        //
        // Seat 2: Is between seat 1 (hype A_1, stored in a[0]) and seat 3 (hype A_2, stored in a[1]).
        //         Loudness = max(A_1, A_2) = max(a[0], a[1]).
        //
        // Seat 4: Is between seat 3 (hype A_2, stored in a[1]) and seat 5 (hype A_3, stored in a[2]).
        //         Loudness = max(A_2, A_3) = max(a[1], a[2]).
        //
        // ...
        //
        // Seat 2i: Is between seat 2i-1 (hype A_i, stored in a[i-1]) and seat 2i+1 (hype A_{i+1}, stored in a[i]).
        //          Loudness = max(A_i, A_{i+1}) = max(a[i-1], a[i]).
        //          This applies for i = 1, 2, ..., N.
        //
        // The loop below iterates with 'i' from 0 to n-1.
        // When loop variable is 'k':
        // It considers a[k] and a[k+1].
        // This corresponds to A_{k+1} and A_{k+2} from the problem statement's 1-based indexing.
        // This calculates the loudness for seat 2(k+1).
        //
        // Example:
        // k=0: max(a[0], a[1]) -> loudness for seat 2(0+1) = seat 2.
        // k=1: max(a[1], a[2]) -> loudness for seat 2(1+1) = seat 4.
        // ...
        // k=n-1: max(a[n-1], a[n]) -> loudness for seat 2((n-1)+1) = seat 2N.
        // This covers all possible empty seats.

        for (int i = 0; i < n; ++i) {
            // Calculate loudness if Chef sits in the empty seat between a[i] and a[i+1]
            int current_loudness = std::max(a[i], a[i + 1]);
            // Update min_loudness if the current option is better
            min_loudness = std::min(min_loudness, current_loudness);
        }

        // Output the minimum possible loudness level
        std::cout << min_loudness << "\n";
    }
    return 0;
}

```