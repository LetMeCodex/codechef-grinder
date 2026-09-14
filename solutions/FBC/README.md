# [Fill the Bucket (FBC)](https://www.codechef.com/problems/FBC)
- **Difficulty Rating**: 419
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum amount of additional water that can be filled into a bucket. We are given two integers: `K`, which represents the total capacity of the bucket, and `X`, which represents the amount of water already present in the bucket. We need to find out how much more water can be added. This operation needs to be performed for `T` test cases.

## Intuition & Mathematical Observation

This is a very basic arithmetic problem.
If a bucket has a total capacity of `K` units and `X` units of water are already present in it, the remaining space available to fill more water is simply the difference between the total capacity and the water already present.

Mathematically, the amount of extra water that can be filled is:
`Extra Water = Total Capacity - Water Already Present`
`Extra Water = K - X`

There are no complex algorithms or data structures required; a simple subtraction operation suffices.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a constant number of operations: reading two integers, one subtraction, and one print operation. Each of these operations takes constant time, $O(1)$. Therefore, the total time complexity is proportional to the number of test cases, $T$, resulting in $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `K`, `X`, `extra_water`) regardless of the input values or the number of test cases. No dynamic data structures like arrays or vectors are used that would consume memory proportional to the input size. Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries as requested

using namespace std; // Uses the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int K, X; // Declare integer variables K and X for bucket capacity and current water.
        cin >> K >> X; // Read K and X for the current test case.

        // Calculate the maximum amount of extra water that can be filled.
        // This is simply the difference between the total capacity (K)
        // and the amount of water already present (X).
        int extra_water = K - X;

        // Print the calculated extra water followed by a newline character.
        // The newline character ensures each output is on a separate line as per format.
        cout << extra_water << "\n";
    }

    return 0; // Indicate successful program execution.
}
```