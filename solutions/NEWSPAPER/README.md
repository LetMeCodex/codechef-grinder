# [Sports Section (NEWSPAPER)](https://www.codechef.com/problems/NEWSPAPER)
- **Difficulty Rating**: 272
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a newspaper with a total of 10 pages, numbered sequentially from 1 to 10. It is stated that the last 3 pages of the newspaper are dedicated to the sports section. We are given a single integer `X`, representing a page number, and our task is to determine whether this page `X` belongs to the sports section. If it does, we should output "YES"; otherwise, we should output "NO".

## Intuition & Mathematical Observation

The newspaper has pages numbered 1, 2, 3, 4, 5, 6, 7, 8, 9, 10.
The problem states that the *last 3 pages* are dedicated to the sports section.
Counting backwards from the last page (page 10):
1. The last page is page 10.
2. The second to last page is page 9.
3. The third to last page is page 8.

Therefore, any page number `X` that is 8, 9, or 10 is part of the sports section.
This condition can be concisely expressed as `X >= 8`. If the given page number `X` is greater than or equal to 8, it's a sports page. Otherwise (if `X` is 1 through 7), it is not.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves reading a single integer input and performing a single comparison (`X >= 8`). These operations take a constant amount of time, regardless of the value of `X` (within its defined constraints).
-   **Space Complexity**: $O(1)$
    The solution uses a fixed, small amount of memory to store the input variable `X` and perform the comparison. This memory usage does not scale with any input size, hence it is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard C++ libraries

using namespace std; // Uses the standard namespace to avoid prefixing std::

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation,
    // further improving performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X; // Declare an integer variable X to store the page number.
    cin >> X; // Read the single integer X from standard input.

    // The problem states that the newspaper has 10 pages, numbered 1 to 10.
    // The last 3 pages are dedicated to the sports section.
    // These pages are:
    // 10 (the last page)
    // 9 (the second to last page)
    // 8 (the third to last page)
    // So, any page number X that is 8, 9, or 10 is part of the sports section.
    // This condition can be simply checked by verifying if X is greater than or equal to 8.
    if (X >= 8) {
        // If X is 8, 9, or 10, it's a sports page.
        cout << "YES\n"; // Output "YES" followed by a newline.
    } else {
        // If X is any page from 1 to 7, it's not a sports page.
        cout << "NO\n"; // Output "NO" followed by a newline.
    }

    return 0; // Indicate successful program execution.
}
```