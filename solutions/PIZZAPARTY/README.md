# [Pizza Party (PIZZAPARTY)](https://www.codechef.com/problems/PIZZAPARTY)
- **Difficulty Rating**: 238
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum number of pizzas required for a party. We are given the number of invited boys (`A`) and invited girls (`B`). Chef is also attending the party and is a boy. Each boy eats 4 slices of pizza, and each girl eats 3 slices. A single pizza always has 8 slices. We need to output the total minimum number of pizzas required.

## Intuition & Mathematical Observation

The core idea is to first calculate the total number of pizza slices needed, and then determine how many 8-slice pizzas are required to cover those slices.

1.  **Count Total Attendees**:
    *   The problem states `A` boys are invited, and Chef is also a boy attending. So, the total number of boys present will be `A + 1`.
    *   The number of girls present is simply `B`.

2.  **Calculate Total Slices Needed**:
    *   Each boy eats 4 slices. So, boys will consume `(total_boys) * 4` slices.
    *   Each girl eats 3 slices. So, girls will consume `(total_girls) * 3` slices.
    *   The total number of slices required is the sum of slices consumed by boys and girls: `(A + 1) * 4 + B * 3`.

3.  **Determine Minimum Pizzas**:
    *   Each pizza has 8 slices. To find the minimum number of pizzas, we need to perform *ceiling division*. If `S` is the total slices needed and `P` is the number of slices per pizza (which is 8), then the number of pizzas required is `ceil(S / P)`.
    *   For positive integers `x` and `y`, the ceiling division `ceil(x / y)` can be efficiently calculated using integer arithmetic as `(x + y - 1) / y`.
    *   Applying this, the minimum pizzas needed will be `(total_slices + 8 - 1) / 8`.

**Example Walkthrough**:
Let `A = 1` (1 invited boy) and `B = 2` (2 invited girls).
*   Total boys = `A + 1 = 1 + 1 = 2`
*   Total girls = `B = 2`
*   Slices for boys = `2 * 4 = 8`
*   Slices for girls = `2 * 3 = 6`
*   Total slices needed = `8 + 6 = 14`
*   Pizzas needed = `(14 + 8 - 1) / 8 = 21 / 8 = 2` (integer division).
    *   (Mathematically, `ceil(14 / 8) = ceil(1.75) = 2`).

The maximum values for `A` and `B` are 100.
*   Max total boys = `100 + 1 = 101`
*   Max total girls = `100`
*   Max slices needed = `101 * 4 + 100 * 3 = 404 + 300 = 704`
*   Max pizzas needed = `(704 + 8 - 1) / 8 = 711 / 8 = 88`
All these values fit comfortably within standard `int` data types. Using `long long` as in the provided solution is a safe practice in competitive programming to prevent potential overflows, even if not strictly necessary for these constraints.

## Complexity Analysis

-   **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (addition, multiplication, division) and input/output operations, regardless of the values of `A` and `B` (within their constraints). These operations take constant time.

-   **Space Complexity**: $O(1)$
    The solution uses a fixed number of variables (`A`, `B`, `total_boys`, `total_girls`, `slices_needed`, `pizzas_needed`) to store intermediate results. The memory usage does not grow with the input values.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout, std::ios_base, std::endl
#include <cstddef>  // Required for NULL (or use nullptr directly)

// Function to encapsulate the problem logic for a single test case
void solve() {
    int A, B;
    // Read the number of invited boys (A) and girls (B)
    std::cin >> A >> B;

    // Chef is a boy, so add 1 to the count of boys.
    int total_boys = A + 1;
    int total_girls = B;

    // Calculate the total number of slices needed.
    // A boy eats 4 slices, a girl eats 3 slices.
    // Using long long for slices_needed to be safe, though int is sufficient for given constraints.
    long long slices_needed = (long long)total_boys * 4 + (long long)total_girls * 3;

    // A single pizza has 8 slices.
    // To find the minimum number of pizzas, we perform ceiling division.
    // For positive integers x and y, ceil(x/y) can be calculated as (x + y - 1) / y.
    long long pizzas_needed = (slices_needed + 8 - 1) / 8;

    // Output the result
    std::cout << pizzas_needed << std::endl;
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); // Or std::cin.tie(nullptr); for modern C++

    // The problem statement indicates only one test case,
    // so we call the solve function once.
    solve();

    return 0;
}

```