# [Parliament (PARLIAMENT)](https://www.codechef.com/problems/PARLIAMENT)
- **Difficulty Rating**: 419
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a resolution passes in a parliament. We are given two integers for each test case:
1. `N`: The total number of members present in the Parliament.
2. `X`: The number of members who voted in favour of the resolution.

According to the constitution, a resolution is passed if and only if "half or more than half the members present in the Parliament vote in favour". We need to print "YES" if the resolution passes, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in correctly interpreting the condition "half or more than half the members present in the Parliament vote in favour".

Let's denote the total members as `N` and members voting in favour as `X`.
The condition can be translated to: `X` must be greater than or equal to `N/2`.

However, when dealing with integer arithmetic, `N/2` behaves differently for even and odd `N`:
*   **If `N` is even (e.g., `N=10`)**: Half is `5`. The condition means `X >= 5`. Integer division `N/2` (i.e., `10/2`) correctly gives `5`. So, `X >= N/2` works.
*   **If `N` is odd (e.g., `N=9`)**: Half is `4.5`. "Half or more than half" means `X` must be at least `4.5`. Since `X` must be an integer, this implies `X >= 5`.
    *   If we use integer division `N/2` (i.e., `9/2`), it evaluates to `4`.
    *   So, `X >= N/2` (which would be `X >= 4`) would incorrectly pass the resolution if `X=4`.
    *   We need `X >= 5` for `N=9`.

To handle both even and odd `N` correctly with integer arithmetic, we can rephrase the condition `X >= N/2` by multiplying both sides by `2`:
`2 * X >= N`

Let's verify this revised condition:
*   **If `N` is even (e.g., `N=10`)**:
    *   Condition: `2 * X >= 10`
    *   Dividing by 2: `X >= 5`. This is correct.
*   **If `N` is odd (e.g., `N=9`)**:
    *   Condition: `2 * X >= 9`
    *   If `X=4`, `2*4 = 8`. `8 >= 9` is `false`. (Correct, `X=4` should not pass).
    *   If `X=5`, `2*5 = 10`. `10 >= 9` is `true`. (Correct, `X=5` should pass).
    *   This correctly captures that `X` must be at least `ceil(N/2)`.

Therefore, the condition `2 * X >= N` is the robust way to check if "half or more than half" members voted in favour, using integer arithmetic.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The program processes `T` test cases.
    *   For each test case, it reads two integers (`N` and `X`) and performs a constant number of arithmetic operations (multiplication, comparison) and a print operation. These operations take constant time.
    *   Thus, the total time complexity is directly proportional to the number of test cases, $O(T)$.

*   **Space Complexity**: $O(1)$
    *   The program uses a few integer variables (`T`, `N`, `X`) to store input and loop counters. These variables occupy a constant amount of memory regardless of the input values or the number of test cases.
    *   Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement

using namespace std; // Uses the standard namespace, as requested by the problem statement

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    // This significantly speeds up I/O operations, which is crucial for problems with large inputs or tight time limits.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, X; // Declare integer variables N and X for the current test case.
        cin >> N >> X; // Read N (total members) and X (members voted in favour) from standard input.

        // According to the constitution, a resolution is passed if and only if
        // "half or more than half the members present in the Parliament vote in favour".
        // This condition can be mathematically expressed as X >= N/2.
        //
        // To handle this condition correctly using integer arithmetic for both even and odd N,
        // we can multiply both sides of the inequality by 2:
        // 2 * X >= N
        //
        // Let's verify this logic:
        // Case 1: N is even (e.g., N=10). Half is 5.
        // The condition is X >= 5.
        // Using our logic: 2 * X >= 10.
        // If X=5, 2*5 = 10, so 10 >= 10 (True). Correct.
        // If X=4, 2*4 = 8, so 8 >= 10 (False). Correct.
        //
        // Case 2: N is odd (e.g., N=9). Half is 4.5.
        // "Half or more than half" means X must be at least 4.5. Since X must be an integer,
        // this implies X >= 5.
        // Using our logic: 2 * X >= 9.
        // If X=5, 2*5 = 10, so 10 >= 9 (True). Correct.
        // If X=4, 2*4 = 8, so 8 >= 9 (False). Correct.
        //
        // This logic correctly captures the problem's requirement for all valid N and X.

        if (2 * X >= N) {
            cout << "YES\n"; // If the condition is met, print "YES" followed by a newline.
        } else {
            cout << "NO\n"; // Otherwise, print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}
```