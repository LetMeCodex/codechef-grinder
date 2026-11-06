# [Range Odd (RNGEODD)](https://www.codechef.com/problems/RNGEODD)
- **Difficulty Rating**: -1
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to read two integers, `L` and `R`, representing a range `[L, R]`. Our task is to print all odd numbers within this inclusive range, separated by spaces. After printing all odd numbers, a newline character should be printed.

**Constraints**:
*   `1 <= L <= R <= 100`

## Intuition & Mathematical Observation

1.  **Identify the first odd number**: We need to start printing from an odd number.
    *   If `L` itself is an odd number, then `L` is our starting point.
    *   If `L` is an even number, then the next number, `L + 1`, will be the first odd number in the range (assuming `L+1 <= R`).
    This can be concisely determined: if `L % 2 != 0`, start with `L`; otherwise, start with `L + 1`.

2.  **Iterate efficiently**: Once we have the first odd number (`start_odd`), all subsequent odd numbers are found by adding 2 to the current odd number. For example, if `start_odd` is 3, the next odd number is `3 + 2 = 5`, then `5 + 2 = 7`, and so on. We continue this process as long as the current number is less than or equal to `R`.

3.  **Output Formatting**: The problem requires numbers to be separated by spaces. This means a space should be printed *before* every odd number *except the very first one*. A simple boolean flag (`first_odd_printed`) can manage this:
    *   Initialize `first_odd_printed = false`.
    *   Before printing any number, check `first_odd_printed`. If it's `true`, print a space.
    *   After printing a number, set `first_odd_printed = true`.

4.  **Performance (I/O)**: Although the constraints (`R <= 100`) are very small, making I/O speed less critical, it's good practice in competitive programming to use faster I/O methods. The provided solution uses `ios_base::sync_with_stdio(false); cin.tie(NULL);` for input (`cin`) and `printf` for output, which are generally faster than `cin`/`cout` without optimizations.

## Complexity Analysis

*   **Time Complexity**: The algorithm iterates through odd numbers in the range `[L, R]`. In the worst case, `L=1` and `R=100`. The loop will run approximately `(R - L) / 2` times. For `R=100`, this is about `(100 - 1) / 2 = 49` iterations. This is a constant number of operations relative to typical competitive programming limits. Therefore, the time complexity is **$O(R - L)$**, which for the given constraints is effectively **$O(1)$** (constant time).

*   **Space Complexity**: The solution uses a few integer variables (`L`, `R`, `current_num`) and a boolean flag (`first_odd_printed`). The amount of memory used does not depend on the input values `L` or `R`. Thus, the space complexity is **$O(1)$** (constant space).

## Solution Code

```cpp
#include <iostream> // Required for cin
#include <cstdio>   // Required for printf

// Use the standard namespace to avoid writing std::repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    // These lines primarily affect cin/cout. While we're switching to printf for output,
    // cin is still used for input, so these are beneficial for input speed.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, R; // Declare two integer variables L and R
    cin >> L >> R; // Read the values of L and R from standard input

    // Determine the first odd number to start printing from.
    // If L is odd, start from L.
    // If L is even, the next number (L+1) will be odd, so start from L+1.
    int current_num;
    if (L % 2 != 0) { // L is odd
        current_num = L;
    } else { // L is even
        current_num = L + 1;
    }

    bool first_odd_printed = false; // Flag to manage space printing

    // Iterate from the first odd number up to R (inclusive), incrementing by 2 each time.
    // This ensures we only process odd numbers and do so efficiently.
    while (current_num <= R) {
        if (first_odd_printed) {
            // If an odd number has already been printed, print a space before the current one.
            printf(" "); // Using printf for faster output
        }
        printf("%d", current_num); // Using printf for faster output
        first_odd_printed = true; // Set flag to true as an odd number has now been printed
        current_num += 2; // Move to the next odd number
    }

    printf("\n"); // Print a newline character at the end of the output line using printf

    return 0; // Indicate successful execution
}
```