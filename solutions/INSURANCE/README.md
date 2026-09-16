# [Insurance (INSURANCE)](https://www.codechef.com/problems/INSURANCE)
- **Difficulty Rating**: 475
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes an insurance policy where a maximum amount `X` can be rebated for damage. If the actual damage cost `Y` is less than or equal to `X`, the full damage cost `Y` is rebated. However, if the actual damage cost `Y` exceeds the maximum rebatable amount `X`, only `X` is rebated. We need to determine the amount the insurance company will rebate for given `X` and `Y`.

## Intuition & Mathematical Observation

The problem statement presents a clear conditional logic:
1. If `Y <= X`, the rebate is `Y`.
2. If `Y > X`, the rebate is `X`.

This is a classic scenario where we need to choose the smaller of two values.
- If `Y` is the smaller value (or equal to `X`), then `Y` is the rebate.
- If `X` is the smaller value, then `X` is the rebate.

This logic can be directly implemented using the `min()` function, which returns the smaller of its two arguments. Therefore, the amount rebated will always be `min(X, Y)`.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    For each test case, the solution involves reading two integers, performing a single `min` operation, and printing one integer. These are all constant-time operations, independent of the magnitude of `X` or `Y`. If there are `T` test cases, the total time complexity would be $O(T)$.

-   **Space Complexity**: $O(1)$.
    The solution only uses a few integer variables (`X`, `Y`, `t`) to store input and intermediate results. The amount of memory used does not grow with the input values, making it constant space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include for competitive programming

// Required namespace
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y;
    // Read the maximum rebatable amount X and the actual damage cost Y
    cin >> X >> Y;

    // According to the policy:
    // - If the amount required for repairing the damage (Y) is <= X lakhs,
    //   that amount (Y) is rebated in full.
    // - If the amount required for repairing the damage (Y) is > X lakhs,
    //   only the maximum rebatable amount (X) is rebated.
    // This logic can be concisely expressed as the minimum of X and Y.
    cout << min(X, Y) << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // cout before cin, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // Read the number of test cases
    cin >> t;
    // Loop through each test case
    while (t--) {
        solve();
    }

    return 0;
}
```