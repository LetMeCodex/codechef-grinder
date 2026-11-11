# [Covid Spread (COVSPRD)](https://www.codechef.com/problems/COVSPRD)
- **Difficulty Rating**: 1346
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total number of infected people in a population of size `N` after `D` days. Initially, on Day 0, exactly 1 person is infected. The spread of the infection follows a specific pattern:
1.  For the first 10 days (Day 1 to Day 10), the number of infected people doubles each day.
2.  From Day 11 onwards, the number of infected people triples each day.
3.  The total number of infected people can never exceed the total population `N`.

We need to output the final count of infected people at the end of `D` days.

## Intuition & Mathematical Observation

The problem describes an exponential growth model with two distinct phases, capped by the total population `N`.

1.  **Base Case (D = 0)**: At the end of Day 0, only the initial person is infected. So, the count is 1.

2.  **Phase 1 (D <= 10)**:
    *   For each day from Day 1 to Day `D`, the number of infected people doubles.
    *   After `D` days, the count would be `1 * 2^D`.
    *   This count must be capped at `N`. So, the actual infected count is `min(N, 2^D)`.
    *   We use `1LL << D` for `2^D` to ensure `long long` arithmetic and prevent overflow if `D` is small but `2^D` exceeds `int` limits.

3.  **Phase 2 (D > 10)**:
    *   This phase requires a two-step calculation:
        a.  **Calculate infected count at the end of Day 10**: Following Phase 1 rules, this would be `min(N, 2^10)`. Let's call this `infected_at_day_10`.
        b.  **Calculate spread from Day 11 to Day D**:
            *   If `infected_at_day_10` is already equal to `N`, it means the entire population was infected by Day 10. In this case, the count remains `N` for all subsequent days.
            *   Otherwise, we start with `infected_at_day_10` and simulate the tripling for the remaining `D - 10` days.
            *   For each of these `D - 10` days, we multiply the current `infected_count` by 3.
            *   Crucially, we must cap the `infected_count` at `N` at each step. An efficient way to do this is to check `if (infected_count > N / 3)`. If this condition is true, it means `infected_count * 3` would exceed `N`. In this scenario, we set `infected_count = N` and stop further tripling, as the population is fully infected. This check also prevents potential `long long` overflow if `N` is close to `LLONG_MAX` and `infected_count * 3` would exceed it (though `N` is only up to `10^9`, so `N*3` fits `long long`).

The key observation for the tripling loop is that `infected_count` grows very rapidly. Even if `N` is `10^9` and `infected_count` starts at `1024` (which is `2^10`), it will reach `N` in a very small number of tripling steps (approximately `log_3(10^9 / 1024) ≈ log_3(10^6) ≈ 12-13` steps). This means the loop for tripling will run at most about 15-20 times, making the simulation efficient enough even for large `D`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    *   Reading `N` and `D` takes constant time.
    *   The `if (D <= 10)` block involves a bit shift and a `min` operation, both $O(1)$.
    *   The `else (D > 10)` block calculates `2^10` and `min(N, ...)` in $O(1)$.
    *   The `for` loop for tripling runs a maximum of about 15-20 iterations (as explained in the intuition), regardless of the value of `D` (for large `D`) or `N`. This is a constant number of operations.
    *   Therefore, each test case is processed in constant time.
    *   For `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$
    *   We use a fixed number of `long long` variables (`N`, `D`, `infected_count`, etc.) to store input and intermediate calculations.
    *   The memory usage does not depend on the input values `N` or `D`.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <algorithm> // Required for std::min

// It's generally good practice to avoid 'using namespace std;' in headers or large projects,
// but for competitive programming, it's common and often requested.
using namespace std;

void solve() {
    long long N, D;
    cin >> N >> D;

    long long infected_count = 1; // Initially, 1 person is infected at Day 0.

    if (D == 0) {
        // At the end of day 0, a single person is infected.
        // infected_count remains 1, which is its initial value.
    } else if (D <= 10) {
        // During the next 10 days (Day 1 to Day 10), the number of infected people doubles each day.
        // Calculate 2^D. Use 1LL to ensure the shift operation is done with long long.
        infected_count = 1LL << D;
        // Cap the infected count at N (total population).
        infected_count = min(N, infected_count);
    } else { // D > 10
        // First, calculate the number of infected people at the end of Day 10.
        long long infected_at_day_10 = 1LL << 10; // 2^10 = 1024
        infected_at_day_10 = min(N, infected_at_day_10); // Cap at N

        // If the population N was already fully infected by day 10,
        // it cannot increase further.
        if (infected_at_day_10 == N) {
            infected_count = N;
        } else {
            // From day 11 onwards, the number of infected people triples each day.
            // Start with the count from day 10.
            infected_count = infected_at_day_10;
            long long days_to_triple = D - 10; // Number of days remaining for tripling.

            // Simulate tripling for `days_to_triple` days.
            // This loop will run a small number of times (at most ~17-18 for N=10^9)
            // because `infected_count` will quickly reach `N` due to exponential growth.
            for (int i = 0; i < days_to_triple; ++i) {
                // Check if multiplying by 3 would exceed N.
                // This prevents overflow and correctly caps the count at N.
                // If infected_count > N / 3, then infected_count * 3 would be > N.
                // Example: N=10, N/3=3. If infected_count=4, 4 > 3 is true.
                // So infected_count becomes N=10. Correct.
                // This check is robust for all N >= 1.
                if (infected_count > N / 3) {
                    infected_count = N;
                    break; // Population fully infected, no need to triple further.
                }
                infected_count *= 3;
            }
            // No need for a final min(N, infected_count) here, as the loop logic already ensures it.
        }
    }

    cout << infected_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```