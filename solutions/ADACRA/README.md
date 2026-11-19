# [Ada and crayons (ADACRA)](https://www.codechef.com/problems/ADACRA)
- **Difficulty Rating**: 1099
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of operations required to make all crayons in a row the same color. We are given a string representing the initial colors of the crayons, where 'U' denotes an "Up" crayon and 'D' denotes a "Down" crayon. An operation consists of choosing any contiguous segment of crayons that are all of the same color and flipping their color. For example, if we have `UUUDDDUU`, we could choose the `DDD` segment and flip it to `UUU`, resulting in `UUUUUUUU`.

## Intuition & Mathematical Observation

The core idea revolves around the "contiguous segment" operation. When we flip a contiguous segment of crayons of the same color, say `DDD` to `UUU`, it takes exactly one operation. This operation effectively "resolves" that entire block of `D`s.

Consider the two possible target states:
1.  **Make all crayons 'U'**: To achieve this, we only need to worry about the segments of 'D' crayons. Each contiguous block of 'D's must be flipped to 'U'. For example, in `UUUDDDUUDD`, the first `DDD` block needs one flip, and the final `DD` block needs another flip. Flipping one `D` block does not affect other `D` blocks or `U` blocks in a way that changes the *number* of distinct `D` blocks that need to be flipped. Therefore, the minimum number of operations to make all crayons 'U' is simply the count of contiguous blocks of 'D's in the initial string.

2.  **Make all crayons 'D'**: Similarly, to achieve this, we only need to worry about the segments of 'U' crayons. Each contiguous block of 'U's must be flipped to 'D'. The minimum number of operations to make all crayons 'D' is the count of contiguous blocks of 'U's in the initial string.

Since we want the *overall minimum* number of operations, we should calculate the operations needed for both scenarios (making all 'U' and making all 'D') and then choose the smaller of the two counts.

**Algorithm:**
1.  Initialize two counters: `num_D_blocks` to count contiguous segments of 'D's, and `num_U_blocks` to count contiguous segments of 'U's.
2.  Iterate through the string from left to right.
3.  The first character always starts a block. So, initialize `num_D_blocks` or `num_U_blocks` to 1 based on `s[0]`.
4.  For subsequent characters (`i` from 1 to `N-1`), if `s[i]` is different from `s[i-1]`, it means a new contiguous block has started. Increment the corresponding counter (`num_D_blocks` if `s[i]` is 'D', `num_U_blocks` if `s[i]` is 'U').
5.  After iterating through the entire string, the answer is `min(num_D_blocks, num_U_blocks)`.

**Example:** `UUUDDDUU`
- `s[0] = 'U'`: `num_U_blocks = 1`.
- `s[1] = 'U'`, `s[1] == s[0]`: No new block.
- `s[2] = 'U'`, `s[2] == s[1]`: No new block.
- `s[3] = 'D'`, `s[3] != s[2]`: New block of 'D's. `num_D_blocks = 1`.
- `s[4] = 'D'`, `s[4] == s[3]`: No new block.
- `s[5] = 'D'`, `s[5] == s[4]`: No new block.
- `s[6] = 'U'`, `s[6] != s[5]`: New block of 'U's. `num_U_blocks = 2`.
- `s[7] = 'U'`, `s[7] == s[6]`: No new block.

Final counts: `num_D_blocks = 1`, `num_U_blocks = 2`.
Result: `min(1, 2) = 1`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading the input string of length $N$ takes $O(N)$ time.
    -   The loop iterates through the string once, from the second character to the end ($N-1$ iterations). Inside the loop, operations are constant time. This takes $O(N)$ time.
    -   Overall, for each test case, the time complexity is dominated by string processing, resulting in $O(N)$.
    -   For $T$ test cases, the total time complexity would be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible string length.

-   **Space Complexity**: $O(N)$
    -   Storing the input string `s` requires $O(N)$ space.
    -   A few integer variables (`n`, `num_D_blocks`, `num_U_blocks`, `i`) use $O(1)$ auxiliary space.
    -   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.
using namespace std; // As requested by critical instructions

void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    
    // num_D_blocks counts contiguous segments of 'D's.
    // To make all crayons 'U', we need to flip each 'D' segment once.
    // So, num_D_blocks is the minimum flips needed to make all 'U'.
    int num_D_blocks = 0; 

    // num_U_blocks counts contiguous segments of 'U's.
    // To make all crayons 'D', we need to flip each 'U' segment once.
    // So, num_U_blocks is the minimum flips needed to make all 'D'.
    int num_U_blocks = 0; 
    
    // N >= 1 due to constraints.
    // Initialize counts based on the first character.
    // The first character always starts a block.
    if (s[0] == 'D') {
        num_D_blocks = 1;
    } else { // s[0] == 'U'
        num_U_blocks = 1;
    }
    
    // Iterate from the second character to count subsequent blocks.
    // A new block starts whenever the current character is different from the previous one.
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) { // A change in character means a new block starts
            if (s[i] == 'D') {
                num_D_blocks++;
            } else { // s[i] == 'U'
                num_U_blocks++;
            }
        }
    }
    
    // The minimum flips is the smaller of the two counts.
    cout << min(num_D_blocks, num_U_blocks) << "\n";
}

int main() {
    // Fast I/O setup as requested.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read the number of test cases.
    while (t--) { // Loop through each test case.
        solve();
    }
    
    return 0;
}
```