# [Waiting Time (WAITTIME)](https://www.codechef.com/problems/WAITTIME)

- **Difficulty Rating**: 319
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has been waiting for a special event for $K$ weeks. However, he has already spent $X$ days waiting for it. We need to calculate how many more days Chef needs to wait to complete the $K$ weeks.

## Intuition & Mathematical Observation
1. The problem defines the total waiting period in weeks ($K$), while the elapsed time is given in days ($X$).
2. Since there are 7 days in a week, the total waiting time in days is calculated as $K \times 7$.
3. To find the remaining days, we subtract the days already spent ($X$) from the total days ($K \times 7$).
4. The formula is: `Remaining Days = (K * 7) - X`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int k, x;
        cin >> k >> x;
        
        // Total days to wait is k weeks, which is k * 7 days.
        // Chef has already waited x days.
        // Remaining days = Total days - Days already waited.
        int total_days = k * 7;
        int remaining_days = total_days - x;
        
        cout << remaining_days << "\n";
    }
    return 0;
}
```