# [Important Pages on CodeChef (CHEFPAGES)](https://www.codechef.com/problems/CHEFPAGES)
- **Difficulty Rating**: 719
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine which CodeChef page to recommend to a user based on their activity. We are given two binary integer inputs, `A` and `B`, where:
- `A = 1` signifies that the user has submitted a solution on the practice page.
- `A = 0` signifies that the user has NOT submitted a solution on the practice page.
- `B = 1` signifies that the user has participated in a contest.
- `B = 0` signifies that the user has NOT participated in a contest.

Based on these inputs, we need to print one of three specific URLs:
1.  If the user has **never submitted on the practice page** (`A = 0`), output: `https://www.codechef.com/practice`
2.  If the user **has submitted on the practice page** (`A = 1`) but **has never participated in a contest** (`B = 0`), output: `https://www.codechef.com/contests`
3.  If the user **has submitted on the practice page** (`A = 1`) AND **has participated in a contest** (`B = 1`), output: `https://discuss.codechef.com`

## Intuition & Mathematical Observation
This problem is a straightforward exercise in conditional logic. There are no complex algorithms, data structures, or advanced mathematical concepts involved. The core idea is to directly translate the given rules into a series of `if-else if-else` statements.

The problem statement defines a clear hierarchy for checking the conditions:
1.  The first condition, `A = 0` (user has not practiced), takes precedence. If this is true, we immediately recommend the practice page, regardless of the value of `B`.
2.  If `A` is not `0` (meaning `A` must be `1`, as per problem constraints), then the user *has* submitted on the practice page. At this point, we proceed to check their contest participation status (`B`).
3.  If `A = 1` and `B = 0` (user has practiced but not participated in a contest), we recommend the contests page.
4.  If `A = 1` and `B = 1` (user has practiced and participated in a contest), we recommend the discuss forum.

This hierarchical decision-making process can be perfectly implemented using nested `if-else` statements or a sequential `if-else if-else` structure, ensuring that the conditions are evaluated in the specified order.

## Complexity Analysis
-   **Time Complexity**: $O(1)$
    The program performs a constant number of operations: reading two integers, a few comparisons, and printing a string. These operations take a fixed amount of time, irrespective of the input values (since `A` and `B` are always 0 or 1). Therefore, the execution time does not scale with any input size, resulting in constant time complexity.

-   **Space Complexity**: $O(1)$
    The program uses a fixed amount of memory to store two integer variables (`A` and `B`) and some internal buffers for input/output operations. This memory usage does not depend on the input values or any other variable factor, hence it is constant space complexity.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations by not synchronizing with C's stdio.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O, especially in interactive problems or those with
    // mixed input and output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables, A and B, to store the input values.
    // A represents whether the user has submitted on the practice page (1 for yes, 0 for no).
    // B represents whether the user has participated in a contest (1 for yes, 0 for no).
    int A, B;

    // Read the two space-separated integers A and B from standard input.
    cin >> A >> B;

    // The problem defines three conditions based on A and B to determine
    // which URL to output. We implement these conditions using if-else if-else statements.

    // Condition 1: If the user has never submitted on the practice page (A = 0).
    // This condition takes precedence. If A is 0, it doesn't matter what B is.
    if (A == 0) {
        // Output the link to the practice page.
        cout << "https://www.codechef.com/practice\n";
    }
    // If A is not 0, it must be 1 (since A is constrained to be 0 or 1).
    // This means the user HAS submitted on the practice page.
    else { // A == 1
        // Now we check the second condition: if the user has submitted on the practice page (A=1)
        // but has never participated in a contest (B = 0).
        if (B == 0) {
            // Output the link to the contests page.
            cout << "https://www.codechef.com/contests\n";
        }
        // If B is not 0, it must be 1 (since B is constrained to be 0 or 1).
        // This implies that A=1 AND B=1, meaning the user has submitted on the practice page
        // AND has participated in a contest.
        else { // B == 1
            // Output the link to the discuss forum.
            cout << "https://discuss.codechef.com\n";
        }
    }

    // The program successfully completes after printing the required output.
    return 0;
}
```