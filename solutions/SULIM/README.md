# Sugar Limit (SULIM)
- **Difficulty Rating**: 1111
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ snacks, each with a tastiness value ($A_i$) and a sugar value ($B_i$). We can choose a sugar limit $L$. We can only eat snacks whose sugar content $B_i$ is less than or equal to $L$. Our goal is to choose $L$ such that the total tastiness of the snacks we eat minus the chosen sugar limit $L$ is maximized.

## Intuition & Mathematical Observation

Let $S$ be the set of indices of snacks we choose to eat. The condition for eating snack $i$ is $B_i \le L$.
The total tastiness we get is $\sum_{i \in S} A_i$.
The total sugar we "pay" is $L$.
We want to maximize: $(\sum_{i \in S} A_i) - L$.

Consider a fixed sugar limit $L$. For this $L$, we can eat any snack $i$ where $B_i \le L$. To maximize our satisfaction for this fixed $L$, we should only eat snacks that have a positive tastiness. If a snack $j$ has $B_j \le L$ but $A_j \le 0$, we are better off not eating it, as it would decrease or not change our total satisfaction.
So, for a fixed $L$, the maximum satisfaction is $\sum_{i: B_i \le L \text{ and } A_i > 0} A_i - L$.

Now, we need to find the optimal $L$. What are the possible values of $L$ we need to consider?
If we choose an $L$ that is not equal to any $B_i$, let's say $B_k < L < B_m$ where $B_k$ and $B_m$ are consecutive sugar values in the sorted list of $B_i$.
If we increase $L$ to $B_m$, we might be able to eat more snacks (those with sugar $B_m$). This can only increase or keep the sum of positive tastiness the same. The $L$ value increases, but the potential gain from new snacks might outweigh the increase in $L$.
Conversely, if we decrease $L$ to $B_k$, we might lose some snacks.

The critical observation is that the set of edible snacks only changes when $L$ crosses one of the $B_i$ values. Therefore, the optimal $L$ must be one of the $B_i$ values, or $L=0$.
If we choose $L=0$, we can only eat snacks with $B_i=0$. The satisfaction would be the sum of tastiness of snacks with $B_i=0$ and $A_i>0$.

Let's sort the snacks based on their sugar content ($B_i$) in ascending order.
Suppose the sorted snacks are $(A_1, B_1), (A_2, B_2), \dots, (A_N, B_N)$ where $B_1 \le B_2 \le \dots \le B_N$.

We can iterate through each snack $i$ and consider setting $L = B_i$.
When $L = B_i$, all snacks $j$ such that $B_j \le B_i$ are candidates for being eaten.
To maximize satisfaction for this $L$, we should only eat snacks $j$ where $B_j \le B_i$ AND $A_j > 0$.
The total tastiness from such snacks would be the sum of $A_j$ for all $j \le i$ where $A_j > 0$.
The satisfaction for this choice of $L$ would be $(\sum_{j=1}^i \max(0, A_j)) - B_i$.

We can maintain a running sum of positive tastiness as we iterate through the sorted snacks.
Let `current_tastiness_sum` be the sum of tastiness of snacks encountered so far that have positive tastiness.
When we consider the $i$-th snack (after sorting by sugar), if its tastiness $A_i$ is positive, we add it to `current_tastiness_sum`.
Then, we calculate the potential satisfaction if we set $L = B_i$: `current_tastiness_sum - B_i`.
We keep track of the maximum satisfaction found so far.

We also need to consider the case where $L=0$. If we set $L=0$, we can only eat snacks with $B_i=0$. The satisfaction would be the sum of positive tastiness of snacks with $B_i=0$. Our algorithm naturally handles this if there are snacks with $B_i=0$. If the first snack has $B_1 > 0$, then `current_tastiness_sum` will be 0, and `max_satisfaction` will be initialized to 0. When we consider $L=B_1$, the satisfaction will be `current_tastiness_sum - B_1`. If `current_tastiness_sum` is 0, this will be negative, and `max_satisfaction` will remain 0.

Let's refine the iteration:
1. Sort snacks by sugar content $B_i$.
2. Initialize `max_satisfaction = 0` and `current_tastiness_sum = 0`.
3. Iterate through the sorted snacks from $i=0$ to $N-1$:
    a. If `snacks[i].tastiness > 0`, add `snacks[i].tastiness` to `current_tastiness_sum`.
    b. Calculate potential satisfaction for $L = \text{snacks[i].sugar}$: `current_tastiness_sum - snacks[i].sugar`.
    c. Update `max_satisfaction = max(max_satisfaction, current_tastiness_sum - snacks[i].sugar)`.
4. The final `max_satisfaction` is the answer.

Example:
Snacks: (A, B) = (10, 5), (2, 3), (-4, 8), (7, 3)
Sorted by sugar: (2, 3), (7, 3), (10, 5), (-4, 8)

Initialize `max_satisfaction = 0`, `current_tastiness_sum = 0`.

i=0: Snack (2, 3)
   `tastiness` (2) > 0. `current_tastiness_sum` = 0 + 2 = 2.
   Consider L = 3. Satisfaction = `current_tastiness_sum` - 3 = 2 - 3 = -1.
   `max_satisfaction` = max(0, -1) = 0.

i=1: Snack (7, 3)
   `tastiness` (7) > 0. `current_tastiness_sum` = 2 + 7 = 9.
   Consider L = 3. Satisfaction = `current_tastiness_sum` - 3 = 9 - 3 = 6.
   `max_satisfaction` = max(0, 6) = 6.

i=2: Snack (10, 5)
   `tastiness` (10) > 0. `current_tastiness_sum` = 9 + 10 = 19.
   Consider L = 5. Satisfaction = `current_tastiness_sum` - 5 = 19 - 5 = 14.
   `max_satisfaction` = max(6, 14) = 14.

i=3: Snack (-4, 8)
   `tastiness` (-4) <= 0. `current_tastiness_sum` remains 19.
   Consider L = 8. Satisfaction = `current_tastiness_sum` - 8 = 19 - 8 = 11.
   `max_satisfaction` = max(14, 11) = 14.

Final `max_satisfaction` = 14.

This approach correctly considers all critical values of $L$ (the $B_i$ values) and for each $L$, it implicitly considers only snacks with positive tastiness that are edible. The initial `max_satisfaction = 0` handles the case where no snacks are eaten or all possible combinations result in negative satisfaction.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$
    - Sorting the snacks takes $O(N \log N)$ time.
    - Iterating through the sorted snacks takes $O(N)$ time.
    - Therefore, the dominant factor is sorting.

- **Space Complexity**: $O(N)$
    - We use a vector of structs to store the snacks, which takes $O(N)$ space.
    - If we can modify the input arrays in-place or if the input is given in a way that allows it, the space complexity could be $O(1)$ beyond input storage. However, the provided solution uses a `std::vector<Snack>` which is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

struct Snack {
    int tastiness;
    int sugar;
};

// Custom comparison function to sort snacks by sugar content
bool compareSnacks(const Snack& a, const Snack& b) {
    return a.sugar < b.sugar;
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of snacks
        std::cin >> n;
        
        std::vector<Snack> snacks(n);
        
        // Read tastiness values
        for (int i = 0; i < n; ++i) {
            std::cin >> snacks[i].tastiness;
        }
        // Read sugar values
        for (int i = 0; i < n; ++i) {
            std::cin >> snacks[i].sugar;
        }

        // Sort snacks based on their sugar content in ascending order.
        // This is crucial because the set of edible snacks only changes
        // when the sugar limit L crosses a snack's sugar value.
        std::sort(snacks.begin(), snacks.end(), compareSnacks);

        long long max_satisfaction = 0; // Stores the maximum satisfaction found so far. Initialized to 0, representing the case of eating no snacks.
        long long current_tastiness_sum = 0; // Stores the sum of tastiness of snacks considered so far that have positive tastiness.

        // Iterate through all possible critical values of L.
        // The critical values for L are the sugar values of the snacks (B_i).
        // If we set L = snacks[i].sugar, we can potentially eat all snacks j
        // where snacks[j].sugar <= snacks[i].sugar.
        // To maximize satisfaction for a given L, we only eat snacks with positive tastiness.
        for (int i = 0; i < n; ++i) {
            // If the current snack has positive tastiness, add it to our running sum.
            // We only consider snacks with positive tastiness because if a snack has
            // negative tastiness, we are better off not eating it even if its sugar
            // content is below the limit L.
            if (snacks[i].tastiness > 0) {
                current_tastiness_sum += snacks[i].tastiness;
            }
            
            // Now, consider the sugar limit L to be equal to the sugar content of the current snack.
            // The total tastiness we can get with this L is `current_tastiness_sum`
            // (sum of positive tastiness of snacks with sugar <= snacks[i].sugar).
            // The satisfaction for this L is `current_tastiness_sum` - L.
            long long current_satisfaction = current_tastiness_sum - snacks[i].sugar;
            
            // Update the maximum satisfaction found so far.
            max_satisfaction = std::max(max_satisfaction, current_satisfaction);
        }
        
        // Output the maximum possible satisfaction.
        std::cout << max_satisfaction << "\n";
    }
    return 0;
}
```