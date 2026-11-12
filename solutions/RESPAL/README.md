# [Restrict Palindromes (RESPAL)](https://www.codechef.com/problems/RESPAL)
- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to construct a string of length `N` using lowercase English letters such that it does not contain any palindromic substring of length 2 or 3. We need to output such a string for a given `N`. This process is repeated for `T` test cases.

## Intuition & Mathematical Observation
The core constraint is that no substring of length 2 or 3 should be a palindrome. Let's break down what this implies:

1.  **No substring of length 2 is a palindrome**: This means that for any index `i`, the character `s[i]` must be different from `s[i+1]`. In simpler terms, no two adjacent characters can be the same. Mathematically, `s[i] != s[i+1]` for all valid `i`.

2.  **No substring of length 3 is a palindrome**: This means that for any index `i`, the character `s[i]` must be different from `s[i+2]`. In simpler terms, characters separated by one character cannot be the same. Mathematically, `s[i] != s[i+2]` for all valid `i`.

Combining these two conditions, we need to find a pattern of characters `s[0], s[1], s[2], s[3], ...` such that:
- `s[i] != s[i+1]` for all valid `i`.
- `s[i] != s[i+2]` for all valid `i`.

Let's try to construct such a string using a minimal set of characters:

*   **Using 1 character (e.g., 'a')**: If we use `aaaaa...`
    - This fails `s[i] != s[i+1]` (e.g., `a == a`).
*   **Using 2 characters (e.g., 'a', 'b')**: A common alternating pattern is `ababab...`
    - This satisfies `s[i] != s[i+1]` (e.g., `a != b`).
    - However, it fails `s[i] != s[i+2]` (e.g., `s[0] = 'a'`, `s[2] = 'a'`). The substring `aba` is a palindrome.
    So, two characters are not enough.

*   **Using 3 characters (e.g., 'a', 'b', 'c')**: Let's try a repeating pattern `abcabcabc...`
    - Let's check `s[i] != s[i+1]`:
        - `a != b` (True)
        - `b != c` (True)
        - `c != a` (True)
        This condition is satisfied.
    - Let's check `s[i] != s[i+2]`:
        - `s[0] = 'a'`, `s[2] = 'c'`. `a != c` (True)
        - `s[1] = 'b'`, `s[3] = 'a'`. `b != a` (True)
        - `s[2] = 'c'`, `s[4] = 'b'`. `c != b` (True)
        This condition is also satisfied.

Since both conditions are met, the repeating pattern `abcabcabc...` is a valid construction for any `N`. We can generate this pattern by appending `(char)('a' + (i % 3))` for each index `i` from `0` to `N-1`. This simple pattern ensures that no adjacent characters are the same, and no characters separated by one character are the same, thus satisfying all problem constraints.

## Complexity Analysis
-   **Time Complexity**:
    -   For each test case, we iterate `N` times to construct the string. Each character append operation to `std::string` takes amortized $O(1)$ time. Printing the string of length `N` takes $O(N)$ time.
    -   Therefore, for a single test case, the time complexity is $O(N)$.
    -   Given `T` test cases and a total sum of `N` over all test cases ($\sum N$), the total time complexity is $O(\sum N)$.
-   **Space Complexity**:
    -   We store the generated string of length `N`. This requires $O(N)$ space.
    -   Other variables use constant space.
    -   Therefore, for a single test case, the space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <vector> // Not strictly necessary for this problem, but common in competitive programming

void solve() {
    int n;
    std::cin >> n; // Read the length N

    std::string s = ""; // Initialize an empty string
    for (int i = 0; i < n; ++i) {
        // Append characters 'a', 'b', 'c' in a repeating pattern
        // 'a' + (i % 3) will give:
        // 'a' for i=0, 3, 6, ...
        // 'b' for i=1, 4, 7, ...
        // 'c' for i=2, 5, 8, ...
        s += (char)('a' + (i % 3));
    }
    std::cout << s << "\n"; // Print the constructed string followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```