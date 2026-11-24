# [Recover Palindrome (P2235)](https://www.codechef.com/problems/P2235)
- **Difficulty Rating**: 825
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a given string `S` of length `N`, which may contain lowercase English letters and '?' characters, can be completed into a *unique* palindrome. We need to replace each '?' with a lowercase English letter. The problem guarantees that the input string can always be completed into at least one palindrome. If there is exactly one way to form such a palindrome, output "YES". Otherwise (if there are multiple ways), output "NO".

## Intuition & Mathematical Observation
A string is a palindrome if it reads the same forwards and backwards. This implies that for any index `i` (0-indexed), the character `S[i]` must be equal to `S[N-1-i]`. We are looking for whether there's a *unique* way to fill in the '?' characters to satisfy this condition. The problem guarantees that at least one palindrome can always be formed, so we only need to check for the existence of *multiple* ways.

Let's analyze the pairs of characters `S[i]` and `S[N-1-i]` for `0 <= i < N/2`:

1.  **`S[i]` is a letter, `S[N-1-i]` is a letter:**
    *   If `S[i] == S[N-1-i]`, this pair is consistent and uniquely determined.
    *   If `S[i] != S[N-1-i]`, this would make it impossible to form a palindrome. However, the problem statement guarantees that at least one palindrome can always be formed, so this case will not occur.

2.  **One of `S[i]` or `S[N-1-i]` is a letter, and the other is '?' (e.g., `S[i] = 'a'`, `S[N-1-i] = '?'`):**
    *   To satisfy the palindrome condition, the '?' *must* be replaced by the letter from its mirrored position. For example, if `S[i] = 'a'`, then `S[N-1-i]` must become 'a'. This pair is uniquely determined.

3.  **Both `S[i]` and `S[N-1-i]` are '?' (`S[i] = '?', S[N-1-i] = '?'`):**
    *   To satisfy the palindrome condition, both '?'s must be replaced by the *same* character. However, they can be replaced by *any* lowercase English letter (e.g., 'a', 'b', 'c', ..., 'z'). Since there are 26 possible choices, this immediately leads to *multiple* ways to form a palindrome. If we encounter such a pair, the answer is "NO".

**Special Case: Middle Character for Odd Length Strings**
If `N` is an odd number, there is a middle character `S[N/2]` that does not have a mirrored pair.
*   If `S[N/2]` is a letter, it's fixed and uniquely determined.
*   If `S[N/2]` is '?', it can be replaced by *any* lowercase English letter. Similar to case 3 above, this leads to *multiple* ways to form a palindrome. If we encounter this, the answer is "NO".

**Conclusion:**
A unique palindrome can be formed if and only if *every* character or pair of characters is uniquely determined. This means:
*   For every `i` from `0` to `N/2 - 1`, it must *not* be the case that both `S[i]` and `S[N-1-i]` are '?'.
*   If `N` is odd, the middle character `S[N/2]` must *not* be '?'.

If any of these conditions are violated, it implies there's at least one position (or pair of positions) that can be filled in multiple ways, leading to multiple possible palindromes. In this scenario, the answer is "NO". Otherwise, if all positions are uniquely determined, the answer is "YES".

## Complexity Analysis
-   **Time Complexity**: The solution involves a single loop that iterates approximately `N/2` times for each test case. Inside the loop, operations like character comparison and assignment are constant time. After the loop, there's a constant time check for the middle character. Therefore, for each test case, the time complexity is $O(N)$. Given `T` test cases, the total time complexity is $O(T \cdot N)$.
-   **Space Complexity**: The solution uses a string `s` of length `N` to store the input. Apart from this, only a few integer variables and a boolean flag are used, which consume constant extra space. Thus, the auxiliary space complexity is $O(1)$. Considering the input string storage, the space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the length of the string
        std::string s;
        std::cin >> s; // Read the string

        bool unique = true; // Flag to track if the palindrome can be uniquely formed

        // Iterate through the first half of the string
        // Compare characters at mirrored positions (s[i] and s[n-1-i])
        for (int i = 0; i < n / 2; ++i) {
            int j = n - 1 - i; // Mirrored position
            
            // If both mirrored positions are '?', they can be filled with any character.
            // This leads to multiple possibilities, so the palindrome is not unique.
            if (s[i] == '?' && s[j] == '?') {
                unique = false; // Mark as not unique
                break;          // No need to check further for this test case
            }
            // Other cases (guaranteed not to lead to impossibility or ambiguity for pairs):
            // - If one is '?' and the other is a letter, the '?' is fixed.
            // - If both are letters and match, they are fixed.
            // - If both are letters and don't match, it's impossible (guaranteed not to happen by problem statement).
            // So, only the '??' case introduces ambiguity for pairs.
        }

        // For odd length strings, the middle character (s[n/2]) mirrors itself.
        // If it's '?', it can be any character, leading to multiple possibilities.
        // This check is only relevant if 'unique' is still true from the pair checks.
        if (unique && n % 2 == 1 && s[n / 2] == '?') {
            unique = false; // Mark as not unique
        }

        // Output "YES" if the palindrome can be uniquely formed, "NO" otherwise.
        if (unique) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```