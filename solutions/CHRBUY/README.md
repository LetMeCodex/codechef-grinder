# [Buying Chairs (CHRBUY)](https://www.codechef.com/problems/CHRBUY)
- **Difficulty Rating**: 564
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to buy exactly `K` chairs to maximize his total stylishness. There are two types of chairs available:
1.  **Wooden Chairs**: There are `W` wooden chairs available. Each wooden chair contributes 2 units of stylishness.
2.  **Plastic Chairs**: There are `P` plastic chairs available. Each plastic chair contributes 1 unit of stylishness.

The problem guarantees that Chef can always buy `K` chairs, i.e., `K <= W + P`. We need to find the maximum possible total stylishness Chef can achieve.

## Intuition & Mathematical Observation

The core idea to maximize total stylishness is to prioritize buying the chairs that offer more stylishness per unit.
Comparing the two types:
*   Wooden chairs offer 2 stylishness per chair.
*   Plastic chairs offer 1 stylishness per chair.

Since wooden chairs provide strictly more stylishness (2 units) than plastic chairs (1 unit) for each chair purchased, Chef should always try to buy as many wooden chairs as possible first. This is a classic greedy approach.

Here's the breakdown of the strategy:

1.  **Maximize Wooden Chairs**: Chef wants to buy `K` chairs in total. The number of wooden chairs he can buy is limited by two factors:
    *   The total number of wooden chairs available (`W`).
    *   The total number of chairs Chef wants to buy (`K`).
    Therefore, Chef will buy `min(W, K)` wooden chairs. Let's call this `num_wooden_chairs`.

2.  **Buy Remaining as Plastic Chairs**: After buying `num_wooden_chairs`, Chef still needs to buy `K - num_wooden_chairs` more chairs to reach the target of `K` chairs. These remaining chairs must be plastic chairs. Let's call this `num_plastic_chairs`.
    *   `num_plastic_chairs = K - num_wooden_chairs`.

    The problem statement guarantees that `K <= W + P`. This guarantee is crucial because it ensures that:
    *   Chef will always be able to buy `K` chairs in total.
    *   Specifically, the calculated `num_plastic_chairs` will never exceed the available `P` plastic chairs.
        *   If `K <= W`: `num_wooden_chairs` will be `K`. `num_plastic_chairs` will be `K - K = 0`. This is valid as `0 <= P` (since `P >= 1` from constraints).
        *   If `K > W`: `num_wooden_chairs` will be `W`. `num_plastic_chairs` will be `K - W`. Since `K <= W + P`, it implies `K - W <= P`. Thus, `num_plastic_chairs` will not exceed `P`. This is also valid.

3.  **Calculate Total Stylishness**: Once the number of wooden and plastic chairs is determined, the total stylishness is calculated as:
    `Total Stylishness = (num_wooden_chairs * 2) + (num_plastic_chairs * 1)`

This greedy strategy is optimal because there's no scenario where buying a plastic chair instead of an available wooden chair would lead to higher total stylishness.

## Complexity Analysis

*   **Time Complexity**: The solution involves reading three integers, performing a `min` operation, a few arithmetic operations (subtraction, multiplication, addition), and printing an integer. All these operations take constant time. Since this process is repeated `T` times for `T` test cases, the total time complexity is $\mathcal{O}(T)$.
*   **Space Complexity**: The solution uses a fixed number of variables (`W`, `P`, `K`, `num_wooden_chairs`, `num_plastic_chairs`, `total_stylishness`, `T`). These variables occupy a constant amount of memory regardless of the input values. Therefore, the space complexity is $\mathcal{O}(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int W, P, K;
    cin >> W >> P >> K; // Read input using cin

    // To maximize stylishness, Chef should prioritize buying wooden chairs
    // because each wooden chair increases stylishness by 2,
    // while each plastic chair increases stylishness by 1.

    // Determine the number of wooden chairs to buy.
    // This is limited by two factors:
    // 1. The total number of wooden chairs available (W).
    // 2. The total number of chairs Chef wants to buy (K).
    // So, Chef can buy at most min(W, K) wooden chairs.
    int num_wooden_chairs = min(W, K); // std::min is now min due to using namespace std;

    // The remaining chairs must be plastic chairs to reach the total of K chairs.
    // The number of plastic chairs needed is K - num_wooden_chairs.
    int num_plastic_chairs = K - num_wooden_chairs;

    // It's guaranteed that K <= W + P. This constraint ensures that:
    // 1. If K <= W: num_wooden_chairs = K. num_plastic_chairs = K - K = 0.
    //    Since P >= 1 (from constraints), 0 <= P is always true.
    // 2. If K > W: num_wooden_chairs = W. num_plastic_chairs = K - W.
    //    The guarantee K <= W + P implies K - W <= P. So, num_plastic_chairs will not exceed P.
    // Therefore, we don't need to explicitly check if num_plastic_chairs > P
    // or adjust num_wooden_chairs downwards. The greedy choice of maximizing
    // wooden chairs first, up to min(W, K), is always valid and optimal.

    // Calculate the total stylishness.
    // Wooden chairs contribute 2 stylishness each, plastic chairs contribute 1 each.
    int total_stylishness = (num_wooden_chairs * 2) + (num_plastic_chairs * 1);

    cout << total_stylishness << "\n"; // Output using cout
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```