# [Burgers (BURGERS)](https://www.codechef.com/problems/BURGERS)

- **Difficulty Rating**: 263
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $A$ patties and $B$ buns. To make one burger, Chef requires exactly one patty and one bun. We need to determine the maximum number of burgers Chef can prepare given the available ingredients.

## Intuition & Mathematical Observation
To form a single burger, we must consume one unit of $A$ and one unit of $B$. If we have an unequal number of patties and buns, the ingredient with the smaller quantity will act as the "limiting factor." 

For example:
- If $A = 5$ and $B = 3$, we can only make 3 burgers because we will run out of buns after the third burger.
- If $A = 2$ and $B = 10$, we can only make 2 burgers because we will run out of patties after the second burger.

Therefore, the maximum number of burgers that can be formed is simply the **minimum** of the two available quantities: $\min(A, B)$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time comparison operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int A, B; // Declare integer variables A for patties and B for buns
        cin >> A >> B; // Read the number of patties and buns for the current test case

        // To make 1 burger, Chef needs 1 patty and 1 bun.
        // The maximum number of burgers Chef can make is limited by the ingredient
        // that Chef has less of.
        // This means the maximum number of burgers is the minimum of A and B.
        cout << min(A, B) << "\n"; // Calculate min(A, B) and print it, followed by a newline
    }

    return 0; // Indicate successful program execution
}
```