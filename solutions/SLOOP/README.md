# [Coldplay (SLOOP)](https://www.codechef.com/problems/SLOOP)
- **Difficulty Rating**: 854
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine how many times a song of a specific duration `S` can be played completely during a trip that lasts for `M` minutes. We are given `T` test cases, and for each test case, we need to read `M` and `S` and output the result.

## Intuition & Mathematical Observation

The core of this problem is a straightforward division. If you have a total duration `M` and each instance of an event (playing a song) takes `S` duration, you want to find out how many full instances of that event can fit into the total duration.

This is precisely what integer division calculates. For example:
*   If the trip duration `M` is 10 minutes and the song duration `S` is 5 minutes, the song can be played $10 / 5 = 2$ times completely.
*   If `M` is 10 minutes and `S` is 6 minutes, the song can be played $10 / 6 = 1$ time completely (with 4 minutes remaining).
*   If `M` is 9 minutes and `S` is 10 minutes, the song cannot be played even once completely, so $9 / 10 = 0$ times.

In C++, the `/` operator performs integer division when both operands are integers, which automatically gives us the floor value (the largest integer less than or equal to the actual quotient). This is exactly what we need for "how many times completely".

Therefore, for each test case, the answer is simply `M / S`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    *   The program iterates `T` times, once for each test case.
    *   Inside the loop, it performs constant time operations: reading two integers (`cin >> M >> S`), one integer division (`M / S`), and printing one integer (`cout << ...`).
    *   Since each test case takes $O(1)$ time, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`T`, `M`, `S`) regardless of the input values (other than `T` itself, which determines the number of iterations, not memory usage for storing inputs).
    *   No data structures are used that grow with the input size.
    *   Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// The problem statement asks to use `using namespace std;`
using namespace std;

int main() {
    // Fast I/O setup as requested by the problem statement.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int M, S; // M: duration of the trip, S: duration of the song.
        cin >> M >> S; // Read M and S for the current test case.

        // To find out how many times the song can be played completely,
        // we need to divide the total trip duration (M) by the song duration (S).
        // Integer division in C++ (M / S) automatically gives the floor value,
        // which is exactly what we need for "how many times completely".
        // For example:
        // If M=10, S=5, then 10/5 = 2. (Song plays 2 times)
        // If M=10, S=6, then 10/6 = 1. (Song plays 1 time completely, 4 minutes remaining)
        // If M=9, S=10, then 9/10 = 0. (Song cannot be completed even once)
        cout << M / S << "\n"; // Output the result followed by a newline.
    }

    return 0; // Indicate successful execution.
}
```