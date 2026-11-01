# [Yoga Class (YOGACLASS)](https://www.codechef.com/problems/YOGACLASS)
- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help Chef maximize the money earned from conducting yoga sessions. Chef has a total of `N` hours available. There are two types of yoga sessions:
1.  **Type 1**: Lasts 1 hour and earns `X` rupees.
2.  **Type 2**: Lasts 2 hours and earns `Y` rupees.

We need to determine the maximum total money Chef can earn by strategically choosing which types of sessions to conduct within the `N` available hours.

## Intuition & Mathematical Observation

The core idea to maximize earnings is to compare the "profitability per hour" of the two types of sessions and prioritize the more profitable one.

Let's analyze the profitability per hour for each session type:
*   **Type 1 Session**: Earns `X` rupees for 1 hour. So, its profitability is `X` rupees/hour.
*   **Type 2 Session**: Earns `Y` rupees for 2 hours. So, its profitability is `Y/2` rupees/hour.

We can identify two main cases based on this comparison:

**Case 1: Type 2 sessions are more profitable per hour.**
This occurs when `Y/2 > X`, which is equivalent to `Y > 2 * X`.
In this scenario, we want to maximize the number of Type 2 sessions because they yield more money for every hour spent.
1.  We can conduct `N / 2` (integer division) Type 2 sessions. Each Type 2 session takes 2 hours.
2.  These `N / 2` sessions will earn `(N / 2) * Y` rupees.
3.  After conducting these sessions, `N % 2` hours will remain.
    *   If `N` is even, `N % 2 = 0`, meaning no hours are left.
    *   If `N` is odd, `N % 2 = 1`, meaning one hour is left.
4.  Any remaining hour can only be filled by a Type 1 session. This will earn `(N % 2) * X` rupees.
5.  The total maximum money in this case will be `(N / 2) * Y + (N % 2) * X`.

**Case 2: Type 1 sessions are equally or more profitable per hour.**
This occurs when `Y/2 <= X`, which is equivalent to `Y <= 2 * X`.
In this scenario, taking two Type 1 sessions (which consume 2 hours and earn `2 * X` rupees) is always better than or equal to taking one Type 2 session (which consumes 2 hours and earns `Y` rupees), because `2 * X >= Y`.
Therefore, it's always optimal to conduct only Type 1 sessions.
1.  We can conduct `N` Type 1 sessions, each taking 1 hour.
2.  The total maximum money in this case will be `N * X`.

The solution implements this logic by checking the condition `Y > 2 * X` and applying the appropriate calculation. It's crucial to use `long long` for total money and intermediate products involving `N`, `X`, and `Y` to prevent potential integer overflow, as `N` and `X` can be up to $10^9$, leading to products up to $10^{18}$.

## Complexity Analysis

*   **Time Complexity**: $O(1)$ per test case.
    The `solve()` function performs a fixed number of arithmetic operations (division, modulo, multiplication, addition) and a single comparison. These operations take constant time regardless of the input values `N`, `X`, and `Y`. Since the `main()` function iterates `T` times, calling `solve()` for each test case, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$.
    The solution uses a constant number of variables (`N`, `X`, `Y`, `total_money`, `num_type2_sessions`, `remaining_hours_for_type1`, `T`) to store input and intermediate results. The memory usage does not depend on the input size `N`.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

void solve() {
    int N, X, Y;
    // Read the number of hours (N), price of Type 1 session (X),
    // and price of Type 2 session (Y) for the current test case.
    std::cin >> N >> X >> Y;

    long long total_money; // Use long long to store total money to prevent potential overflow,
                           // although for these constraints, int would suffice.

    // Compare the profitability per hour of Type 1 vs Type 2 sessions.
    // Type 1: X rupees per hour.
    // Type 2: Y rupees for 2 hours, effectively Y/2 rupees per hour.
    // The comparison Y > 2 * X is equivalent to Y/2 > X.

    if (Y > 2 * X) {
        // If Type 2 sessions are more profitable per hour (Y/2 > X),
        // maximize the number of Type 2 sessions.
        
        // Calculate the maximum number of Type 2 sessions possible.
        // Each Type 2 session takes 2 hours.
        long long num_type2_sessions = N / 2; 
        
        // Calculate the remaining hours after taking Type 2 sessions.
        // These remaining hours can only be filled with Type 1 sessions.
        long long remaining_hours_for_type1 = N % 2; 
        
        // Calculate total earnings.
        total_money = num_type2_sessions * Y + remaining_hours_for_type1 * X;
    } else {
        // If Type 1 sessions are equally or more profitable per hour (Y/2 <= X),
        // or if Type 2 sessions are less profitable per hour,
        // it's always better to take only Type 1 sessions.
        // This means taking N Type 1 sessions and 0 Type 2 sessions.
        
        // Calculate total earnings. Cast N to long long before multiplication
        // to ensure the product is computed as long long.
        total_money = (long long)N * X;
    }

    // Output the maximum amount of money Chef can earn.
    std::cout << total_money << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {  // Loop through each test case.
        solve();   // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```