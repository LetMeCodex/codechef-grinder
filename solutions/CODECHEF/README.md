# [Codechef Round (CODECHEF)](https://www.codechef.com/problems/CODECHEF)
- **Difficulty Rating**: 232
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a CodeChef round is held on a given day of the week. We are provided with an integer `N` representing the day. The days are numbered starting from 1 for Sunday, 2 for Monday, 3 for Tuesday, and so on. The problem statement explicitly mentions that CodeChef rounds are **only** held on Wednesday. We need to output "YES" if the given day `N` is a Wednesday, and "NO" otherwise.

## Intuition & Mathematical Observation

The problem is a straightforward conditional check based on a direct mapping of days to numbers.
According to the problem:
*   Sunday = 1
*   Monday = 2
*   Tuesday = 3
*   Wednesday = 4
*   Thursday = 5
*   Friday = 6
*   Saturday = 7

We are told that CodeChef rounds are *only* held on Wednesday. From the mapping, Wednesday corresponds to the number 4.
Therefore, the logic is simple:
1.  Read the input integer `N`.
2.  If `N` is equal to 4, it means the day is Wednesday, and a CodeChef round is held. Output "YES".
3.  Otherwise (if `N` is any other number from 1 to 7), it's not Wednesday, and no CodeChef round is held. Output "NO".

There are no complex algorithms, data structures, or mathematical observations beyond this direct comparison.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    The program performs a fixed number of operations regardless of the input value `N`: one integer read, one comparison, and one string print. All these operations take constant time.
*   **Space Complexity**: $O(1)$
    The program uses a constant amount of memory for storing the input integer `N` and a few standard library buffers. The memory usage does not scale with any input size.

## Solution Code

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the day of the week.
    cin >> N; // Read the integer N from standard input.

    // According to the problem statement:
    // Sunday is 1st, Monday is 2nd, Tuesday is 3rd, Wednesday is 4th, and so on.
    // Codechef rounds are held ONLY on Wednesday.
    // Therefore, we need to check if the input day N corresponds to Wednesday, which is the 4th day.
    if (N == 4) {
        cout << "YES\n"; // If N is 4, it's Wednesday, so output "YES".
    } else {
        cout << "NO\n"; // For any other day (N is not 4), output "NO".
    }

    return 0; // Indicate successful program execution.
}
```