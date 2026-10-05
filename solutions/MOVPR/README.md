# [Movie Snacks (MOVPR)](https://www.codechef.com/problems/MOVPR)
- **Difficulty Rating**: 263
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef wants to buy snacks for a movie. He needs exactly 2 buckets of popcorn and 3 drinks.
There are three ways to purchase items:
1. A single bucket of popcorn costs `X` rupees.
2. A single drink costs `Y` rupees.
3. A combo offer (one bucket of popcorn + one drink) costs `Z` rupees.

The task is to find the minimum total cost Chef has to pay to acquire 2 popcorns and 3 drinks.

## Intuition & Mathematical Observation

The core requirement is to obtain 2 popcorns (P) and 3 drinks (D). We can represent this as `P + P + D + D + D`.

Let's analyze the most efficient way to acquire a pair of (1 Popcorn + 1 Drink).
There are two options:
1. Buy one popcorn individually (`X`) and one drink individually (`Y`). Total cost: `X + Y`.
2. Buy one combo offer (`Z`). Total cost: `Z`.

The minimum cost to get one popcorn and one drink is `min(X + Y, Z)`. Let's call this `cost_PD`.

Now, let's break down the total requirement (2P + 3D) using this optimal `cost_PD`:
We can view `2P + 3D` as:
`(1P + 1D) + (1P + 1D) + (1D)`

From this breakdown, we can see that we need two instances of `(1P + 1D)` and one additional `(1D)`.
- Each `(1P + 1D)` bundle can be acquired for `cost_PD`. Since we need two such bundles, this will cost `2 * cost_PD`.
- The remaining `(1D)` must be bought individually, which costs `Y`.

Therefore, the total minimum cost will be `2 * cost_PD + Y`.

This strategy ensures that we always pick the cheaper option for the (Popcorn + Drink) bundles, and then cover the remaining individual drink requirement.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (addition, multiplication, and `min` function call) and input/output operations. These operations take constant time, regardless of the input values.
-   **Space Complexity**: $O(1)$
    The solution uses a constant number of integer variables (`X`, `Y`, `Z`, `effective_cost_for_one_popcorn_and_one_drink`, `minimum_total_cost`) to store prices and intermediate results. The memory usage does not scale with any input parameter.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required include for competitive programming, includes iostream, algorithm, etc.
using namespace std;     // Required namespace for competitive programming

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare integer variables for the prices.
    // X: price of one bucket of popcorn
    // Y: price of one drink
    // Z: price of one combo (one popcorn + one drink)
    int X, Y, Z;

    // Read the three prices from standard input.
    cin >> X >> Y >> Z;

    // Chef needs to buy 2 buckets of popcorn and 3 drinks.
    // This requirement can be broken down into:
    // (1 popcorn + 1 drink)
    // + (1 popcorn + 1 drink)
    // + (1 drink)

    // First, determine the most cost-effective way to acquire one popcorn and one drink.
    // This can be achieved either by buying them individually (cost X + Y)
    // or by buying a combo offer (cost Z).
    // We choose the minimum of these two options.
    int effective_cost_for_one_popcorn_and_one_drink = min(X + Y, Z);

    // Now, calculate the total minimum cost.
    // We need two sets of (1 popcorn + 1 drink), so that's 2 times the effective cost.
    // We also need one additional drink, which costs Y.
    int minimum_total_cost = 2 * effective_cost_for_one_popcorn_and_one_drink + Y;

    // Print the calculated minimum total cost to standard output, followed by a newline.
    cout << minimum_total_cost << "\n";

    // Indicate successful program execution.
    return 0;
}
```