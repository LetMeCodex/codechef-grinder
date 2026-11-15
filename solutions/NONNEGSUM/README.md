# [Non-Negative Sum (NONNEGSUM)](https://www.codechef.com/problems/NONNEGSUM)
- **Difficulty Rating**: 944
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to select the maximum possible number of elements from a given array `A` such that the sum of the selected elements is non-negative (i.e., greater than or equal to zero). The array `A` can contain positive, negative, and zero integers, with values ranging from -100 to 100.

## Intuition & Mathematical Observation

To maximize the count of selected elements while ensuring their sum remains non-negative, we should employ a greedy strategy:

1.  **Prioritize Non-Negative Numbers:** Any non-negative number (0 or positive) will either increase the sum or keep it the same, and always increases the count. Therefore, we should always include all non-negative numbers from the array. They contribute positively or neutrally to the sum and help us maximize the count.

2.  **Handle Negative Numbers Greedily:** Negative numbers decrease the sum. To include as many negative numbers as possible without making the total sum negative, we should always choose the "least negative" numbers first. For example, adding -1 has a smaller negative impact on the sum than adding -2. If we can add -1 and keep the sum non-negative, we should do so. If adding -1 makes the sum negative, then adding -2 (or any other more negative number) would also make it negative. This implies an ordering: we should try to add all occurrences of -1, then all occurrences of -2, then -3, and so on, up to -100.

**Algorithm Steps:**

1.  Initialize `current_sum = 0` and `current_count = 0`.
2.  Create a frequency array (e.g., `neg_counts`) to store the counts of negative numbers. `neg_counts[i]` will store the count of the number `-i`. Since values are between -100 and 100, `neg_counts` will need to be of size 101 (for indices 1 to 100).
3.  **First Pass:** Iterate through the input array `A`:
    *   If an element `val` is non-negative (`val >= 0`), add it to `current_sum` and increment `current_count`.
    *   If `val` is negative (`val < 0`), increment `neg_counts[-val]`.
4.  **Second Pass (Greedy Selection of Negatives):** Iterate from `i = 1` to `100` (representing negative numbers -1, -2, ..., -100):
    *   For each `i`, let `num_val = -i`.
    *   Iterate `count_of_this_num = neg_counts[i]` times (i.e., for each occurrence of `num_val`):
        *   Check if adding `num_val` to `current_sum` would keep the sum non-negative (`current_sum + num_val >= 0`).
        *   If true: Add `num_val` to `current_sum` and increment `current_count`.
        *   If false: We cannot add this `num_val` (or any subsequent occurrences of it, or any more negative numbers like -i-1, -i-2, etc., as they would only make the sum even smaller). At this point, we have found the maximum possible count. Output `current_count` and terminate for this test case.
5.  If the loops complete (meaning all negative numbers were processed and the sum remained non-negative), output the final `current_count`.

## Complexity Analysis

*   **Time Complexity**: $O(N + \text{MAX_ABS_VAL})$
    *   The first pass iterates through `N` elements to read input and populate `neg_counts`. This takes $O(N)$ time.
    *   The second pass iterates from `i = 1` to `100` (where 100 is `MAX_ABS_VAL`). Inside this loop, it iterates `count_of_this_num` times. The sum of `count_of_this_num` across all `i` is at most `N` (the total number of negative elements). So, in the worst case, this part also takes $O(N)$ time if all numbers are negative, or $O(\text{MAX_ABS_VAL})$ if `N` is very small but `MAX_ABS_VAL` is large (e.g., N=1, val=-100). Since `MAX_ABS_VAL` is a constant (100), this simplifies to $O(N)$.
    *   Therefore, the total time complexity is $O(N)$.
*   **Space Complexity**: $O(\text{MAX_ABS_VAL})$
    *   We use a `std::vector<int> neg_counts(101, 0);` to store frequencies of negative numbers. The size of this vector is fixed at 101, independent of `N`.
    *   Thus, the auxiliary space complexity is $O(1)$ (considering `MAX_ABS_VAL` as a constant).

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <numeric>  // Not strictly needed, but often useful

void solve() {
    int n;
    std::cin >> n; // Read N

    // Use a frequency array for negative numbers.
    // neg_counts[i] will store the count of the number -i.
    // Since A_i is between -100 and 100, negative numbers are -1 to -100.
    // Size 101 to cover indices 1 to 100.
    std::vector<int> neg_counts(101, 0); 
    
    long long current_sum = 0; // To keep track of the sum of selected elements
    int current_count = 0;     // To keep track of the count of selected elements

    // First pass: include all non-negative numbers and count negative numbers
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val; // Read each element
        if (val >= 0) {
            current_sum += val;
            current_count++;
        } else {
            // Store count of negative numbers.
            // For val = -5, neg_counts[5]++.
            neg_counts[-val]++; 
        }
    }

    // Second pass: try to add negative numbers, starting from the least negative (-1)
    // Iterate from i = 1 (representing -1) up to 100 (representing -100).
    for (int i = 1; i <= 100; ++i) {
        int num_val = -i; // The actual negative number, e.g., -1, -2, ...
        int count_of_this_num = neg_counts[i];

        // Try to add all occurrences of this specific negative number (e.g., all -1s).
        for (int k = 0; k < count_of_this_num; ++k) {
            // If adding the current negative number keeps the sum non-negative
            if (current_sum + num_val >= 0) {
                current_sum += num_val;
                current_count++;
            } else {
                // If adding this negative number makes the sum negative,
                // then we cannot add any more numbers. This is because:
                // 1. Any remaining occurrences of the current num_val would also make the sum negative.
                // 2. Any subsequent num_val (e.g., -2 after -1) would be even smaller/more negative,
                //    and thus would also make the sum negative.
                // So, we output the current count and stop processing for this test case.
                std::cout << current_count << "\n";
                return; // Exit the solve function
            }
        }
    }

    // If we processed all negative numbers and the sum is still non-negative,
    // output the final maximum count.
    std::cout << current_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0;
}
```