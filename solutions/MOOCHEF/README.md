# Moody Chef (MOOCHEF)
- **Difficulty Rating**: 991
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the maximum and minimum possible "happiness" a chef can experience after eating $N$ dishes. Each dish $A_i$ has a certain "mood value". The chef's happiness starts at 0. For each dish, if its mood value $A_i$ falls within a given range $[l, r]$ (inclusive), the chef's happiness increases by 1. Otherwise, if $A_i$ is outside this range, the chef's happiness decreases by 1. We need to find the maximum and minimum values the happiness can reach after considering all $N$ dishes.

## Intuition & Mathematical Observation

The problem describes a sequential process where happiness changes based on each dish. We start with an initial happiness of 0. For each dish $A_i$, we have a binary decision: either the dish is "loved" (i.e., $l \le A_i \le r$) or it's "not loved" (i.e., $A_i < l$ or $A_i > r$).

If a dish is loved, happiness increases by 1.
If a dish is not loved, happiness decreases by 1.

We are interested in the *cumulative* happiness after each dish. Let $H_0 = 0$ be the initial happiness. For $i = 1, \dots, N$, let $H_i$ be the happiness after considering the $i$-th dish.
If $l \le A_i \le r$, then $H_i = H_{i-1} + 1$.
If $A_i < l$ or $A_i > r$, then $H_i = H_{i-1} - 1$.

The problem asks for the maximum and minimum values among $H_1, H_2, \dots, H_N$.

Consider the change in happiness for each dish. It's either $+1$ or $-1$. This is a classic scenario where we can track the running sum (or in this case, running difference).

Let's maintain a `current_happiness` variable. We initialize it to 0. As we iterate through the dishes:
1. If the current dish $A_i$ is within the range $[l, r]$, we increment `current_happiness`.
2. If the current dish $A_i$ is outside the range $[l, r]$, we decrement `current_happiness`.

To find the maximum happiness, we need to keep track of the highest value `current_happiness` reaches at any point during the iteration. We can use a `max_happiness` variable, initialized to a very small number (or 0, since happiness can't be less than 0 initially and can only decrease from there if the first dish is not loved). We update `max_happiness = max(max_happiness, current_happiness)` after processing each dish.

Similarly, to find the minimum happiness, we need to keep track of the lowest value `current_happiness` reaches. We can use a `min_happiness` variable, initialized to a very large number (or 0, as explained above). We update `min_happiness = min(min_happiness, current_happiness)` after processing each dish.

The initial state of `max_happiness` and `min_happiness` should be carefully considered. Since the happiness starts at 0 and the first dish can either increase it to 1 or decrease it to -1, initializing both `max_happiness` and `min_happiness` to 0 is a safe starting point. The loop will then correctly update them based on the first and subsequent dishes.

For example, if $N=3$, $l=2$, $r=4$, and the dishes are $A = [1, 3, 5]$:
- Initial happiness = 0. `max_happiness` = 0, `min_happiness` = 0.
- Dish 1 ($A_1=1$): $1 < 2$, so not loved. `current_happiness` = 0 - 1 = -1.
  `max_happiness` = max(0, -1) = 0.
  `min_happiness` = min(0, -1) = -1.
- Dish 2 ($A_2=3$): $2 \le 3 \le 4$, so loved. `current_happiness` = -1 + 1 = 0.
  `max_happiness` = max(0, 0) = 0.
  `min_happiness` = min(-1, 0) = -1.
- Dish 3 ($A_3=5$): $5 > 4$, so not loved. `current_happiness` = 0 - 1 = -1.
  `max_happiness` = max(0, -1) = 0.
  `min_happiness` = min(-1, -1) = -1.

The final output would be 0 and -1.

The logic seems straightforward: iterate through the array, update the current happiness based on the condition, and track the maximum and minimum values of this current happiness.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the $N$ dishes exactly once. Inside the loop, the operations (comparison, addition/subtraction, `max`, `min`) take constant time. Therefore, the total time complexity is directly proportional to the number of dishes, $N$.

- **Space Complexity**: $O(1)$
  The code uses a fixed number of variables (`N`, `l`, `r`, `current_happiness`, `max_happiness`, `min_happiness`, `A_i`, `T`) regardless of the input size $N$. No auxiliary data structures that grow with $N$ are used. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as per problem instruction
using namespace std;

void solve() {
    int N, l, r;
    cin >> N >> l >> r;

    int current_happiness = 0;
    int max_happiness = 0; // Initialize max_happiness to 0
    int min_happiness = 0; // Initialize min_happiness to 0

    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;

        // Check if A_i is within the loved range [l, r]
        if (A_i >= l && A_i <= r) {
            current_happiness++; // Increase happiness if loved
        } else {
            current_happiness--; // Decrease happiness otherwise
        }

        // Update maximum and minimum happiness encountered so far
        // We are interested in the happiness *after* each dish is processed.
        max_happiness = max(max_happiness, current_happiness);
        min_happiness = min(min_happiness, current_happiness);
    }

    // Output the maximum and minimum happiness
    cout << max_happiness << " " << min_happiness << "\n";
}

int main() {
    // Fast I/O as per problem instruction
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