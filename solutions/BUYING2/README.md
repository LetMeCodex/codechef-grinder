# [Buying Sweets (BUYING2)](https://www.codechef.com/problems/BUYING2)
- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum number of sweets a customer can buy given a total amount of money `x` and a list of `n` banknotes they possess. The crucial condition is that the customer is considered "adequate" if, for the number of sweets they decide to buy, removing *any single banknote* from their possession would result in an amount of money insufficient to buy that same number of sweets. If no such positive number of sweets can be bought satisfying this condition, we should output -1.

## Intuition & Mathematical Observation

Let $S$ be the total sum of money the customer has (sum of all banknotes).
Let $X$ be the cost of one sweet.
Let $K$ be the number of sweets the customer decides to buy.
Let $a_i$ be the value of the $i$-th banknote.

The problem states two main conditions for the customer to be "adequate" for buying $K$ sweets:

1.  **Sufficient Funds**: The total sum of money must be enough to buy $K$ sweets.
    $S \ge K \times X$

2.  **Inadequacy upon Removal**: If any single banknote $a_i$ is removed, the remaining money is *not* enough to buy $K$ sweets.
    For all $i \in \{1, \dots, n\}$, $S - a_i < K \times X$.

We are looking for the *maximum* positive integer $K$ that satisfies both these conditions.

Let's analyze the second condition: $S - a_i < K \times X$ for all $i$.
This inequality must hold for every banknote. To ensure this, $K \times X$ must be strictly greater than the largest possible value of $S - a_i$.
The largest value of $S - a_i$ occurs when $a_i$ is the smallest banknote.
So, $K \times X > \max_{i} (S - a_i) = S - \min_{i} (a_i)$.

Let $\min\_a = \min_{i} (a_i)$ be the value of the smallest banknote.
The second condition becomes: $K \times X > S - \min\_a$.

Rearranging this inequality to find a lower bound for $K$:
$K > \frac{S - \min\_a}{X}$

Since $K$ must be an integer, the smallest integer $K$ satisfying this is $\lfloor \frac{S - \min\_a}{X} \rfloor + 1$.
Let's call this $K_{\text{min\_req}}$. Note that if $S - \min\_a < 0$, this logic still holds as $K$ must be positive. However, since banknote values are positive, $S \ge \min\_a$, so $S - \min\_a \ge 0$.

Now, let's consider the first condition: $S \ge K \times X$.
This gives an upper bound for $K$:
$K \le \frac{S}{X}$
The maximum integer $K$ satisfying this is $\lfloor \frac{S}{X} \rfloor$.
Let's call this $K_{\text{max\_possible}}$.

We are looking for the largest integer $K$ such that $K_{\text{min\_req}} \le K \le K_{\text{max\_possible}}$.
Such a $K$ exists if and only if $K_{\text{max\_possible}} \ge K_{\text{min\_req}}$.
If this condition holds, the largest possible value for $K$ is $K_{\text{max\_possible}}$.

Additionally, the problem implies that the customer must buy a *positive* number of sweets. So, we must also have $K > 0$. This means $K_{\text{max\_possible}}$ must be greater than 0.

Therefore, the logic is:
1. Calculate the total sum of money $S$.
2. Find the minimum banknote value $\min\_a$.
3. Calculate $K_{\text{max\_possible}} = \lfloor S / X \rfloor$.
4. Calculate $K_{\text{min\_req}} = \lfloor (S - \min\_a) / X \rfloor + 1$.
5. If $K_{\text{max\_possible}} \ge K_{\text{min\_req}}$ AND $K_{\text{max\_possible}} > 0$, then the maximum number of sweets is $K_{\text{max\_possible}}$.
6. Otherwise, it's impossible to satisfy the conditions, and the answer is -1.

Let's verify with an example:
$N=4, X=7$. Banknotes $A = [10, 4, 8, 5]$.
$S = 10 + 4 + 8 + 5 = 27$.
$\min\_a = 4$.

$K_{\text{max\_possible}} = \lfloor 27 / 7 \rfloor = 3$.
$K_{\text{min\_req}} = \lfloor (27 - 4) / 7 \rfloor + 1 = \lfloor 23 / 7 \rfloor + 1 = 3 + 1 = 4$.

Is $K_{\text{max\_possible}} \ge K_{\text{min\_req}}$? Is $3 \ge 4$? No.
Is $K_{\text{max\_possible}} > 0$? Yes, $3 > 0$.
Since the first condition fails, the answer is -1. This matches the sample output.

Another example:
$N=2, X=10$. Banknotes $A = [20, 50]$.
$S = 20 + 50 = 70$.
$\min\_a = 20$.

$K_{\text{max\_possible}} = \lfloor 70 / 10 \rfloor = 7$.
$K_{\text{min\_req}} = \lfloor (70 - 20) / 10 \rfloor + 1 = \lfloor 50 / 10 \rfloor + 1 = 5 + 1 = 6$.

Is $K_{\text{max\_possible}} \ge K_{\text{min\_req}}$? Is $7 \ge 6$? Yes.
Is $K_{\text{max\_possible}} > 0$? Yes, $7 > 0$.
Both conditions are met. The maximum number of sweets is $K_{\text{max\_possible}} = 7$. This matches the sample output.

The original code had a loop that was not necessary for this derived logic. The core of the solution is calculating $S$, $\min\_a$, $K_{\text{max\_possible}}$, and $K_{\text{min\_req}}$ and then comparing them.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading input: $O(N)$ for reading the banknotes.
    -   Calculating total sum: $O(N)$ while reading banknotes.
    -   Finding minimum banknote: $O(N)$ in a separate loop (or can be done during sum calculation).
    -   Calculations for $K_{\text{max\_possible}}$ and $K_{\text{min\_req}}$: $O(1)$.
    -   Comparison and output: $O(1)$.
    The dominant factor is reading and processing the banknotes. Therefore, the total time complexity is $O(N)$ per test case.

-   **Space Complexity**:
    -   Storing the banknotes: $O(N)$ for the `std::vector<long long> a`.
    -   Other variables: $O(1)$.
    The space complexity is $O(N)$ per test case due to storing the banknotes. If we can calculate the sum and minimum without storing all banknotes (e.g., by processing them as they are read), the space complexity could be reduced to $O(1)$. However, the provided solution stores the vector.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of banknotes
        long long x; // Cost of one sweet
        std::cin >> n >> x;

        std::vector<long long> a(n); // Values of banknotes
        long long total_sum = 0;
        long long min_a = -1; // Initialize min_a to a value that will be updated by the first banknote

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            total_sum += a[i];
            // Update minimum banknote value
            if (min_a == -1 || a[i] < min_a) {
                min_a = a[i];
            }
        }

        // Calculate the maximum possible number of sweets the customer can afford
        // if there were no "adequacy" condition.
        // K_max_possible = floor(total_sum / x)
        long long k_max_possible = total_sum / x;

        // Calculate the minimum number of sweets required to satisfy the "adequacy" condition.
        // The condition is: for all i, total_sum - a[i] < K * x
        // This implies K * x > total_sum - min_a
        // So, K > (total_sum - min_a) / x
        // The smallest integer K satisfying this is floor((total_sum - min_a) / x) + 1.
        long long k_min_req;
        if (total_sum - min_a < 0) { // This case should not happen with positive banknote values
            k_min_req = 1; // If S - min_a is negative, K > negative value, smallest positive K is 1.
        } else {
            k_min_req = (total_sum - min_a) / x + 1;
        }

        // We need to find the largest K such that k_min_req <= K <= k_max_possible.
        // Such a K exists if k_max_possible >= k_min_req.
        // Also, K must be a positive number of sweets.
        if (k_max_possible >= k_min_req && k_max_possible > 0) {
            // If a valid K exists, the largest possible is k_max_possible.
            std::cout << k_max_possible << "\n";
        } else {
            // Otherwise, it's impossible to satisfy the conditions.
            std::cout << -1 << "\n";
        }
    }
    return 0;
}
```