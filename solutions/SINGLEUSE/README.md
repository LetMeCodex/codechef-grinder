# [Single-use Attack (SINGLEUSE)](https://www.codechef.com/problems/SINGLEUSE)
- **Difficulty Rating**: 777
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of attacks required to defeat a boss with `H` health. We have two types of attacks:
1.  **Normal Attack**: Deals `X` damage. Can be used any number of times.
2.  **Special Attack**: Deals `Y` damage. Can be used at most once.

We need to determine the optimal strategy to minimize the total number of attacks.

## Intuition & Mathematical Observation

The key constraint is that the special attack can be used **at most once**. This immediately suggests two primary strategies:

1.  **Never use the special attack**: All damage is dealt by normal attacks.
2.  **Use the special attack exactly once**: The special attack deals `Y` damage, and the remaining health is dealt by normal attacks.

We calculate the number of attacks for each strategy and take the minimum of the two.

Let's formalize the calculation for each strategy:

**General Calculation for Attacks:**
To deal `h` health using attacks that each deal `d` damage, the number of attacks needed is `ceil(h / d)`. In integer arithmetic, this can be calculated as `(h + d - 1) / d`. This formula correctly handles cases where `h` is a multiple of `d` and when it's not.

**Strategy 1: Don't use the special attack at all.**
*   Total health to deal: `H`
*   Damage per attack: `X` (from normal attacks)
*   Number of attacks: `attacks_no_special = (H + X - 1) / X`

**Strategy 2: Use the special attack exactly once.**
*   First, use the special attack. This consumes 1 attack and deals `Y` damage.
*   Remaining health: `H - Y`.
*   **Case A: `H - Y <= 0`**
    *   If the special attack alone is enough to defeat the boss (or overkills), then only 1 attack (the special attack itself) is needed.
    *   Number of attacks: `attacks_with_special = 1`
*   **Case B: `H - Y > 0`**
    *   The remaining `H - Y` health must be dealt by normal attacks.
    *   Number of normal attacks needed for remaining health: `normal_attacks_after_special = ((H - Y) + X - 1) / X`
    *   Total attacks: `attacks_with_special = 1` (for the special attack) `+ normal_attacks_after_special`

Finally, the minimum number of attacks is `min(attacks_no_special, attacks_with_special)`.

## Complexity Analysis

*   **Time Complexity**: For each test case, we perform a fixed number of arithmetic operations (addition, subtraction, division, comparison, `min`). These operations take constant time. Therefore, the time complexity per test case is $O(1)$. Since there are `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: We use a few integer variables to store `H`, `X`, `Y`, and intermediate results. This amount of memory is constant and does not depend on the input size. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std for convenience in competitive programming
using namespace std;

void solve() {
    int H, X, Y;
    cin >> H >> X >> Y;

    // Strategy 1: Don't use the special attack at all.
    // All damage comes from normal attacks.
    // Number of normal attacks needed = ceil(H / X)
    // Using integer division: (H + X - 1) / X
    int attacks_no_special = (H + X - 1) / X;

    // Strategy 2: Use the special attack exactly once.
    int attacks_with_special;
    if (H - Y <= 0) {
        // If the special attack alone is enough to defeat the boss (or overkills),
        // only 1 attack (the special attack) is needed.
        attacks_with_special = 1;
    } else {
        // The special attack deals Y damage.
        // Remaining health = H - Y.
        // This remaining health must be dealt by normal attacks.
        int remaining_health = H - Y;
        // Number of normal attacks needed for remaining health = ceil(remaining_health / X)
        // Using integer division: (remaining_health + X - 1) / X
        int normal_attacks_after_special = (remaining_health + X - 1) / X;
        // Total attacks = 1 (for special attack) + normal_attacks_after_special
        attacks_with_special = 1 + normal_attacks_after_special;
    }

    // The minimum number of attacks is the better of the two strategies.
    cout << min(attacks_no_special, attacks_with_special) << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // Unties cin from cout and disables synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```