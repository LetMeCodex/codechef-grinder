Here's a clean, high-quality solution writeup for the CodeChef problem "Another Good String (ADVITIYA4)" in GitHub-Flavored Markdown.

---

# [Another Good String (ADVITIYA4)](https://www.codechef.com/problems/ADVITIYA4)
- **Difficulty Rating**: 1314
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum length of a "beautiful substring" in a string. A beautiful substring is defined as a substring where all characters are identical (e.g., "aaa", "bb").

Initially, we are given a string `S` of length `N`. We need to calculate `A_0`, which is the maximum length of a beautiful substring in `S`.

Following this, `Q` queries are processed. In each query, a new character `c_new` is appended to the *end* of the current string. After appending, we must calculate `A_k`, the maximum length of a beautiful substring in the *new* (extended) string.

Finally, we need to print `A_0, A_1, ..., A_Q` separated by spaces.

**Constraints:**
- `T` test cases (1 to 1000)
- `N` (initial string length): 1 to $10^5$
- `Q` (number of queries): 1 to $10^5$
- Sum of `N` over all test cases $\le 2 \cdot 10^5$
- Sum of `Q` over all test cases $\le 2 \cdot 10^5$
- Characters are lowercase English letters.

## Intuition & Mathematical Observation

The core of this problem lies in efficiently updating the maximum beautiful substring length when a character is appended. A naive approach of re-scanning the entire string after each append operation would be too slow, leading to $O(Q \cdot (N+Q))$ time complexity, which is unacceptable given $N, Q \le 10^5$.

We need an $O(1)$ update mechanism per query. Let's observe how the maximum length changes:

1.  **Maximum length can only increase or stay the same:** When a character is appended, the existing string `S` is a prefix of the new string `S'`. Therefore, all beautiful substrings that existed in `S` still exist in `S'`. This means the overall maximum length can never decrease.

2.  **Only the suffix matters for new maximums:** A new maximum length beautiful substring can only be formed if the appended character `c_new` extends an existing beautiful suffix, or starts a new one that becomes the longest. Any beautiful substring that doesn't involve `c_new` would have already been accounted for in the previous `overall_max_len`.

This leads to the following strategy:
We need to maintain two key pieces of information:
*   `overall_max_len`: The maximum length of a beautiful substring found anywhere in the string *so far*.
*   `current_suffix_len`: The length of the beautiful substring that ends at the *very end* of the current string.
*   `last_char`: The character that forms the `current_suffix_len`.

**Initial Calculation (for string `S`):**
1.  Initialize `overall_max_len = 0`, `current_suffix_len = 0`, `last_char = '\0'` (or handle the first character specially).
2.  Iterate through the initial string `S` from left to right:
    *   If the current character `S[i]` is the same as `last_char`, increment `current_suffix_len`.
    *   Otherwise (if `S[i]` is different or it's the first character), update `last_char = S[i]` and reset `current_suffix_len = 1`.
    *   In either case, update `overall_max_len = max(overall_max_len, current_suffix_len)`.
3.  After iterating through `S`, `overall_max_len` will hold `A_0`.

**Processing Queries (for each `c_new`):**
1.  Compare the appended character `c_new` with `last_char` (which is the last character of the string *before* appending `c_new`).
2.  If `c_new == last_char`: Increment `current_suffix_len`.
3.  Else (`c_new` is different): Update `last_char = c_new` and reset `current_suffix_len = 1`.
4.  Update `overall_max_len = max(overall_max_len, current_suffix_len)`.
5.  This new `overall_max_len` is `A_k`.

By following this logic, each character (from the initial string or from a query) is processed in $O(1)$ time.

**Example Walkthrough:**
Let `S = "aaabbc"`, `Q = 2`.
Initial state: `overall_max_len = 0`, `current_suffix_len = 0`, `last_char = '\0'`.

**Initial Scan of `S`:**
- `S[0] = 'a'`: `last_char = 'a'`, `current_suffix_len = 1`, `overall_max_len = 1`.
- `S[1] = 'a'`: `current_suffix_len = 2`, `overall_max_len = 2`.
- `S[2] = 'a'`: `current_suffix_len = 3`, `overall_max_len = 3`.
- `S[3] = 'b'`: `last_char = 'b'`, `current_suffix_len = 1`, `overall_max_len = 3`.
- `S[4] = 'b'`: `current_suffix_len = 2`, `overall_max_len = 3`.
- `S[5] = 'c'`: `last_char = 'c'`, `current_suffix_len = 1`, `overall_max_len = 3`.
`A_0 = 3`. Current string: "aaabbc". `last_char = 'c'`, `current_suffix_len = 1`.

**Query 1: Append 'c'**
- `c_new = 'c'`. `c_new == last_char` ('c' == 'c').
- `current_suffix_len++` becomes `2`.
- `overall_max_len = max(3, 2) = 3`.
`A_1 = 3`. Current string: "aaabbcc". `last_char = 'c'`, `current_suffix_len = 2`.

**Query 2: Append 'd'**
- `c_new = 'd'`. `c_new != last_char` ('d' != 'c').
- `last_char = 'd'`, `current_suffix_len = 1`.
- `overall_max_len = max(3, 1) = 3`.
`A_2 = 3`. Current string: "aaabbccd". `last_char = 'd'`, `current_suffix_len = 1`.

Results: `3 3 3`.

## Complexity Analysis

*   **Time Complexity**:
    *   **Initial scan**: We iterate through the initial string `S` once. This takes $O(N)$ time.
    *   **Queries**: For each of the `Q` queries, we perform a constant number of operations (character comparison, increment, `max` function). This takes $O(1)$ time per query, totaling $O(Q)$ for all queries.
    *   **Printing results**: We store `Q+1` results and print them, which takes $O(Q)$ time.
    *   **Total Time Complexity per test case**: $O(N + Q)$.
    *   Given the constraints that the sum of `N` and `Q` over all test cases is $\le 2 \cdot 10^5$, the overall time complexity will be $O(\sum N + \sum Q)$, which is efficient enough to pass within the time limits.

*   **Space Complexity**:
    *   We store the input string `S`, which takes $O(N)$ space.
    *   We use a few integer variables (`overall_max_len`, `current_suffix_len`) and a character variable (`last_char`), which take $O(1)$ space.
    *   We store the results in a `std::vector<int> results`, which will hold `Q+1` integers. This takes $O(Q)$ space.
    *   **Total Space Complexity per test case**: $O(N + Q)$.
    *   Given the constraints, this space usage is well within limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, vector, algorithm etc.

// The problem statement explicitly asks for 'using namespace std;'
using namespace std; 

void solve() {
    int N, Q;
    cin >> N >> Q; // Use cin directly due to 'using namespace std;'
    string S;
    cin >> S;

    // Variables to keep track of the state
    int overall_max_len = 0;
    char last_char = '\0'; // Initialize with a character that won't match any input ('a'-'z')
    int current_suffix_len = 0;

    // Calculate initial state for S
    // N >= 1 according to constraints, so S is never empty.
    // Initialize with the first character of S
    last_char = S[0];
    current_suffix_len = 1;
    overall_max_len = 1; // Minimum length of a beautiful substring is 1 if N > 0

    // Iterate from the second character to calculate initial overall_max_len
    // and the state of the suffix
    for (int i = 1; i < N; ++i) {
        if (S[i] == last_char) {
            current_suffix_len++;
        } else {
            last_char = S[i];
            current_suffix_len = 1;
        }
        overall_max_len = max(overall_max_len, current_suffix_len); // Use max directly
    }

    vector<int> results;
    results.push_back(overall_max_len); // Store A_0

    // Process queries
    for (int k = 0; k < Q; ++k) {
        char c_new;
        cin >> c_new; // Read the character to append

        if (c_new == last_char) {
            current_suffix_len++; // Extend the current beautiful suffix
        } else {
            last_char = c_new; // Start a new beautiful suffix
            current_suffix_len = 1;
        }
        overall_max_len = max(overall_max_len, current_suffix_len); // Update overall max
        results.push_back(overall_max_len); // Store A_k
    }

    // Print results
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    cout << "\n"; // Use "\n" instead of endl for performance
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```