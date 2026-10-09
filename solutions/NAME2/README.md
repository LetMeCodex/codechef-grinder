# [Your Name is Mine (NAME2)](https://www.codechef.com/problems/NAME2)
- **Difficulty Rating**: 1285
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two strings, `m` and `w`, determine if one string is a subsequence of the other. A subsequence is formed by deleting zero or more characters from a string without changing the order of the remaining characters.

## Intuition & Mathematical Observation
The problem asks us to check if string `m` is a subsequence of string `w`, OR if string `w` is a subsequence of string `m`.

Let's define the `isSubsequence(a, b)` function. This function returns `true` if string `a` is a subsequence of string `b`, and `false` otherwise. The standard way to implement this is using two pointers. We iterate through string `b` with one pointer (`j`) and through string `a` with another pointer (`i`). If `a[i]` matches `b[j]`, we advance `i`. Regardless of a match, we always advance `j`. If `i` reaches the end of string `a`, it means all characters of `a` were found in `b` in the correct order, so `a` is a subsequence of `b`.

The core logic of the problem is to call this `isSubsequence` function twice: once to check if `m` is a subsequence of `w`, and once to check if `w` is a subsequence of `m`. If either of these checks returns `true`, then the answer is "YES". Otherwise, the answer is "NO".

An important observation regarding subsequences and lengths:
- If string `A` is a subsequence of string `B`, then the length of `A` must be less than or equal to the length of `B` (i.e., $|A| \le |B|$).
- If $|A| > |B|$, it's impossible for `A` to be a subsequence of `B`.

While the provided solution checks both `isSubsequence(m, w)` and `isSubsequence(w, m)` directly, we could optimize slightly by considering lengths first. For example, if `m.length() > w.length()`, we only need to check `isSubsequence(w, m)`. If `w.length() > m.length()`, we only need to check `isSubsequence(m, w)`. If their lengths are equal, and one is a subsequence of the other, they must be identical strings. However, the current approach is clear and correct.

The `isSubsequence` function works as follows:
Initialize two pointers, `i` for string `a` and `j` for string `b`, both to 0.
Iterate while `i` is within the bounds of `a` and `j` is within the bounds of `b`:
  If `a[i]` equals `b[j]`, increment `i` (meaning we found the next character of `a`).
  Always increment `j` (to move to the next character in `b`).
After the loop, if `i` has reached the length of `a`, it means all characters of `a` were found in `b` in order, so `a` is a subsequence of `b`.

## Complexity Analysis
- **Time Complexity**: $O(|m| + |w|)$
  The `isSubsequence` function iterates through both strings at most once. In the worst case, it traverses the entire length of both strings. Since we call `isSubsequence` at most twice (once for `m` in `w`, and once for `w` in `m`), the total time complexity is dominated by the lengths of the two input strings.
- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space for variables like `t`, `m`, `w`, and the pointers `i` and `j` within the `isSubsequence` function. The space used by the input strings themselves is not counted as extra space.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Function to check if string A is a subsequence of string B
bool isSubsequence(const std::string& a, const std::string& b) {
    int i = 0, j = 0; // i for string a, j for string b
    while (i < a.length() && j < b.length()) {
        if (a[i] == b[j]) {
            i++; // Found a character of 'a', move to the next character in 'a'
        }
        j++; // Always move to the next character in 'b'
    }
    // If i reached the end of string 'a', it means all characters of 'a' were found in 'b' in order.
    return i == a.length();
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        std::string m, w; // Input strings
        std::cin >> m >> w;

        // The problem requires checking if 'm' is a subsequence of 'w' OR
        // if 'w' is a subsequence of 'm'.
        if (isSubsequence(m, w) || isSubsequence(w, m)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
```