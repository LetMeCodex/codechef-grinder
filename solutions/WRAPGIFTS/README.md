# [Christmas Gifts (WRAPGIFTS)](https://www.codechef.com/problems/WRAPGIFTS)
- **Difficulty Rating**: 574
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the maximum number of complete gift boxes Chef can wrap. We are given the dimensions (Height `H`, Length `L`, and Width `W`) of a single rectangular gift box. Chef has a fixed amount of wrapping paper: 1000 square centimeters. We need to calculate how many such gift boxes can be completely covered by this paper.

## Intuition & Mathematical Observation

The core idea is to figure out how much wrapping paper is needed for *one* gift box, and then see how many times that amount fits into the total available paper.

1.  **Wrapping Paper for One Gift**: A rectangular gift box is a cuboid. The amount of wrapping paper required to cover it completely is equal to its total surface area. A cuboid has 6 faces, with three pairs of identical faces:
    *   Two faces with dimensions Length (`L`) x Width (`W`) (top and bottom).
    *   Two faces with dimensions Length (`L`) x Height (`H`) (front and back).
    *   Two faces with dimensions Width (`W`) x Height (`H`) (left and right).

    The total surface area (`TSA`) of one gift box can be calculated as:
    `TSA = 2 * (L * W) + 2 * (L * H) + 2 * (W * H)`
    This can be simplified to:
    `TSA = 2 * (L * W + L * H + W * H)`

2.  **Maximum Number of Gifts**: Once we have the `TSA` for one gift, we can find out how many complete gifts Chef can wrap by dividing the `total_paper_area` (which is 1000 sq cm) by the `TSA`. Since we are interested in *complete* gifts, any fractional part from the division should be discarded. Integer division in most programming languages (like C++) automatically handles this truncation.

    `max_gifts = total_paper_area / TSA` (using integer division)

The problem constraints state that H, L, W are between 1 and 10. This ensures that the surface area of one gift will be small enough to fit comfortably within a standard integer type, and the calculations will not overflow.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program processes `T` test cases. For each test case, it performs a fixed number of arithmetic operations (reading three integers, a few multiplications, additions, and one division) and one print operation. These operations take constant time, independent of the input values H, L, W (as they are small). Therefore, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `H`, `L`, `W`, `surface_area_one_gift`, `max_gifts`, `total_paper_area`) to store input and intermediate results. The amount of memory used does not depend on the magnitude of the input values or the number of test cases (beyond storing `T` itself). Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

int main() {
    // Optimize C++ standard streams for competitive programming.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    std::cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int H, L, W; // Declare integer variables for Height, Length, and Width of the gift box.
        std::cin >> H >> L >> W; // Read the dimensions for the current test case.

        // Calculate the surface area of one gift box.
        // A rectangular box has 6 faces:
        // - Two faces with dimensions L x W (top and bottom). Area: 2 * L * W
        // - Two faces with dimensions L x H (front and back). Area: 2 * L * H
        // - Two faces with dimensions W x H (left and right). Area: 2 * W * H
        // Total Surface Area = 2 * (L*W + L*H + W*H)
        // All dimensions (H, L, W) are small (1 to 10), so intermediate products
        // and the final surface area will easily fit within an 'int' type.
        int surface_area_one_gift = 2 * (L * W + L * H + W * H);

        // The total available wrapping paper area is a constant 1000 square centimeters.
        const int total_paper_area = 1000;

        // Calculate the maximum number of complete gifts Chef can wrap.
        // This is found by dividing the total available paper area by the surface area
        // required for one gift. Integer division automatically truncates any fractional
        // part, giving us the number of *complete* gifts.
        int max_gifts = total_paper_area / surface_area_one_gift;

        // Output the result for the current test case, followed by a newline character.
        std::cout << max_gifts << "\n";
    }

    return 0; // Indicate successful program execution.
}
```