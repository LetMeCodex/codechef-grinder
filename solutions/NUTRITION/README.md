# [Max Nutrition (NUTRITION)](https://www.codechef.com/problems/NUTRITION)
- **Difficulty Rating**: 1123
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum total nutrition we can obtain from a given set of fruits. We are provided with `N` fruits, each characterized by its `type` ($A_i$) and its `nutrition value` ($B_i$). The key constraint is that we can pick **at most one fruit of each type**. If we choose not to pick any fruit of a particular type, its contribution to the total nutrition is 0. Our goal is to maximize the sum of nutrition values of the chosen fruits.

The fruit types ($A_i$) range from 1 to 100, and nutrition values ($B_i$) range from -100 to 100.

## Intuition & Mathematical Observation

The core of this problem lies in the constraint: "at most one fruit of each type". This constraint simplifies the problem significantly because the decision for one fruit type (e.g., type 5) is independent of the decisions for any other fruit type (e.g., type 7). This means we can determine the maximum possible nutrition for each fruit type individually and then sum these maximums to get the overall maximum total nutrition.

Let's consider a single fruit type, say `X`.
1.  **Multiple fruits of type X**: If there are several fruits of type `X` available, each with a different nutrition value, we should always choose the one with the **highest nutrition value**. This is because we can only pick one, and picking the highest value maximizes our gain from type `X`.
2.  **Negative nutrition values**: If the maximum nutrition value found for type `X` is negative (e.g., -5), it means picking any fruit of type `X` would decrease our total nutrition. In such a scenario, it's always better to pick **no fruit of type X**, which contributes 0 to the total nutrition.
3.  **Zero nutrition values**: If the maximum nutrition value for type `X` is 0, picking it or not picking it yields the same result (0 contribution). So, we can treat this similarly to negative values – we only add positive contributions.

Based on these observations, the strategy is:
1.  For each unique fruit type (from 1 to 100), find the maximum nutrition value among all available fruits of that type.
2.  Initialize a `total_max_nutrition` sum to 0.
3.  Iterate through all possible fruit types (1 to 100). If the maximum nutrition value found for a particular type is **greater than 0**, add it to `total_max_nutrition`. Otherwise (if it's 0 or negative), we effectively choose not to pick any fruit of that type, so we add 0.
4.  The final `total_max_nutrition` will be the answer.

## Complexity Analysis

Let `N` be the number of fruits and `M` be the maximum possible fruit type (which is 100 according to constraints).

*   **Time Complexity**:
    *   Reading `N` and the `A` and `B` arrays takes $O(N)$ time.
    *   Initializing the `max_nutrition_per_type` array (of size `M+1`) takes $O(M)$ time. Since `M` is a constant (100), this is $O(1)$.
    *   The first loop iterates `N` times to populate `max_nutrition_per_type`. Inside the loop, array access and `max` operations are $O(1)$. So, this step takes $O(N)$ time.
    *   The second loop iterates `M` times (from 1 to 100) to sum up the maximum nutritions. Inside the loop, array access and addition are $O(1)$. So, this step takes $O(M)$ time, which is $O(1)$.
    *   Therefore, for a single test case, the total time complexity is $O(N + M)$. Since `M` is a constant, this simplifies to $O(N)$.
    *   Given `T` test cases, the overall time complexity is $O(T \cdot N)$.
    *   With `T <= 1000` and `N <= 100`, the maximum operations would be approximately $1000 \times 100 = 10^5$, which is well within typical time limits.

*   **Space Complexity**:
    *   `A` vector: $O(N)$ space.
    *   `B` vector: $O(N)$ space.
    *   `max_nutrition_per_type` vector: $O(M)$ space. Since `M` is a constant (100), this is $O(1)$ space.
    *   Other variables (`N`, `total_max_nutrition`, loop counters) take $O(1)$ space.
    *   Thus, the total space complexity is $O(N + M)$, which simplifies to $O(N)$ because `M` is a constant.
    *   With `N <= 100`, this is very minimal memory usage.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as per problem instructions.

// Use the standard namespace as per problem instructions.
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of fruits.

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i]; // Read fruit types.
    }

    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i]; // Read nutrition values.
    }

    // max_nutrition_per_type[type_id] will store the maximum nutrition value
    // found for a fruit of that specific type.
    // Fruit types A_i are between 1 and 100 (inclusive, as per problem constraints).
    // We need an array of size 101 to cover indices 0 to 100.
    // Initialize all values to -101, which is less than the minimum
    // possible nutrition value B_i (-100). This ensures that the first B_i
    // encountered for any type will correctly update its max_nutrition_per_type entry.
    vector<int> max_nutrition_per_type(101, -101); 

    // Iterate through all fruits to find the maximum nutrition for each type.
    for (int i = 0; i < N; ++i) {
        // For fruit A[i] with nutrition B[i], update the maximum for its type.
        max_nutrition_per_type[A[i]] = max(max_nutrition_per_type[A[i]], B[i]);
    }

    // Calculate the total maximum nutrition.
    // Initialize with 0, as eating no fruits gives 0 nutrition.
    // Using long long for total_max_nutrition is a good practice for sums,
    // though for given constraints (max sum 100 types * 100 nutrition = 10000),
    // an int would technically suffice.
    long long total_max_nutrition = 0; 

    // Iterate through all possible fruit types (from 1 to 100).
    // For each type, if its maximum nutrition value is positive, add it to the total.
    // If it's zero or negative, we choose not to eat any fruit of that type,
    // as it would not increase (or would decrease) the total nutrition.
    for (int i = 1; i <= 100; ++i) { 
        if (max_nutrition_per_type[i] > 0) {
            total_max_nutrition += max_nutrition_per_type[i];
        }
    }

    // Output the result for the current test case.
    cout << total_max_nutrition << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.
    while (T--) {
        solve(); // Solve each test case.
    }

    return 0;
}
```