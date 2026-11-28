# [Exun Quiz (EXQUIZ)](https://www.codechef.com/problems/EXQUIZ)
- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the minimum number of questions a student must have attempted to achieve a specific total score `S`, given that the total number of attempted questions cannot exceed `N`. The scoring system is: +4 points for each correct answer and -1 point for each wrong answer. If it's impossible to achieve the score `S` under these conditions, we should output -1.

## Intuition & Mathematical Observation
Let's define our variables:
- `c`: The number of correct answers.
- `w`: The number of wrong answers.

From the problem statement, we can derive the following relationships and constraints:

1.  **Score Equation**: The total score `S` is calculated as `4 * c - 1 * w`.
    `4c - w = S`

2.  **Total Attempts Constraint**: The total number of questions attempted (`c + w`) must be between 0 and `N` (inclusive). We are looking for the minimum `c + w`.
    `0 <= c + w <= N`

3.  **Non-negativity**: The number of correct and wrong answers cannot be negative.
    `c >= 0`
    `w >= 0`

Our goal is to minimize `c + w` subject to these constraints.

First, let's express `w` in terms of `c` and `S` from the score equation:
`w = 4c - S`

Now, substitute this expression for `w` into the other constraints:

**A. Non-negativity of `w`**:
`w >= 0`
`4c - S >= 0`
`4c >= S`
`c >= S / 4`
Since `c` must be an integer, `c >= ceil(S / 4.0)`. In integer arithmetic, for positive `S`, this can be calculated as `(S + 3) / 4`. To handle `S <= 0` correctly (where `c` must still be non-negative), we take `max(0LL, (S + 3) / 4LL)`.

**B. Total Attempts Constraint**:
`0 <= c + w <= N`
Substitute `w = 4c - S`:
`0 <= c + (4c - S) <= N`
`0 <= 5c - S <= N`

This gives us two inequalities:
   i. `5c - S >= 0`
      `5c >= S`
      `c >= S / 5`
      Since `c` must be an integer, `c >= ceil(S / 5.0)`. This lower bound is less strict than `c >= S/4` (for `S >= 0`), so `c >= S/4` will be the dominant lower bound for `c` from score/wrong answer constraints.

   ii. `5c - S <= N`
       `5c <= N + S`
       `c <= (N + S) / 5`
       Since `c` must be an integer, `c <= floor((N + S) / 5.0)`. In integer arithmetic, this is simply `(N + S) / 5LL`.

**Combining all constraints on `c`**:
The minimum possible value for `c` (let's call it `min_c_possible`) is determined by `c >= 0` and `c >= ceil(S/4.0)`. Thus, `min_c_possible = max(0LL, (S + 3) / 4LL)`.

The maximum possible value for `c` (let's call it `max_c_possible`) is determined by `c <= floor((N + S) / 5.0)`. Thus, `max_c_possible = (N + S) / 5LL`.

So, a valid integer `c` must exist in the range `[min_c_possible, max_c_possible]`.

The quantity we want to minimize is the total number of attempts: `c + w = c + (4c - S) = 5c - S`.
Since `5c - S` is a strictly increasing function of `c`, to minimize this value, we need to choose the smallest possible integer `c` that satisfies all constraints. This smallest valid `c` is `min_c_possible`.

Therefore, the algorithm is:
1.  Calculate `min_c_possible = max(0LL, (S + 3) / 4LL)`.
2.  Calculate `max_c_possible = (N + S) / 5LL`.
3.  If `min_c_possible > max_c_possible`, it means there is no integer `c` that satisfies all conditions. In this case, output -1.
4.  Otherwise, a valid `c` exists. The minimum number of attempts is achieved with `c = min_c_possible`. Calculate and output `5LL * min_c_possible - S`.

**Important Note on Data Types**: Given `N` up to $10^9$ and `S` up to $4 \times 10^9$, `S` can exceed the maximum value of a 32-bit signed integer (approx $2 \times 10^9$). Therefore, `N` and `S`, and any intermediate calculations involving them (like `N + S`, `5 * c`, `5 * c - S`), must use `long long` to prevent overflow.

## Complexity Analysis
-   **Time Complexity**: The solution involves a few arithmetic operations (addition, subtraction, multiplication, division, and `max`). These operations take constant time. Therefore, for each test case, the time complexity is $O(1)$. With `T` test cases, the total time complexity is $O(T)$.
-   **Space Complexity**: The solution uses a fixed number of variables (`N`, `S`, `min_c`, `max_c`) to store input and intermediate results. This requires a constant amount of memory, making the space complexity $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    // N: Max attempts, S: Target score
    // Use long long for N and S as S can be up to 4 * 10^9,
    // which exceeds the capacity of a 32-bit int.
    long long N, S;
    cin >> N >> S;

    // Let c be correct answers, w be wrong answers.
    // Score equation: 4c - w = S  =>  w = 4c - S
    // Total attempts: c + w = c + (4c - S) = 5c - S

    // Constraints on c:
    // 1. c >= 0 (number of correct answers cannot be negative)
    // 2. w >= 0  =>  4c - S >= 0  =>  4c >= S  =>  c >= S/4
    //    For integer c, c >= ceil(S/4.0). Using integer division: (S + 3) / 4
    //    Combined with c >= 0, the lower bound is max(0LL, (S + 3) / 4LL).
    // 3. Total attempts >= 0  =>  5c - S >= 0  =>  5c >= S  =>  c >= S/5
    //    This constraint is less strict than c >= S/4 for S >= 0, so it's covered.
    // 4. Total attempts <= N  =>  5c - S <= N  =>  5c <= N + S  =>  c <= (N + S)/5
    //    For integer c, c <= floor((N + S)/5.0). Using integer division: (N + S) / 5

    // Calculate the minimum possible value for c that satisfies c >= 0 and w >= 0
    long long min_c = 0;
    min_c = max(min_c, (S + 3) / 4LL); // Use 4LL to ensure long long division

    // Calculate the maximum possible value for c that satisfies total attempts <= N
    long long max_c = (N + S) / 5LL; // Use 5LL to ensure long long division

    // If the minimum required c is greater than the maximum allowed c,
    // then no valid integer c exists that satisfies all conditions.
    if (min_c > max_c) {
        cout << -1 << "\n";
    } else {
        // The total attempts is 5c - S.
        // To minimize attempts, we need to choose the smallest valid c, which is min_c.
        cout << (5LL * min_c - S) << "\n"; // Use 5LL to ensure long long multiplication
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

```