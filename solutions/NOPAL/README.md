# [Palindromes Not Allowed (NOPAL)](https://www.codechef.com/problems/NOPAL)
- **Difficulty Rating**: 1360
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to construct a string of a given length `N` such that it does not contain any palindrome of length 2 or more. We need to do this for `T` test cases. The length `N` can be up to 100.

## Intuition & Mathematical Observation

The core constraint is to avoid any substring that is a palindrome and has a length of at least 2. Let's consider what this means:

1.  **Avoid palindromes of length 2**: This means no `AA` substrings. For example, `s[i] != s[i+1]` for all `i`.
2.  **Avoid palindromes of length 3**: This means no `ABA` substrings. For example, `s[i] != s[i+2]` for all `i`.
3.  **Avoid palindromes of length 4**: This means no `ABBA` substrings. This would imply `s[i] == s[i+3]` and `s[i+1] == s[i+2]`.
4.  **Avoid palindromes of length `L`**: In general, for a substring to be a palindrome, `s[k] == s[L-1-k]` for all `0 <= k < L/2` (relative to the start of the substring).

Let's try to construct a simple repeating pattern using a minimal set of characters.

*   **Using 1 character (e.g., `aaaaa...`)**: This immediately fails, as `aa` is a length-2 palindrome.
*   **Using 2 characters (e.g., `ababab...`)**:
    *   Does it avoid `AA`? Yes, `a != b`.
    *   Does it avoid `ABA`? No, `s[0] = 'a'`, `s[1] = 'b'`, `s[2] = 'a'`. So `aba` is present. This pattern is not valid.

*   **Using 3 characters (e.g., `abcabcabc...`)**:
    Let's define this pattern as `s[i] = 'a' + (i % 3)`.

    1.  **Check for `AA` (length 2 palindrome)**:
        This requires `s[i] == s[i+1]`.
        In our pattern, `s[i]` is `a`, `b`, or `c`. `s[i+1]` will be the next character in the cycle (`b`, `c`, or `a`).
        `'a' != 'b'`, `'b' != 'c'`, `'c' != 'a'`.
        So, `s[i] != s[i+1]` is always true. No length-2 palindromes. This is good.

    2.  **Check for `ABA` (length 3 palindrome)**:
        This requires `s[i] == s[i+2]`.
        In our pattern, `s[i] = 'a' + (i % 3)` and `s[i+2] = 'a' + ((i+2) % 3)`.
        For `s[i] == s[i+2]` to be true, `i % 3` must be equal to `(i+2) % 3`.
        Let `k = i % 3`. We need `k == (k+2) % 3`.
        *   If `k=0`: `0 == (0+2)%3 = 2`. False.
        *   If `k=1`: `1 == (1+2)%3 = 0`. False.
        *   If `k=2`: `2 == (2+2)%3 = 1`. False.
        So, `s[i] != s[i+2]` is always true. No length-3 palindromes. This is also good.

    3.  **Check for palindromes of length 4 or more**:
        *   Any palindrome of **even length** `L >= 2` (e.g., `ABBA`, `ABCCBA`) must have `s[k] == s[k+1]` for some `k` within the palindrome (specifically, the two middle characters). For example, in `ABBA`, `s[1] == s[2]` (the `BB` part). Since our pattern `abcabc...` ensures `s[i] != s[i+1]` for *any* `i`, it cannot contain any `AA` type substring. Therefore, it cannot contain any even-length palindrome.
        *   Any palindrome of **odd length** `L >= 3` (e.g., `ABA`, `ABCBA`) must have `s[k] == s[k+2]` for some `k` within the palindrome (specifically, characters separated by one character). For example, in `ABCBA`, `s[0] == s[2]` (the `ACA` part) and `s[1] == s[3]` (the `BCB` part). Since our pattern `abcabc...` ensures `s[i] != s[i+2]` for *any* `i`, it cannot contain any `ABA` type substring. Therefore, it cannot contain any odd-length palindrome.

Since the `abcabc...` pattern avoids both `s[i] == s[i+1]` and `s[i] == s[i+2]`, it successfully avoids all palindromes of length 2 or more. This is a valid and simple construction.

## Complexity Analysis

*   **Time Complexity**: For each test case, we iterate `N` times to construct the string. Appending a character to a `std::string` in C++ takes amortized $O(1)$ time. Printing the final string takes $O(N)$ time. Since there are `T` test cases, the total time complexity is $O(T \cdot N)$. Given `N <= 100` and `T <= 1000`, $1000 \cdot 100 = 10^5$ operations, which is very efficient.
*   **Space Complexity**: For each test case, we store the constructed string of length `N`. This requires $O(N)$ space. Given `N <= 100`, this is a very small amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, etc.
using namespace std; // As requested by the problem statement

void solve() {
    int n;
    cin >> n; // Read the length of the string
    string s = ""; // Initialize an empty string
    for (int i = 0; i < n; ++i) {
        // Append characters 'a', 'b', 'c' in a cyclic manner
        // 'a' for i%3 == 0
        // 'b' for i%3 == 1
        // 'c' for i%3 == 2
        s += (char)('a' + (i % 3));
    }
    cout << s << "\n"; // Print the constructed string followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming practice.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}

```