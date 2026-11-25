# [Chef Bakes Cake 2 (BAKECAKE2)](https://www.codechef.com/problems/BAKECAKE2)
- **Difficulty Rating**: 612
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to bake a cake and needs `N` different ingredients. For each ingredient `i`, he requires `A[i]` units. He currently has `B[i]` units of each ingredient `i`. Each unit of any ingredient costs 1 coin. Chef wants to find the minimum cost to acquire all the necessary ingredients.

## Intuition & Mathematical Observation

The problem asks for the minimum cost to obtain all required ingredients. Since each unit of any ingredient costs 1 coin, the minimum cost is achieved by only buying the exact amount of each ingredient that is missing.

For each ingredient `i`, Chef needs `A[i]` units and has `B[i]` units.
- If `A[i] <= B[i]`, Chef already has enough or more of ingredient `i`. He doesn't need to buy any more of this ingredient. The cost for this ingredient is 0.
- If `A[i] > B[i]`, Chef needs to buy `A[i] - B[i]` more units of ingredient `i`. The cost for this ingredient is `A[i] - B[i]`.

The total minimum cost is the sum of the costs for each individual ingredient. Mathematically, for each ingredient `i` from 0 to `N-1`, the cost is `max(0, A[i] - B[i])`. The total cost is the sum of these values over all `N` ingredients.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the `N` ingredients twice: once to read the required amounts `A` and once to read the available amounts `B`. Then, it iterates through the `N` ingredients one more time to calculate the total cost. Each of these operations takes time proportional to `N`. Therefore, the total time complexity is $O(N)$ per test case. Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.

- **Space Complexity**: $O(N)$
  The code uses two vectors, `A` and `B`, each of size `N`, to store the required and available amounts of ingredients, respectively. This requires $O(N)$ space. The other variables use constant space. Therefore, the space complexity is $O(N)$ per test case.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, vector, algorithm, etc.

// Using namespace std; is requested by the problem statement for competitive programming contexts.
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the total number of ingredients

    // Create a vector to store the required amounts of each ingredient (A_i)
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read A_i for each ingredient
    }

    // Create a vector to store the currently available amounts of each ingredient (B_i)
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i]; // Read B_i for each ingredient
    }

    // Initialize total_cost to 0. Using long long to be safe, though int would suffice given constraints.
    long long total_cost = 0;

    // Iterate through each ingredient to calculate the cost
    for (int i = 0; i < N; ++i) {
        // For each ingredient i, calculate the amount needed:
        // If A[i] (required) is greater than B[i] (available), Chef needs to buy A[i] - B[i] units.
        // Otherwise (if A[i] <= B[i]), Chef has enough or more, so 0 units need to be bought.
        // Since each unit costs 1 coin, the cost for this ingredient is simply the amount to buy.
        total_cost += max(0, A[i] - B[i]);
    }

    // Output the total cost for the current test case, followed by a newline
    cout << total_cost << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}
```