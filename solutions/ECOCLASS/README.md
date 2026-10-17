# [Economics Class (ECOCLASS)](https://www.codechef.com/problems/ECOCLASS)
- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the number of "equilibrium" time points for a given product. We are provided with `N` time points. For each time point `i`, we are given two values: the supply of the product (`S[i]`) and the demand for the product (`D[i]`). An equilibrium point is defined as a time point where the supply equals the demand (`S[i] == D[i]`). Our task is to count how many such equilibrium points exist among the `N` given time points. This process needs to be repeated for multiple test cases.

## Intuition & Mathematical Observation

The problem statement directly defines what constitutes an "equilibrium" state: it's when supply is exactly equal to demand. There's no complex economic model or advanced mathematical concept required. The core idea is a straightforward comparison.

For each time point `i` from `0` to `N-1`:
1. We read the supply value `S[i]`.
2. We read the demand value `D[i]`.
3. We check if `S[i]` is equal to `D[i]`.
4. If they are equal, we increment a counter.

After checking all `N` time points, the final value of the counter will be the total number of equilibrium points. This is a simple counting problem that can be solved by iterating through the given data once.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading `N` takes $O(1)$.
    -   Reading `N` supply values takes $O(N)$.
    -   Reading `N` demand values takes $O(N)$.
    -   Iterating through `N` time points to compare supply and demand and increment a counter takes $O(N)$ operations (each comparison and potential increment is $O(1)$).
    -   Therefore, for a single test case, the total time complexity is $O(1) + O(N) + O(N) + O(N) = O(N)$.
    -   Since there are `T` test cases, the overall time complexity will be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible value of `N` across all test cases.

-   **Space Complexity**: $O(N)$
    -   We use two vectors, `S` and `D`, each of size `N`, to store the supply and demand values. This requires $O(N)$ space for each vector, totaling $O(N)$ space.
    -   Other variables like `N`, `equilibrium_count`, and loop counters take $O(1)$ space.
    -   Thus, the dominant space usage is for storing the input arrays, resulting in $O(N)$ space complexity.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector, etc.

// Use the standard namespace to avoid prefixing standard library elements with std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of time points for this test case

    // Declare two vectors to store supply and demand data.
    // Vectors are dynamic arrays, suitable when size N is known at runtime.
    vector<int> S(N); // Supply array
    vector<int> D(N); // Demand array

    // Read the supply values into the S vector
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // Read the demand values into the D vector
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    int equilibrium_count = 0; // Initialize a counter for time points in equilibrium

    // Iterate through each time point from 0 to N-1
    for (int i = 0; i < N; ++i) {
        // Check if supply equals demand at the current time point
        if (S[i] == D[i]) {
            equilibrium_count++; // If they are equal, increment the counter
        }
    }

    // Output the total number of equilibrium points for the current test case
    cout << equilibrium_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```