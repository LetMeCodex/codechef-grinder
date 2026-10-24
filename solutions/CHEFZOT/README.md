# [Chef and Subarray (CHEFZOT)](https://www.codechef.com/problems/CHEFZOT)
- **Difficulty Rating**: 1191
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to find the maximum length of a contiguous subarray within a given array `A` such that the product of all elements in that subarray is non-zero.

## Intuition & Mathematical Observation

The core of this problem lies in understanding when the product of elements in a subarray is non-zero.
A fundamental property of multiplication is that if any factor in a product is zero, the entire product becomes zero. Conversely, for a product to be non-zero, *all* its factors must be non-zero.

Therefore, the problem boils down to finding the longest contiguous subarray that contains *no zero elements*.

Our approach will be to iterate through the array and keep track of the current length of consecutive non-zero elements.
1.  Initialize `max_length = 0` (to store the maximum length found so far) and `current_length = 0` (to store the length of the current sequence of non-zero elements).
2.  As we iterate through each `element` in the array:
    *   If `element` is non-zero: It contributes to the current sequence of non-zero elements. We increment `current_length`.
    *   If `element` is zero: The current sequence of non-zero elements is broken.
        *   At this point, `current_length` holds the length of the non-zero subarray that just ended. We compare `current_length` with `max_length` and update `max_length` if `current_length` is greater.
        *   Then, we reset `current_length` to `0` because a new sequence of non-zero elements must start after this zero.
3.  After the loop finishes, there's a crucial final check: The longest non-zero subarray might extend all the way to the end of the input array. In this case, `current_length` would hold its length, but it wouldn't have been compared with `max_length` inside the loop (because no zero followed it). So, we perform one last comparison and update `max_length` if `current_length` is greater.
4.  Finally, print `max_length`.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    The solution involves a single pass through the input array of `N` elements. Inside the loop, constant-time operations (reading an element, comparison, increment, assignment) are performed. Thus, the total time complexity is directly proportional to the number of elements, $N$.

*   **Space Complexity**: $O(1)$
    The solution uses a fixed number of integer variables (`N`, `max_length`, `current_length`, `element`) regardless of the input array's size. No additional data structures that scale with `N` are used. Therefore, the space complexity is constant.

## Solution Code

```cpp
#include <cstdio> // Required for scanf and printf

int main() {
    // When using scanf/printf, the C++ stream optimizations are not applicable
    // and should be omitted to avoid potential conflicts or unnecessary overhead.
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int N; // Declare an integer variable N to store the number of elements
    // Read the value of N using scanf
    scanf("%d", &N);

    int max_length = 0; // Initialize max_length to 0. This will store the maximum length of a subarray with non-zero product.
    int current_length = 0; // Initialize current_length to 0. This will store the length of the current consecutive subarray of non-zero elements.

    // Loop through N elements of the array
    for (int i = 0; i < N; ++i) {
        int element; // Declare an integer variable to store the current element
        // Read the current element using scanf
        scanf("%d", &element);

        if (element != 0) {
            // If the current element is non-zero, it contributes to the current non-zero subarray.
            // Increment current_length.
            current_length++;
        } else {
            // If the current element is zero, it breaks any ongoing non-zero subarray.
            // First, update max_length with the length of the non-zero subarray that just ended.
            // Using an if statement for max is equivalent to std::max and avoids including <algorithm>.
            if (current_length > max_length) {
                max_length = current_length;
            }
            // Then, reset current_length to 0, as a new non-zero subarray must start after this zero.
            current_length = 0;
        }
    }

    // After the loop finishes, there might be a non-zero subarray ending at the very last element of the array.
    // This final check ensures that such a subarray's length is considered.
    if (current_length > max_length) {
        max_length = current_length;
    }

    // Print the final maximum length followed by a newline character using printf.
    printf("%d\n", max_length);

    return 0; // Indicate successful program execution
}
```