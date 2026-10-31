# [Chef and Coupon (COUPON2)](https://www.codechef.com/problems/COUPON2)
- **Difficulty Rating**: 1222
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy groceries on two different days. On each day, Chef buys three items. The prices of these items are given for Day 1 ($A_1, A_2, A_3$) and Day 2 ($B_1, B_2, B_3$). There's a delivery charge $D$ for each day. Chef can choose to buy a coupon for $C$ which, if bought, waives the delivery charge for both days if the total cost of items on that day is strictly less than 150. Chef wants to know if buying the coupon will result in a strictly lower total cost compared to not buying it.

## Intuition & Mathematical Observation
The problem asks us to compare two scenarios:
1.  **Not buying the coupon**: Chef pays the sum of all item prices on both days plus the delivery charge for each day.
2.  **Buying the coupon**: Chef pays the sum of all item prices on both days, the price of the coupon, and potentially the delivery charges for each day if the condition for waiving the charge is not met.

Let's break down the costs for each scenario:

**Scenario 1: Not buying the coupon**
*   Total cost of items on Day 1: $S_1 = A_1 + A_2 + A_3$
*   Total cost of items on Day 2: $S_2 = B_1 + B_2 + B_3$
*   Delivery charge for Day 1: $D$
*   Delivery charge for Day 2: $D$
*   Total cost without coupon = $S_1 + S_2 + D + D = S_1 + S_2 + 2D$

**Scenario 2: Buying the coupon**
*   Total cost of items on Day 1: $S_1 = A_1 + A_2 + A_3$
*   Total cost of items on Day 2: $S_2 = B_1 + B_2 + B_3$
*   Cost of coupon: $C$
*   Delivery charge for Day 1: $D$ if $S_1 < 150$, otherwise $0$.
*   Delivery charge for Day 2: $D$ if $S_2 < 150$, otherwise $0$.

So, the total cost with the coupon can be calculated as:
$Cost_{with\_coupon} = S_1 + S_2 + C + (\text{delivery on Day 1 if } S_1 < 150) + (\text{delivery on Day 2 if } S_2 < 150)$

We need to determine if $Cost_{with\_coupon} < Cost_{without\_coupon}$.

Let's express the delivery charges more formally:
*   Delivery on Day 1 with coupon: $D_1 = (S_1 < 150) ? D : 0$
*   Delivery on Day 2 with coupon: $D_2 = (S_2 < 150) ? D : 0$

Then, $Cost_{with\_coupon} = S_1 + S_2 + C + D_1 + D_2$.

The condition to print "YES" is:
$S_1 + S_2 + C + D_1 + D_2 < S_1 + S_2 + 2D$

We can simplify this inequality by canceling out $S_1 + S_2$ from both sides:
$C + D_1 + D_2 < 2D$

This means Chef should buy the coupon if the cost of the coupon plus the delivery charges that are *not* waived is strictly less than the total delivery charges Chef would have paid without the coupon (which is $2D$).

The logic is straightforward: calculate the total cost in both scenarios and compare them. The code implements this direct comparison.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations and comparisons for each test case. The input size for each test case is constant (a few integers). Therefore, the time complexity per test case is constant. If there are $T$ test cases, the total time complexity is $O(T)$. However, when analyzing the complexity of the algorithm for a single test case, it is $O(1)$.

- **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the input values and intermediate calculations. The memory usage does not grow with the input size. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int D, C; // Delivery charge and coupon price
    cin >> D >> C;

    int A1, A2, A3; // Item prices for Day 1
    cin >> A1 >> A2 >> A3;
    int S1 = A1 + A2 + A3; // Sum of item prices for Day 1

    int B1, B2, B3; // Item prices for Day 2
    cin >> B1 >> B2 >> B3;
    int S2 = B1 + B2 + B3; // Sum of item prices for Day 2

    // Calculate total cost without buying the coupon
    // Chef pays for items on Day 1, delivery for Day 1, items on Day 2, delivery for Day 2
    int cost_without_coupon = S1 + S2 + (2 * D);

    // Calculate total cost if Chef buys the coupon
    // Start with item costs and the coupon price
    int cost_with_coupon = S1 + S2 + C;

    // Check delivery charge for Day 1 with coupon
    // If sum of items is less than 150, delivery charge applies
    if (S1 < 150) {
        cost_with_coupon += D;
    }

    // Check delivery charge for Day 2 with coupon
    // If sum of items is less than 150, delivery charge applies
    if (S2 < 150) {
        cost_with_coupon += D;
    }

    // Compare the two costs and print the result
    // Chef buys the coupon only if it costs strictly less
    if (cost_with_coupon < cost_without_coupon) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```