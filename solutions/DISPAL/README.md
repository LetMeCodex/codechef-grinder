# [Distinct Palindrome (DISPAL)](https://www.codechef.com/problems/DISPAL)
- **Difficulty Rating**: 1304
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to construct a palindrome of length `N` that uses exactly `X` distinct lowercase English letters. If it's impossible to construct such a palindrome, we should output `-1`. Otherwise, we should output any valid palindrome.

## Intuition & Mathematical Observation

1.  **Palindrome Structure**: A palindrome is a string that reads the same forwards and backwards. This implies that for any character at index `i` (0-indexed), it must be equal to the character at index `N - 1 - i`. That is, `S[i] == S[N - 1 - i]`.

2.  **Distinct Characters in a Palindrome**: The set of distinct characters used in a palindrome is entirely determined by the characters in its first half.
    *   If `N` is odd, say `N = 2k + 1`, the first half consists of characters `S[0]` through `S[k-1]` and the middle character `S[k]`. The characters `S[k+1]` through `S[2k]` are mirrors of `S[k-1]` through `S[0]`.
    *   If `N` is even, say `N = 2k`, the first half consists of characters `S[0]` through `S[k-1]`. The characters `S[k]` through `S[2k-1]` are mirrors of `S[k-1]` through `S[0]`.
    *   In both cases, the characters `S[0]` to `S[ceil(N/2) - 1]` (which can be calculated as `S[0]` to `S[(N+1)/2 - 1]` using integer division) are sufficient to determine the entire palindrome and thus all distinct characters used. Let's denote the length of this "effective first half" as `mid_len = (N + 1) / 2`.

3.  **Constraint on `X`**: To use exactly `X` distinct characters, we must be able to place these `X` distinct characters within the `mid_len` positions of the effective first half. The maximum number of distinct characters we can possibly use in `mid_len` positions is `mid_len` itself (by making all `mid_len` characters distinct). Therefore, if `X` is greater than `mid_len`, it's impossible to form such a palindrome, and we should output `-1`.

4.  **Construction Strategy (if possible)**:
    *   If `X <= mid_len`, it is always possible to construct such a palindrome.
    *   We need to use exactly `X` distinct characters. The simplest way to achieve this is to use the first `X` lowercase English letters: `'a'`, `'b'`, ..., up to `'a' + X - 1`.
    *   We can fill the first `X` positions of our string with these distinct characters: `S[0] = 'a'`, `S[1] = 'b'`, ..., `S[X-1] = 'a' + X - 1`.
    *   For the remaining positions in the effective first half (from index `X` up to `mid_len - 1`), we need to fill them without introducing any *new* distinct characters. The simplest approach is to fill all these positions with `'a'` (or any character already used). This ensures that we maintain exactly `X` distinct characters.
    *   Once the characters `S[0]` through `S[mid_len - 1]` are determined, we complete the palindrome by mirroring these characters to the second half: `S[N - 1 - i] = S[i]` for `i` from `0` to `mid_len - 1`.

This strategy guarantees that:
*   The resulting string is a palindrome.
*   It has length `N`.
*   It uses exactly `X` distinct characters (since we explicitly used `X` distinct characters for the initial part and then reused one of them for the rest of the first half).

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N` and `X`: $O(1)$.
    *   Calculating `mid_len`: $O(1)$.
    *   Checking the `X > mid_len` condition: $O(1)$.
    *   Initializing the `result` string of length `N`: $O(N)$.
    *   The first loop (filling `S[0]` to `S[X-1]`): Runs `X` times. Each operation is $O(1)$. Total $O(X)$.
    *   The second loop (filling `S[X]` to `S[mid_len-1]`): Runs `mid_len - X` times. Each operation is $O(1)$. Total $O(mid\_len - X)$.
    *   The third loop (mirroring characters): Runs `mid_len` times. Each operation is $O(1)$. Total $O(mid\_len)$.
    *   Printing the final `result` string: $O(N)$.
    *   Since `X <= mid_len <= N`, all these operations are bounded by $O(N)$.
    *   Therefore, the total time complexity per test case is $O(N)$. For `T` test cases, the total time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   Storing `N`, `X`, `mid_len`: $O(1)$.
    *   Storing the `result` string: $O(N)$ characters.
    *   Thus, the total space complexity per test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std for convenience as requested
using namespace std;

void solve() {
    int N, X;
    cin >> N >> X;

    // The number of distinct characters in a palindrome is determined by the distinct characters
    // in its first half (specifically, the first ceil(N/2) characters).
    // Let mid_len = ceil(N/2). Using integer division, this is (N+1)/2.
    // We need to use X distinct characters. The maximum number of distinct characters
    // we can use in the first mid_len positions is mid_len itself.
    // So, if X > mid_len, it's impossible to have X distinct characters.
    int mid_len = (N + 1) / 2;

    if (X > mid_len) {
        cout << -1 << "\n";
        return;
    }

    // If it's possible, construct the palindrome.
    // We will use the first X lowercase letters ('a', 'b', ..., 'a'+X-1)
    // to fill the initial part of the string.
    // For the remaining characters in the first half (if any), we can just use 'a'.
    // This ensures that exactly X distinct characters are used.
    
    string result(N, ' '); // Initialize string of length N with spaces

    // Fill the first X characters of the string with 'a', 'b', ..., 'a'+X-1
    for (int i = 0; i < X; ++i) {
        result[i] = 'a' + i;
    }

    // Fill the remaining characters in the first half (from index X up to mid_len-1) with 'a'.
    // This character 'a' is already one of the X distinct characters used.
    // This loop only runs if X < mid_len.
    for (int i = X; i < mid_len; ++i) {
        result[i] = 'a';
    }

    // Complete the palindrome by mirroring the first half to the second half.
    // For a palindrome, S[i] == S[N-1-i].
    // We only need to iterate up to mid_len - 1 because the characters from mid_len onwards
    // are determined by the characters before mid_len.
    for (int i = 0; i < mid_len; ++i) {
        result[N - 1 - i] = result[i];
    }

    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```