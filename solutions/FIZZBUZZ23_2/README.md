# Survival Time (FIZZBUZZ23_2)
- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total number of days a family can survive given an initial number of buns ($N$), the number of buns each person eats per day ($X$), and the number of additional days they can survive after the food supply runs out ($D$). The family consists of Alice and 4 other members, making a total of 5 people. A crucial condition is that if there aren't enough buns to feed the entire family on a given day, nobody eats anything from the bun supply.

## Intuition & Mathematical Observation

The core of the problem lies in understanding how the bun supply is consumed and how the additional survival days factor in.

1.  **Family Size and Daily Consumption**:
    The family consists of 5 members (Alice + 4 others).
    Each member eats $X$ buns per day.
    Therefore, the total number of buns the family consumes per day is $5 \times X$. Let's call this `daily_consumption`.

2.  **Survival Days from Buns**:
    The family has an initial supply of $N$ buns.
    They can only eat from the buns if they have enough to feed everyone. This means they can only complete a full day of eating if they have at least `daily_consumption` buns.
    The number of *full days* they can survive solely on the bun supply is determined by integer division: `days_from_buns = N / daily_consumption`.
    If $N < daily\_consumption$, then `days_from_buns` will be 0, which correctly reflects that they cannot even survive one full day using the buns.

3.  **Additional Survival Days**:
    The problem states that "After the food supply runs out, the family can survive for a further $D$ days." This implies that regardless of how many buns are left over after the `days_from_buns` are accounted for, they have an additional $D$ days of survival. The condition "If there aren't enough buns to feed the whole family, nobody will eat anything" is handled by the integer division for `days_from_buns`. Once that count is reached, the bun supply is effectively "out" for the purpose of feeding the whole family.

4.  **Total Survival Days**:
    The total survival time is the sum of the days they can survive using the buns and the additional days they can survive afterwards.
    Total Survival Days = `days_from_buns` + $D$.

Let's verify with the examples:

*   **Test Case 1**: $N=50, X=2, D=10$
    *   `daily_consumption` = $5 \times 2 = 10$ buns/day.
    *   `days_from_buns` = $50 / 10 = 5$ days.
    *   Total Survival Days = $5 + 10 = 15$ days. (Matches sample)

*   **Test Case 2**: $N=120, X=5, D=15$
    *   `daily_consumption` = $5 \times 5 = 25$ buns/day.
    *   `days_from_buns` = $120 / 25 = 4$ days. (After 4 days, $4 \times 25 = 100$ buns are consumed. $120 - 100 = 20$ buns remain. On day 5, they need 25 buns, but only 20 are left, so they cannot complete day 5 using buns.)
    *   Total Survival Days = $4 + 15 = 19$ days. (Matches sample)

The logic holds. The problem can be solved with simple arithmetic operations.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    For each test case, we perform a fixed number of arithmetic operations (multiplication, division, addition). The number of test cases is $T$. Thus, the total time complexity is $O(T \times 1) = O(T)$. However, if we consider the operations per test case, it's constant time, $O(1)$.

-   **Space Complexity**: $O(1)$
    We only use a few variables to store the input values and intermediate results. The memory usage does not depend on the input size, making it constant space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        long long n, x, d; // N: initial buns, X: buns per person per day, D: additional survival days
        std::cin >> n >> x >> d;

        // Total family members are 5 (Alice + 4 others)
        long long family_members = 5;

        // Total buns required per day by the family
        // Since X >= 1 and family_members = 5, daily_consumption will always be >= 5.
        long long daily_consumption = family_members * x;

        // Calculate how many full days the buns can sustain the family.
        // Integer division automatically handles the condition that if there aren't
        // enough buns for a full day, that day is not counted.
        long long days_from_buns = n / daily_consumption;

        // The total survival days are the days they can survive using buns plus
        // the additional days they can survive after the bun supply runs out.
        long long total_survival_days = days_from_buns + d;
        
        std::cout << total_survival_days << "\n";
    }
    return 0;
}
```