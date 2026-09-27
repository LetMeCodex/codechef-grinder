# [It is My Serve (MYSERVE)](https://www.codechef.com/problems/MYSERVE)
- **Difficulty Rating**: 691
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a table tennis match with a specific serving rule:
1. Alice serves the first two points.
2. Bob serves the next two points.
3. This pattern repeats: Alice, Alice, Bob, Bob, Alice, Alice, Bob, Bob, and so on.

Given Alice's current score `P` and Bob's current score `Q`, we need to determine whose turn it is to serve the *next* point.

## Intuition & Mathematical Observation

The core of this problem lies in identifying the serving pattern and relating it to the total number of points played.

1.  **Serving Cycle**: The serving pattern is Alice, Alice, Bob, Bob. This is a cycle of 4 serves.
    *   Serve 1: Alice
    *   Serve 2: Alice
    *   Serve 3: Bob
    *   Serve 4: Bob
    *   Serve 5: Alice
    *   Serve 6: Alice
    *   Serve 7: Bob
    *   Serve 8: Bob
    ...and so on.

2.  **Total Points Played**: If Alice has `P` points and Bob has `Q` points, then a total of `P + Q` points have been completed in the match.

3.  **Next Serve Index**: If `P + Q` points have been completed, the *next* serve will be the `(P + Q + 1)`-th serve in the match sequence. Let's call this `next_serve_index`.

4.  **Determining the Server using Modulo Arithmetic**:
    To figure out who serves the `next_serve_index`-th point, we can use the modulo operator with the cycle length (which is 4). It's often easier to work with 0-indexed values for modulo operations.
    Let's consider `(next_serve_index - 1)` to make it 0-indexed. This value represents the number of *completed* serves.
    *   If `(next_serve_index - 1) % 4` is 0 or 1, it corresponds to Alice's turn (e.g., 0th, 1st, 4th, 5th completed serves, which means 1st, 2nd, 5th, 6th actual serves).
    *   If `(next_serve_index - 1) % 4` is 2 or 3, it corresponds to Bob's turn (e.g., 2nd, 3rd, 6th, 7th completed serves, which means 3rd, 4th, 7th, 8th actual serves).

    Since `next_serve_index - 1 = (P + Q + 1) - 1 = P + Q`, we can simply check `(P + Q) % 4`.
    *   If `(P + Q) % 4` is 0 or 1, Alice serves.
    *   If `(P + Q) % 4` is 2 or 3, Bob serves.

This simple modulo operation allows us to determine the server for any given `P` and `Q`.

## Complexity Analysis

*   **Time Complexity**: $O(1)$
    For each test case, we perform a constant number of arithmetic operations (addition, modulo) and a comparison. These operations take constant time regardless of the input values `P` and `Q` (within integer limits). Since there are `T` test cases, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`T`, `P`, `Q`, `total_points_scored`, `next_serve_index`, `remainder`) to store input and intermediate results. The memory usage does not grow with the input values `P` and `Q`. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream and other standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int P, Q; // Declare integer variables P and Q for Alice's and Bob's scores
        cin >> P >> Q; // Read Alice's and Bob's scores for the current test case

        // Calculate the total number of points scored so far.
        int total_points_scored = P + Q;

        // The problem asks whose serve it is *now*, which means who will make the *next* serve.
        // If 'total_points_scored' points have been completed, the next serve will be the
        // (total_points_scored + 1)-th serve in the match sequence.
        int next_serve_index = total_points_scored + 1;

        // The serving pattern is: Alice (1st, 2nd), Bob (3rd, 4th), Alice (5th, 6th), Bob (7th, 8th), etc.
        // This is a cycle of 4 serves.
        // We can determine the server by looking at (next_serve_index - 1) modulo 4.
        // (next_serve_index - 1) is used to make it 0-indexed for modulo operation.
        // Note that (next_serve_index - 1) is simply 'total_points_scored'.
        //
        // If (total_points_scored) % 4 is:
        // 0: Corresponds to 1st, 5th, 9th serves (Alice)
        // 1: Corresponds to 2nd, 6th, 10th serves (Alice)
        // 2: Corresponds to 3rd, 7th, 11th serves (Bob)
        // 3: Corresponds to 4th, 8th, 12th serves (Bob)
        
        int remainder = total_points_scored % 4;

        // If the remainder is 0 or 1, it's Alice's serve.
        if (remainder == 0 || remainder == 1) {
            cout << "Alice\n";
        } else { // Otherwise, the remainder must be 2 or 3, so it's Bob's serve.
            cout << "Bob\n";
        }
    }

    return 0; // Indicate successful execution
}
```