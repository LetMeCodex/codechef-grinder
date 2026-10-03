# [Area OR Perimeter (AREAPERI)](https://www.codechef.com/problems/AREAPERI)
- **Difficulty Rating**: 858
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read two integer values, `L` (length) and `B` (breadth), representing the dimensions of a rectangle. We need to calculate the area and the perimeter of this rectangle. After calculating both values, we must compare them and print the result according to these rules:
1. If the **Area is strictly greater than the Perimeter**, print "Area" on the first line, and the calculated Area on the second line.
2. If the **Perimeter is strictly greater than the Area**, print "Peri" on the first line, and the calculated Perimeter on the second line.
3. If the **Area and Perimeter are equal**, print "Eq" on the first line, and the calculated Area (or Perimeter, since they are equal) on the second line.

## Intuition & Mathematical Observation

This is a straightforward problem that primarily tests basic arithmetic operations and conditional logic.

1.  **Formulas**: The core of the problem lies in correctly applying the standard mathematical formulas for a rectangle:
    *   **Area** = `Length * Breadth` (L * B)
    *   **Perimeter** = `2 * (Length + Breadth)` (2 * (L + B))

2.  **Comparison**: After calculating both the area and the perimeter, we need to use `if-else if-else` statements to compare these two values. There are three distinct outcomes: Area > Perimeter, Perimeter > Area, or Area == Perimeter. Each outcome requires a specific two-line output format.

3.  **Data Types**: Given the constraints on `L` and `B` (1 to 1000), the maximum possible area would be `1000 * 1000 = 1,000,000`, and the maximum perimeter would be `2 * (1000 + 1000) = 4,000`. Both these values fit comfortably within a standard `int` data type in C++ (which typically handles values up to `2 * 10^9`). Therefore, no special large integer types are required.

The problem doesn't involve any complex algorithms or data structures; it's a direct application of basic programming constructs.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    *   Reading two integers (`L` and `B`) takes constant time.
    *   Calculating the area involves one multiplication, which is a constant time operation.
    *   Calculating the perimeter involves one addition and one multiplication, also constant time operations.
    *   Comparing the area and perimeter and printing the result involves a few comparisons and print statements, all of which are constant time operations.
    *   Since all operations take a fixed amount of time regardless of the input values (within the given constraints), the overall time complexity is constant.

*   **Space Complexity**: $O(1)$
    *   We declare a fixed number of variables: `L`, `B`, `area`, and `perimeter`. The memory used by these variables does not depend on the magnitude of `L` or `B`.
    *   Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    cin.tie(NULL);

    // Declare variables for length (L) and breadth (B) of the rectangle.
    // 'int' is sufficient for L and B, as their maximum values are 1000.
    // The calculated area (L*B) and perimeter (2*(L+B)) will also fit within
    // the typical range of an 'int' (up to 2*10^9).
    int L, B;

    // Read the length L from the first line of input.
    cin >> L;
    // Read the breadth B from the second line of input.
    cin >> B;

    // Calculate the area of the rectangle.
    // Formula: Area = Length * Breadth
    int area = L * B;

    // Calculate the perimeter of the rectangle.
    // Formula: Perimeter = 2 * (Length + Breadth)
    int perimeter = 2 * (L + B);

    // Compare the calculated area and perimeter to determine which is greater,
    // or if they are equal.
    if (area > perimeter) {
        // If the area is strictly greater than the perimeter:
        // Print "Area" on the first line.
        cout << "Area\n";
        // Print the calculated area on the second line.
        cout << area << "\n";
    } else if (perimeter > area) {
        // If the perimeter is strictly greater than the area:
        // Print "Peri" on the first line.
        cout << "Peri\n";
        // Print the calculated perimeter on the second line.
        cout << perimeter << "\n";
    } else { // This condition is met if area == perimeter
        // If the area and perimeter are equal:
        // Print "Eq" on the first line.
        cout << "Eq\n";
        // Print the value (either area or perimeter, as they are the same) on the second line.
        cout << area << "\n";
    }

    // The main function returns 0 to indicate successful execution of the program.
    return 0;
}
```