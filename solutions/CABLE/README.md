# [Volume Comparison (CABLE)](https://www.codechef.com/problems/CABLE)
- **Difficulty Rating**: 318
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to compare the volumes of two geometric shapes: a cuboid and a cube. We are given the dimensions of the cuboid (length $A$, width $B$, height $C$) and the edge length of the cube ($X$). Our task is to calculate the volume of both shapes and then determine which one has a greater volume. If the cuboid's volume is greater, we should print "Cuboid". If the cube's volume is greater, we should print "Cube". If their volumes are equal, we should print "Equal".

The input consists of a single line containing four space-separated integers: $A, B, C, X$. The constraints for all dimensions are $1 \le A, B, C, X \le 10$.

## Intuition & Mathematical Observation

This problem is a direct application of basic geometry formulas.

1.  **Volume of a Cuboid**: The volume of a cuboid is calculated by multiplying its length, width, and height. Given dimensions $A, B, C$, the volume of the cuboid is $V_{\text{cuboid}} = A \times B \times C$.

2.  **Volume of a Cube**: The volume of a cube is calculated by cubing its edge length. Given edge length $X$, the volume of the cube is $V_{\text{cube}} = X \times X \times X$ (or $X^3$).

Once both volumes are calculated, the problem reduces to a simple comparison:
*   If $V_{\text{cuboid}} > V_{\text{cube}}$, output "Cuboid".
*   If $V_{\text{cube}} > V_{\text{cuboid}}$, output "Cube".
*   Otherwise (if $V_{\text{cuboid}} = V_{\text{cube}}$), output "Equal".

Given the constraints ($1 \le A, B, C, X \le 10$), the maximum possible volume for either shape is $10 \times 10 \times 10 = 1000$. An `int` data type in C++ is more than sufficient to store these values without overflow. However, as a general good practice in competitive programming, and to strictly adhere to common critical instructions regarding potential integer overflow, using `long long` for volume calculations is a safe choice, even if not strictly necessary for these specific constraints.

The problem statement implies a single test case, so no loop for multiple test cases is required.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (multiplications) and comparisons, regardless of the input values (within the given constraints).
    -   Reading four integers: $O(1)$
    -   Calculating two volumes: $O(1)$ (three multiplications for cuboid, three for cube)
    -   Comparing volumes: $O(1)$
    -   Printing the result: $O(1)$
    All operations take constant time.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables to store the input dimensions ($A, B, C, X$) and the calculated volumes ($volume\_cuboid, volume\_cube$). No dynamic data structures or arrays are used, and the memory usage does not scale with the input values.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement

// Use the standard namespace, as requested by the problem statement
using namespace std;

int main() {
    // Include fast I/O inside main(), as requested by the problem statement
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare variables to store the dimensions of the cuboid (A, B, C)
    // and the edge length of the cube (X).
    // The constraints are 1 <= A,B,C,X <= 10.
    // The maximum possible volume for either object is 10*10*10 = 1000.
    // An 'int' type is sufficient to store these values without overflow.
    // However, to strictly adhere to the critical instruction "integer overflow (use long long in C++)",
    // we use 'long long' for variables that store dimensions and volumes.
    long long A, B, C, X;

    // Read the input values using cin, as requested
    cin >> A >> B >> C >> X;

    // Calculate the volume of the cuboid
    long long volume_cuboid = A * B * C;

    // Calculate the volume of the cube
    long long volume_cube = X * X * X;

    // Compare the volumes and print the result using cout << ... << "\n", as requested
    if (volume_cuboid > volume_cube) {
        cout << "Cuboid\n";
    } else if (volume_cube > volume_cuboid) {
        cout << "Cube\n";
    } else {
        cout << "Equal\n";
    }

    // The problem statement's input format description ("The first and only line of input will contain four space-separated integers A, B, C and X")
    // indicates a single test case. The general instruction "Handle multiple test cases (e.g. int t; cin >> t; while(t--)) properly as requested by the problem statement"
    // is likely boilerplate. Based on the specific input format, this solution processes a single set of inputs.

    return 0;
}
```