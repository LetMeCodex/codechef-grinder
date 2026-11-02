# [Copy-Paste (RRCOPY)](https://www.codechef.com/problems/RRCOPY)
- **Difficulty Rating**: 1280
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the minimum possible size of an initial array `B` from which a given array `A` can be obtained using a series of "Copy-Paste" operations. A "Copy-Paste" operation consists of choosing an element `x` that is already present in the current array and appending it to the end of the array.

For example, if `B = [1, 2]`:
1. Copy-Paste `1`: Array becomes `[1, 2, 1]`
2. Copy-Paste `2`: Array becomes `[1, 2, 1, 2]`
3. Copy-Paste `1`: Array becomes `[1, 2, 1, 2, 1]`

The goal is to find the smallest `B` that can eventually form `A`.

## Intuition & Mathematical Observation

The key to solving this problem lies in understanding what the "Copy-Paste" operation *does* and *does not* do.

1.  **What it does:** A "Copy-Paste" operation duplicates an *existing* element. It increases the count of an element already present in the array.
2.  **What it does not do:** It *never* introduces a new, distinct value into the array. If an element `x` is not in the array, you cannot "Copy-Paste" it.

Consider the set of unique elements in the final array `A`. Let this set be $U_A$.
Now, consider the set of unique elements in the initial array `B`. Let this set be $U_B$.

*   If an element `x` is present in `A` (i.e., $x \in U_A$), it *must* have been present in the initial array `B` (i.e., $x \in U_B$). Why? Because "Copy-Paste" operations only duplicate existing elements; they cannot conjure a new element out of thin air. If `x` wasn't in `B`, it could never appear in `A`.
*   Therefore, $U_A \subseteq U_B$.

To minimize the size of the initial array `B`, we should make it as small as possible while still satisfying the condition that all unique elements of `A` are present in `B`. The most efficient way to do this is to include each unique element of `A` exactly once in `B`. If we included an element `x` twice in `B`, we could have achieved the same set of unique elements by including `x` only once and then using a "Copy-Paste" operation to duplicate it if needed.

Thus, the minimum size of the initial array `B` is simply the total count of unique elements present in the final array `A`.

The solution strategy is to iterate through the given array `A`, keep track of all unique elements encountered, and finally output the count of these unique elements.

## Complexity Analysis

Let $N$ be the size of the input array `A`, and $M$ be the maximum possible value an element $A_i$ can take (given as $10^5$ in constraints).

*   **Time Complexity**:
    1.  **Initialization**: `std::vector<bool> seen(100001, false);` initializes a boolean vector of size $M+1$. This takes $O(M)$ time.
    2.  **Input Loop**: The code iterates `N` times to read each element of array `A`. Inside the loop:
        *   Reading an integer: $O(1)$.
        *   Accessing and updating `seen[val]`: $O(1)$ on average for `std::vector<bool>` (which is often specialized to use bits).
        *   Incrementing `unique_count`: $O(1)$.
        The total time for the loop is $N \times O(1) = O(N)$.
    3.  **Output**: Printing the `unique_count` is $O(1)$.
    4.  **Overall per test case**: $O(M + N)$. Given $N \le 10^5$ and $M \le 10^5$, this is $O(10^5 + 10^5) = O(10^5)$.
    5.  **Total for T test cases**: Since there are $T$ test cases ($T \le 10$), the total time complexity is $T \times O(M + N)$. This is approximately $10 \times (10^5 + 10^5) = 2 \times 10^6$ operations, which is well within typical time limits.

*   **Space Complexity**:
    1.  `std::vector<bool> seen(100001, false);`: This vector requires $O(M)$ space to store boolean flags for values up to $M$.
    2.  Other variables (`N`, `unique_count`, `val`, `T`): These take $O(1)$ space.
    3.  **Overall**: The dominant factor is the `seen` vector, so the space complexity is $O(M)$. In this case, $O(10^5)$ bits (or bytes, depending on `std::vector<bool>` implementation details), which is a small constant amount of memory.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector

void solve() {
    int N;
    std::cin >> N;
    
    // The problem asks for the minimal size of an initial array from which
    // the given array A can be obtained using "Copy-Paste" operations.
    // A "Copy-Paste" operation duplicates existing elements; it never introduces
    // new distinct values. Therefore, the set of unique elements in the initial
    // array must be the same as the set of unique elements in the final array A.
    // To minimize the initial array's size, it should contain each unique element
    // exactly once. Thus, the answer is simply the count of unique elements in A.

    // Constraints: 1 <= Ai <= 10^5.
    // We use a boolean vector to efficiently track which elements have been seen.
    // The size needs to be 100001 to cover indices from 0 to 100000.
    // Since Ai >= 1, index 0 will not be used.
    std::vector<bool> seen(100001, false); 
    int unique_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        // If this value has not been seen before, mark it as seen and increment the count.
        if (!seen[val]) {
            seen[val] = true;
            unique_count++;
        }
    }
    
    // Output the total count of unique elements.
    std::cout << unique_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }
    
    return 0;
}

```