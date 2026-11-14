# [Cake Baking (CAKEBAKE7)](https://www.codechef.com/problems/CAKEBAKE7)
- **Difficulty Rating**: 339
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum number of "happy" customers given `N` customers and `M` cakes. The conditions are:
1.  Every customer must receive at least one cake.
2.  A customer is considered "happy" if they receive exactly two cakes.
We need to maximize the count of such happy customers. The constraints are $1 \le N \le 10^9$ and $N \le M \le 10^9$.

## Intuition & Mathematical Observation
Let's break down the cake distribution process to maximize happy customers:

1.  **Initial Distribution (Mandatory)**: The problem states that every customer *must* receive at least one cake. To satisfy this fundamental requirement, we distribute one cake to each of the `N` customers.
    *   Cakes used for initial distribution: `N`
    *   Cakes remaining for further distribution: `M - N`
    *   Current state: All `N` customers have received 1 cake each.

2.  **Making Customers Happy**: A customer becomes happy if they receive a *second* cake. We now have `M - N` cakes remaining from the initial distribution. Each of these remaining cakes can be given to one of the `N` customers (who currently have 1 cake) to bring their total to 2, thus making them happy.

3.  **Limiting Factors**: The number of customers we can make happy is limited by two distinct factors:
    *   **Available Cakes for Happiness**: We have `M - N` cakes available to distribute as second cakes. Each such cake can make one customer happy. Therefore, we can make at most `M - N` customers happy using these additional cakes.
    *   **Available Customers**: There are only `N` customers in total. Even if we have a very large number of remaining cakes (`M - N` is large), we cannot make more than `N` customers happy because there are no more customers to give cakes to.

4.  **Combining the Limits**: To maximize the number of happy customers, we must consider both limiting factors simultaneously. The maximum number of happy customers will be the minimum of the number of available cakes for happiness and the total number of customers.
    *   Maximum happy customers = $\min(\text{Total Customers}, \text{Cakes Available for Second Distribution})$
    *   Maximum happy customers = $\min(N, M - N)$

Since the problem constraints explicitly state $N \le M$, the value `M - N` will always be non-negative, ensuring a valid (non-negative) count for happy customers.

## Complexity Analysis
-   **Time Complexity**: The solution involves reading two integers (`N` and `M`), performing a single subtraction (`M - N`), a single `min` operation, and then printing the result. All these operations take constant time, regardless of the magnitude of `N` and `M` (as long as they fit in standard integer types). Therefore, the time complexity is $O(1)$.
-   **Space Complexity**: The solution only uses a few integer variables to store `N`, `M`, and the calculated result (`happy_customers`). This requires a constant amount of memory, independent of the input values. Therefore, the space complexity is $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Required by problem statement for common headers

// Required by problem statement to avoid std:: prefix
using namespace std;

int main() {
    // Enable fast I/O as required by problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // As per the problem-specific "Input Format":
    // "The first and only line of each test case contains 2 integers - N and M."
    // This implies a single test case, as no 'T' (number of test cases) is mentioned.
    // The general instruction about handling multiple test cases is a guideline for problems
    // that explicitly specify 'T' in their input format.

    int N, M;
    // Read the number of customers (N) and cakes (M)
    cin >> N >> M;

    // Logic to calculate maximum happy customers:
    // 1. To ensure no customer is unhappy, each of the N customers must receive at least 1 cake.
    //    This uses N cakes.
    // 2. The number of cakes remaining for additional distribution is M - N.
    // 3. Each of these remaining cakes can make one customer happy (by giving them an additional cake,
    //    bringing their total to 2). So, we can make at most (M - N) customers happy this way.
    // 4. However, we cannot make more customers happy than the total number of customers available, which is N.
    // 5. Therefore, the maximum number of happy customers is the minimum of (N) and (M - N).

    int happy_customers = min(N, M - N);

    // Output the result followed by a newline character
    cout << happy_customers << "\n";

    return 0;
}
```