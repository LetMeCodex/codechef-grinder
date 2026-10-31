# [International Gym Day (GYMDAY)](https://www.codechef.com/problems/GYMDAY)
- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a gym membership that costs $X$ coins. He has $Y$ coins. He can attend trial sessions, each costing 1 coin. For each trial session he attends, he gets a $D\%$ discount on the membership price. The discount percentage from trial sessions is capped at $100\%$. Chef wants to find the minimum number of trial sessions he needs to attend to afford the membership, given his initial budget $Y$. If it's impossible to afford the membership, output -1.

## Intuition & Mathematical Observation

Let $s$ be the number of trial sessions Chef attends.
Each trial session costs 1 coin. So, attending $s$ sessions costs $s$ coins.
Chef's remaining budget after attending $s$ sessions is $Y - s$.
For each trial session, Chef gets a $D\%$ discount. So, for $s$ sessions, the total discount percentage is $s \times D$.
This discount percentage is capped at $100\%$. So, the effective discount percentage is $\min(s \times D, 100)$.
The membership price after discount is $X \times \frac{100 - \min(s \times D, 100)}{100}$.

Chef can afford the membership if his remaining budget is greater than or equal to the discounted membership price:
$Y - s \ge X \times \frac{100 - \min(s \times D, 100)}{100}$

We are looking for the minimum non-negative integer $s$ that satisfies this condition.

First, consider the base case: if Chef can already afford the membership without any trial sessions ($s=0$), then the minimum sessions needed is 0. This happens if $Y \ge X$.

If $Y < X$, Chef needs to attend trial sessions to get a discount.
The problem constraints are $X \le 50$ and $D \le 5$.
The maximum possible discount percentage from trial sessions is $s \times D$. Since $D \le 5$, and the discount is capped at $100\%$, the effective discount percentage will never exceed $100\%$.
If $s \times D \ge 100$, the discount is $100\%$, and the membership price becomes $0$. In this case, Chef can afford it if $Y - s \ge 0$, i.e., $s \le Y$.

Let's analyze the inequality:
$Y - s \ge X \times \frac{100 - \min(s \times D, 100)}{100}$

Since $X \le 50$ and $D \le 5$, the maximum value of $s \times D$ we might need to consider for a significant discount is when $s$ is relatively small. For instance, if $s=20$, $s \times D = 20 \times 5 = 100$. So, if $s \ge 20$, the discount is $100\%$.
This means we only need to consider $s$ up to a certain point where the discount becomes $100\%$.
If $s \times D \ge 100$, the condition becomes $Y - s \ge 0$, which means $s \le Y$.
So, if a solution exists where the discount is $100\%$, the minimum $s$ would be the smallest $s$ such that $s \times D \ge 100$ and $s \le Y$. The smallest such $s$ is $\lceil \frac{100}{D} \rceil$ (if $D>0$). If this value is $\le Y$, then it's a potential solution.

However, the problem statement implies that the discount is applied based on the number of sessions. It's more natural to think that the discount is $s \times D$ as long as $s \times D \le 100$.
Let's assume the discount is $s \times D$ and the price is $X \times \frac{100 - s \times D}{100}$.
The condition is $Y - s \ge X \times \frac{100 - s \times D}{100}$.
To avoid floating-point issues, we can rewrite this using integer arithmetic:
$(Y - s) \times 100 \ge X \times (100 - s \times D)$
$100Y - 100s \ge 100X - s \times D \times X$
$s \times D \times X - 100s \ge 100X - 100Y$
$s \times (D \times X - 100) \ge 100 \times (X - Y)$

Now, we analyze this inequality based on the term $(D \times X - 100)$:

**Case 1: $D \times X - 100 \le 0$**
If $D \times X - 100 = 0$:
$s \times 0 \ge 100 \times (X - Y)$
$0 \ge 100 \times (X - Y)$
Since we are in the case where $Y < X$, $X - Y > 0$. So, $100 \times (X - Y) > 0$.
The inequality becomes $0 \ge \text{positive number}$, which is impossible.
If $D \times X - 100 < 0$:
$s \times (\text{negative number}) \ge 100 \times (X - Y)$
$s \times (\text{negative number}) \ge \text{positive number}$
This implies $s \le \frac{\text{positive number}}{\text{negative number}}$, which means $s$ must be negative. Since $s$ must be non-negative, this is impossible.

Therefore, if $D \times X \le 100$ and $Y < X$, it's impossible to afford the membership. In this case, the answer is -1.

**Case 2: $D \times X - 100 > 0$**
In this case, $D \times X > 100$.
$s \ge \frac{100 \times (X - Y)}{D \times X - 100}$

Since $s$ must be an integer, the minimum number of sessions is $\lceil \frac{100 \times (X - Y)}{D \times X - 100} \rceil$.
However, we also have the constraint that Chef must be able to afford the trial sessions themselves, i.e., $s \le Y$.
Also, the discount is capped at $100\%$. If $s \times D \ge 100$, the price becomes 0.
The minimum $s$ for $100\%$ discount is $\lceil \frac{100}{D} \rceil$. Let this be $s_{max\_discount}$.
If $s_{max\_discount} \le Y$, then the minimum sessions needed is $\min(\lceil \frac{100 \times (X - Y)}{D \times X - 100} \rceil, s_{max\_discount})$.
However, the formula $s \ge \frac{100 \times (X - Y)}{D \times X - 100}$ implicitly handles the discount cap. If the calculated $s$ leads to $s \times D > 100$, it means the required discount is more than $100\%$, which is not possible. The formula derived from the inequality already considers the effective discount.

Given the constraints $X \le 50$, $Y \le 50$, $D \le 5$:
The maximum value of $Y$ is 50. This means Chef can afford at most 50 trial sessions.
So, we only need to check values of $s$ from 0 up to 50.
We can iterate through $s = 0, 1, 2, \dots, 50$. For each $s$, we check if Chef can afford the membership:
1. Chef must be able to afford the trial sessions: $s \le Y$. If $s > Y$, we can stop searching for larger $s$ because Chef cannot even pay for the sessions.
2. Calculate the discounted price:
   Effective discount percentage = $\min(s \times D, 100)$.
   Discounted price = $X \times \frac{100 - \min(s \times D, 100)}{100}$.
3. Check if Chef can afford it: $Y - s \ge \text{Discounted price}$.
   Using integer arithmetic: $(Y - s) \times 100 \ge X \times (100 - \min(s \times D, 100))$.

The first value of $s$ (starting from 0) that satisfies these conditions is the minimum number of sessions. If no such $s$ is found up to 50, then it's impossible.

Let's re-verify the condition $D \times X \le 100 \implies -1$.
Example: $D=1, X=50, Y=40$.
$D \times X = 1 \times 50 = 50 \le 100$.
$Y < X$ (40 < 50).
According to our logic, this should be -1.
Let's check manually:
$s=0$: Budget=40, Price=50. Cannot afford.
$s=1$: Cost=1, Budget=39. Discount=1%. Price=50 * 0.99 = 49.5. Cannot afford.
$s=2$: Cost=2, Budget=38. Discount=2%. Price=50 * 0.98 = 49. Cannot afford.
...
$s=10$: Cost=10, Budget=30. Discount=10%. Price=50 * 0.90 = 45. Cannot afford.
...
$s=20$: Cost=20, Budget=20. Discount=20%. Price=50 * 0.80 = 40. Cannot afford.
...
$s=30$: Cost=30, Budget=10. Discount=30%. Price=50 * 0.70 = 35. Cannot afford.
...
$s=40$: Cost=40, Budget=0. Discount=40%. Price=50 * 0.60 = 30. Cannot afford.
If $s=50$, cost=50, budget=0. Discount=50%. Price=50 * 0.50 = 25. Cannot afford.
It seems indeed impossible.

The iterative approach is safe and covers all cases due to the small constraints.

**Initial check:**
If $Y \ge X$, output 0.

**Iterative approach:**
For $s$ from 0 to 50:
  If $s > Y$, break (cannot afford trial sessions).
  Calculate effective discount: `discount_percent = min(s * D, 100)`
  Calculate membership cost: `membership_cost_num = X * (100 - discount_percent)`
  Calculate remaining budget: `remaining_budget_num = (Y - s) * 100`
  If `remaining_budget_num >= membership_cost_num`:
    Output $s$ and break.

If the loop finishes without finding a solution, output -1.

Let's trace the provided code with an example:
$D=5, X=40, Y=38$
$Y < X$ (38 < 40), so we proceed.
Loop for $s$:
$s=0$: $s \le Y$ (0 <= 38). `discount_percent = min(0*5, 100) = 0`. `membership_cost_num = 40 * (100 - 0) = 4000`. `remaining_budget_num = (38 - 0) * 100 = 3800`. $3800 \ge 4000$ is false.
$s=1$: $s \le Y$ (1 <= 38). `discount_percent = min(1*5, 100) = 5`. `membership_cost_num = 40 * (100 - 5) = 40 * 95 = 3800`. `remaining_budget_num = (38 - 1) * 100 = 37 * 100 = 3700`. $3700 \ge 3800$ is false.
$s=2$: $s \le Y$ (2 <= 38). `discount_percent = min(2*5, 100) = 10`. `membership_cost_num = 40 * (100 - 10) = 40 * 90 = 3600`. `remaining_budget_num = (38 - 2) * 100 = 36 * 100 = 3600`. $3600 \ge 3600$ is true.
Output $s=2$. This matches our manual trace.

The code's logic:
```cpp
        if (y >= x) { // Base case: already affordable
            std::cout << 0 << "\n";
            continue;
        }

        // The condition d * x <= 100 implies impossibility if y < x.
        // This is derived from s * (D*X - 100) >= 100 * (X - Y).
        // If D*X - 100 <= 0 and X > Y, then LHS is non-positive and RHS is positive, impossible.
        if (d * x <= 100) {
            std::cout << -1 << "\n";
            continue;
        }

        // Iterative search for minimum sessions
        int min_sessions = -1;
        for (int s = 0; s <= 50; ++s) { // Max Y is 50, so max sessions to check is 50
            if (s > y) { // Cannot afford 's' trial sessions
                break;
            }
            // Check if (Y - s) * 100 >= X * (100 - s * D)
            // Using long long to prevent overflow for intermediate calculations
            long long current_budget_after_sessions = (long long)y - s;
            long long membership_cost_numerator = (long long)x * (100 - s * d);

            if (current_budget_after_sessions * 100 >= membership_cost_numerator) {
                min_sessions = s;
                break; // Found the minimum number of sessions
            }
        }
        std::cout << min_sessions << "\n";
```
The code implements the iterative approach correctly. The initial check for $d*x \le 100$ is a valid optimization based on the mathematical derivation. The loop limit of 50 is appropriate because $Y \le 50$.

## Complexity Analysis

- **Time Complexity**:
  The code first performs a constant number of checks ($O(1)$).
  Then, it enters a loop that iterates at most 51 times (from $s=0$ to $s=50$). Inside the loop, all operations are constant time.
  Therefore, the time complexity is $O(51)$, which simplifies to $O(1)$ because the loop limit is a constant independent of the input size $N$ (if we consider $N$ as the number of test cases, the complexity per test case is constant). If we consider the maximum value of $Y$ as a parameter, the complexity is $O(Y_{max})$, where $Y_{max}$ is the maximum possible value of $Y$. Given $Y_{max}=50$, it's effectively $O(1)$.

- **Space Complexity**:
  The solution uses a few integer variables to store input values and loop counters. The amount of memory used does not grow with the input size.
  Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int d, x, y; // D: discount percentage per session, X: membership cost, Y: Chef's budget
        std::cin >> d >> x >> y;

        // If Chef's budget is already enough for the membership without any trial sessions,
        // then 0 sessions are needed.
        if (y >= x) {
            std::cout << 0 << "\n";
            continue;
        }

        // Mathematical observation:
        // Let 's' be the number of trial sessions.
        // Cost of sessions = s. Remaining budget = Y - s.
        // Discount percentage = min(s * D, 100).
        // Discounted price = X * (100 - min(s * D, 100)) / 100.
        // Condition for affordability: Y - s >= X * (100 - min(s * D, 100)) / 100.
        // Using integer arithmetic: (Y - s) * 100 >= X * (100 - min(s * D, 100)).
        //
        // If s * D < 100, the inequality is:
        // 100*Y - 100*s >= 100*X - s*D*X
        // s*D*X - 100*s >= 100*X - 100*Y
        // s * (D*X - 100) >= 100 * (X - Y)
        //
        // If D*X - 100 <= 0 (i.e., D*X <= 100):
        // Since Y < X, (X - Y) > 0, so 100 * (X - Y) > 0.
        // If D*X - 100 == 0, the inequality becomes 0 >= positive number, which is impossible.
        // If D*X - 100 < 0, the inequality becomes s * (negative) >= positive, which implies s must be negative.
        // Since s must be non-negative, this is impossible.
        // Thus, if D*X <= 100 and Y < X, it's impossible to afford the membership.
        if (d * x <= 100) {
            std::cout << -1 << "\n";
            continue;
        }

        // If D*X > 100, then D*X - 100 > 0.
        // We need to find the minimum non-negative integer 's' such that:
        // 1. Chef can afford the trial sessions: s <= Y.
        // 2. Chef can afford the discounted membership: (Y - s) * 100 >= X * (100 - s * D).
        //    (Note: For small s, s*D might be < 100. The formula X*(100 - s*D) implicitly assumes this.
        //     If s*D >= 100, the price becomes 0. The condition becomes Y-s >= 0, i.e., s <= Y.
        //     The iterative approach below correctly handles this by checking up to Y.)
        //
        // Since Y <= 50, the maximum number of trial sessions Chef can afford is 50.
        // We can iterate through possible values of 's' from 0 up to Y (or 50, whichever is smaller).
        int min_sessions = -1;
        for (int s = 0; s <= 50; ++s) { // Iterate up to 50, as Y <= 50
            // If Chef cannot afford 's' trial sessions, he cannot afford more either.
            if (s > y) {
                break;
            }

            // Calculate the membership cost after discount.
            // The discount percentage is s * D. This is capped at 100%.
            // However, the derived inequality (Y - s) * 100 >= X * (100 - s * D)
            // implicitly handles the discount cap because if s*D becomes very large,
            // the term (100 - s*D) becomes very small or negative.
            // The constraint s <= Y ensures we don't overspend on sessions.
            // The maximum effective discount is 100%, meaning price is 0.
            // If s*D >= 100, then X * (100 - s*D) / 100 <= 0.
            // The condition becomes Y - s >= 0, which is s <= Y.
            // So, if s*D >= 100, we just need s <= Y. The smallest such s would be ceil(100/D).
            // The loop correctly checks this by iterating up to Y.

            // We need to check: (Y - s) * 100 >= X * (100 - s * D)
            // Using long long to prevent potential overflow during multiplication.
            long long current_budget_after_sessions = (long long)y - s;
            long long membership_cost_numerator = (long long)x * (100 - s * d);

            // Check if the remaining budget is sufficient for the membership cost.
            // We multiply current_budget_after_sessions by 100 to compare with membership_cost_numerator.
            if (current_budget_after_sessions * 100 >= membership_cost_numerator) {
                min_sessions = s; // Found the minimum number of sessions
                break;            // Exit the loop as we found the minimum
            }
        }
        std::cout << min_sessions << "\n";
    }
    return 0;
}
```