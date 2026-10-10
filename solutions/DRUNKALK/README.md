# [Drunk Alcoholic (DRUNKALK)](https://www.codechef.com/problems/DRUNKALK)
- **Difficulty Rating**: 874
- **Solved in**: 1 attempt(s)

## Problem Summary

Faizal, an alcoholic, starts at position 0 on a number line. His movement pattern is as follows:
- For the 1st second, he moves 3 steps forward.
- For the 2nd second, he moves 1 step backward.
- For the 3rd second, he moves 3 steps forward.
- For the 4th second, he moves 1 step backward.
And so on. This pattern continues for `k` seconds. We need to determine Faizal's final position after `k` seconds.

## Intuition & Mathematical Observation

Let's trace Faizal's position for the first few seconds to identify a pattern:
- **After 1 second (k=1):** Moves +3. Final position: `3`.
- **After 2 seconds (k=2):** Moves +3 (1st sec), then -1 (2nd sec). Final position: `3 - 1 = 2`.
- **After 3 seconds (k=3):** Moves +3, -1, then +3 (3rd sec). Final position: `2 + 3 = 5`.
- **After 4 seconds (k=4):** Moves +3, -1, +3, then -1 (4th sec). Final position: `5 - 1 = 4`.
- **After 5 seconds (k=5):** Moves +3, -1, +3, -1, then +3 (5th sec). Final position: `4 + 3 = 7`.

We can observe a repeating cycle of movement over two seconds:
- **Odd second:** Faizal moves +3 steps.
- **Even second:** Faizal moves -1 step.

Combining these two, over a full 2-second cycle (one odd second and one even second), the net displacement is `+3 - 1 = +2` steps.

Now, let's analyze based on whether `k` is even or odd:

1.  **If `k` is an even number of seconds:**
    Let `k = 2m` for some integer `m`.
    Faizal completes `m` full cycles of 2 seconds each.
    Since each 2-second cycle results in a net displacement of +2 steps, after `m` cycles, the total displacement will be `m * 2`.
    Substituting `m = k/2`, the total displacement is `(k/2) * 2 = k`.
    So, if `k` is even, Faizal's final position is `k`.
    (e.g., k=2, position=2; k=4, position=4)

2.  **If `k` is an odd number of seconds:**
    Let `k = 2m + 1` for some integer `m`.
    Faizal completes `m` full cycles of 2 seconds each, and then takes one final step which corresponds to an odd second.
    The `m` full cycles result in a displacement of `m * 2` steps.
    The final step (the `(2m+1)`-th second) is an odd second, so it adds +3 steps to his position.
    Total displacement = `(m * 2) + 3`.
    Since `k = 2m + 1`, we have `2m = k - 1`.
    Substituting this into the total displacement: `(k - 1) + 3 = k + 2`.
    So, if `k` is odd, Faizal's final position is `k + 2`.
    (e.g., k=1, position=3 (1+2); k=3, position=5 (3+2); k=5, position=7 (5+2))

This covers all cases and provides a simple formula based on the parity of `k`.

## Complexity Analysis

-   **Time Complexity**: $O(T)$
    The program iterates `T` times, once for each test case. Inside the loop, it performs a constant number of operations: reading an integer, a modulo operation, an `if-else` check, and a simple arithmetic calculation. These operations take constant time, $O(1)$. Therefore, the total time complexity is directly proportional to the number of test cases, `T`.

-   **Space Complexity**: $O(1)$
    The program uses a few integer variables (`T`, `k`) to store input and intermediate results. The memory usage for these variables is constant and does not depend on the input size `k` or the number of test cases `T`. No dynamic data structures or arrays are used that would scale with input.

## Solution Code

```cpp
#include <bits/stdc++.h> // Standard header for competitive programming

// Use the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop T times, once for each test case.
    while (T--) {
        int k; // Declare an integer variable k for the number of seconds.
        cin >> k; // Read the value of k for the current test case.

        // Determine Faizal's final position based on whether k is even or odd.
        if (k % 2 == 0) {
            // If k is an even number of seconds:
            // Faizal completes k/2 full cycles of movement.
            // Each cycle consists of 3 steps forward and then 1 step backward,
            // resulting in a net displacement of +2 steps per cycle.
            // So, after k/2 cycles, the total displacement is (k/2) * 2 = k.
            cout << k << "\n";
        } else {
            // If k is an odd number of seconds:
            // Faizal completes (k-1)/2 full cycles of movement,
            // and then takes one final 3 steps forward.
            // The (k-1)/2 cycles result in a displacement of ((k-1)/2) * 2 = k-1 steps.
            // The final 3 steps forward add 3 more to this displacement.
            // So, the total displacement is (k-1) + 3 = k+2.
            cout << k + 2 << "\n";
        }
    }

    return 0; // Indicate successful execution of the program.
}
```