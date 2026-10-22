# [Layered Cake (LAYERCAKE)](https://www.codechef.com/problems/LAYERCAKE)

- **Difficulty Rating**: 875
- **Solved in**: 2 attempt(s)

## Problem Summary
Given two arrays, $A$ (size $N$) and $B$ (size $M$), representing the sizes of the first and second layers of a cake respectively, we need to find the number of pairs $(A_i, B_j)$ such that $A_i > B_j$. A valid cake is formed by placing a layer of size $B_j$ on top of a layer of size $A_i$ only if $A_i > B_j$.

## Intuition & Mathematical Observation
The constraints on the values of $A_i$ and $B_j$ are small (between 1 and 100). This allows us to use **Frequency Arrays** to count the occurrences of each size.

1.  **Frequency Counting**: We count how many times each size appears in array $A$ and array $B$.
2.  **Prefix Sums**: To efficiently calculate how many elements in $B$ are strictly smaller than a given value $A_i$, we precompute a prefix sum array for the frequencies of $B$. Specifically, `prefix_sum_B[x]` stores the total count of elements in $B$ that are $\le x$.
3.  **Calculation**: For every unique size $v$ present in $A$, the number of valid pairs is `(count of v in A) * (count of elements in B < v)`. Since the count of elements in $B < v$ is simply `prefix_sum_B[v - 1]`, we can compute the total count in $O(100)$ time per test case.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N + M + K))$, where $T$ is the number of test cases, $N$ and $M$ are the sizes of the arrays, and $K$ is the range of values (100). Given the constraints, this is highly efficient.
- **Space Complexity**: $O(K)$, where $K=100$, to store the frequency and prefix sum arrays.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector

// Function to solve a single test case
void solve() {
    int N, M;
    std::cin >> N >> M; // Read N and M

    // Use frequency arrays because A_i, B_i values are small (1 to 100).
    // freqA[x] stores the count of value x in array A.
    // freqB[x] stores the count of value x in array B.
    // Size 101 is used to cover values from 0 to 100.
    std::vector<int> freqA(101, 0);
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        freqA[val]++;
    }

    std::vector<int> freqB(101, 0);
    for (int i = 0; i < M; ++i) {
        int val;
        std::cin >> val;
        freqB[val]++;
    }

    // Create a prefix sum array for freqB.
    // prefix_sum_B[x] will store the total count of elements in B that are less than or equal to x.
    std::vector<int> prefix_sum_B(101, 0);
    for (int val = 1; val <= 100; ++val) {
        prefix_sum_B[val] = prefix_sum_B[val - 1] + freqB[val];
    }

    long long count = 0; // Initialize count of valid cakes. Use long long for safety.
    
    // Iterate through each possible size for the first layer (from 1 to 100)
    for (int val_A = 1; val_A <= 100; ++val_A) {
        // If there are any first layers of size val_A
        if (freqA[val_A] > 0) {
            // We need to find how many second layers B_j are strictly smaller than val_A.
            // This is equivalent to finding the count of B_j such that B_j <= (val_A - 1).
            int num_B_smaller = prefix_sum_B[val_A - 1];
            
            // Each of the freqA[val_A] first layers of size val_A can be paired
            // with each of the num_B_smaller second layers.
            count += (long long)freqA[val_A] * num_B_smaller;
        }
    }
    
    // Output the total number of valid layered cakes for this test case
    std::cout << count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, once for each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```