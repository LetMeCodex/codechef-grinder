# [Even Numbers Hate (EVENHATE)](https://www.codechef.com/problems/EVENHATE)
- **Difficulty Rating**: 1165
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to rearrange a given array `A` of `N` integers into a new array `B` such that the number of odd prefix sums in `B` is maximized. We need to output this maximum count of odd prefix sums. A prefix sum `P_k` is defined as the sum of the first `k` elements of `B` (i.e., `B_1 + B_2 + ... + B_k`).

## Intuition & Mathematical Observation

The core of this problem lies in understanding how the parity (even or odd) of a sum changes when we add a new number.

Let `P_k` be the prefix sum up to index `k`, and `B_{k+1}` be the next element. Then `P_{k+1} = P_k + B_{k+1}`.
The parity rules for addition are:
*   Even + Even = Even
*   Even + Odd = Odd
*   Odd + Even = Odd
*   Odd + Odd = Even

From these rules, we can observe how adding an element affects the parity of the prefix sum:
*   If `P_k` is **Even**:
    *   Adding an **Even** `B_{k+1}` keeps `P_{k+1}` **Even**.
    *   Adding an **Odd** `B_{k+1}` makes `P_{k+1}` **Odd**.
*   If `P_k` is **Odd**:
    *   Adding an **Even** `B_{k+1}` keeps `P_{k+1}` **Odd**.
    *   Adding an **Odd** `B_{k+1}` makes `P_{k+1}` **Even**.

Our goal is to maximize the number of odd prefix sums. Let's count the total number of odd and even elements in the input array `A`. Let these be `count_odd` and `count_even` respectively.

**Case 1: `count_odd == 0`**
If there are no odd numbers in the array, all elements are even. Any sum of even numbers will always be even. Therefore, all prefix sums `P_1, P_2, ..., P_N` will be even. In this case, the maximum number of odd prefix sums is **0**.

**Case 2: `count_odd > 0`**
If there is at least one odd number, we can definitely achieve at least one odd prefix sum. To maximize odd prefix sums, we should follow a greedy strategy:

1.  **Start with an Odd number**: Place one odd number as `B_1`. This makes `P_1` **Odd**. (1 odd prefix sum achieved).
    *   Current sum parity: Odd.
    *   Remaining odd numbers: `count_odd - 1`.
    *   Remaining even numbers: `count_even`.

2.  **Place all Even numbers**: Since our current prefix sum `P_1` is Odd, adding an Even number `B_i` will keep the sum `P_i` Odd. To maximize consecutive odd prefix sums, we should place all `count_even` numbers immediately after `B_1`.
    *   `B_2, ..., B_{1+count_even}` will all be even.
    *   `P_2, ..., P_{1+count_even}` will all be **Odd**.
    *   This adds `count_even` more odd prefix sums.
    *   Total odd prefix sums so far: `1 + count_even`.
    *   Current sum parity: Odd.
    *   Remaining odd numbers: `count_odd - 1`.
    *   Remaining even numbers: `0`.

3.  **Place the remaining Odd numbers**: We now have `count_odd - 1` odd numbers left, and our current prefix sum is Odd.
    *   If we add an Odd number, the sum becomes Even.
    *   If we add another Odd number, the sum becomes Odd again.
    *   This pattern continues: Odd -> Even -> Odd -> Even...
    *   Each pair of remaining odd numbers will contribute one odd prefix sum (the one after the second odd number in the pair).
    *   The number of odd prefix sums we can get from `count_odd - 1` remaining odd numbers is `(count_odd - 1) / 2` (using integer division, which is equivalent to `floor((count_odd - 1) / 2)`).

Combining these steps, the total maximum number of odd prefix sums when `count_odd > 0` is:
`1` (from the first odd number)
`+ count_even` (from all even numbers)
`+ (count_odd - 1) / 2` (from the remaining odd numbers)

So, the formula is `1 + count_even + (count_odd - 1) / 2`.

**Example:** `A = [1, 2, 3, 4, 5]`
`count_odd = 3`, `count_even = 2`

1.  Place `1`: `B = [1]`. `P_1 = 1` (Odd). (1 odd sum)
2.  Place `2, 4`: `B = [1, 2, 4]`. `P_1=1` (Odd), `P_2=3` (Odd), `P_3=7` (Odd). (2 more odd sums)
3.  Place `3, 5`: `B = [1, 2, 4, 3, 5]`. `P_4=10` (Even), `P_5=15` (Odd). (1 more odd sum)

Total odd prefix sums: `1 + 2 + 1 = 4`.
Using formula: `1 + 2 + (3 - 1) / 2 = 1 + 2 + 2 / 2 = 1 + 2 + 1 = 4`. The formula matches.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   We iterate through the input array `A` once to count the odd and even numbers. This takes $O(N)$ time.
    *   The subsequent calculations and printing are $O(1)$.
    *   Since there are `T` test cases, the total time complexity will be $O(T \cdot N)$.

*   **Space Complexity**: $O(1)$
    *   We only use a few integer variables (`N`, `count_odd`, `count_even`, `A_i`) to store counts and current input, which requires constant extra space regardless of the input size `N`.

## Solution Code

```cpp
#include <bits/stdc++.h> 
using namespace std;

void solve() {
    int N;
    cin >> N;
    int count_odd = 0;
    int count_even = 0;
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        if (A_i % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    if (count_odd == 0) {
        // If there are no odd numbers, all elements are even.
        // Any sum of even numbers is even. So all prefix sums will be even.
        // Thus, 0 odd prefix sums.
        cout << 0 << "\n";
    } else {
        // If there is at least one odd number:
        // Optimal strategy:
        // 1. Place one odd number first (P_1 will be odd).
        // 2. Place all 'count_even' even numbers next (P_i remains odd).
        // 3. Place the remaining (count_odd - 1) odd numbers.
        //    Each remaining odd number flips the parity. Since the sum
        //    was odd before these, the sequence of parities will be
        //    Even, Odd, Even, Odd, ...
        //    The number of odd sums in this sequence of (count_odd - 1) elements
        //    is floor((count_odd - 1) / 2).
        // Total maximum odd prefix sums = (1 + count_even) + floor((count_odd - 1) / 2).
        cout << (1 + count_even + (count_odd - 1) / 2) << "\n";
    }
}

int main() {
    // Fast I/O to speed up competitive programming solutions.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```