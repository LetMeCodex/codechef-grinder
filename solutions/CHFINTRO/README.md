# [Chef and Interactive Contests (CHFINTRO)](https://www.codechef.com/problems/CHFINTRO)
- **Difficulty Rating**: 951
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the status of `N` contestants based on their ratings. We are given a minimum required rating, `r`. For each contestant, we read their individual rating, `R`. If a contestant's rating `R` is greater than or equal to the minimum required rating `r`, they are deemed a "Good boi". Otherwise, if their rating `R` is less than `r`, they are a "Bad boi". We need to print "Good boi" or "Bad boi" for each contestant on a new line.

## Intuition & Mathematical Observation

The problem is a straightforward application of conditional logic. For each contestant, we simply need to perform a direct comparison between their rating and the given threshold. There are no complex algorithms, data structures, or mathematical observations required beyond this basic `if-else` check.

The steps are:
1.  Read the total number of contestants (`N`) and the minimum required rating (`r`).
2.  Iterate `N` times, once for each contestant.
3.  In each iteration, read the current contestant's rating (`R`).
4.  Compare `R` with `r`:
    *   If `R >= r`, print "Good boi".
    *   Else (`R < r`), print "Bad boi".

This process is repeated for all `N` contestants independently.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   Reading `N` and `r` takes constant time, $O(1)$.
    *   The core logic involves a `for` loop that iterates `N` times.
    *   Inside the loop, we perform:
        *   Reading an integer `R`: $O(1)$.
        *   A comparison `R >= r`: $O(1)$.
        *   Printing a fixed string ("Good boi" or "Bad boi"): $O(1)$.
    *   Since constant time operations are performed `N` times, the total time complexity is proportional to `N`.

*   **Space Complexity**: $O(1)$
    *   We use a few integer variables (`N`, `r`, `i`, `R`) to store input values and loop counters. These variables occupy a constant amount of memory regardless of the input size `N`.
    *   No dynamic data structures (like arrays, vectors, maps) are used that would scale with the input.
    *   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for cin and cout
// #include <bits/stdc++.h> // A common competitive programming header, includes iostream and many others

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N; // Number of contestants
    int r; // Minimum rating required to not forget flushing

    // Read N and r from the first line of input
    std::cin >> N >> r;

    // Loop N times, once for each contestant
    for (int i = 0; i < N; ++i) {
        int R; // Rating of the current contestant
        // Read the contestant's rating
        std::cin >> R;

        // Check if the contestant's rating R is at least r
        if (R >= r) {
            // If rating is sufficient, print "Good boi"
            std::cout << "Good boi\n";
        } else {
            // Otherwise, print "Bad boi"
            std::cout << "Bad boi\n";
        }
    }

    return 0; // Indicate successful execution
}

```