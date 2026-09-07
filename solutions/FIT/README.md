# [Fitness (FIT)](https://www.codechef.com/problems/FIT)
- **Difficulty Rating**: 258
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total distance a chef travels in a week for work. The chef walks $X$ km to the office and $X$ km back home each day. The office is open 5 days a week.

## Intuition & Mathematical Observation
The core of the problem is to break down the total weekly distance into smaller, manageable parts.

1.  **Daily Travel Distance**: The chef travels $X$ km to the office and $X$ km back home. Therefore, the total distance traveled in a single day is $X + X = 2 \times X$ km.

2.  **Weekly Travel Distance**: The office is open for 5 days a week. So, to find the total distance traveled in a week, we multiply the daily travel distance by the number of working days:
    Total Weekly Distance = (Daily Travel Distance) $\times$ (Number of Working Days)
    Total Weekly Distance = $(2 \times X) \times 5$

    This simplifies to $10 \times X$ km.

The problem statement also mentions that the input $X$ can be up to $10^5$. When we calculate $2 \times X \times 5$, the maximum value can be $10 \times 10^5 = 10^6$. This value fits within a standard 32-bit integer type. However, to be safe and to handle potential intermediate calculations or slightly larger constraints in similar problems, using a `long long` for the total distance is a good practice.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (multiplication and addition) for each test case, regardless of the input value of $X$. The loop runs $T$ times, where $T$ is the number of test cases. Thus, for each test case, the time complexity is constant.

- **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `t`, `x`, and `total_distance`. This amount of space does not depend on the input size.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int x; // Distance to the office in km
        cin >> x;

        // Chef walks X km to the office and X km back home.
        // So, daily travel is 2 * X km.
        // The office is open 5 days a week.
        // Total weekly travel = (2 * X) * 5
        // Using long long for total_distance to ensure no overflow,
        // although for the given constraints, int would suffice.
        long long total_distance = (long long)2 * x * 5;

        cout << total_distance << "\n";
    }
    return 0;
}
```