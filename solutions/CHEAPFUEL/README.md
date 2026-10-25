# [Which Fuel is Cheaper (CHEAPFUEL)](https://www.codechef.com/problems/CHEAPFUEL)
- **Difficulty Rating**: 926
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to compare the prices of petrol and diesel after a certain number of months, given their initial prices and their monthly price increases. We are given:
- `X`: Initial price of petrol.
- `Y`: Initial price of diesel.
- `A`: Monthly increase in petrol price.
- `B`: Monthly increase in diesel price.
- `K`: The number of months after which we need to compare the prices.

We need to determine which fuel will be cheaper after `K` months, or if their prices will be the same.

## Intuition & Mathematical Observation

The core of this problem lies in calculating the future price of each fuel and then comparing them.

Let's denote:
- $P_0$ as the initial price of petrol (`X`).
- $D_0$ as the initial price of diesel (`Y`).
- $P_{inc}$ as the monthly increase in petrol price (`A`).
- $D_{inc}$ as the monthly increase in diesel price (`B`).
- $K$ as the number of months.

After $K$ months, the price of petrol will be its initial price plus the total increase over $K$ months. The total increase in petrol price will be $P_{inc} \times K$.
So, the final price of petrol, $P_K$, will be:
$P_K = P_0 + P_{inc} \times K$
$P_K = X + A \times K$

Similarly, after $K$ months, the price of diesel will be its initial price plus the total increase over $K$ months. The total increase in diesel price will be $D_{inc} \times K$.
So, the final price of diesel, $D_K$, will be:
$D_K = D_0 + D_{inc} \times K$
$D_K = Y + B \times K$

Once we have calculated $P_K$ and $D_K$, we can compare them:
1. If $P_K < D_K$, petrol is cheaper.
2. If $D_K < P_K$, diesel is cheaper.
3. If $P_K = D_K$, they are the same price.

The problem constraints on `X`, `Y`, `A`, `B`, and `K` are up to $10^9$. The maximum possible price after $K$ months could be roughly $10^9 + 10^9 \times 10^9$, which can exceed the capacity of a standard 32-bit integer. Therefore, it's prudent to use `long long` for calculations involving the final prices to avoid potential integer overflow.

## Complexity Analysis

- **Time Complexity**: $O(1)$
The solution involves a fixed number of arithmetic operations (addition, multiplication, comparison) and input/output operations for each test case. The number of operations does not depend on the input values themselves, only on the structure of the calculation. Since we process each test case independently and the operations are constant time, the time complexity per test case is $O(1)$. If there are $T$ test cases, the total time complexity is $O(T)$.

- **Space Complexity**: $O(1)$
The solution uses a fixed number of variables to store the input values and the calculated final prices. The memory usage does not grow with the input size. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries, including iostream
using namespace std;     // Brings all names from std namespace into the global scope

// Function to solve a single test case
void solve() {
    int X, Y, A, B, K;
    // Read the five space-separated integers for the current test case
    cin >> X >> Y >> A >> B >> K;

    // Calculate the final price of petrol after K months
    // Initial price X + (monthly increase A * number of months K)
    // Using long long for calculation to be safe, though int would suffice for given constraints.
    long long final_petrol_price = (long long)X + (long long)A * K;

    // Calculate the final price of diesel after K months
    // Initial price Y + (monthly increase B * number of months K)
    long long final_diesel_price = (long long)Y + (long long)B * K;

    // Compare the final prices and print the appropriate result
    if (final_petrol_price < final_diesel_price) {
        cout << "PETROL\n"; // Petrol is cheaper
    } else if (final_diesel_price < final_petrol_price) {
        cout << "DIESEL\n"; // Diesel is cheaper
    } else {
        cout << "SAME PRICE\n"; // Both have the same price
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}
```