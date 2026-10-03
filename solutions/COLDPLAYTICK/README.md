# [Coldplay Tickets (COLDPLAYTICK)](https://www.codechef.com/problems/COLDPLAYTICK)
- **Difficulty Rating**: 292
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to calculate the total cost for attending a Coldplay concert. We are given the number of friends, `N`, who will accompany us. Each ticket for the concert costs 5000 INR. We need to determine the total amount of money required to purchase tickets for ourselves and all `N` friends.

## Intuition & Mathematical Observation

The core of the problem lies in correctly identifying the total number of people who need tickets.
1.  **Yourself**: You, as the person organizing, will need one ticket.
2.  **Friends**: Your `N` friends will each need one ticket.

Combining these, the total number of people for whom tickets must be purchased is `N` (friends) + `1` (yourself).
So, `Total People = N + 1`.

Given that each ticket costs 5000 INR, the total cost will be the product of the total number of people and the cost per ticket.
`Total Cost = (Total People) * 5000`
Substituting `Total People`, we get:
`Total Cost = (N + 1) * 5000`

Let's consider the constraints: `1 <= N <= 5`.
*   If `N = 1` (1 friend): Total people = 1 + 1 = 2. Total cost = 2 * 5000 = 10000 INR.
*   If `N = 5` (5 friends): Total people = 5 + 1 = 6. Total cost = 6 * 5000 = 30000 INR.

The maximum possible total cost (30000 INR) fits comfortably within a standard 32-bit integer type. However, using `long long` for the `total_cost` variable is a good general practice in competitive programming to prevent potential integer overflows, especially if constraints were larger.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input `N`: one input read, one addition, one multiplication, and one output print. These operations take constant time. Therefore, the time complexity is constant.

*   **Space Complexity**: $O(1)$
    The program uses a few variables (`N`, `total_people`, `total_cost`) to store data. The amount of memory used by these variables does not depend on the input `N` and remains constant. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    cin.tie(NULL);

    // Declare an integer variable N to store the number of friends.
    // According to constraints, 1 <= N <= 5.
    int N;

    // Read the value of N from standard input.
    cin >> N;

    // Calculate the total number of people for whom tickets are needed.
    // This includes N friends and 1 ticket for yourself.
    // So, total_people = N + 1.
    int total_people = N + 1;

    // Calculate the total cost.
    // Each ticket costs 5000 INR.
    // The maximum possible value for total_people is 5 (friends) + 1 (yourself) = 6.
    // The maximum total cost will be 6 * 5000 = 30000 INR.
    // This value fits comfortably within a standard 'int' data type.
    // However, using 'long long' for the result is a good general practice in
    // competitive programming to prevent potential integer overflows, even if
    // not strictly necessary for these specific constraints.
    long long total_cost = (long long)total_people * 5000;

    // Print the calculated total cost to standard output,
    // followed by a newline character as required.
    cout << total_cost << "\n";

    // Return 0 to indicate successful program execution.
    return 0;
}
```