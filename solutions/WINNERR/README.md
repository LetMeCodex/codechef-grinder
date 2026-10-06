# [Determine the Winner (WINNERR)](https://www.codechef.com/problems/WINNERR)
- **Difficulty Rating**: 626
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine the winner between two participants, P and Q, in a programming contest. Each participant attempts two problems, A and B. Participant P takes `PA` minutes to solve problem A and `PB` minutes to solve problem B. Similarly, participant Q takes `QA` minutes for problem A and `QB` minutes for problem B.

The winner is the participant who finishes *both* problems earlier. If both participants finish both problems at the exact same time, the result is a "TIE". We need to output "P", "Q", or "TIE" accordingly.

## Intuition & Mathematical Observation

The core of this problem lies in understanding what it means for a participant to "finish both problems". A participant has truly completed both problems only when the *later* of their two problem-solving times has passed.

Let's consider participant P:
*   P solves problem A in `PA` minutes.
*   P solves problem B in `PB` minutes.
*   To have *both* problems solved, P must wait until the time taken for the slower of the two problems has elapsed. For example, if `PA = 10` and `PB = 15`, P has solved problem A at 10 minutes, but problem B is still ongoing until 15 minutes. Thus, P has completed both problems only at the 15-minute mark.
*   Mathematically, the time at which participant P finishes both problems is `max(PA, PB)`. Let's call this `penalty_P`.

Similarly, for participant Q:
*   Q solves problem A in `QA` minutes.
*   Q solves problem B in `QB` minutes.
*   The time at which participant Q finishes both problems is `max(QA, QB)`. Let's call this `penalty_Q`.

Once we have calculated `penalty_P` and `penalty_Q`, determining the winner is straightforward:
1.  If `penalty_P < penalty_Q`, participant P wins because they finished both problems earlier.
2.  If `penalty_Q < penalty_P`, participant Q wins.
3.  If `penalty_P == penalty_Q`, it's a TIE.

This logic holds true for all test cases.

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    *   The `solve()` function performs a fixed number of operations: four integer reads, two `std::max` comparisons, and one `std::cout` operation. All these operations take constant time, so `solve()` is $O(1)$.
    *   The `main()` function calls `solve()` `T` times, where `T` is the number of test cases.
    *   Therefore, the total time complexity is $O(T \times 1) = O(T)$.

*   **Space Complexity**: $O(1)$
    *   Inside the `solve()` function, we declare a constant number of integer variables (`PA`, `PB`, `QA`, `QB`, `penalty_P`, `penalty_Q`). These variables consume a fixed amount of memory regardless of the input values (within integer limits).
    *   No data structures are used that grow with the input size.
    *   Thus, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::max

// It's common in competitive programming to include <bits/stdc++.h>
// which includes most standard libraries, and use namespace std.
// However, for specific needs, including only what's necessary is good practice.
// For this problem, iostream and algorithm are sufficient.
// #include <bits/stdc++.h> 
// using namespace std;

void solve() {
    int PA, PB, QA, QB;
    std::cin >> PA >> PB >> QA >> QB;

    // Calculate time penalty for participant P
    // The penalty is the minimum time instant at which both problems are solved.
    // This means P must have solved problem A (at PA) AND problem B (at PB).
    // So, P has solved both problems only after the later of the two times.
    int penalty_P = std::max(PA, PB);

    // Calculate time penalty for participant Q
    // Similarly, Q has solved both problems only after the later of their two times.
    int penalty_Q = std::max(QA, QB);

    // Determine the winner based on penalties
    if (penalty_P < penalty_Q) {
        std::cout << "P\n";
    } else if (penalty_Q < penalty_P) {
        std::cout << "Q\n";
    } else { // penalty_P == penalty_Q
        std::cout << "TIE\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0;
}
```