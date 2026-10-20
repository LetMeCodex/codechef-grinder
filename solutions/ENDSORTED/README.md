# [End Sorted (ENDSORTED)](https://www.codechef.com/problems/ENDSORTED)
- **Difficulty Rating**: 1049
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum number of adjacent swaps required to transform a given permutation $P$ of length $N$ such that the element '1' is at the first position (index 1) and the element 'N' is at the last position (index $N$). The remaining elements can be in any order.

## Intuition & Mathematical Observation

1.  **Goal**: We need to move '1' to index 1 and 'N' to index $N$. The positions of other elements don't matter.
2.  **Adjacent Swaps**: An adjacent swap allows an element to move one position to the left or one position to the right.
3.  **Minimum Swaps for a Single Element**: To move an element from its current position `curr_pos` to a target position `target_pos` using only adjacent swaps, it takes `|curr_pos - target_pos|` swaps. Each swap moves the element one step closer to its target.
    *   To move '1' from its initial position `pos1` to index 1: It requires `pos1 - 1` swaps to the left.
    *   To move 'N' from its initial position `posN` to index $N$: It requires `N - posN` swaps to the right.
4.  **Interaction between '1' and 'N'**:
    *   **Case 1: '1' is initially to the left of 'N' (`pos1 < posN`)**:
        In this scenario, '1' needs to move left, and 'N' needs to move right. Their paths do not intersect in a way that allows them to "share" swaps. The total minimum operations will simply be the sum of the individual operations required for each: `(pos1 - 1) + (N - posN)`.
    *   **Case 2: '1' is initially to the right of 'N' (`pos1 > posN`)**:
        Here, '1' needs to move left, and 'N' needs to move right. For them to reach their target positions, they *must* cross each other. Consider what happens when '1' and 'N' are adjacent, say `... N 1 ...`. If we swap them to `... 1 N ...`, this single adjacent swap achieves two things simultaneously:
        *   '1' moves one step to the left.
        *   'N' moves one step to the right.
        This means that one adjacent swap effectively contributes to *both* the movement of '1' and the movement of 'N'. If we simply sum their individual movements, we would be "double-counting" this shared swap. Therefore, when `pos1 > posN`, we need to subtract 1 from the total sum of individual movements to account for this shared operation.

**Algorithm**:
1.  Read the integer $N$.
2.  Iterate through the permutation $P$ from index 1 to $N$.
3.  Keep track of the 1-based index of '1' (let's call it `pos1`) and the 1-based index of 'N' (let's call it `posN`).
4.  Calculate the initial sum of operations: `operations = (pos1 - 1) + (N - posN)`.
5.  If `pos1 > posN`, subtract 1 from `operations`: `operations -= 1`.
6.  Print `operations`.

## Complexity Analysis

*   **Time Complexity**: $O(N)$ per test case.
    *   We iterate through the input permutation once to find the positions of '1' and 'N'. This takes $O(N)$ time.
    *   All other operations (reading $N$, calculations, printing) take constant time, $O(1)$.
    *   Given $T$ test cases, the total time complexity is $O(T \cdot N)$. With $T \le 100$ and $N \le 10^5$, $T \cdot N \le 100 \cdot 10^5 = 10^7$, which is efficient enough for the given time limits.

*   **Space Complexity**: $O(1)$ per test case.
    *   We only store a few integer variables (`N`, `pos1`, `posN`, `P_i`, `operations`). We do not store the entire permutation in memory.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (std::cin, std::cout)
// #include <vector>   // Not strictly necessary for this problem as we only iterate, but often useful
// #include <numeric>  // Not needed for this specific problem, but generally useful for competitive programming

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the length of the permutation P

    int pos1 = -1; // Stores the 1-based index of element '1'
    int posN = -1; // Stores the 1-based index of element 'N'

    // Iterate through the permutation to find the positions of '1' and 'N'
    // The loop variable 'i' represents the 1-based index of the current element.
    for (int i = 1; i <= N; ++i) {
        int P_i;
        std::cin >> P_i; // Read the current element P_i
        if (P_i == 1) {
            pos1 = i; // If P_i is '1', record its index
        }
        if (P_i == N) {
            posN = i; // If P_i is 'N', record its index
        }
    }

    // Calculate the total number of operations
    // 'operations' is declared as long long to be safe, though int would suffice for N <= 10^5
    long long operations = 0;

    // Step 1: Calculate operations to move '1' to the first position (index 1).
    // If '1' is at pos1, it needs to move (pos1 - 1) steps to the left.
    operations += (pos1 - 1);

    // Step 2: Calculate operations to move 'N' to the last position (index N).
    // If 'N' is at posN, it needs to move (N - posN) steps to the right.
    operations += (N - posN);

    // Step 3: Adjust for the case where '1' is initially to the right of 'N'.
    // If pos1 > posN, it means '1' is to the right of 'N' in the initial permutation.
    // For '1' to move left and 'N' to move right to their target positions, they must
    // effectively "cross" each other. One adjacent swap operation can achieve
    // both moving '1' one step left AND moving 'N' one step right (if they are adjacent).
    // This means one operation is "saved" or "double-counted" in the sum of individual movements.
    // So, we subtract 1 from the total.
    if (pos1 > posN) {
        operations -= 1;
    }

    // Output the minimum number of operations for the current test case
    std::cout << operations << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations by disabling synchronization with C's stdio.
    // std::cin.tie(NULL) prevents std::cin from flushing std::cout before each input operation,
    // further improving I/O performance.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful program execution
}
```