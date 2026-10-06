# [Room Allocation (ROOMALLOC)](https://www.codechef.com/problems/ROOMALLOC)
- **Difficulty Rating**: 729
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the minimum total number of rooms required to accommodate students from `N` different colleges. For each college `i`, there are `A_i` members. The constraint is that each room can accommodate at most 2 people. We need to find the sum of the minimum rooms needed across all `N` colleges.

## Intuition & Mathematical Observation

The core of this problem lies in determining the minimum number of rooms for a single college with `A_i` members. To minimize the number of rooms, we should maximize the occupancy of each room, which means putting 2 people in a room whenever possible.

Let's consider the number of rooms needed for `A_i` members:

1.  **If `A_i` is even**: We can pair up all members perfectly. Each room will have 2 people. The number of rooms required will be `A_i / 2`.
    *   Example: If `A_i = 4`, rooms = `4 / 2 = 2`.
    *   Example: If `A_i = 2`, rooms = `2 / 2 = 1`.

2.  **If `A_i` is odd**: We can form `(A_i - 1) / 2` pairs, each occupying one room. This leaves 1 member remaining. This single remaining member will require an additional room. So, the total number of rooms will be `(A_i - 1) / 2 + 1`, which simplifies to `(A_i + 1) / 2`.
    *   Example: If `A_i = 3`, rooms = `(3 - 1) / 2 + 1 = 1 + 1 = 2`.
    *   Example: If `A_i = 1`, rooms = `(1 - 1) / 2 + 1 = 0 + 1 = 1`.

Both of these cases can be elegantly combined using the ceiling function: `ceil(A_i / 2)`.
In integer arithmetic, `ceil(X / Y)` can often be computed as `(X + Y - 1) / Y`. For our case, `ceil(A_i / 2)` becomes `(A_i + 2 - 1) / 2`, which simplifies to `(A_i + 1) / 2`. This integer division trick correctly handles both even and odd `A_i` values:

*   If `A_i = 1`: `(1 + 1) / 2 = 1`
*   If `A_i = 2`: `(2 + 1) / 2 = 1`
*   If `A_i = 3`: `(3 + 1) / 2 = 2`
*   If `A_i = 4`: `(4 + 1) / 2 = 2`

So, for each college, we calculate `(A_i + 1) / 2` and add it to a running total. This total will be our final answer.

## Complexity Analysis

*   **Time Complexity**: $O(T \cdot N)$
    *   There are `T` test cases.
    *   For each test case, we read `N` and then iterate `N` times to read `A_i` for each college.
    *   Inside the loop, we perform a constant number of arithmetic operations (addition, division) and an assignment.
    *   Therefore, the time complexity per test case is $O(N)$, and for `T` test cases, it's $O(T \cdot N)$.
    *   Given `T <= 100` and `N <= 100`, the maximum operations would be around `100 * 100 = 10,000`, which is very efficient and well within typical time limits.

*   **Space Complexity**: $O(1)$
    *   The solution uses a few integer variables (`T`, `N`, `total_rooms`, `A_i`) to store input and intermediate calculations. The amount of memory used does not depend on the input size `N`.
    *   Hence, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> 

// Using the standard namespace to avoid writing std:: before cin, cout, etc.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can further speed up I/O in interactive problems or problems with mixed I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N; // Variable to store the number of colleges
        cin >> N; // Read the number of colleges

        long long total_rooms = 0; // Variable to store the total minimum rooms needed.
                                   // Using long long to be safe, though 'int' would suffice
                                   // given the constraints (max 100 colleges * 50 rooms/college = 5000).

        // Loop N times to read the number of members from each college
        for (int i = 0; i < N; ++i) {
            int A_i; // Variable to store the number of members from the i-th college
            cin >> A_i; // Read A_i

            // Calculate rooms needed for the current college:
            // Each room can accommodate at most 2 people.
            // To minimize rooms, we put 2 people per room whenever possible.
            // The formula (A_i + 1) / 2 using integer division correctly calculates
            // the ceiling of A_i / 2.
            // For example:
            // A_i = 1 => (1+1)/2 = 1 room
            // A_i = 2 => (2+1)/2 = 1 room
            // A_i = 3 => (3+1)/2 = 2 rooms
            // A_i = 4 => (4+1)/2 = 2 rooms
            total_rooms += (A_i + 1) / 2;
        }

        // Output the total minimum rooms for the current test case, followed by a newline.
        cout << total_rooms << "\n";
    }

    return 0; // Indicate successful execution
}
```