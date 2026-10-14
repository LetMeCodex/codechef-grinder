# [Alternating String (ALTSTR)](https://www.codechef.com/problems/ALTSTR)
- **Difficulty Rating**: 1116
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible length of an "alternating string" that can be formed using characters from a given binary string `S`. The input string `S` consists only of '0's and '1's. An alternating string is defined as one where no two adjacent characters are the same (e.g., "01010", "101", "0", "1"). We need to output this maximum length.

## Intuition & Mathematical Observation

To form an alternating string, we essentially need to arrange '0's and '1's such that they never appear consecutively. This means the pattern must be `0101...` or `1010...`.

Let's count the total number of '0's (`count0`) and '1's (`count1`) available in the given string `S`.

1.  **Pairing up '0's and '1's**:
    The most efficient way to build an alternating string is to pair up '0's and '1's. Each pair (e.g., `01` or `10`) contributes 2 to the length of the alternating string.
    The number of such pairs we can form is limited by the character type that appears fewer times. For example, if we have three '0's and two '1's, we can form at most two `01` or `10` pairs.
    Thus, we can form `min(count0, count1)` pairs. These pairs can be arranged to form an alternating string of length `2 * min(count0, count1)`.
    *   Example: `S = "00011"`. `count0 = 3`, `count1 = 2`. `min(3, 2) = 2`. We can form `0101` (length 4). We used two '0's and two '1's.

2.  **Handling leftover characters**:
    After forming `2 * min(count0, count1)` length string, we might have some characters left over if `count0` is not equal to `count1`.
    *   If `count0 == count1`, all characters have been used up in pairs, and the length is `2 * count0` (or `2 * count1`). No characters are left.
    *   If `count0 != count1`, it means one type of character is in the majority. For example, if `count0 = 3`, `count1 = 2`, after forming `0101`, we have one '0' left.
    *   Can we use this leftover character? Yes, we can append *exactly one* of the leftover majority characters to the alternating string. For instance, `0101` can become `01010` by appending the extra '0'. This new string is still alternating, and its length increases by 1.
    *   We cannot append more than one such character without breaking the alternating property (e.g., `010100` is not alternating).
    *   Therefore, if `count0 != count1`, we can add `1` to our total length.

**Combining these observations:**
The maximum length of the alternating string will be `2 * min(count0, count1)`.
If `count0` is not equal to `count1`, we add `1` to this length.
So, the final formula is: `2 * min(count0, count1) + (count0 != count1 ? 1 : 0)`.

Let's verify with edge cases:
*   `S = "0"`: `count0 = 1`, `count1 = 0`. `min(1, 0) = 0`. `2 * 0 = 0`. `count0 != count1` is true, so add 1. Result: `0 + 1 = 1`. Correct ("0").
*   `S = "111"`: `count0 = 0`, `count1 = 3`. `min(0, 3) = 0`. `2 * 0 = 0`. `count0 != count1` is true, so add 1. Result: `0 + 1 = 1`. Correct ("1").

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   The code iterates through the input string `S` once to count the occurrences of '0's and '1's. This takes $O(N)$ time, where $N$ is the length of the string `S`.
    *   All subsequent operations (like `min`, comparisons, additions) are constant time operations, $O(1)$.
    *   Since this process is repeated for `T` test cases, the total time complexity would be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible length of string `S`.

*   **Space Complexity**: $O(N)$
    *   The primary space usage comes from storing the input string `S`, which requires $O(N)$ space.
    *   A few integer variables (`n`, `count0`, `count1`, `result`) are used, which consume $O(1)$ auxiliary space.
    *   Therefore, the overall space complexity is dominated by the input string storage, making it $O(N)$. If we consider only auxiliary space (excluding input storage), it would be $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm etc.

// Using namespace std; as per problem instructions
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count0 = 0;
    int count1 = 0;

    // Count the occurrences of '0' and '1' in the string S
    for (char c : s) {
        if (c == '0') {
            count0++;
        } else { // c must be '1'
            count1++;
        }
    }

    // The maximum length of an alternating string can be formed by
    // pairing up as many '0's and '1's as possible.
    // Each pair (01 or 10) contributes 2 to the length.
    // The number of such pairs is min(count0, count1).
    // So, an initial alternating string of length 2 * min(count0, count1) can be formed.
    int result = 2 * min(count0, count1);

    // If the counts of '0's and '1's are not equal, it means there are
    // some characters of the majority type left over. We can append exactly
    // one of these leftover characters to the alternating string to extend
    // its length by 1, while still maintaining the alternating property.
    // For example, if we have "0101" and a '0' left, we can make "01010".
    // We cannot append more than one character without breaking the alternating property.
    if (count0 != count1) {
        result += 1;
    }
    
    cout << result << "\n";
}

int main() {
    // Fast I/O as per problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
```