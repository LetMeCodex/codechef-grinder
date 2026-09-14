# [Chef and NextGen (HELIUM3)](https://www.codechef.com/problems/HELIUM3)
- **Difficulty Rating**: 562
- **Solved in**: 1 attempt(s)

## Problem Summary

Chefland needs to power its operations for `B` years, requiring `A` units of power each year. They have `X` grams of Helium-3, and each gram can produce `Y` units of power. The task is to determine if the total power generated from the available Helium-3 is sufficient to meet Chefland's power requirements for `B` years. If the available power is sufficient, print "Yes"; otherwise, print "No".

## Intuition & Mathematical Observation

The problem asks us to compare the total power Chefland needs with the total power they can generate from their Helium-3 reserves.

1.  **Calculate Total Power Required:**
    Chefland needs `A` units of power per year, and this requirement spans `B` years.
    So, the total power required over `B` years is `A * B`.

2.  **Calculate Total Power Available:**
    Chefland possesses `X` grams of Helium-3, and each gram can produce `Y` units of power.
    Therefore, the total power that can be generated from the available Helium-3 is `X * Y`.

3.  **Compare and Decide:**
    The project can be funded (i.e., Chefland's power needs can be met) if the total power available is greater than or equal to the total power required.
    Mathematically, we need to check if `(X * Y) >= (A * B)`.
    If this condition is true, print "Yes"; otherwise, print "No".

The constraints on `A, B, X, Y` are up to 1000. The maximum product `1000 * 1000 = 1,000,000` fits comfortably within a standard 32-bit integer type (`int`). However, using `long long` for calculations is a good practice in competitive programming to prevent potential integer overflows, especially if constraints were slightly larger or intermediate calculations could exceed `int` limits.

## Complexity Analysis

-   **Time Complexity**: For each test case, the solution performs a fixed number of arithmetic operations (two multiplications and one comparison) and input/output operations. These operations take constant time. If there are `T` test cases, the total time complexity will be $O(T)$.
-   **Space Complexity**: The solution uses a constant number of variables (`A, B, X, Y`, `required_power`, `available_power`, `T`) to store input and intermediate results. The memory usage does not depend on the magnitude of the input values. Therefore, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes most standard libraries

// Use the standard namespace as requested by the problem statement
using namespace std;

void solve() {
    // Declare variables to store the input values.
    // Using 'long long' to be absolutely safe against potential integer overflow,
    // although for the given constraints (A, B, X, Y <= 1000),
    // their products (up to 1000 * 1000 = 1,000,000) would fit within a standard 'int'.
    long long A, B, X, Y;

    // Read the four space-separated integers for the current test case.
    cin >> A >> B >> X >> Y;

    // Calculate the total power required by Chefland over B years.
    // This is A units per year multiplied by B years.
    long long required_power = A * B;

    // Calculate the total power that can be generated from the available Helium-3.
    // This is X grams multiplied by Y units per gram.
    long long available_power = X * Y;

    // Check if the available power is sufficient to meet the required power.
    // The project gets funded if available_power is greater than or equal to required_power.
    if (available_power >= required_power) {
        // If sufficient, print "Yes".
        cout << "Yes\n";
    } else {
        // Otherwise, print "No".
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}
```