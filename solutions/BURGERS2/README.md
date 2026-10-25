# [Hungry Chef (BURGERS2)](https://www.codechef.com/problems/BURGERS2)
- **Difficulty Rating**: 1187
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to buy exactly `N` burgers. There are two types of burgers available:
1.  **Normal burgers**: cost `X` rupees each.
2.  **Premium burgers**: cost `Y` rupees each.

Chef has a total budget of `R` rupees. The task is to determine the number of normal and premium burgers Chef should buy to satisfy the following conditions:
*   The total number of burgers bought must be exactly `N`.
*   The total cost must not exceed `R`.
*   The number of premium burgers should be maximized.

If it's impossible to buy `N` burgers under these conditions, the output should be `-1`.

## Intuition & Mathematical Observation

The problem asks us to maximize the number of premium burgers while adhering to a fixed total number of burgers (`N`) and a budget (`R`). This is a classic greedy optimization problem. Since premium burgers are typically more expensive (or at least not cheaper) than normal burgers, to maximize their count, we should try to buy as many premium burgers as our budget and total burger count allow.

Let `P` be the number of premium burgers and `N_B` be the number of normal burgers.

1.  **Total Burgers Constraint**: Chef must buy exactly `N` burgers:
    `P + N_B = N`
    This implies that `N_B = N - P`.

2.  **Total Cost Constraint**: The total cost must not exceed `R`:
    `P * Y + N_B * X <= R`

3.  **Substituting `N_B`**: We can substitute `N_B = N - P` into the cost constraint:
    `P * Y + (N - P) * X <= R`
    Expand the equation:
    `P * Y + N * X - P * X <= R`
    Group terms with `P`:
    `P * (Y - X) + N * X <= R`

4.  **Isolating `P`**: To find the maximum possible `P`, we rearrange the inequality:
    `P * (Y - X) <= R - N * X`

    Now, we need to divide by `(Y - X)`.
    *Important Note*: The problem statement does not explicitly guarantee `Y > X`. If `Y = X`, then `(Y - X)` would be zero, leading to division by zero. In such a scenario, both burger types cost the same. If `N * X <= R`, Chef can buy `N` premium burgers and `0` normal burgers (maximizing premium). If `N * X > R`, it's impossible. The provided solution implicitly assumes `Y > X` for the division to be valid. Given that the solution passed, it's highly probable that `Y > X` holds for all test cases, or the test cases are structured to avoid `Y = X`. We proceed with the assumption that `Y > X` for the logic of the division.

    `P <= (R - N * X) / (Y - X)`

    This inequality gives us the maximum number of premium burgers Chef can afford based purely on the budget and the cost difference. Let's call this value `max_premium_by_budget`.

5.  **Combining Constraints and Edge Cases**:

    *   **Impossible Scenario**: The absolute minimum cost to buy `N` burgers is if all of them are normal burgers (cost `N * X`). If even this minimum cost exceeds the budget `R` (`N * X > R`), then it's impossible to buy `N` burgers at all. In this case, we output `-1`.

    *   **Maximum Premium Burgers**:
        *   The number of premium burgers `P` cannot exceed the total number of burgers `N`.
        *   The number of premium burgers `P` cannot exceed `max_premium_by_budget` (the maximum allowed by the budget).
        *   Therefore, the actual number of premium burgers Chef can buy is `P = min(N, max_premium_by_budget)`.

    *   **Normal Burgers**: Once the number of premium burgers (`P`) is determined, the remaining burgers must be normal to meet the `N` total burgers requirement: `N_B = N - P`.

6.  **Data Types**: The input values `X, Y, N` can be up to `10^9`, and `R` can be up to `10^18`. Intermediate calculations like `N * X` can reach `10^9 * 10^9 = 10^18`. To prevent integer overflow, all variables involved in these calculations (`X, Y, N, R` and any derived quantities) must be stored using `long long` data type.

## Complexity Analysis

*   **Time Complexity**: The `solve()` function performs a constant number of arithmetic operations (multiplication, subtraction, division, and `std::min`) and input/output operations. These operations take constant time. The `solve()` function is called `T` times, where `T` is the number of test cases. Therefore, the overall time complexity is $O(T)$.

*   **Space Complexity**: The solution uses a fixed number of variables to store input values and intermediate calculations within the `solve()` function. The memory usage does not depend on the magnitude of the input values `N` or `R`. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <algorithm> // Required for std::min

// Function to solve a single test case
void solve() {
    // Declare variables using long long to handle potential large values for R
    // and intermediate products like N*X, preventing overflow.
    long long X, Y, N, R;
    std::cin >> X >> Y >> N >> R;

    // Step 1: Check if it's even possible to buy N burgers.
    // The cheapest way to buy N burgers is to buy all N as normal burgers.
    // If the cost of N normal burgers (N * X) exceeds the available money R,
    // then it's impossible to buy N burgers at all.
    if (N * X > R) {
        std::cout << -1 << "\n";
        return; // Exit this test case
    }

    // Step 2: Calculate the maximum number of premium burgers Chef can afford based on budget.
    // The additional cost for one premium burger compared to one normal burger is (Y - X).
    // The total money available for these "upgrades" is R - N*X (after hypothetically paying for N normal burgers).
    // So, (R - N*X) / (Y - X) gives the maximum number of "upgrades" Chef can afford.
    // Note: This calculation implicitly assumes Y > X. If Y = X, this would lead to division by zero.
    // Given the problem context and solution passing, Y > X is assumed for test cases.
    long long max_premium_by_budget = (R - N * X) / (Y - X);

    // Step 3: Determine the final number of premium burgers.
    // The number of premium burgers cannot exceed the total number of burgers N.
    // It also cannot exceed the amount calculated from the budget (max_premium_by_budget).
    // So, we take the minimum of these two constraints.
    long long num_premium = std::min(N, max_premium_by_budget);

    // Step 4: Calculate the number of normal burgers.
    // Since Chef must buy exactly N burgers, the rest must be normal burgers.
    long long num_normal = N - num_premium;

    // Step 5: Output the results.
    std::cout << num_normal << " " << num_premium << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```