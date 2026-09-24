# [Lazy Chef (LAZYCHF)](https://www.codechef.com/problems/LAZYCHF)
- **Difficulty Rating**: 801
- **Solved in**: 1 attempt(s)

## Problem Summary

The Lazy Chef has a recipe that takes $x$ minutes to prepare. However, he is lazy and takes $m$ times longer to prepare it, so his preparation time would be $x \times m$ minutes. There's a constraint: he can take at most $d$ extra minutes beyond the original preparation time $x$. We need to find the actual time the Chef will take to prepare the dish.

## Intuition & Mathematical Observation

The problem states two conditions for the Chef's preparation time:

1.  **Laziness Factor**: The Chef takes $x \times m$ minutes due to his laziness.
2.  **Delay Limit**: The Chef can take at most $d$ extra minutes. This means the total time cannot exceed $x + d$ minutes.

The actual time taken by the Chef will be the minimum of these two possibilities. If his lazy preparation time ($x \times m$) is less than or equal to the maximum allowed time ($x + d$), he will take $x \times m$ minutes. Otherwise, he will be limited by the delay constraint and will take $x + d$ minutes.

Therefore, the actual time taken is $\min(x \times m, x + d)$.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (multiplication, addition, and comparison) for each test case. The number of test cases is read once, and then a loop runs for that many iterations. Inside the loop, the operations are constant time. Thus, the overall time complexity is constant per test case.

-   **Space Complexity**: $O(1)$
    The solution uses a few integer variables to store the input values and the result. The amount of memory used does not depend on the input size, making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace for convenience

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases

    while (T--) { // Loop T times, decrementing T in each iteration
        int x, m, d;
        cin >> x >> m >> d; // Read the three integers for the current testcase

        // Calculate the time Chef would take due to his laziness.
        // This is the original time multiplied by his laziness factor.
        int lazy_time = x * m;

        // Calculate the maximum time allowed due to the delay limit.
        // This is the original time plus the maximum allowed delay.
        int max_allowed_time = x + d;

        // The actual time taken is the minimum of these two values.
        // Chef will take his lazy_time, but not more than max_allowed_time.
        int result = min(lazy_time, max_allowed_time);

        cout << result << "\n"; // Print the result followed by a newline character
    }

    return 0; // Indicate successful execution
}
```