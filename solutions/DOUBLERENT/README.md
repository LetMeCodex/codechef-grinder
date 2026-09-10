# [Double Rent (DOUBLERENT)](https://www.codechef.com/problems/DOUBLERENT)
- **Difficulty Rating**: 234
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the new rent if an initial rent `X` is doubled. We are given the initial rent `X` as input, and we need to output the final rent. The constraints on `X` are small (1 to 10).

## Intuition & Mathematical Observation

The problem statement directly specifies that the rent is "doubled". In mathematics, doubling a quantity means multiplying it by 2. Therefore, if the initial rent is `X`, the final rent will simply be `2 * X`. This is a straightforward arithmetic operation.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The program performs a constant number of operations: reading an integer, performing a single multiplication, and printing an integer. These operations take a fixed amount of time regardless of the value of `X` (within typical integer limits).

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`X`, `final_rent`) to store the input and the result. The memory required for these variables is constant and does not depend on the input value `X`.

## Solution Code

```cpp
#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable X to store the initial rent.
    // Constraints: 1 <= X <= 10, so 'int' is sufficient.
    int X;

    // Read the initial rent X from standard input.
    cin >> X;

    // Calculate the final rent.
    // The problem states the owner decided to "double" the rent.
    // So, the final rent is 2 times the initial rent X.
    int final_rent = 2 * X;

    // Output the final rent to standard output, followed by a newline character.
    cout << final_rent << "\n";

    // Return 0 to indicate successful execution of the program.
    return 0;
}
```