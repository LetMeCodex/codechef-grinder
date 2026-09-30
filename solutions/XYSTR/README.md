# [Chef and String (XYSTR)](https://www.codechef.com/problems/XYSTR)
- **Difficulty Rating**: 1124
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of pairs that can be formed from a line of students. Each student is represented by a character: 'x' for a boy and 'y' for a girl. A valid pair must consist of one boy and one girl. An important constraint is that once a student is part of a pair, they cannot be part of any other pair. Our goal is to maximize the total number of such pairs.

## Intuition & Mathematical Observation

This problem can be solved using a greedy approach. The key observation, implicitly suggested by the problem's difficulty rating and common competitive programming patterns (though not explicitly stated in the problem description), is that we should form pairs using *adjacent* students whenever possible. If the problem allowed non-adjacent pairs, the solution would be a simple `min(count('x'), count('y'))`, which would be too trivial for a difficulty rating of 1124.

Let's proceed with the assumption that we are looking for adjacent pairs:

1.  **Greedy Strategy**: We iterate through the line of students from left to right. When we encounter a student at index `i`, we check if they can form a valid boy-girl pair with the student immediately next to them, at index `i+1`.

2.  **Why this is optimal**:
    *   If `s[i]` and `s[i+1]` can form a pair (i.e., one is 'x' and the other is 'y'), forming this pair is always beneficial. It adds one to our total pair count.
    *   By forming the pair `(s[i], s[i+1])`, we consume both students. We then advance our pointer to `i+2` to look for the next potential pair. This choice doesn't prevent any future pairs from being formed, as `s[i]` and `s[i+1]` would have to be consumed anyway if they were to form a pair. By taking the earliest possible adjacent pair, we maximize the remaining available students for subsequent adjacent pairs.
    *   If `s[i]` and `s[i+1]` cannot form a pair (e.g., `xx` or `yy`), then `s[i]` cannot form an adjacent pair starting at `i` with `s[i+1]`. In this case, `s[i]` is left unpaired (at least with `s[i+1]`), and we advance our pointer to `i+1` to consider `s[i+1]` as the start of a new potential pair.

This greedy strategy ensures that we maximize the number of pairs by always taking an available adjacent pair.

### Algorithm Steps:

1.  Initialize a counter `pairs = 0`.
2.  Initialize an index `i = 0` to traverse the string.
3.  Loop while `i` is less than `n - 1` (where `n` is the string length), to ensure `s[i+1]` is a valid index.
4.  Inside the loop:
    *   Check if `s[i]` and `s[i+1]` are of different genders (i.e., `s[i] != s[i+1]`). This means one is 'x' and the other is 'y'.
    *   If they are of different genders:
        *   Increment `pairs`.
        *   Advance `i` by 2 (since both `s[i]` and `s[i+1]` are now part of a pair and cannot be used again).
    *   If they are of the same gender:
        *   Advance `i` by 1 (since `s[i]` cannot form a pair with `s[i+1]`, we move on to consider `s[i+1]` as the start of a new potential pair).
5.  After the loop finishes, `pairs` will hold the maximum number of adjacent boy-girl pairs. Print `pairs`.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    *   The solution iterates through the input string `s` using a `while` loop. In each iteration, the index `i` is incremented by either 1 or 2. This means the loop will run at most `N` times, where `N` is the length of the string.
    *   All operations inside the loop (character comparison, incrementing counters) are constant time operations, $O(1)$.
    *   Therefore, for a single test case, the time complexity is linear with respect to the string length, $O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$. With $T \le 100$ and $N \le 10^5$, the total operations are approximately $100 \cdot 10^5 = 10^7$, which is well within typical time limits (usually $10^8$ operations per second).

-   **Space Complexity**: $O(N)$
    *   The primary space usage comes from storing the input string `s`, which requires $O(N)$ space.
    *   A few integer variables (`n`, `pairs`, `i`, `t`) are used, which consume a constant amount of space, $O(1)$.
    *   Thus, the overall space complexity is dominated by the input string, resulting in $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, string, etc.

using namespace std; // Use standard namespace

void solve() {
    string s;
    cin >> s; // Read the input string
    int n = s.length(); // Get the length of the string
    int pairs = 0; // Initialize the count of pairs
    int i = 0; // Initialize the pointer for iterating through students

    // Iterate while there are at least two students remaining to potentially form a pair
    while (i < n - 1) {
        // Check if students at index i and i+1 can form a boy-girl pair
        // This means one is 'x' and the other is 'y' (i.e., they are not the same gender)
        if (s[i] != s[i+1]) { // Equivalent to ((s[i] == 'x' && s[i+1] == 'y') || (s[i] == 'y' && s[i+1] == 'x'))
            pairs++; // Increment the pair count
            i += 2; // If a pair is formed, both students i and i+1 are used.
                    // So, skip both and move to student i+2 for the next potential pair.
        } else {
            // If no valid pair can be formed with students i and i+1 (either same gender),
            // student i cannot be part of an adjacent pair starting at i.
            // Move to student i+1 to see if they can start a new pair.
            i += 1;
        }
    }
    cout << pairs << "\n"; // Print the maximum number of pairs
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```