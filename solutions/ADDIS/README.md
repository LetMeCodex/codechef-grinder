# [Additive Dissonance (ADDIS)](https://www.codechef.com/problems/ADDIS)
- **Difficulty Rating**: 1064
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to construct a new array $B$ of size $N$ such that for each element $A_i$ in the original array, there exists an integer $X_i \neq 0$ where $A_i = B_i - X_i$ or $A_i = B_i + X_i$. This is equivalent to saying that for each $A_i$, $B_i$ must be either $A_i - X_i$ or $A_i + X_i$ for some non-zero $X_i$. The goal is to minimize the maximum frequency of any element in the constructed array $B$.

## Intuition & Mathematical Observation

Let's consider an element $V$ that appears $k$ times in the array $A$. For each of these $k$ occurrences, say $A_i = V$, we must choose a $B_i$ such that $B_i = V - X_i$ or $B_i = V + X_i$ for some $X_i \neq 0$.

We want to minimize the maximum frequency of any element in $B$. This means we should try to distribute the $k$ occurrences of $V$ in $A$ into as many distinct values in $B$ as possible.

Consider a single value $V$ that appears $k$ times in $A$. We can choose a single non-zero integer $X$. Then for each occurrence of $V$ in $A$, we can map it to either $V - X$ or $V + X$ in $B$. To minimize the frequency of any single value derived from $V$, we should split the $k$ occurrences as evenly as possible between $V - X$ and $V + X$. The most balanced split would be $\lceil k/2 \rceil$ occurrences mapped to one value and $\lfloor k/2 \rfloor$ occurrences mapped to the other. In either case, the maximum frequency contributed by the original $k$ occurrences of $V$ to any single value in $B$ will be $\lceil k/2 \rceil$.

Now, we need to consider if different values in $A$ can map to the same value in $B$. Suppose $V_1$ and $V_2$ are two distinct values in $A$. If we choose a single $X$ for all transformations, we could have $V_1 - X = V_2 + X$, which implies $V_1 - V_2 = 2X$. This means if the difference between two values in $A$ is $2X$, they could potentially map to the same value in $B$.

However, the problem statement allows us to choose a *different* $X_i$ for *each* $A_i$. This is a crucial observation. If we can choose $X_i$ independently for each $A_i$, we can ensure that for any two distinct values $V_1, V_2$ in $A$, and any two distinct occurrences of $V_1$ and $V_2$ (say $A_i = V_1$ and $A_j = V_2$), we can choose $X_i$ and $X_j$ such that $A_i - X_i \neq A_j - X_j$, $A_i - X_i \neq A_j + X_j$, $A_i + X_i \neq A_j - X_j$, and $A_i + X_i \neq A_j + X_j$.

A simpler interpretation that leads to the correct solution is to consider that we can pick *one* non-zero integer $X$ that is used for all transformations. The problem statement says "for each element $A_i$ in the original array, there exists an integer $X_i \neq 0$". This implies that $X_i$ can be different for each $A_i$. However, if we can choose a single $X$ that works for all transformations, we can simplify the problem.

Let's re-read carefully: "for each element $A_i$ in the original array, there exists an integer $X_i \neq 0$ where $A_i = B_i - X_i$ or $A_i = B_i + X_i$". This means for each $A_i$, we pick *some* $X_i \neq 0$.

Consider a value $V$ that appears $k$ times in $A$. We want to map these $k$ occurrences to values in $B$. If we can choose $X_i$ independently for each occurrence, we can ensure that no two occurrences of $V$ map to the same value in $B$, and no occurrence of $V$ maps to the same value as an occurrence of a different value $V'$ from $A$. This would mean each of the $N$ elements in $A$ maps to a unique element in $B$, resulting in a maximum frequency of 1. However, this is not always possible if the range of values is limited.

The key insight comes from realizing that we can choose *one* non-zero integer $X$ and use it for all transformations. If we can do this, then for each $A_i$, $B_i$ will be either $A_i - X$ or $A_i + X$.
If a value $V$ appears $k$ times in $A$, these $k$ occurrences can be transformed into $V-X$ or $V+X$. To minimize the maximum frequency, we split these $k$ occurrences as evenly as possible between $V-X$ and $V+X$. The maximum frequency for any value derived from $V$ will be $\lceil k/2 \rceil$.

The crucial part is that we can choose $X$ such that the sets $\{A_i - X\}$ and $\{A_i + X\}$ for all $i$ are mostly disjoint. Specifically, we can choose $X$ large enough such that for any two distinct values $V_1, V_2$ in $A$, the four values $V_1-X, V_1+X, V_2-X, V_2+X$ are all distinct. The only potential collision is if $V_1 - X = V_2 + X$, which means $V_1 - V_2 = 2X$. Since the set of differences $|V_1 - V_2|$ is finite, we can always pick an $X$ such that $2X$ is not equal to any of these differences. For example, pick $X$ larger than half the maximum difference between any two elements in $A$.

With such an $X$, the transformations for different values in $A$ will not collide. For example, if $A_i = V_1$ and $A_j = V_2$ ($V_1 \neq V_2$), then $V_1 - X \neq V_2 - X$, $V_1 + X \neq V_2 + X$, $V_1 - X \neq V_2 + X$, and $V_1 + X \neq V_2 - X$.
This means that the $k$ occurrences of a value $V$ in $A$ can only contribute to the frequencies of $V-X$ and $V+X$ in $B$. To minimize the maximum frequency, we split these $k$ occurrences as evenly as possible between $V-X$ and $V+X$. The maximum frequency contributed by $V$ to any single element in $B$ is $\lceil k/2 \rceil$.

Since the transformations for different original values $V$ do not interfere with each other (due to our choice of $X$), the maximum frequency in $B$ will be the maximum of $\lceil k/2 \rceil$ over all distinct values $V$ in $A$, where $k$ is the frequency of $V$ in $A$.

The integer division `(count + 1) / 2` correctly computes $\lceil \text{count} / 2 \rceil$. For example:
- If `count = 5`, `(5 + 1) / 2 = 6 / 2 = 3`. $\lceil 5/2 \rceil = 3$.
- If `count = 4`, `(4 + 1) / 2 = 5 / 2 = 2` (integer division). $\lceil 4/2 \rceil = 2$.

So, the algorithm is:
1. Count the frequencies of each distinct number in array $A$.
2. For each distinct number with frequency $k$, calculate $\lceil k/2 \rceil$.
3. The answer is the maximum of these $\lceil k/2 \rceil$ values.

## Complexity Analysis

- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the map implementation.
    - Reading $N$ elements and inserting them into a `std::map` takes $O(N \log D)$ time, where $D$ is the number of distinct elements. In the worst case, $D=N$, so it's $O(N \log N)$.
    - Iterating through the map to find the maximum frequency takes $O(D)$ time, which is at most $O(N)$.
    - If `std::unordered_map` were used, the average time complexity for insertion would be $O(1)$, leading to an overall average time complexity of $O(N)$. The worst-case for `std::unordered_map` is $O(N^2)$ for insertions, but this is rare.
    - Given the constraints and typical competitive programming scenarios, $O(N \log N)$ with `std::map` is perfectly acceptable.

- **Space Complexity**: $O(D)$, where $D$ is the number of distinct elements in $A$.
    - In the worst case, $D=N$, so the space complexity is $O(N)$ to store the frequencies in the map.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Not strictly needed for this solution, but often useful
#include <map>      // For std::map to count frequencies
#include <algorithm> // For std::max

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the array

    // Use a map to store frequencies of each number in array A.
    // std::map provides sorted keys, but for this problem, order doesn't matter.
    // std::unordered_map could also be used for potentially faster average-case performance.
    std::map<int, int> counts; 
    for (int i = 0; i < N; ++i) {
        int A_i;
        std::cin >> A_i; // Read each element of array A
        counts[A_i]++;   // Increment its frequency
    }

    int min_max_freq_B = 0; // This will store the minimum possible value of the maximum frequency in B

    // Iterate through the frequencies of distinct elements in A
    for (auto const& pair : counts) {
        // 'pair.first' is the value (A_i), 'pair.second' is its frequency (count)
        int count = pair.second;

        // For each distinct value 'V' that appears 'count' times in A,
        // we can transform these 'count' occurrences into two groups in array B:
        // 1. 'count_minus' elements equal to 'V - X'
        // 2. 'count_plus' elements equal to 'V + X'
        // where count_minus + count_plus = count.
        // To minimize the frequency of any single value originating from 'V',
        // we should make 'count_minus' and 'count_plus' as balanced as possible.
        // This means count_minus = ceil(count / 2.0) and count_plus = floor(count / 2.0) (or vice versa).
        // The maximum frequency contributed by these 'count' elements will be ceil(count / 2.0).
        // In integer arithmetic, ceil(k / 2.0) can be computed as (k + 1) / 2.
        
        // We can always choose an integer X (X != 0) such that for any two distinct values V1, V2 in A,
        // the four values V1-X, V1+X, V2-X, V2+X are all distinct.
        // The only potential collision is if |V1 - V2| = 2X.
        // Since the set of possible differences |V1 - V2| is finite, we can always pick an X
        // such that 2X is not equal to any of these differences. For example, pick X large enough.
        // Thus, the maximum frequency in B will be the maximum of ceil(count / 2.0) over all distinct values in A.
        
        min_max_freq_B = std::max(min_max_freq_B, (count + 1) / 2);
    }

    std::cout << min_max_freq_B << "\n"; // Output the result for the current test case
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```