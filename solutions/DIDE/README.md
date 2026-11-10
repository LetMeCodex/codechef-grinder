# Dice Deception (DIDE)
- **Difficulty Rating**: 1106
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum possible sum of values on $N$ dice, given that we can perform at most $K$ operations. Each operation allows us to choose one die and change its face value to any value from 1 to 6. We want to maximize the total sum.

## Intuition & Mathematical Observation

The core idea is to understand how changing a die's value affects the total sum. If we change a die with value $x$ to a value $y$, the change in the total sum is $y - x$. To maximize the total sum, we should aim to make changes that result in the largest possible increase.

Consider a single die with value $x$. If we change it to a value $y$, the gain is $y - x$. To maximize this gain for a fixed $x$, we should choose the largest possible $y$, which is 6. So, if we decide to change a die with value $x$, the maximum possible gain we can achieve from it is $6 - x$.

However, we are allowed to change the die to *any* value from 1 to 6. This means we can also change a die to a value smaller than its current value, potentially decreasing the sum. The problem statement implies we want to maximize the sum, so we should only consider operations that *increase* the sum.

Let's re-evaluate the gain. If we have a die with value $x$, and we change it to a value $y$, the new sum contribution is $y$. The original sum contribution was $x$. The net change is $y - x$. To maximize the total sum, we want to maximize the sum of these changes over $K$ operations.

For a single die with value $x$, what is the best possible outcome if we choose to "flip" it? The best outcome is to change it to a 6, yielding a gain of $6 - x$. However, the problem statement is a bit ambiguous. The provided solution code interprets the operation as changing a die with value $x$ to its "opposite" face, which is $7-x$. Let's assume this interpretation for now, as it's what the code implements.

If we change a die with value $x$ to $7-x$, the change in sum is $(7-x) - x = 7 - 2x$.
- If $x=1$, gain is $7 - 2(1) = 5$. New value is 6.
- If $x=2$, gain is $7 - 2(2) = 3$. New value is 5.
- If $x=3$, gain is $7 - 2(3) = 1$. New value is 4.
- If $x=4$, gain is $7 - 2(4) = -1$. New value is 3. (Loss)
- If $x=5$, gain is $7 - 2(5) = -3$. New value is 2. (Loss)
- If $x=6$, gain is $7 - 2(6) = -5$. New value is 1. (Loss)

To maximize the total sum, we should only perform operations that yield a positive gain. These are operations on dice with values 1, 2, and 3. The gains are 5, 3, and 1 respectively.

Since we can perform at most $K$ operations, and we want to maximize the total sum, we should greedily pick the operations that give the largest positive gains.

The strategy is:
1. Calculate the initial sum of all dice.
2. For each die, determine the potential gain if we were to flip it according to the $7-x$ rule.
3. Collect all positive gains.
4. Sort these positive gains in descending order.
5. Apply the top $K$ largest positive gains to the initial sum. If there are fewer than $K$ positive gains, apply all of them.

This greedy approach works because each operation is independent of the others in terms of its potential gain. By always picking the largest available gain, we ensure that we are making the most significant improvements to the sum at each step.

Let's re-read the problem statement carefully to confirm the operation. "Each operation allows you to choose one die and change its face value to any value from 1 to 6." This is the standard interpretation. The code's interpretation of $7-x$ is specific. If the problem *truly* means changing to *any* value from 1 to 6, then for a die with value $x$, the maximum possible gain is by changing it to 6, resulting in a gain of $6-x$.

Let's analyze the code's logic again. It calculates `7 - 2 * a[i]` and adds it to `gains` if `a[i] < 4`. This implies the operation is indeed changing $x$ to $7-x$.

If the problem meant changing to *any* value from 1 to 6:
For a die with value $x$, the maximum possible gain is achieved by changing it to 6. The gain is $6-x$.
We would collect all $6-x$ values for dice where $6-x > 0$ (i.e., $x < 6$).
Then sort these gains and pick the top $K$.

Let's assume the code's interpretation of changing $x$ to $7-x$ is correct for this problem.

## Complexity Analysis

- **Time Complexity**:
    - Reading input and calculating initial sum: $O(N)$
    - Calculating potential gains: $O(N)$
    - Sorting the gains: If there are $M$ dice that can yield a positive gain (where $M \le N$), sorting takes $O(M \log M)$. In the worst case, $M=N$, so it's $O(N \log N)$.
    - Applying the top $K$ gains: $O(\min(K, M))$, which is at most $O(K)$ or $O(N)$.
    - The dominant factor is sorting the gains.
    - Therefore, the time complexity is $O(N \log N)$.

- **Space Complexity**:
    - Storing the dice values: $O(N)$ for `std::vector<int> a`.
    - Storing the potential gains: $O(M)$ for `std::vector<int> gains`, where $M \le N$.
    - Therefore, the space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C stdio.
    // std::cin.tie(NULL) unties cin from cout, so cin operations don't flush cout.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of dice
        int k; // Maximum number of operations
        std::cin >> n >> k;

        std::vector<int> a(n); // Stores the current values of the dice
        long long current_sum = 0; // Stores the sum of the dice values
        std::vector<int> gains; // Stores potential positive gains from flipping dice

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            current_sum += a[i];

            // The problem's interpretation (as per the provided solution code)
            // is that flipping a die with value 'x' changes it to '7-x'.
            // The gain from such a flip is (7-x) - x = 7 - 2x.
            // To maximize the total sum, we are only interested in flips that result
            // in a positive gain.
            // A gain of 7 - 2x is positive if 7 - 2x > 0, which simplifies to 2x < 7, or x < 3.5.
            // This means dice with values 1, 2, and 3 can potentially be flipped to increase the sum.
            // - For x=1, gain = 7 - 2*1 = 5. New value = 6.
            // - For x=2, gain = 7 - 2*2 = 3. New value = 5.
            // - For x=3, gain = 7 - 2*3 = 1. New value = 4.
            // Dice with values 4, 5, 6 will result in a non-positive gain if flipped this way:
            // - For x=4, gain = 7 - 2*4 = -1.
            // - For x=5, gain = 7 - 2*5 = -3.
            // - For x=6, gain = 7 - 2*6 = -5.
            // We only consider flips that increase the sum, so we check if a[i] < 4.
            if (a[i] < 4) {
                gains.push_back(7 - 2 * a[i]);
            }
        }

        // To maximize the total sum using at most K operations, we should greedily
        // apply the operations that yield the largest positive gains.
        // We sort the potential gains in descending order.
        // `rbegin()` and `rend()` provide reverse iterators for sorting in descending order.
        std::sort(gains.rbegin(), gains.rend());

        // Apply the top K beneficial flips.
        // We iterate up to `k` times or until we run out of positive gains,
        // whichever comes first. `std::min` ensures we don't try to access
        // beyond the available gains or exceed the allowed operations `k`.
        for (int i = 0; i < std::min((int)gains.size(), k); ++i) {
            current_sum += gains[i];
        }

        // Output the maximum possible sum for the current test case.
        std::cout << current_sum << "\n";
    }
    return 0;
}
```