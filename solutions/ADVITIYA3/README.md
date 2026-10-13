# [Cookie Day (ADVITIYA3)](https://www.codechef.com/problems/ADVITIYA3)
- **Difficulty Rating**: 995
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to consider `N` cookie jars, each containing a certain number of cookies `A_i`. We also have `K` children. The goal is to select *one* jar and distribute its cookies among the `K` children such that:
1. Each child receives an equal number of cookies.
2. Each child receives at least one cookie.

We need to find the minimum number of cookies that would be "wasted" (i.e., remain in the jar after distribution) across all possible choices of jars. If no jar can satisfy the distribution conditions, we should output -1.

## Intuition & Mathematical Observation

Let's break down the conditions and how to approach the problem:

1.  **Condition for Distribution**: If `K` children each receive `X` cookies, the total number of cookies distributed from a jar would be `K * X`. The problem states that each child must receive *at least one* cookie, meaning `X >= 1`. This implies that the total cookies in the chosen jar (`A_i`) must be at least `K * 1 = K`. If a jar `A_i` contains fewer than `K` cookies (`A_i < K`), it's impossible to give even one cookie to each of the `K` children, so such a jar cannot be used.

2.  **Minimizing Wasted Cookies**: If a jar `A_i` has enough cookies (`A_i >= K`), we can distribute them. To minimize the wasted cookies, we should maximize the number of cookies given to each child. The maximum equal number of cookies `X` that each child can receive from `A_i` cookies is `A_i / K` (using integer division).
    The total cookies distributed would then be `K * (A_i / K)`.
    The number of cookies remaining (wasted) in the jar would be `A_i - (K * (A_i / K))`.
    This mathematical expression is precisely what the modulo operator (`%`) calculates: `A_i % K`.

3.  **Finding the Overall Minimum**: We need to iterate through all `N` cookie jars. For each jar `A_i`:
    *   First, check if `A_i >= K`. If not, this jar cannot be used for distribution, and we move to the next jar.
    *   If `A_i >= K`, calculate the `current_wasted = A_i % K`.
    *   We maintain a variable, say `min_wasted_cookies`, initialized to a very large value (e.g., `numeric_limits<long long>::max()`). We update `min_wasted_cookies = min(min_wasted_cookies, current_wasted)`.

4.  **Handling Impossible Cases**: It's possible that *none* of the `N` jars contain `K` or more cookies. In this scenario, no valid distribution is possible from any jar. To handle this, we use a boolean flag, `possible_distribution_found`, initialized to `false`. If we ever find a jar `A_i` such that `A_i >= K`, we set this flag to `true`. After checking all jars, if `possible_distribution_found` is still `false`, we output -1. Otherwise, we output the `min_wasted_cookies` we found.

This systematic approach ensures all conditions are met and the correct minimum (or -1) is reported.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    The solution iterates through `N` cookie jars once for each test case. Inside the loop, it performs constant-time operations (reading an integer, comparison, modulo arithmetic, and `min` function).
    Given `T` test cases, the total time complexity will be $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a fixed number of variables (`N`, `K`, `min_wasted_cookies`, `possible_distribution_found`, `A_i`, `current_wasted`) regardless of the input size `N` or `K`. No dynamic data structures or arrays whose size depends on `N` are used.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, limits, etc.

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    long long N, K; // N: number of cookie jars, K: number of children
    cin >> N >> K;
    
    // Initialize min_wasted_cookies to a very large value.
    // This ensures any valid remainder (0 to K-1) will be smaller.
    long long min_wasted_cookies = numeric_limits<long long>::max();
    
    // Flag to track if we found at least one jar from which distribution is possible.
    bool possible_distribution_found = false;
    
    // Iterate through each of the N cookie jars
    for (int i = 0; i < N; ++i) {
        long long A_i; // Number of cookies in the i-th jar
        cin >> A_i;
        
        // Condition: Each child must receive at least 1 cookie.
        // This implies that the total cookies in the jar (A_i) must be at least K.
        if (A_i >= K) {
            // If A_i >= K, it's possible to distribute cookies.
            // Each child receives A_i / K cookies (integer division).
            // The number of cookies wasted is the remainder: A_i % K.
            long long current_wasted = A_i % K;
            
            // Update the minimum wasted cookies found so far
            min_wasted_cookies = min(min_wasted_cookies, current_wasted);
            
            // Mark that we have found at least one possible distribution
            possible_distribution_found = true;
        }
    }
    
    // After checking all jars, output the result
    if (possible_distribution_found) {
        cout << min_wasted_cookies << "\n";
    } else {
        // If no jar allowed for a valid distribution, print -1
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }
    
    return 0;
}
```