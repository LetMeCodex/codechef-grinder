# [Check Even (CHKEV)](https://www.codechef.com/problems/CHKEV)
- **Difficulty Rating**: 275
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if there exists at least one even integer within a given closed integer range `[L, R]`. We are given two integers, `L` and `R`, representing the start and end of the range, respectively. We need to print "Yes" if an even number exists in the range, and "No" otherwise.

## Intuition & Mathematical Observation

An even number is an integer that is divisible by 2 (i.e., its remainder when divided by 2 is 0). We need to check if any number `X` such that `L <= X <= R` satisfies `X % 2 == 0`.

Let's analyze the possible scenarios:

1.  **If `L` is an even number**:
    In this case, `L` itself is an even number, and it is part of the range `[L, R]`. Therefore, an even number exists in the range.
    *Example*: If `L=2, R=5`, then `2` is even and in the range. Output: "Yes".
    *Example*: If `L=4, R=4`, then `4` is even and in the range. Output: "Yes".

2.  **If `L` is an odd number**:
    Now we need to check if any subsequent number in the range is even.
    *   **If `L < R`**: This means the range `[L, R]` contains at least two numbers: `L` and `L+1`. Since `L` is odd, `L+1` must be an even number. As `L < R`, `L+1` will always be less than or equal to `R` (because `L+1 <= R` is implied by `L < R` for integers). Thus, `L+1` is an even number within the range `[L, R]`.
        *Example*: If `L=3, R=5`, then `3` is odd. Since `3 < 5`, `3+1=4` is even and in the range `[3, 5]`. Output: "Yes".
        *Example*: If `L=1, R=10`, then `1` is odd. Since `1 < 10`, `1+1=2` is even and in the range `[1, 10]`. Output: "Yes".
    *   **If `L == R`**: In this specific case, the range `[L, R]` contains only one number, `L`. Since we are in the scenario where `L` is odd, there are no even numbers in the range.
        *Example*: If `L=3, R=3`, then `3` is odd. The range only contains `3`. Output: "No".

Combining these observations, an even number exists in the range `[L, R]` if either `L` is even, OR `L` is odd but `L < R`.
The only case where no even number exists is when `L` is odd AND `L == R`.

This logic can be concisely expressed as: `(L % 2 == 0) || (L < R)`.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading two integers and performing a constant number of arithmetic operations (modulo, comparison) and a conditional check. These operations take constant time regardless of the input values `L` and `R`.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`L`, `R`) to store the input. The memory usage does not depend on the magnitude of `L` or `R`, or the size of the range.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can also speed up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables L and R to store the input range.
    int L, R;
    
    // Read the two integers L and R from standard input.
    cin >> L >> R;

    // The problem asks if there is any even integer in the range [L, R].
    // An integer X is even if X % 2 == 0.
    //
    // An even number exists in the range if:
    // 1. L itself is even (L % 2 == 0).
    //    OR
    // 2. L is odd, but the range includes at least one number after L (i.e., L < R).
    //    In this case, L+1 would be in the range. Since L is odd, L+1 is always even.
    //
    // The only scenario where no even number exists is if L is odd AND L == R.
    // This means the range contains only L, which is odd.
    if (L % 2 == 0 || L < R) {
        // If the condition is true, print "Yes" followed by a newline.
        cout << "Yes\n";
    } else {
        // Otherwise (L is odd AND L == R), print "No" followed by a newline.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}
```