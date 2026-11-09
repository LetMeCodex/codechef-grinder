# [Good Pairs (EQPAIR)](https://www.codechef.com/problems/EQPAIR)
- **Difficulty Rating**: 1248
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to count the number of "good pairs" in a given array `A` of `N` integers. A pair `(i, j)` is considered "good" if `i < j` and `A[i] == A[j]`. We need to output the total count of such good pairs.

**Example:**
If `A = [1, 2, 1, 3, 2]`:
- `A[0] = 1`, `A[2] = 1` -> Pair `(0, 2)` is good.
- `A[1] = 2`, `A[4] = 2` -> Pair `(1, 4)` is good.
Total good pairs = 2.

## Intuition & Mathematical Observation

The core of the problem lies in identifying pairs of elements that have the same value. The specific indices `i` and `j` only matter in that `i` must be less than `j`. However, if we have multiple occurrences of the *same value*, say `X`, at different indices, any two distinct indices where `X` appears will form a good pair.

Consider a number `X` that appears `k` times in the array. Let these occurrences be at indices `idx_1, idx_2, ..., idx_k`. If we pick any two distinct indices from this set, say `idx_a` and `idx_b`, then `A[idx_a]` will be equal to `A[idx_b]` (both are `X`). Since the problem statement implies `i < j`, if we pick two distinct indices, one will naturally be smaller than the other, satisfying the `i < j` condition. The number of ways to choose 2 distinct indices from `k` available indices is given by the combination formula "k choose 2", which is:
$$ \binom{k}{2} = \frac{k \times (k - 1)}{2} $$

So, the strategy is:
1.  Count the frequency of each distinct number in the input array.
2.  For each distinct number, if its frequency (let's call it `k`) is 2 or more, calculate the number of good pairs it can form using the formula `k * (k - 1) / 2`.
3.  Sum up these calculated values for all distinct numbers.

An `unordered_map` (or `std::map`) is an efficient data structure to store and retrieve frequencies of numbers.

**Example Walkthrough:**
`A = [1, 2, 1, 3, 2]`
1.  **Frequency Count:**
    - `1`: appears 2 times
    - `2`: appears 2 times
    - `3`: appears 1 time
2.  **Calculate Pairs:**
    - For number `1`: frequency `k = 2`. Pairs = `2 * (2 - 1) / 2 = 2 * 1 / 2 = 1`.
    - For number `2`: frequency `k = 2`. Pairs = `2 * (2 - 1) / 2 = 2 * 1 / 2 = 1`.
    - For number `3`: frequency `k = 1`. Since `k < 2`, it cannot form any good pairs.
3.  **Total Good Pairs:** `1 + 1 = 2`.

It's important to use `long long` for the total count and intermediate calculations involving `k * (k - 1)` to prevent integer overflow, as `N` can be up to $10^5$, making `k * (k - 1) / 2` potentially as large as $(10^5 \times (10^5 - 1)) / 2 \approx 5 \times 10^9$, which exceeds the capacity of a 32-bit integer.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    1.  **Reading input and frequency counting**: We iterate through the `N` elements of the array. For each element, we perform an insertion or update operation in an `unordered_map`. On average, `unordered_map` operations (insertion, access) take $O(1)$ time. In the worst case (due to hash collisions), they can take $O(N)$ time, but this is rare with good hash functions. Thus, this step is $O(N)$ on average.
    2.  **Calculating pairs**: We then iterate through the `unordered_map`. If there are `D` distinct elements in the array, this loop runs `D` times. `D` can be at most `N`. Inside the loop, operations are $O(1)$. So, this step is $O(D)$, which is at most $O(N)$.
    Combining these, the overall average time complexity is $O(N)$.

-   **Space Complexity**: $O(D)$
    The `unordered_map` stores the frequency of each distinct element. In the worst case, all `N` elements in the input array are distinct, so the map will store `N` entries. Each entry takes constant space. Therefore, the space complexity is proportional to the number of distinct elements `D`, which is at most $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <unordered_map> // For efficient frequency counting

void solve() {
    int N;
    std::cin >> N;
    std::unordered_map<int, int> counts; // Map to store frequencies of numbers
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i;
        counts[A_i]++; // Increment frequency for A_i
    }

    long long total_good_pairs = 0;
    // Iterate through the map to calculate pairs for each distinct number
    for (auto const& pair_entry : counts) {
        // pair_entry.first is the number, pair_entry.second is its count
        long long count = pair_entry.second; // Use long long for count to avoid overflow in multiplication
        if (count >= 2) {
            // If a number appears 'count' times, the number of ways to choose 2 elements
            // from these 'count' occurrences is count * (count - 1) / 2.
            total_good_pairs += count * (count - 1) / 2;
        }
    }
    std::cout << total_good_pairs << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}

```