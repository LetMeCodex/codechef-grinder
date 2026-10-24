# [Sabotage (SBTG)](https://www.codechef.com/problems/SBTG)
- **Difficulty Rating**: 984
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has an initial score `X` and competes against `N` opponents, whose scores are given in an array `A`. Chef can perform at most `K` sabotage operations. Each sabotage operation has two effects:
1. Chef's score increases by `100`.
2. The score of one chosen opponent is reduced to `0`.

Chef wants to minimize his final rank. The rank is defined as `1 + (number of opponents with a score strictly greater than Chef's final score)`.

## Intuition & Mathematical Observation

The problem asks us to minimize Chef's rank by strategically using up to `K` sabotage operations. Let's break down the optimal strategy:

1.  **Optimal Sabotage Target**: If we decide to perform `k` sabotage operations (where `0 <= k <= K`), we should always choose to sabotage the `k` opponents with the *highest* scores. This is because reducing a higher score to `0` is more effective in ensuring it falls below Chef's potential score, thereby minimizing the count of opponents with scores greater than Chef's. If an opponent's score is already `0` or less than Chef's score, sabotaging them would be pointless. By targeting the strongest opponents, we maximize the impact of our operations.

2.  **Chef's Score Calculation**: If we perform `k` sabotage operations, Chef's score will become `X + k * 100`. This is a direct application of the problem rules.

3.  **Iterating Through Possibilities**: Since we can perform *at most* `K` operations, we must consider all possible numbers of operations, `k`, ranging from `0` to `K`. For each `k`, we will calculate Chef's score and the resulting number of opponents with higher scores, then take the minimum rank found across all `k`.

4.  **Efficient Counting with Sorting**:
    *   To easily identify and "sabotage" the `k` strongest opponents, we should first sort the array `A` of opponent scores in **descending order**.
    *   If we perform `k` operations, the first `k` opponents in the sorted array (`A[0]` to `A[k-1]`) are considered sabotaged. Their scores are effectively `0` and will not be greater than Chef's score (unless Chef's score is negative, which is not possible here as `X >= 0` and `k*100 >= 0`).
    *   We then only need to consider the remaining `N-k` opponents (`A[k]` to `A[N-1]`). For these opponents, we count how many of them have a score strictly greater than Chef's current score (`X + k * 100`).
    *   Since the sub-array `A[k]` to `A[N-1]` is also sorted in descending order, we can efficiently find the count using `std::lower_bound`. `std::lower_bound` with `std::greater<int>()` comparator will find the first element in the range that is less than or equal to Chef's score. All elements before this found element in the range are strictly greater than Chef's score. The number of such elements can be found using `std::distance`.

By combining these observations, the algorithm is:
1. Read `N, X, K` and the array `A`.
2. Sort `A` in descending order.
3. Initialize `min_rank` to a very large value (e.g., `N + 1`).
4. Loop `k` from `0` to `K`:
    a. Calculate Chef's current score: `current_X = X + k * 100`.
    b. Identify the range of unsabotaged opponents: `A[k]` to `A[N-1]`.
    c. Use `std::lower_bound` on this range (with `std::greater<int>()` comparator) to find the first opponent whose score is less than or equal to `current_X`.
    d. The number of opponents with scores strictly greater than `current_X` in this range is the distance from `A[k]` to the iterator returned by `lower_bound`. Let this be `current_R`.
    e. Update `min_rank = std::min(min_rank, current_R + 1)`.
5. Print `min_rank`.

## Complexity Analysis

*   **Time Complexity**:
    *   Sorting the array `A` takes $O(N \log N)$ time.
    *   The loop iterates `K+1` times (for `k` from `0` to `K`).
    *   Inside the loop, `std::lower_bound` operates on a sub-array of size at most `N`, taking $O(\log N)$ time. `std::distance` and other arithmetic operations are $O(1)$.
    *   Therefore, the loop contributes $O(K \log N)$ time.
    *   The total time complexity is $O(N \log N + K \log N)$.
    *   Given $N, K \le 1000$, this is roughly $1000 \log 1000 + 1000 \log 1000 \approx 1000 \times 10 + 1000 \times 10 = 20000$ operations, which is very efficient and well within typical time limits.

*   **Space Complexity**:
    *   Storing the input array `A` requires $O(N)$ space.
    *   `std::sort` typically uses $O(\log N)$ auxiliary space (e.g., for introsort, which is common for `std::sort`).
    *   All other variables use $O(1)$ space.
    *   The total space complexity is dominated by the input array, resulting in $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort, std::lower_bound, std::min
#include <functional> // For std::greater<int>
#include <iterator>   // For std::distance

void solve() {
    int N, X, K;
    std::cin >> N >> X >> K;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    // Sort A in descending order.
    // This allows us to easily "sabotage" the K strongest opponents
    // by considering elements from index k onwards in the sorted array.
    std::sort(A.begin(), A.end(), std::greater<int>());

    int min_rank = N + 1; // Initialize with the worst possible rank (all N opponents have higher score + 1)

    // Iterate through all possible number of sabotage operations, from 0 to K.
    for (int k = 0; k <= K; ++k) {
        // Calculate Chef's score after k operations.
        // X can go up to 10000 + 500*100 = 60000, which fits comfortably in an int.
        int current_X = X + k * 100; 
        
        // current_R will store the count of participants with score > current_X.
        int current_R = 0;
        
        // The first k participants (A[0]...A[k-1] in the sorted array) are considered sabotaged.
        // Their scores are effectively 0 and won't be greater than current_X.
        // We only need to consider participants from index k to N-1.
        
        // std::lower_bound with std::greater<int>() comparator finds the first element
        // in the range [A.begin() + k, A.end()) that is less than or equal to current_X.
        // All elements before this iterator in the specified range are strictly greater than current_X.
        auto it = std::lower_bound(A.begin() + k, A.end(), current_X, std::greater<int>());
        
        // The number of such elements is the distance from the start of the considered range to 'it'.
        current_R = std::distance(A.begin() + k, it);
        
        // Update the minimum rank found so far.
        min_rank = std::min(min_rank, current_R + 1);
    }
    std::cout << min_rank << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
```