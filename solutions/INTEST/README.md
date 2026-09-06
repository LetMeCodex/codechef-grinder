# [Enormous Input Test (INTEST)](https://www.codechef.com/problems/INTEST)
- **Difficulty Rating**: 464
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to read two positive integers, `N` and `K`, from the first line of input. Following this, there will be `N` lines, each containing a single integer `T`. Our task is to count how many of these `N` integers (`T`) are divisible by `K`. The problem statement explicitly mentions that its purpose is to test the speed of I/O, implying that standard input/output operations might be a bottleneck for large inputs.

## Intuition & Mathematical Observation

The core of the problem is straightforward: checking divisibility. An integer `T` is divisible by another integer `K` if the remainder of their division is 0. In programming, this is typically checked using the modulo operator (`%`). So, `T % K == 0` is the condition we need to verify for each `T`.

The "enormous input" hint is the most critical aspect for competitive programming. For C++, standard `cin`/`cout` can be slow due to synchronization with C's `stdio` library and flushing operations. To overcome this, we employ two common optimizations:
1.  `ios_base::sync_with_stdio(false);`: This unties C++ standard streams from C standard streams, allowing them to operate independently and often much faster.
2.  `cin.tie(NULL);`: This prevents `cin` from flushing `cout` before each input operation. By default, `cin` flushes `cout`, which can add significant overhead in input-heavy programs. Setting `cin.tie(NULL)` disables this behavior.

By applying these optimizations, we can process a large number of inputs efficiently. The overall approach is to initialize a counter to zero, loop `N` times, read each `T`, check its divisibility by `K`, and increment the counter if it's divisible. Finally, print the total count.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading `N` and `K` takes constant time, $O(1)$.
    -   The program then enters a loop that iterates `N` times.
    -   Inside the loop, reading an integer `ti`, performing a modulo operation (`ti % k`), and incrementing a counter (`count++`) are all constant time operations, $O(1)$.
    -   Finally, printing the `count` takes constant time, $O(1)$.
    -   Since the loop runs `N` times and each operation inside it is constant time, the dominant factor is the loop, leading to a total time complexity of $O(N)$.

-   **Space Complexity**: $O(1)$
    -   We use a few integer variables: `n`, `k`, `count`, and `ti`. The memory required for these variables is constant and does not depend on the input size `N`.
    -   No arrays, data structures, or recursive calls are used that would consume memory proportional to the input size.
    -   Therefore, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // allowing them to operate independently and often faster.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can significantly speed up input-heavy programs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    // Read the two positive integers n and k from the first line of input.
    // n represents the number of subsequent integers, and k is the divisor.
    cin >> n >> k;

    int count = 0; // Initialize a counter for numbers divisible by k.

    // Loop n times to read each of the n subsequent integers.
    for (int i = 0; i < n; ++i) {
        int ti;
        // Read the current integer ti.
        cin >> ti;

        // Check if ti is divisible by k.
        // The modulo operator (%) returns the remainder of a division.
        // If the remainder is 0, ti is divisible by k.
        if (ti % k == 0) {
            count++; // Increment the counter if ti is divisible by k.
        }
    }

    // Print the total count of integers divisible by k, followed by a newline.
    cout << count << "\n";

    return 0; // Indicate successful execution.
}
```