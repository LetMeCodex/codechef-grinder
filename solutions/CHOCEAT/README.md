# Chocolate Eating (CHOCEAT)
- **Difficulty Rating**: 903
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible satisfaction Chef can achieve by eating a total of $A$ milk chocolates and $B$ dark chocolates. Chef's satisfaction increases by 1 after eating a chocolate if and only if the number of milk chocolates eaten so far is not equal to the number of dark chocolates eaten so far.

## Intuition & Mathematical Observation

Let $m$ be the number of milk chocolates eaten so far, and $d$ be the number of dark chocolates eaten so far. Chef's satisfaction increases at a particular step if $m \neq d$ after eating a chocolate. The total number of chocolates eaten is $A + B$. The total satisfaction is the sum of increases over all $A+B$ steps. This can be expressed as:

Total Satisfaction = (Total number of chocolates eaten) - (Number of steps where $m = d$)
Total Satisfaction = $(A + B) - (\text{Number of steps where } m = d)$

To maximize satisfaction, we need to minimize the number of steps where $m = d$.

The condition $m = d$ can only occur when the total number of chocolates eaten so far is even. Let's say at some step, $m = d = k$. This means $k$ milk chocolates and $k$ dark chocolates have been eaten. This is only possible if we have at least $k$ milk chocolates and $k$ dark chocolates available, i.e., $k \le A$ and $k \le B$. Therefore, the maximum possible value for $k$ such that $m=d=k$ can be reached is $\min(A, B)$.

Consider two cases:

**Case 1: $A \neq B$**
Without loss of generality, assume $A > B$.
Chef can choose to eat all $A$ milk chocolates first, and then all $B$ dark chocolates.
Let's trace the satisfaction:
1.  **Eating $A$ milk chocolates:**
    *   After eating the 1st milk chocolate: $m=1, d=0$. $m \neq d$. Satisfaction +1.
    *   After eating the 2nd milk chocolate: $m=2, d=0$. $m \neq d$. Satisfaction +1.
    *   ...
    *   After eating the $A$-th milk chocolate: $m=A, d=0$. $m \neq d$. Satisfaction +1.
    In this phase, $d$ is always 0, and $m$ is always greater than 0 (since $A \ge 1$). Thus, $m \neq d$ for all $A$ steps. Total satisfaction from this phase is $A$.

2.  **Eating $B$ dark chocolates:**
    *   After eating the 1st dark chocolate: $m=A, d=1$. Since $A > B \ge 1$, we have $A \neq 1$. So $m \neq d$. Satisfaction +1.
    *   After eating the 2nd dark chocolate: $m=A, d=2$. Since $A > B \ge 2$, we have $A \neq 2$. So $m \neq d$. Satisfaction +1.
    *   ...
    *   After eating the $B$-th dark chocolate: $m=A, d=B$. Since $A > B$, we have $A \neq B$. So $m \neq d$. Satisfaction +1.
    In this phase, $m$ is always $A$, and $d$ ranges from 1 to $B$. Since $A > B$, $m$ is always strictly greater than $d$. Thus, $m \neq d$ for all $B$ steps. Total satisfaction from this phase is $B$.

The total satisfaction achieved with this strategy is $A + B$. This strategy is valid because we have enough chocolates of each type.
The same logic applies if $B > A$. Chef can eat all $B$ dark chocolates first, then all $A$ milk chocolates, achieving a total satisfaction of $B + A$.
Therefore, if $A \neq B$, the maximum satisfaction is $A + B$.

**Case 2: $A = B$**
Let $A = B = k$. The total number of chocolates is $2k$.
If Chef tries to eat all milk chocolates first, then all dark chocolates:
1.  **Eating $k$ milk chocolates:**
    *   $m=1, d=0 \implies m \neq d$. Sat +1.
    *   ...
    *   $m=k, d=0 \implies m \neq d$. Sat +1.
    Total satisfaction from this phase is $k$.

2.  **Eating $k$ dark chocolates:**
    *   After eating the 1st dark chocolate: $m=k, d=1$. Since $k \ge 1$, $m \neq d$. Sat +1.
    *   ...
    *   After eating the $(k-1)$-th dark chocolate: $m=k, d=k-1$. $m \neq d$. Sat +1.
    *   After eating the $k$-th dark chocolate: $m=k, d=k$. $m = d$. Sat +0.
    In this phase, there are $k-1$ steps where satisfaction is gained, and 1 step where satisfaction is not gained (when $m=d=k$).

The total satisfaction achieved with this strategy is $k + (k-1) = 2k - 1$.
Since $A = B = k$, this is $A + B - 1$.

Can we do better? If $A=B=k$, any sequence of eating chocolates will eventually lead to a state where $m=d$. For example, if we alternate eating milk and dark chocolates:
M: $m=1, d=0$. Sat +1.
D: $m=1, d=1$. Sat +0.
M: $m=2, d=1$. Sat +1.
D: $m=2, d=2$. Sat +0.
...
In this alternating strategy, every second step results in $m=d$. The total number of steps is $2k$. There will be $k$ steps where $m=d$. The total satisfaction would be $(2k) - k = k$. This is less than $2k-1$.

The strategy of eating all of one type first, then all of the other, minimizes the number of times $m=d$ occurs. When $A=B=k$, this strategy results in exactly one instance where $m=d$ (when $m=k, d=k$). Thus, the minimum number of "bad" steps is 1.
Total Satisfaction = $(A+B) - 1 = 2k - 1$.

**Conclusion:**
- If $A \neq B$, maximum satisfaction is $A + B$.
- If $A = B$, maximum satisfaction is $A + B - 1$.

This can be concisely written as $A + B - (A == B ? 1 : 0)$.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case. The solution involves a simple comparison and arithmetic operations.
-   **Space Complexity**: $O(1)$ per test case. The solution uses a constant amount of extra space.

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
        long long a, b; // Number of milk and dark chocolates
        cin >> a >> b;

        // If the number of milk chocolates and dark chocolates are different,
        // Chef can eat all of the majority type first, then all of the minority type.
        // In this sequence, the number of milk chocolates eaten will never equal
        // the number of dark chocolates eaten after any step.
        // Thus, satisfaction increases in every single step.
        // Total satisfaction = a + b.
        //
        // If the number of milk chocolates and dark chocolates are the same (a == b),
        // Chef can eat all of one type first, then all of the other.
        // For example, if a=b=k, Chef eats k milk chocolates, then k dark chocolates.
        // - Eating k milk chocolates: m goes from 1 to k, d is 0. m != d always. Satisfaction = k.
        // - Eating k dark chocolates:
        //   - First k-1 dark chocolates: m=k, d goes from 1 to k-1. m != d always. Satisfaction = k-1.
        //   - Last dark chocolate: m=k, d=k. m == d. Satisfaction = 0.
        // Total satisfaction = k + (k-1) = 2k - 1 = a + b - 1.
        // This is the maximum possible because any strategy will eventually lead to m == d at least once
        // when a == b. The strategy described minimizes these occurrences to exactly one.

        if (a == b) {
            // If counts are equal, one step will always result in m == d.
            // Max satisfaction is total chocolates - 1.
            cout << a + b - 1 << "\n";
        } else {
            // If counts are different, we can arrange eating such that m never equals d.
            // Max satisfaction is total chocolates.
            cout << a + b << "\n";
        }
    }
    return 0;
}
```