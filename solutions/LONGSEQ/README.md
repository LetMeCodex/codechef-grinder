# [Chef and digits of a number (LONGSEQ)](https://www.codechef.com/problems/LONGSEQ)
- **Difficulty Rating**: 1209
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given binary string `D` (consisting only of '0's and '1's) can be made "good" by flipping *exactly one* digit. A string is considered "good" if all its digits are the same (i.e., all '0's or all '1's). We need to output "Yes" if it's possible, and "No" otherwise.

## Intuition & Mathematical Observation

Let's analyze the conditions under which a string can become "good" by flipping exactly one digit:

A string is "good" if all its digits are identical. This means the final string must either be composed entirely of '0's (e.g., "0000") or entirely of '1's (e.g., "1111").

Consider these two target states:

1.  **Target: All digits become '0's.**
    *   To achieve this by flipping *exactly one* digit, the original string must have contained all '0's except for a single '1'. If we flip that unique '1' to a '0', all digits will become '0's.
    *   If the original string had zero '1's (i.e., all '0's), we would have to flip a '0' to a '1', resulting in a string like "0010", which is not all '0's. This doesn't work.
    *   If the original string had more than one '1' (e.g., "0110"), flipping one '1' to '0' would still leave other '1's (e.g., "0010"), so it wouldn't be all '0's. This also doesn't work.
    *   **Conclusion for this target**: The original string must contain *exactly one '1'*.

2.  **Target: All digits become '1's.**
    *   Similarly, to achieve this by flipping *exactly one* digit, the original string must have contained all '1's except for a single '0'. If we flip that unique '0' to a '1', all digits will become '1's.
    *   If the original string had zero '0's (i.e., all '1's), we would have to flip a '1' to a '0', resulting in a string like "1101", which is not all '1's. This doesn't work.
    *   If the original string had more than one '0' (e.g., "1001"), flipping one '0' to '1' would still leave other '0's (e.g., "1101"), so it wouldn't be all '1's. This also doesn't work.
    *   **Conclusion for this target**: The original string must contain *exactly one '0'*.

Combining these observations, a binary string `D` can be made "good" by flipping exactly one digit if and only if it contains *either exactly one '0' OR exactly one '1'*.

The algorithm is straightforward:
1.  Count the occurrences of '0's (`count0`) and '1's (`count1`) in the input string `D`.
2.  If `count0 == 1` or `count1 == 1`, print "Yes".
3.  Otherwise, print "No".

## Complexity Analysis

*   **Time Complexity**:
    For each test case, we iterate through the input string `D` once to count the occurrences of '0's and '1's. If `N` is the length of the string `D`, this operation takes $O(N)$ time. Reading the string also takes $O(N)$ time. The comparison and printing take $O(1)$ time.
    Since there are `T` test cases, the total time complexity will be $O(\sum N)$, where $\sum N$ is the sum of lengths of all strings across all test cases. Given typical constraints for this difficulty, $\sum N$ is usually limited (e.g., $10^6$ or $2 \cdot 10^6$), making this solution efficient enough.

*   **Space Complexity**:
    We store the input string `D`, which requires $O(N)$ space. We also use a few integer variables (`T`, `count0`, `count1`), which take $O(1)$ additional space.
    Therefore, the space complexity is $O(N)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times for each test case
        string D;
        cin >> D; // Read the binary string D

        int count0 = 0; // Counter for '0's
        int count1 = 0; // Counter for '1's

        // Iterate through each character of the string D
        for (char c : D) {
            if (c == '0') {
                count0++; // Increment count0 if the character is '0'
            } else { // The problem states D contains only '0's and '1's, so if not '0', it must be '1'
                count1++; // Increment count1 if the character is '1'
            }
        }

        // Check the condition:
        // If there is exactly one '0' (it can be flipped to '1' to make all '1's)
        // OR if there is exactly one '1' (it can be flipped to '0' to make all '0's)
        if (count0 == 1 || count1 == 1) {
            cout << "Yes\n"; // Output "Yes" if possible
        } else {
            cout << "No\n"; // Output "No" otherwise
        }
    }

    return 0; // Indicate successful execution
}
```