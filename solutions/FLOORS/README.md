# [Too many Floors (FLOORS)](https://www.codechef.com/problems/FLOORS)
- **Difficulty Rating**: 717
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the absolute difference in floor numbers between two given room numbers, `X` and `Y`. We are told that each floor contains exactly 10 rooms. Rooms are numbered sequentially starting from 1. This means:
- Rooms 1 to 10 are on Floor 1.
- Rooms 11 to 20 are on Floor 2.
- Rooms 21 to 30 are on Floor 3.
And so on.

We need to process multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is to determine the floor number for any given room number. Let's denote a room number as `R`.

Consider the pattern:
- For `R` from 1 to 10, the floor is 1.
- For `R` from 11 to 20, the floor is 2.
- For `R` from 21 to 30, the floor is 3.

If we use integer division by 10:
- `1 / 10 = 0`, `10 / 10 = 1` (for room 10, this is problematic if we just add 1)
- `11 / 10 = 1`, `20 / 10 = 2`

A common trick for problems involving groups of `N` items starting from 1 is to adjust the number to be 0-indexed before division. If we subtract 1 from the room number, then divide by 10, and finally add 1, it should work:

Let's test the formula `(R - 1) / 10 + 1`:
- For `R = 1` (first room on Floor 1): `(1 - 1) / 10 + 1 = 0 / 10 + 1 = 0 + 1 = 1`. Correct.
- For `R = 10` (last room on Floor 1): `(10 - 1) / 10 + 1 = 9 / 10 + 1 = 0 + 1 = 1`. Correct.
- For `R = 11` (first room on Floor 2): `(11 - 1) / 10 + 1 = 10 / 10 + 1 = 1 + 1 = 2`. Correct.
- For `R = 20` (last room on Floor 2): `(20 - 1) / 10 + 1 = 19 / 10 + 1 = 1 + 1 = 2`. Correct.
- For `R = 21` (first room on Floor 3): `(21 - 1) / 10 + 1 = 20 / 10 + 1 = 2 + 1 = 3`. Correct.

This formula `(room_number - 1) / 10 + 1` correctly calculates the floor number for any given `room_number`.

Once we have the floor numbers for `X` and `Y` (let's call them `floor_x` and `floor_y`), the problem simply asks for the absolute difference between them: `abs(floor_x - floor_y)`.

The solution involves:
1. Reading the two room numbers, `X` and `Y`.
2. Calculating `floor_x = (X - 1) / 10 + 1`.
3. Calculating `floor_y = (Y - 1) / 10 + 1`.
4. Printing `abs(floor_x - floor_y)`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    For each test case, we perform a constant number of arithmetic operations (subtraction, division, addition) and one absolute difference calculation. These operations take constant time. If there are $T$ test cases, the total time complexity will be proportional to $T$.

-   **Space Complexity**: $O(1)$
    We only use a few integer variables to store the input room numbers (`x`, `y`), their respective floor numbers (`floor_x`, `floor_y`), and the number of test cases (`t`). The amount of memory used does not depend on the input values or the number of test cases, making it constant space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes common headers like iostream, cmath (for abs)
using namespace std;

// Function to calculate the floor number for a given room number
int get_floor(int room_number) {
    // Formula: (room_number - 1) / 10 + 1
    // Subtract 1 to make it 0-indexed for division, then divide by 10 (rooms per floor)
    // Add 1 back to convert to 1-indexed floor number
    return (room_number - 1) / 10 + 1;
}

int main() {
    // Optimize C++ standard streams for faster input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) { // Loop through each test case
        int x, y; // Room numbers
        cin >> x >> y;

        // Calculate floor numbers for x and y using the helper function
        int floor_x = get_floor(x);
        int floor_y = get_floor(y);

        // Print the absolute difference between the floor numbers
        cout << abs(floor_x - floor_y) << "\n";
    }

    return 0; // Indicate successful execution
}

```