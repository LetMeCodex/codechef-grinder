# [Lucky Seven (LUCKYSEVEN)](https://www.codechef.com/problems/LUCKYSEVEN)
- **Difficulty Rating**: 213
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem "Lucky Seven" asks us to read a single string `S` which is guaranteed to have a length of exactly 10 characters. Our task is to print the 7th character of this string.

## Intuition & Mathematical Observation

The core of this problem lies in understanding string indexing conventions in programming.

1.  **String Indexing**: In C++ (and many other programming languages like Python, Java, etc.), strings are 0-indexed. This means:
    *   The 1st character is at index 0.
    *   The 2nd character is at index 1.
    *   ...and so on.
2.  **Finding the 7th Character**: Following the 0-indexed convention, the 7th character of a string will be located at index `7 - 1 = 6`.
3.  **Constraints**: The problem statement guarantees that the string `S` will always have a length of 10. This simplifies things as we don't need to worry about edge cases like the string being too short (e.g., less than 7 characters), which would lead to an out-of-bounds error. We can directly access `S[6]`.

Therefore, the solution is straightforward: read the input string and print the character at index 6.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    *   Reading a string of fixed length 10 takes constant time.
    *   Accessing a character at a specific, fixed index (like index 6) takes constant time.
    *   Printing a single character takes constant time.
    *   Since all operations are independent of the input size (which is fixed at 10), the overall time complexity is constant.

*   **Space Complexity**: $O(1)$
    *   Storing the input string of fixed length 10 requires a constant amount of memory.
    *   No additional data structures are used that would scale with input size.
    *   Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYSEVEN
 * The problem asks for the 7th character of a string S of length 10.
 * In C++, strings are 0-indexed, so the 7th character is at index 6.
 * Time Complexity: O(1) per test case (string length is fixed at 10).
 * Space Complexity: O(1) to store the string.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single string input per execution 
    // based on the sample cases, but we structure it to handle the input string.
    string s;
    if (cin >> s) {
        // The 7th character is at index 6 (0-indexed)
        cout << s[6] << "\n";
    }

    return 0;
}
```