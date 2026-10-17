# [Strong Language (SSCRIPT)](https://www.codechef.com/problems/SSCRIPT)
- **Difficulty Rating**: 1291
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a given binary string `S`, consisting of characters `'*'` and `'#'`, contains at least `K` consecutive `'*'` characters. We are provided with the length of the string `N`, the minimum required consecutive stars `K`, and the string `S` itself. We need to output "YES" if such a sequence exists, and "NO" otherwise. This needs to be done for `T` test cases.

## Intuition & Mathematical Observation

The core idea is to iterate through the string and keep track of the longest sequence of consecutive `'*'` characters encountered.

1.  **Initialize Counters**: We need two counters:
    *   `current_consecutive_stars`: To count the stars in the current sequence we are examining.
    *   `max_consecutive_stars`: To store the maximum length of a consecutive star sequence found so far across the entire string. Both should be initialized to 0.

2.  **Iterate Through String**: We traverse the string `S` from left to right, character by character.
    *   **If `S[i]` is `'*'`**: This means the current sequence of stars continues or starts. We increment `current_consecutive_stars`.
    *   **If `S[i]` is `'#'`**: This character breaks any ongoing sequence of stars.
        *   At this point, `current_consecutive_stars` holds the length of the sequence of stars that just ended. We compare this length with `max_consecutive_stars` and update `max_consecutive_stars` if `current_consecutive_stars` is greater.
        *   After updating, we reset `current_consecutive_stars` to 0, as a new sequence (if any) will start after this `'#'`.

3.  **Handle Trailing Stars**: After the loop finishes, it's possible that the string ends with a sequence of `'*'` characters. In this case, `current_consecutive_stars` would hold the length of this final sequence, but it wouldn't have been compared and potentially updated `max_consecutive_stars` because no `'#'` character followed it to trigger the update logic. Therefore, we need one final comparison: `max_consecutive_stars = max(max_consecutive_stars, current_consecutive_stars);`

4.  **Final Check**: Once we have the `max_consecutive_stars` for the entire string, we simply check if `max_consecutive_stars >= K`. If true, we print "YES"; otherwise, we print "NO".

This approach ensures that we correctly identify the longest sequence of consecutive stars regardless of its position in the string.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    The solution involves a single pass through the input string `S`, which has a length of `N`. Inside the loop, all operations (character comparison, increment, `max` function) take constant time, $O(1)$. Therefore, the time complexity for processing one test case is directly proportional to the length of the string. For `T` test cases, the total time complexity would be $O(T \cdot N)$.

*   **Space Complexity**: $O(N)$ for storing the input string, or $O(1)$ auxiliary space.
    The algorithm uses a few integer variables (`N`, `K`, `current_consecutive_stars`, `max_consecutive_stars`, `T`, loop counter `i`) which require a constant amount of memory, $O(1)$. The input string `S` itself occupies $O(N)$ space. If we consider the space for storing the input string as part of the algorithm's space usage, then the space complexity is $O(N)$. If we consider only the auxiliary space (space used *in addition* to input storage), then it's $O(1)$. In competitive programming, $O(N)$ is typically stated for string problems to account for the string storage.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

// Using namespace std; as requested by problem statement
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K; // Read N and K
    string S;
    cin >> S; // Read the string S

    int current_consecutive_stars = 0; // Counter for the current sequence of '*'
    int max_consecutive_stars = 0;     // Stores the maximum length found so far

    // Iterate through the string
    for (int i = 0; i < N; ++i) {
        if (S[i] == '*') {
            // If the character is a star, increment the current counter
            current_consecutive_stars++;
        } else {
            // If it's not a star, the current sequence of stars is broken.
            // Update max_consecutive_stars with the length of the just-ended sequence.
            max_consecutive_stars = max(max_consecutive_stars, current_consecutive_stars);
            // Reset the current counter for the next potential sequence.
            current_consecutive_stars = 0;
        }
    }
    // After the loop, there might be a sequence of stars at the very end of the string.
    // We need one final update to ensure this last sequence is considered.
    max_consecutive_stars = max(max_consecutive_stars, current_consecutive_stars);

    // Check if the maximum consecutive stars found is at least K
    if (max_consecutive_stars >= K) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O as requested by problem statement
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