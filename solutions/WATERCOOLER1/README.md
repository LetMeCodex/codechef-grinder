# [The Cooler Dilemma 1 (WATERCOOLER1)](https://www.codechef.com/problems/WATERCOOLER1)
- **Difficulty Rating**: 506
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef is faced with a decision regarding a water cooler. He has two options:
1.  **Buy** a new water cooler for a fixed cost of $Y$ rupees.
2.  **Rent** a water cooler for $X$ rupees per month.

Chef plans to use the water cooler for $M$ months. He wants to choose the option that costs him less. If both options cost the same, Chef prefers to buy the cooler. The task is to determine whether Chef should rent or buy.

## Intuition & Mathematical Observation

The core of the problem is to compare the total cost of renting the cooler for the planned duration with the one-time cost of buying it.

1.  **Cost of Buying**: This is a fixed amount, $Y$ rupees.
2.  **Cost of Renting**: Chef plans to use the cooler for $M$ months, and the rent is $X$ rupees per month. So, the total cost of renting for $M$ months will be $X \times M$ rupees.

Now, we need to compare these two costs:
*   If the total cost of renting ($X \times M$) is **strictly less** than the cost of buying ($Y$), Chef should choose to rent.
*   Otherwise (if $X \times M \ge Y$), Chef should choose to buy. This covers cases where renting is more expensive or equally expensive. The problem statement explicitly mentions that if costs are equal, Chef will buy, which aligns with the "not strictly less than" condition.

Let's consider the constraints: $X, Y, M$ are up to $10^4$.
The product $X \times M$ can be up to $10^4 \times 10^4 = 10^8$. An `int` in C++ typically handles values up to $2 \times 10^9$, so `int` would technically suffice for all variables and the product. However, using `long long` for `X`, `Y`, `M`, and the calculated `total_rent_cost` is a safer practice to prevent potential overflow in similar problems with slightly larger constraints, or if the problem setters decide to increase constraints in the future. The provided solution uses `long long`, which is robust.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program processes $T$ test cases. For each test case, it performs a constant number of operations: reading three integers, one multiplication, one comparison, and one print operation. These operations take $O(1)$ time per test case. Therefore, the total time complexity is $T \times O(1) = O(T)$. Given $T \le 100$, this is extremely efficient.

*   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory for variables like `T`, `X`, `Y`, `M`, and `total_rent_cost`. The memory usage does not depend on the magnitude of the input values or the number of test cases (beyond storing `T` itself). Hence, the space complexity is constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // meaning C++ streams will not synchronize with C standard streams (like printf/scanf).
    // This can significantly speed up I/O operations.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    // This is useful when you have interleaved cin and cout, but for problems where
    // all output is done after all input for a test case, its effect might be less noticeable.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        long long X, Y, M; // Declare X, Y, M as long long to safely handle values up to 10^4
                           // and their product (X*M) which can be up to 10^8.
                           // While int would technically suffice for 10^8, long long is safer
                           // and good practice for products.
        std::cin >> X >> Y >> M; // Read the values of X, Y, and M for the current test case.

        // Calculate the total cost of renting the cooler for M months.
        // The product X * M is stored in a long long variable to prevent potential overflow,
        // especially if constraints were slightly larger.
        long long total_rent_cost = X * M;

        // Check Chef's decision condition: rent only if total_rent_cost is strictly less than Y.
        // If total_rent_cost is less than Y, Chef rents ("YES").
        // Otherwise (if total_rent_cost is greater than or equal to Y), Chef buys ("NO").
        // This covers the tie-breaker condition where if costs are equal, Chef buys.
        if (total_rent_cost < Y) {
            std::cout << "YES\n"; // If true, Chef should rent. Print "YES" followed by a newline.
        } else {
            std::cout << "NO\n"; // Otherwise, Chef should purchase. Print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}
```