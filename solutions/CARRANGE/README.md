# [Car Range (CARRANGE)](https://www.codechef.com/problems/CARRANGE)
- **Difficulty Rating**: 938
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum distance a car can travel given three parameters:
1.  `P`: The total number of people in the car, including the driver.
2.  `M`: The base fuel economy of the car in kilometers per litre (km/litre) when only the driver is present.
3.  `V`: The total volume of fuel in the car's tank in litres.

The crucial rule is that for every *extra* passenger (i.e., anyone beyond the driver), the car's fuel economy decreases by 1 km/litre. We need to output the maximum distance the car can travel for each test case.

## Intuition & Mathematical Observation

The core of the problem lies in correctly calculating the car's *effective* fuel economy, which changes based on the number of passengers.

1.  **Identify Extra Passengers**: The problem states that `P` is the total number of people, including the driver. If there's one driver, then the number of additional passengers is `P - 1`. For example, if `P=1`, there are `1-1=0` extra passengers. If `P=3`, there are `3-1=2` extra passengers.

2.  **Calculate Fuel Economy Reduction**: Each extra passenger reduces the fuel economy by 1 km/litre. So, if there are `(P - 1)` extra passengers, the total reduction in fuel economy will be `(P - 1) * 1 = P - 1` km/litre.

3.  **Determine Effective Fuel Economy**: The base fuel economy is `M`. After accounting for the reduction due to extra passengers, the effective fuel economy becomes `M - (P - 1)`.

4.  **Calculate Maximum Distance**: Once we have the effective fuel economy and the total fuel volume `V`, the maximum distance the car can travel is simply the product of these two values:
    `Maximum Distance = Effective Fuel Economy * V`
    `Maximum Distance = (M - (P - 1)) * V`

Let's trace with an example: `P=2, M=10, V=5`
*   Number of extra passengers: `P - 1 = 2 - 1 = 1`.
*   Reduction in fuel economy: `1` km/litre.
*   Effective fuel economy: `M - 1 = 10 - 1 = 9` km/litre.
*   Maximum distance: `9 * 5 = 45` km.

This simple formula can be directly applied to solve the problem.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program reads `T` test cases.
    *   Inside the loop for each test case, it performs a constant number of operations: reading three integers (`P`, `M`, `V`), a few arithmetic calculations (subtraction, multiplication), and printing one integer. All these operations take $O(1)$ time.
    *   Since there are `T` test cases, the total time complexity is proportional to `T`.

*   **Space Complexity**: $O(1)$
    *   The program uses a fixed number of variables (`T`, `P`, `M`, `V`, `extra_passengers`, `effective_fuel_economy`, `max_distance`) to store input and intermediate results.
    *   The memory used by these variables does not depend on the input values (other than the fixed size of integer types), making the space complexity constant.

## Solution Code

```cpp
#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    while (T--) { // Loop T times, processing each test case.
        int P, M, V;
        cin >> P >> M >> V; // Read P (people), M (base fuel economy), V (fuel volume).

        // Calculate the number of extra passengers.
        // P includes the driver, so P-1 are the additional passengers.
        int extra_passengers = P - 1;

        // Calculate the effective fuel economy.
        // The base fuel economy M is decreased by 1 km/litre for each extra passenger.
        int effective_fuel_economy = M - extra_passengers;

        // Calculate the maximum distance the car can travel.
        // Distance = Effective Fuel Economy * Volume of Fuel.
        // The maximum possible distance is 56 * 100 = 5600, which fits in an int.
        // However, using long long for the result is a good general practice in competitive programming
        // to prevent potential overflow issues, even if not strictly necessary here.
        long long max_distance = (long long)effective_fuel_economy * V;

        // Output the calculated maximum distance, followed by a newline.
        cout << max_distance << "\n";
    }

    return 0; // Indicate successful execution.
}
```