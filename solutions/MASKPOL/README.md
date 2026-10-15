# [Mask Policy (MASKPOL)](https://www.codechef.com/problems/MASKPOL)
- **Difficulty Rating**: 1064
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of masks required to prevent the spread of a virus. We are given the total number of people `N` and the number of infected people `A`. The virus spreads when an infected person interacts with an uninfected person. We need to ensure that any such interaction does not lead to further infection.

## Intuition & Mathematical Observation

To stop the virus from spreading, we must ensure that no interaction between an infected person and an uninfected person results in transmission. There are two distinct groups of people:

1.  **Infected People**: There are `A` individuals in this group.
2.  **Uninfected People**: The remaining `N - A` individuals are uninfected.

To prevent transmission during an interaction between these two groups, we have two primary strategies:

1.  **Mask all infected people**: If all `A` infected individuals wear masks, they cannot transmit the virus to anyone, including the `N - A` uninfected people. This strategy requires `A` masks.
2.  **Mask all uninfected people**: If all `N - A` uninfected individuals wear masks, they cannot contract the virus from anyone, including the `A` infected people. This strategy requires `N - A` masks.

Since we want to find the *minimum* number of masks required, we should choose the strategy that uses fewer masks. Therefore, the minimum number of masks needed will be the smaller of these two quantities: `A` and `N - A`.

**Minimum Masks = min(A, N - A)**

## Complexity Analysis

*   **Time Complexity**: $O(T)$
    The program reads the number of test cases `T`. For each test case, it performs a constant number of operations: reading two integers (`N` and `A`), one subtraction (`N - A`), one `min` operation, and one print operation. All these operations take constant time, $O(1)$. Since these constant time operations are repeated `T` times, the total time complexity is $O(T)$.

*   **Space Complexity**: $O(1)$
    The program uses a fixed number of integer variables (`T`, `N`, `A`, `uninfected_people`, `min_masks`) to store input and intermediate results. The memory usage does not depend on the input size `N` or the number of test cases `T`. Hence, the space complexity is constant, $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, A; // N: total number of people, A: number of infected people
        cin >> N >> A; // Read N and A for the current test case

        // Calculate the number of uninfected people
        int uninfected_people = N - A;

        // To stop the virus spread, we need to ensure that any interaction
        // between an infected person and an uninfected person does not lead to infection.
        // This can be achieved by either:
        // 1. Masking all 'A' infected people. Cost = A masks.
        // 2. Masking all 'N - A' uninfected people. Cost = N - A masks.
        // The minimum number of masks required is the smaller of these two options.
        int min_masks = min(A, uninfected_people);

        // Output the result for the current test case, followed by a newline
        cout << min_masks << "\n";
    }

    return 0; // Indicate successful execution
}
```