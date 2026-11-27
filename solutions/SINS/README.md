# [The Deadly Sin (SINS)](https://www.codechef.com/problems/SINS)
- **Difficulty Rating**: 1372
- **Solved in**: 1 attempt(s)

## Problem Summary

Meliodas and Ban are engaged in a "chocolate war". They start with `X` and `Y` chocolates respectively. The war proceeds in rounds:
1. In each round, the person with fewer chocolates eats as many chocolates as they have from the other's collection. For example, if Meliodas has `X` and Ban has `Y`:
    - If `X > Y`, Meliodas loses `Y` chocolates, resulting in `(X - Y, Y)`.
    - If `Y > X`, Ban loses `X` chocolates, resulting in `(X, Y - X)`.
2. The war stops under two conditions:
    - At least one of them is left with no chocolates.
    - They have the same number of chocolates.

The task is to determine the total number of chocolates remaining when the war stops.

## Intuition & Mathematical Observation

The core of this problem lies in recognizing the operation described: "Whoever has lesser number of chocolates eats as many chocolates as he has from the other's collection." This operation is precisely the *subtractive form* of the Euclidean algorithm for finding the Greatest Common Divisor (GCD).

Let's trace an example:
Suppose Meliodas has `X=5` chocolates and Ban has `Y=3` chocolates.
1. `(5, 3)`: `X > Y`. Meliodas loses 3 chocolates. New state: `(5 - 3, 3) = (2, 3)`.
2. `(2, 3)`: `Y > X`. Ban loses 2 chocolates. New state: `(2, 3 - 2) = (2, 1)`.
3. `(2, 1)`: `X > Y`. Meliodas loses 1 chocolate. New state: `(2 - 1, 1) = (1, 1)`.
4. `(1, 1)`: They have the same number of chocolates. The war stops.
Total chocolates remaining: `1 + 1 = 2`.

Notice that `GCD(5, 3) = 1`. The final state is `(GCD, GCD)`, and the total chocolates are `2 * GCD`.

Let's consider another example: `X=4, Y=8`.
1. `(4, 8)`: `Y > X`. Ban loses 4 chocolates. New state: `(4, 8 - 4) = (4, 4)`.
2. `(4, 4)`: They have the same number of chocolates. The war stops.
Total chocolates remaining: `4 + 4 = 8`.

Notice that `GCD(4, 8) = 4`. Again, the final state is `(GCD, GCD)`, and the total chocolates are `2 * GCD`.

The Euclidean algorithm, when applied subtractively, converges to a state where both numbers are equal to their initial GCD. The problem's stopping condition "they have the same number of chocolates" directly corresponds to this state `(G, G)`, where `G = GCD(X_initial, Y_initial)`. At this point, the total chocolates are `G + G = 2 * G`.

**Edge Case Handling:**
The problem also states that the war stops if "atleast one of them is left with no chocolates".
- If `X=0` and `Y=5` initially: The war stops immediately. Total chocolates = `0 + 5 = 5`.
- If `X=5` and `Y=0` initially: The war stops immediately. Total chocolates = `5 + 0 = 5`.
In these cases, `GCD(0, 5) = 5`. If we applied `2 * GCD`, we would get `10`, which is incorrect.
Therefore, the `2 * GCD` rule only applies if both `X` and `Y` are initially positive. If either `X` or `Y` is zero at the start, the war stops instantly, and the total chocolates are simply `X + Y`.

**Final Logic:**
- If `X == 0` or `Y == 0`, the answer is `X + Y`.
- Otherwise (if `X > 0` and `Y > 0`), the answer is `2 * std::gcd(X, Y)`.

## Complexity Analysis

-   **Time Complexity**: $O(T \cdot \log(\min(X, Y)))$
    -   Reading the number of test cases `T` takes $O(1)$.
    -   For each of the `T` test cases:
        -   Reading `X` and `Y` takes $O(1)$.
        -   The `if` condition and basic arithmetic take $O(1)$.
        -   The `std::gcd(X, Y)` function (which implements the Euclidean algorithm) has a time complexity proportional to the logarithm of the minimum of the two input numbers. For `long long` values up to $10^9$, $\log(10^9)$ is a very small constant (approximately 30 for base 2).
        -   Printing the result takes $O(1)$.
    -   Given $T \le 10^5$ and $X, Y \le 10^9$, the total operations are roughly $10^5 \times \log(10^9)$, which is well within typical time limits.

-   **Space Complexity**: $O(1)$
    -   The solution uses a constant number of variables (`T`, `X`, `Y`, `common_chocolates`) regardless of the input values.
    -   The `std::gcd` function typically uses an iterative approach or a recursive approach with a stack depth proportional to $\log(\min(X, Y))$, which is negligible and considered constant space for practical purposes.

## Solution Code

```cpp
#include <bits/stdc++.h> // As requested by the problem statement

// Using namespace std; as requested by the problem statement
using namespace std;

int main() {
    // Fast I/O setup as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of testcases
    while (T--) { // Loop through each testcase
        long long X, Y; // Use long long for X and Y to handle values up to 10^9
        cin >> X >> Y; // Read the number of chocolates Meliodas and Ban have

        if (X == 0 || Y == 0) {
            // According to the problem statement, the war stops if "atleast one of them is left with no chocolates".
            // If X or Y is initially 0, this condition is met immediately.
            // The total chocolates remaining is simply the sum of their current chocolates.
            cout << X + Y << "\n";
        } else {
            // If both X and Y are positive, the war continues.
            // The process described: "Whoever has lesser number of chocolates eats as many chocolates as he has from the other's collection"
            // This operation (if X > Y, new state is (X-Y, Y); if Y > X, new state is (X, Y-X))
            // is precisely the subtractive form of the Euclidean algorithm for finding the Greatest Common Divisor (GCD).
            //
            // The war continues until "they have the same number of chocolates".
            // The Euclidean algorithm, when applied subtractively, converges to a state where both numbers are equal to their initial GCD.
            // For example: (5, 3) -> (2, 3) -> (2, 1) -> (1, 1). Here GCD(5,3) = 1.
            // (4, 8) -> (4, 4). Here GCD(4,8) = 4.
            //
            // So, if initial X_0, Y_0, they stop when both have GCD(X_0, Y_0) chocolates.
            // The total chocolates remaining will be GCD(X_0, Y_0) + GCD(X_0, Y_0) = 2 * GCD(X_0, Y_0).
            
            long long common_chocolates = std::gcd(X, Y); // Calculate GCD using C++17's std::gcd
            cout << 2 * common_chocolates << "\n"; // Output 2 times the GCD
        }
    }

    return 0; // Indicate successful execution
}
```