# [Access Code Equality (WECNITK)](https://www.codechef.com/problems/WECNITK)
- **Difficulty Rating**: 355
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read a single string as input. We need to check if this input string is exactly equal to "WECNITK".
- If the input string is "WECNITK", we should print "Welcome to Web Club!".
- Otherwise (if the input string is anything else), we should print "Access denied".

## Intuition & Mathematical Observation

This problem is a direct string comparison task. There are no complex algorithms, data structures, or mathematical observations required. The core idea is simply to:
1. Read the given input string.
2. Compare it character by character with the target string "WECNITK".
3. Based on the comparison result, print one of the two specified messages.

Since the target string "WECNITK" has a fixed length (7 characters), and the problem implies the input string will also be of a length relevant to this comparison, a direct string equality check is sufficient.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    -   Reading the input string `s`: The maximum length of the string to be compared is fixed (7 characters for "WECNITK"). Reading a string of fixed length takes constant time.
    -   Comparing `s` with "WECNITK": String comparison in C++ (using `operator==` for `std::string`) takes time proportional to the length of the shorter string. Since both strings are effectively of fixed length 7, this comparison takes constant time.
    -   Printing the output: Printing a fixed string takes constant time.
    -   Therefore, the overall time complexity is constant, $O(1)$.

-   **Space Complexity**: $O(1)$
    -   Storing the input string `s`: A `std::string` variable is used to store the input. Since the maximum length of this string is fixed (7 characters), the space required is constant.
    -   No other significant data structures are used.
    -   Therefore, the overall space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream and string
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization, though for this problem's
    // minimal I/O, its impact is negligible.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare a string variable to store the input.
    string s;
    // Read the input string from standard input.
    cin >> s;

    // Check if the input string 's' is exactly equal to "WECNITK".
    if (s == "WECNITK") {
        // If it matches, print the success message.
        cout << "Welcome to Web Club!\n";
    } else {
        // Otherwise, print the access denied message.
        cout << "Access denied\n";
    }

    // Indicate successful program execution.
    return 0;
}
```