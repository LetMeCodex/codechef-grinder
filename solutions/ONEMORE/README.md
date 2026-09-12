# Just One More Episode (ONEMORE)
- **Difficulty Rating**: 320
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to watch one more episode of a TV series before an exam. Each episode is 24 minutes long. Chef will finish watching strictly before the exam starts if the total available time `X` is strictly greater than the duration of one episode. We need to determine if Chef can watch one more episode and finish strictly before the exam.

## Intuition & Mathematical Observation
The problem states that an episode is exactly 24 minutes long. Chef needs to finish watching *strictly before* the exam. This means that the total time available for watching the episode, `X`, must be greater than the duration of the episode.

If `X` is exactly 24 minutes, Chef will finish watching the episode precisely when the exam starts, not strictly before.
If `X` is less than 24 minutes, Chef cannot even complete watching one episode.

Therefore, the condition for Chef to be able to watch one more episode and finish strictly before the exam is simply:
`X > 24`

If this condition is met, the answer is "Yes". Otherwise, the answer is "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$
  The solution involves a single comparison for each test case. The number of operations does not depend on the input value `x` (beyond the comparison itself).
- **Space Complexity**: $O(1)$
  The solution uses a constant amount of extra space to store variables like `t` and `x`.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        // An episode is 24 minutes long.
        // Chef finishes strictly before the exam starts if the available time X
        // is strictly greater than the episode duration (24 minutes).
        if (x > 24) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
```