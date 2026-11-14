# [Chef and Mean   (CHFM)](https://www.codechef.com/problems/CHFM)
- **Difficulty Rating**: 1229
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find if it's possible to remove exactly one coin from a given collection of $N$ coins such that the average value of the remaining $N-1$ coins is the same as the average value of the original $N$ coins. If it's possible, we should output the 1-based index of the coin to be removed. If multiple such coins exist, we should output the one with the smallest index. If no such coin exists, output "Impossible".

## Intuition & Mathematical Observation

Let's denote the initial number of coins as $N$ and their total sum as $Sum$.
The initial mean (average) value of the coins is $Mean_{initial} = \frac{Sum}{N}$.

Suppose we remove a coin with value $A_i$ (where $A_i$ is the value of the coin at index $i$).
After removing this coin:
- The number of remaining coins becomes $N-1$.
- The sum of the remaining coins becomes $Sum - A_i$.
- The new mean (average) value of the remaining coins is $Mean_{new} = \frac{Sum - A_i}{N - 1}$.

According to the problem statement, we want $Mean_{new}$ to be equal to $Mean_{initial}$.
So, we set up the equation:
$\frac{Sum - A_i}{N - 1} = \frac{Sum}{N}$

Now, let's solve this equation for $A_i$:
1. Cross-multiply:
   $N \cdot (Sum - A_i) = Sum \cdot (N - 1)$
2. Distribute terms:
   $N \cdot Sum - N \cdot A_i = N \cdot Sum - Sum$
3. Subtract $N \cdot Sum$ from both sides:
   $-N \cdot A_i = -Sum$
4. Multiply by -1:
   $N \cdot A_i = Sum$
5. Isolate $A_i$:
   $A_i = \frac{Sum}{N}$

This crucial mathematical observation tells us that for a coin $A_i$ to satisfy the condition, its value must be exactly equal to the original mean of all coins.

Since all coin values $A_i$ are integers, it implies two important conditions:
1. The total sum $Sum$ must be perfectly divisible by $N$. If $Sum \pmod N \neq 0$, then $\frac{Sum}{N}$ would not be an integer. In such a case, no integer coin value $A_i$ can be equal to $\frac{Sum}{N}$, making it "Impossible".
2. If $Sum$ is divisible by $N$, we calculate the `required_value = Sum / N`. Then, we need to find a coin $A_i$ in the original collection whose value is exactly `required_value`.

The problem asks for the coin with the *smallest index* if multiple such coins exist. Therefore, our strategy is:
1. Calculate the total `sum` of all coin values.
2. Check if `sum` is divisible by `N`.
   - If `sum % N != 0`, then it's "Impossible".
   - If `sum % N == 0`, calculate `required_value = sum / N`.
3. Iterate through the coins from index $0$ to $N-1$. The first coin $A_i$ we encounter whose value is equal to `required_value` is our answer. We output its 1-based index ($i+1$) and stop.
4. If we iterate through all coins and don't find any coin with `required_value`, then it's "Impossible".

## Complexity Analysis

-   **Time Complexity**:
    -   Reading $N$ coin values and calculating their `sum`: This takes $O(N)$ time.
    -   Checking divisibility and iterating through the coins to find the `required_value`: In the worst case, we might have to iterate through all $N$ coins. This takes $O(N)$ time.
    -   Since these operations are sequential, the total time complexity for a single test case is $O(N)$.
    -   Given $T$ test cases, the overall time complexity is $O(T \cdot N)$.
    -   With $N$ up to $10^5$ and $T$ up to $10$, $T \cdot N$ would be $10 \cdot 10^5 = 10^6$, which is well within typical time limits.

-   **Space Complexity**:
    -   We store all $N$ coin values in a `std::vector<long long> a`. This requires $O(N)$ space.
    -   Other variables like `sum`, `n`, `t`, `best_coin_index`, `required_value` use constant space, $O(1)$.
    -   Therefore, the total space complexity is $O(N)$ per test case.
    -   With $N$ up to $10^5$, storing $10^5$ `long long` integers is feasible (approx $10^5 \times 8$ bytes = 0.8 MB).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed for sum, but useful for other reductions
#include <algorithm> // Not strictly needed for this problem

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the number of coins
        std::vector<long long> a(n); // Vector to store coin values
        long long sum = 0; // Variable to store the total sum of coin values

        // Read coin values and calculate their sum
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            sum += a[i];
        }

        int best_coin_index = -1; // Initialize with -1 to indicate no coin found yet

        // The condition for the mean to remain the same after removing coin i is:
        // (Sum - A_i) / (N - 1) = Sum / N
        // N * (Sum - A_i) = Sum * (N - 1)
        // N * Sum - N * A_i = N * Sum - Sum
        // -N * A_i = -Sum
        // N * A_i = Sum
        // A_i = Sum / N
        // This means the value of the coin to be removed must be equal to the original mean.
        // Since coin values are integers, Sum must be perfectly divisible by N.

        // First, check if Sum is divisible by N.
        if (sum % n == 0) {
            long long required_value = sum / n; // Calculate the target value for the coin to be removed
            
            // Iterate through the coins to find the first one that matches the required_value
            for (int i = 0; i < n; ++i) {
                if (a[i] == required_value) {
                    best_coin_index = i + 1; // Store 1-based index
                    break; // Found the smallest index, so we can stop searching
                }
            }
        }

        // Output the result
        if (best_coin_index != -1) {
            std::cout << best_coin_index << "\n";
        } else {
            std::cout << "Impossible\n";
        }
    }
    return 0;
}

```