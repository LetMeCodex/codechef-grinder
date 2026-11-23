# [Maximise Sum (P4149)](https://www.codechef.com/problems/P4149)
- **Difficulty Rating**: 1372
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to find the maximum possible sum of elements in an array after performing a specific operation any number of times. The operation allows us to choose any two distinct indices `i` and `j` and replace `A[i]` with `-A[i]` and `A[j]` with `-A[j]`.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the effect of the given operation on the array elements. When we choose two indices `i` and `j` and flip their signs (i.e., `A[i] -> -A[i]` and `A[j] -> -A[j]`), let's analyze how the *count of negative numbers* in the array changes:

1.  **Both `A[i]` and `A[j]` are positive:** Both become negative. The count of negative numbers increases by 2.
2.  **Both `A[i]` and `A[j]` are negative:** Both become positive. The count of negative numbers decreases by 2.
3.  **One is positive, one is negative (e.g., `A[i]` positive, `A[j]` negative):** `A[i]` becomes negative, `A[j]` becomes positive. The count of negative numbers effectively remains unchanged (one negative added, one negative removed).

In all three scenarios, the *parity* (whether it's even or odd) of the total number of negative elements in the array *does not change*. This is the crucial observation. If we start with an even number of negative elements, we will always end up with an even number of negative elements. Similarly, if we start with an odd number of negative elements, we will always end up with an odd number of negative elements.

To maximize the sum of elements, our ideal scenario is to make all elements positive. This would result in a sum equal to the sum of the absolute values of all original elements. Let `total_abs_sum` be `sum(|A[i]|)` for all `i`.

Now, we consider two cases based on the parity of the initial count of negative numbers:

### Case 1: The initial count of negative numbers (`neg_count`) is EVEN.
Since the parity of negative numbers never changes, and we started with an even count, we can always reach a state where there are exactly 0 negative numbers. This means we can make all elements positive.
For example, if we have `[-2, -3, 4, 5]`, `neg_count = 2`. We can pick indices of -2 and -3, apply the operation. They become `2` and `3`. The array becomes `[2, 3, 4, 5]`.
In this case, the maximum sum is simply the sum of the absolute values of all elements: `total_abs_sum`.

### Case 2: The initial count of negative numbers (`neg_count`) is ODD.
Since the parity of negative numbers never changes, and we started with an odd count, we *cannot* reach a state where there are 0 negative numbers. We must always have an odd number of negative elements. To maximize the sum, we want to have the *smallest possible odd number* of negative elements, which is 1.
If we are forced to leave exactly one element negative, which one should it be?
Consider the scenario where we have made all elements positive (summing to `total_abs_sum`). Now, we are forced to flip one element, say `A[k]`, back to negative. Its contribution changes from `|A[k]|` to `-|A[k]|`. The net change in the total sum is `(-|A[k]|) - (|A[k]|) = -2 * |A[k]|`.
To maximize the final sum, we need to minimize this subtraction. This means we should choose the element `A[k]` that has the *minimum absolute value* to be the one that remains negative.
So, if `neg_count` is odd, the maximum sum will be `total_abs_sum - 2 * min_abs_val`, where `min_abs_val` is the minimum absolute value among all elements in the array. Note that if `0` is present in the array, `min_abs_val` will be `0`. In this case, `total_abs_sum - 2 * 0 = total_abs_sum`, which is correct as flipping `0` has no effect on the sum.

### Algorithm Steps:
1.  Initialize `total_abs_sum = 0` (use `long long` to prevent overflow, as sums can be large).
2.  Initialize `neg_count = 0`.
3.  Initialize `min_abs_val = INT_MAX` (from `<climits>`).
4.  Iterate through each element `val` in the input array:
    a.  If `val < 0`, increment `neg_count`.
    b.  Add `std::abs(val)` to `total_abs_sum`.
    c.  Update `min_abs_val = std::min(min_abs_val, std::abs(val))`.
5.  After processing all elements:
    a.  If `neg_count % 2 == 0`, print `total_abs_sum`.
    b.  If `neg_count % 2 != 0`, print `total_abs_sum - 2 * min_abs_val`.

## Complexity Analysis
-   **Time Complexity**: $O(N)$
    We iterate through the input array exactly once to calculate `total_abs_sum`, `neg_count`, and `min_abs_val`. This takes $O(N)$ time, where $N$ is the number of elements in the array. Since this process is repeated for each test case, the total time complexity will be $O(T \cdot N)$, where $T$ is the number of test cases.
-   **Space Complexity**: $O(1)$
    We only use a few constant extra variables (`n`, `total_abs_sum`, `neg_count`, `min_abs_val`, `val`) regardless of the input array size. We do not store the entire array.

## Solution Code
```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <algorithm> // Required for std::abs and std::min
#include <climits>  // Required for INT_MAX

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the number of elements in the array

    long long total_abs_sum = 0; // Stores the sum of absolute values of all elements. Use long long to prevent overflow.
    int neg_count = 0;           // Counts the number of negative elements
    int min_abs_val = INT_MAX;   // Stores the minimum absolute value found in the array. Initialize with a very large value.

    // Iterate through the array elements
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val; // Read an element directly

        if (val < 0) {
            neg_count++; // Increment negative count if the element is negative
        }
        
        // Add the absolute value of the current element to total_abs_sum
        total_abs_sum += std::abs(val);
        
        // Update min_abs_val if the absolute value of the current element is smaller
        min_abs_val = std::min(min_abs_val, std::abs(val));
    }

    // Based on the parity of negative_count, determine the maximum sum
    if (neg_count % 2 == 0) {
        // If the count of negative numbers is even, we can make all elements positive.
        // The maximum sum is simply the sum of all absolute values.
        std::cout << total_abs_sum << "\n";
    } else {
        // If the count of negative numbers is odd, we must end up with an odd number of negative elements.
        // To maximize the sum, we want exactly one element to be negative, and it should be the one
        // with the smallest absolute value.
        // The sum will be (sum of all absolute values) - 2 * (smallest absolute value).
        // This is because if we made all positive (sum = total_abs_sum), and then had to flip one
        // element 'x' back to negative, its contribution changes from |x| to -|x|, a net change of -2|x|.
        std::cout << total_abs_sum - 2 * min_abs_val << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```