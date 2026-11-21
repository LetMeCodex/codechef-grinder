# [Accommodation (ACMDT)](https://www.codechef.com/problems/ACMDT)
- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of rooms, let's call it `K`, required to accommodate `B` boys and `G` girls, subject to the following constraints for *each* room:
1.  Each room must have at least `X` boys.
2.  Each room must have at least `Y` girls.
3.  Each room must have at most `N` people in total.

If it's impossible to satisfy all conditions, we should output `-1`.

## Intuition & Mathematical Observation

The problem asks for the *minimum* number of rooms `K`. This suggests that we need to find a range `[K_lower_bound, K_upper_bound]` for `K` that satisfies all conditions. If such a range exists (i.e., `K_lower_bound <= K_upper_bound`), then the minimum `K` will be `K_lower_bound`. Otherwise, if `K_lower_bound > K_upper_bound`, it's impossible, and we output `-1`.

Let's derive the bounds for `K`:

**1. Initial Feasibility Check:**
Before calculating any bounds for `K`, we should check if even a single room can satisfy the basic requirements. A single room must have at least `X` boys and `Y` girls. This means it must accommodate at least `X + Y` people. If `X + Y` exceeds the maximum capacity `N` for a single room, then it's impossible to satisfy the conditions with any number of rooms.
*   If `X + Y > N`, output `-1`.

**2. Upper Bound for K (`K_upper_bound`):**
The total number of boys `B` must be distributed among `K` rooms, with each room having at least `X` boys. This implies that `K * X` (minimum boys required across `K` rooms) must be less than or equal to `B`.
*   `K * X <= B  =>  K <= B / X` (integer division)

Similarly, for girls:
*   `K * Y <= G  =>  K <= G / Y` (integer division)

To satisfy both conditions, `K` must be less than or equal to the minimum of these two values:
*   `K_upper_bound = min(B / X, G / Y)`

**3. Lower Bound for K (`K_lower_bound`):**
We need to find the minimum `K` required based on various constraints:

*   **Based on total boys `B`:** Each room must have at least `Y` girls. Since a room can hold at most `N` people, the maximum number of boys a single room can accommodate is `N - Y`. To accommodate `B` boys, we need at least `ceil(B / (N - Y))` rooms.
    *   `K >= ceil(B / (N - Y))`

*   **Based on total girls `G`:** Each room must have at least `X` boys. Similarly, the maximum number of girls a single room can accommodate is `N - X`. To accommodate `G` girls, we need at least `ceil(G / (N - X))` rooms.
    *   `K >= ceil(G / (N - X))`

*   **Based on total people `B + G`:** Each room can hold at most `N` people. To accommodate `B + G` total people, we need at least `ceil((B + G) / N)` rooms.
    *   `K >= ceil((B + G) / N)`

To satisfy all these minimum requirements, `K` must be greater than or equal to the maximum of these three values:
*   `K_lower_bound = max(ceil(B / (N - Y)), ceil(G / (N - X)), ceil((B + G) / N))`

**Important Note on Denominators:**
The initial check `X + Y > N` ensures that `N - Y >= X` and `N - X >= Y`. Since `X, Y >= 1` (from problem constraints), it implies `N - Y >= 1` and `N - X >= 1`. Also, `N >= X + Y >= 1 + 1 = 2`. Thus, all denominators (`N - Y`, `N - X`, `N`) are guaranteed to be positive, preventing division by zero.

**Ceiling Division:**
For positive integers `a` and `b`, `ceil(a / b)` can be computed using integer arithmetic as `(a + b - 1) / b`. This formula correctly handles cases where `a` is a multiple of `b` and when `a` is not. It also correctly handles `a=0` (e.g., `ceil(0/b) = 0`).

**Final Result:**
After calculating `K_lower_bound` and `K_upper_bound`:
*   If `K_lower_bound > K_upper_bound`, it's impossible to find a `K` that satisfies all conditions. Output `-1`.
*   Otherwise, the minimum number of rooms required is `K_lower_bound`. Output `K_lower_bound`.

## Complexity Analysis

*   **Time Complexity**: The solution involves a fixed number of arithmetic operations (addition, subtraction, multiplication, division) and comparisons. These operations take constant time. The `solve()` function therefore runs in $O(1)$ time. Since there are `T` test cases, the total time complexity is $O(T)$.
*   **Space Complexity**: The solution uses a few `long long` variables to store inputs and intermediate calculations. This amount of memory is constant and does not depend on the input size. Thus, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm> // For std::max and std::min
#include <vector>    // For std::max({initializer_list})

// Function for ceiling division (a / b) for positive integers
long long ceil_div(long long a, long long b) {
    // This handles cases where a is 0 correctly (0/b = 0)
    // and positive a, b.
    // For a=0, b>0: (0+b-1)/b = (b-1)/b = 0.
    // For a>0, b>0: (a+b-1)/b correctly computes ceil(a/b).
    return (a + b - 1) / b;
}

void solve() {
    long long B, G, X, Y, N;
    std::cin >> B >> G >> X >> Y >> N;

    // Initial check: A single room must be able to satisfy minimum boy and girl counts
    // and total capacity. If X boys and Y girls are placed, total people is X+Y.
    // This must not exceed N.
    if (X + Y > N) {
        std::cout << -1 << "\n";
        return;
    }

    // Calculate upper bound for K (number of rooms)
    // Each room must have at least X boys and at least Y girls.
    // So, K rooms can accommodate at most K*X boys and K*Y girls.
    // Thus, B >= K*X  => K <= B/X
    // And G >= K*Y  => K <= G/Y
    // K_upper_bound is the minimum of these two maximums.
    long long k_upper_bound = std::min(B / X, G / Y);

    // Calculate lower bounds for K (number of rooms)
    // 1. Each room can have at most N-Y boys (because it must have at least Y girls).
    //    To accommodate B boys, we need at least ceil(B / (N-Y)) rooms.
    long long k_lower_bound_boys = ceil_div(B, N - Y);

    // 2. Each room can have at most N-X girls (because it must have at least X boys).
    //    To accommodate G girls, we need at least ceil(G / (N-X)) rooms.
    long long k_lower_bound_girls = ceil_div(G, N - X);

    // 3. Each room can have at most N people in total.
    //    To accommodate B+G people, we need at least ceil((B+G) / N) rooms.
    long long k_lower_bound_total_people = ceil_div(B + G, N);

    // K_lower_bound is the maximum of these three minimums.
    // Note: N-Y, N-X, N are guaranteed to be positive if X+Y <= N.
    // If X+Y <= N, then X <= N-Y. Since X >= 1, N-Y >= 1.
    // Similarly, Y <= N-X. Since Y >= 1, N-X >= 1.
    // Also N >= X+Y >= 1+1 = 2. So N >= 1.
    // Thus, no division by zero or negative denominators.
    long long k_lower_bound = std::max({k_lower_bound_boys, k_lower_bound_girls, k_lower_bound_total_people});

    // If the minimum required rooms (k_lower_bound) is greater than
    // the maximum possible rooms (k_upper_bound), then it's impossible.
    if (k_lower_bound > k_upper_bound) {
        std::cout << -1 << "\n";
    } else {
        // Otherwise, the minimum number of rooms is k_lower_bound.
        std::cout << k_lower_bound << "\n";
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```