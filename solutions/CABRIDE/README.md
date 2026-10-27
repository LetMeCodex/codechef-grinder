# [Cab Rides (CABRIDE)](https://www.codechef.com/problems/CABRIDE)
- **Difficulty Rating**: 945
- **Solved in**: 2 attempt(s)

## Problem Summary
We need to transport $N$ people using cabs with a capacity of 4 people each. The cost of a cab ride with $X$ people is given by $\max(200, 100 \times X)$. We want to find the minimum total cost to transport all $N$ people.

## Intuition & Mathematical Observation

The problem states that each cab has a capacity of 4 people. To transport $N$ people, we need a minimum number of cabs. The minimum number of cabs required can be calculated using the ceiling function: $\lceil \frac{N}{4} \rceil$. In integer arithmetic, this can be represented as $(N + 3) / 4$.

The cost of a single cab ride is defined as $\max(200, 100 \times X)$, where $X$ is the number of people in that cab. However, the problem asks for the *minimum total cost* to transport $N$ people. This implies we should consider the most efficient way to fill the cabs.

Let $C$ be the minimum number of cabs required, so $C = \lceil \frac{N}{4} \rceil$.
If we use $C$ cabs, the total number of people we can transport is $4 \times C$. Since $C = \lceil \frac{N}{4} \rceil$, we know that $4 \times C \ge N$. This means we can always fit all $N$ people into $C$ cabs.

Now, let's consider the cost. The problem statement for the cost of a cab ride with $X$ people is $\max(200, 100 \times X)$. This formula suggests a base cost of 200, and if the number of people $X$ is large enough such that $100 \times X > 200$, then the cost is $100 \times X$.

If we have $C$ cabs, and we distribute the $N$ people among them, what is the total cost? The problem statement is a bit ambiguous here. It could mean the sum of costs for each individual cab, or it could be interpreted as a total cost based on the total number of people and the number of cabs.

Let's re-examine the cost formula: $\max(200, 100 \times X)$.
If we have $C$ cabs, and we want to minimize the total cost, we should try to fill them as much as possible.
Consider the total number of people $N$. If we were to transport $N$ people in a single "effective" cab, the cost would be $\max(200, 100 \times N)$.

However, we are constrained by the capacity of 4 people per cab.
The minimum number of cabs is $C = \lceil N/4 \rceil$.

Let's consider two scenarios for the total cost:

1.  **Cost based on the number of cabs:** If each of the $C$ cabs incurs a cost, what would that cost be? If we assume each cab is filled with *some* people (at least one, up to 4), the cost for each cab would be at least 200. So, $C$ cabs would cost at least $200 \times C$.

2.  **Cost based on the total number of people:** If the cost is directly proportional to the total number of people, and there's a minimum threshold, it might be $100 \times N$.

The problem statement's phrasing "The cost for a cab with X people is max(200, 100 * X)" and then asking for the "minimum total cost" suggests that we need to find the overall cost for transporting $N$ people.

The key insight comes from observing the structure of the cost function. The cost is either a fixed minimum of 200, or it scales linearly with the number of people ($100 \times X$).

If we have $N$ people, and we use $C = \lceil N/4 \rceil$ cabs:
-   If $N$ is small, say $N=1$, we need 1 cab. Cost = $\max(200, 100 \times 1) = 200$.
-   If $N=4$, we need 1 cab. Cost = $\max(200, 100 \times 4) = 400$.
-   If $N=5$, we need 2 cabs.
    -   Option A: 4 people in cab 1, 1 person in cab 2. Cost = $\max(200, 100 \times 4) + \max(200, 100 \times 1) = 400 + 200 = 600$.
    -   Option B: 3 people in cab 1, 2 people in cab 2. Cost = $\max(200, 100 \times 3) + \max(200, 100 \times 2) = 300 + 200 = 500$.
    -   This approach of summing individual cab costs becomes complicated.

Let's reconsider the problem's structure. The cost is defined per cab. If we use $C$ cabs, and we want to minimize the total cost, we should aim to make the cost per cab as low as possible. The lowest cost per cab is 200. This happens when $100 \times X \le 200$, i.e., $X \le 2$.

However, we need to transport $N$ people. The total number of people $N$ is the primary factor.
The problem can be interpreted as: we need to cover $N$ people. The "cost unit" is a cab. Each cab has a capacity of 4.
The total cost is determined by the total number of people $N$ and the number of cabs $C$.

The formula $\max(200 \times C, 100 \times N)$ seems to capture the essence.
Let's test this:
-   $N=1$: $C = \lceil 1/4 \rceil = 1$. Cost = $\max(200 \times 1, 100 \times 1) = \max(200, 100) = 200$. (Correct)
-   $N=4$: $C = \lceil 4/4 \rceil = 1$. Cost = $\max(200 \times 1, 100 \times 4) = \max(200, 400) = 400$. (Correct)
-   $N=5$: $C = \lceil 5/4 \rceil = 2$. Cost = $\max(200 \times 2, 100 \times 5) = \max(400, 500) = 500$.
    Let's verify $N=5$ with the individual cab cost summation:
    To minimize cost, we should put as many people as possible in cabs where $100 \times X > 200$.
    If we have 2 cabs for 5 people:
    -   Cab 1: 3 people. Cost = $\max(200, 100 \times 3) = 300$.
    -   Cab 2: 2 people. Cost = $\max(200, 100 \times 2) = 200$.
    Total cost = $300 + 200 = 500$. This matches $\max(200 \times C, 100 \times N)$.

-   $N=8$: $C = \lceil 8/4 \rceil = 2$. Cost = $\max(200 \times 2, 100 \times 8) = \max(400, 800) = 800$.
    Individual cab cost summation:
    -   Cab 1: 4 people. Cost = $\max(200, 100 \times 4) = 400$.
    -   Cab 2: 4 people. Cost = $\max(200, 100 \times 4) = 400$.
    Total cost = $400 + 400 = 800$. Matches.

-   $N=10$: $C = \lceil 10/4 \rceil = 3$. Cost = $\max(200 \times 3, 100 \times 10) = \max(600, 1000) = 1000$.
    Individual cab cost summation:
    To minimize cost, we want to maximize people in cabs where $100 \times X > 200$.
    We have 3 cabs for 10 people.
    -   Cab 1: 4 people. Cost = 400.
    -   Cab 2: 4 people. Cost = 400.
    -   Cab 3: 2 people. Cost = 200.
    Total cost = $400 + 400 + 200 = 1000$. Matches.

The formula $\max(200 \times C, 100 \times N)$ seems to be the correct interpretation.
Let's break down why this formula works:
-   The term $200 \times C$ represents the cost if each of the $C$ cabs has a minimum cost of 200. This is the scenario when the number of people in each cab is small (2 or less).
-   The term $100 \times N$ represents the cost if the total cost is directly proportional to the total number of people, with a rate of 100 per person. This is the scenario when the number of people in cabs is large enough that $100 \times X > 200$ for most cabs.

The `max` function correctly chooses the dominant factor.
-   When $N$ is small, $C$ is also small. $200 \times C$ might be larger than $100 \times N$. For example, $N=1$, $C=1$. $200 \times 1 = 200$, $100 \times 1 = 100$. $\max(200, 100) = 200$.
-   When $N$ is large, $100 \times N$ will likely be larger than $200 \times C$. For example, $N=10$, $C=3$. $200 \times 3 = 600$, $100 \times 10 = 1000$. $\max(600, 1000) = 1000$.

The integer division for calculating $C$ is $(N + 3) / 4$.
The cost calculation is `max((long long)200 * num_cabs, (long long)100 * n)`. Using `long long` is important to prevent potential overflow if $N$ is large.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (division, addition, multiplication, max) and input/output operations for each test case. The number of operations does not depend on the input size $N$.

-   **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `t`, `n`, `num_cabs`, and `cost`. This space requirement does not grow with the input size.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem: CABRIDE
 * The cost for a cab with X people is max(200, 100 * X).
 * We need to transport N people with cabs of capacity 4.
 * The minimum number of cabs is ceil(N / 4.0).
 *
 * The total cost is determined by the minimum of two scenarios:
 * 1. The cost if each of the minimum required cabs incurs a base cost of 200.
 *    This is 200 * ceil(N / 4.0).
 * 2. The cost if the total cost is directly proportional to the number of people,
 *    with a rate of 100 per person. This is 100 * N.
 *
 * The formula max(200 * ceil(N/4.0), 100 * N) works because:
 * - If N is small, the 200 * ceil(N/4.0) term (representing the minimum cost per cab)
 *   is likely to dominate.
 * - If N is large, the 100 * N term (representing the linear cost per person)
 *   is likely to dominate.
 *
 * The minimum number of cabs, ceil(N / 4.0), can be calculated using integer
 * division as (N + 3) / 4.
 */

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    // Read the number of test cases. If reading fails, exit.
    if (!(cin >> t)) return 0;

    // Process each test case
    while (t--) {
        int n; // Number of people to transport
        cin >> n;

        // Calculate the minimum number of cabs required.
        // ceil(n / 4.0) is equivalent to (n + 3) / 4 using integer division.
        int num_cabs = (n + 3) / 4;

        // Calculate the total cost.
        // We use long long for cost to avoid potential integer overflow,
        // especially for the 100 * n term when n is large.
        // The cost is the maximum of:
        // 1. Minimum cost if each cab costs at least 200: 200 * num_cabs
        // 2. Cost based on total people: 100 * n
        long long cost = max((long long)200 * num_cabs, (long long)100 * n);

        // Output the calculated minimum cost for the current test case
        cout << cost << "\n";
    }

    return 0; // Indicate successful execution
}
```