# [Cute Strings (CUTESTR)](https://www.codechef.com/problems/CUTESTR)
- **Difficulty Rating**: 271
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given 3-character string is "cute". A string is defined as cute if two conditions are met simultaneously:
1. The first character of the string is equal to its third character.
2. The second character of the string is 'w'.

If both conditions are true, we should print "Cute". Otherwise, we should print "No".

## Intuition & Mathematical Observation

This problem is a direct application of conditional logic. There are no complex algorithms, data structures, or deep mathematical observations required. The problem statement explicitly defines what makes a string "cute" with two simple conditions.

Our intuition should be to:
1. Read the input string.
2. Access its characters by their indices (0, 1, and 2, since it's a 3-character string).
3. Check if `string[0]` is equal to `string[2]`.
4. Check if `string[1]` is equal to `'w'`.
5. If both checks pass, the string is cute. Otherwise, it is not.

This can be implemented using a single `if-else` statement with a logical AND (`&&`) operator combining the two conditions.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The input string has a fixed length of 3 characters.
    - Reading a 3-character string takes constant time.
    - Accessing specific characters by index (`s[0]`, `s[1]`, `s[2]`) takes constant time.
    - Performing two comparisons and a logical AND operation takes constant time.
    - Printing the output ("Cute" or "No") takes constant time.
    Since all operations take a constant amount of time regardless of the input (as the input size is fixed), the overall time complexity is $O(1)$.

-   **Space Complexity**: $O(1)$
    - We store the input string `s`, which has a fixed length of 3 characters. This requires a constant amount of memory.
    - No additional data structures are used that would scale with input size.
    Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, string, etc.

// It's common in competitive programming to use the entire std namespace.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is generally good practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare a string variable to store the input.
    // The problem guarantees the string will be of length 3.
    string s;

    // Read the 3-character string from standard input.
    cin >> s;

    // Check the two conditions for a string to be "cute":
    // 1. The first character (s[0]) must be equal to the third character (s[2]).
    // 2. The second character (s[1]) must be 'w'.
    if (s[0] == s[2] && s[1] == 'w') {
        // If both conditions are true, the string is cute.
        cout << "Cute\n";
    } else {
        // Otherwise, the string is not cute.
        cout << "No\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}
```