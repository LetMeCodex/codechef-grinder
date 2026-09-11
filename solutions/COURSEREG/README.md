# [Course Registration (COURSEREG)](https://www.codechef.com/problems/COURSEREG)
- **Difficulty Rating**: 470
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if it's possible for `N` friends to register for a course. We are given three integers for each test case:
1. `N`: The number of friends who want to register.
2. `M`: The maximum capacity of the course.
3. `K`: The number of students who have already registered for the course.

We need to output "Yes" if all `N` friends can register without exceeding the course capacity, and "No" otherwise.

## Intuition & Mathematical Observation

The core idea is to calculate the total number of students that would be in the course if all `N` friends successfully register. This total would be the sum of students already registered (`K`) and the `N` friends who wish to register.

Let `total_students_if_friends_enroll = K + N`.

Now, we compare this calculated total with the maximum capacity of the course, `M`.
- If `total_students_if_friends_enroll` is less than or equal to `M` (i.e., `K + N <= M`), it means there is enough space for all `N` friends to register. In this case, the answer is "Yes".
- If `total_students_if_friends_enroll` is greater than `M` (i.e., `K + N > M`), it means registering all `N` friends would exceed the course capacity. In this case, the answer is "No".

This is a simple arithmetic calculation followed by a comparison.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a constant number of operations: reading three integers, one addition, one comparison, and printing a string. All these operations take constant time, $O(1)$. Therefore, the total time complexity is proportional to the number of test cases, $O(T)$.

-   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `N`, `M`, `K`, `total_students_after_friends_enroll`) to store input and intermediate results. The memory usage does not depend on the magnitude of the input values or the number of test cases (beyond the storage for `T` itself). Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes almost all standard library headers

// The problem statement specifically requests using namespace std;
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int N, M, K;
        // Read the three integers N, M, and K for the current test case
        cin >> N >> M >> K;

        // Calculate the total number of students that would be in the course
        // if all N friends successfully enroll.
        int total_students_after_friends_enroll = K + N;

        // Check if this total number of students is within the course's maximum capacity M.
        // If total_students_after_friends_enroll is less than or equal to M,
        // then it is possible for all N friends to enroll.
        if (total_students_after_friends_enroll <= M) {
            cout << "Yes\n"; // Output "Yes" if possible
        } else {
            // Otherwise, if the total exceeds M, it's not possible.
            cout << "No\n"; // Output "No" if not possible
        }
    }

    return 0; // Indicate successful program execution
}
```