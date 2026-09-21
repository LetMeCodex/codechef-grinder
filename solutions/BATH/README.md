# [Bath in Winters (BATH)](https://www.codechef.com/problems/BATH)
- **Difficulty Rating**: 643
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the maximum number of people that can take a bath given a certain amount of water in a geyser and the water requirement per person. Specifically:
*   A geyser contains `X` litres of water.
*   Each person requires 2 buckets of water for a bath.
*   Each bucket can hold `Y` litres of water.

We need to find the maximum whole number of people who can take a bath.

## Intuition & Mathematical Observation

The core idea is to determine the total water needed for one person and then see how many such "units" of water can be accommodated by the total water available in the geyser.

1.  **Water per bucket:** Each bucket holds `Y` litres.
2.  **Water per person:** One person needs 2 buckets. Therefore, one person needs `2 * Y` litres of water.
3.  **Maximum people:** The geyser has `X` litres of water in total. If each person needs `2 * Y` litres, the maximum number of people that can take a bath is `X` divided by `(2 * Y)`. Since we can only have a whole number of people, we use integer division, which automatically truncates any fractional part, giving us the maximum whole number of people.

So, the formula is: `max_people = X / (2 * Y)`

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a fixed number of constant-time operations: reading two integers (`X`, `Y`), one multiplication, one division, and printing the result. These operations do not depend on the magnitude of `X` or `Y`. Therefore, each test case is processed in $O(1)$ time. With `T` test cases, the total time complexity is $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `X`, `Y`, `water_needed_per_person`, `max_people`) to store input and intermediate results. The amount of memory used by these variables is constant and does not grow with the input values or the number of test cases. Hence, the space complexity is $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Required header as per problem instructions

using namespace std; // Required namespace as per problem instructions

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y; // Declare variables for geyser capacity (X) and bucket capacity (Y)
        cin >> X >> Y; // Read X and Y for the current test case

        // Calculate the total water required for one person to take a bath.
        // One person needs 2 buckets, and each bucket holds Y litres.
        int water_needed_per_person = 2 * Y;

        // Calculate the maximum number of people that can take a bath.
        // This is done by dividing the total water available in the geyser (X)
        // by the water needed per person.
        // Integer division automatically handles the "maximum whole number of people".
        int max_people = X / water_needed_per_person;

        // Output the result for the current test case, followed by a newline.
        cout << max_people << "\n";
    }

    return 0; // Indicate successful program execution
}
```