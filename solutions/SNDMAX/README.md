# [Second Max of Three Numbers (SNDMAX)](https://www.codechef.com/problems/SNDMAX)
- **Difficulty Rating**: 300
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the second largest number among three given distinct integers. This operation needs to be performed for `N` different test cases. For each test case, we read three integers and output their second maximum.

## Intuition & Mathematical Observation

Given three distinct numbers, say `A`, `B`, and `C`, the "second maximum" is simply the number that falls in the middle when these three numbers are arranged in ascending or descending order.

For example:
- If the numbers are 10, 20, 30: Sorted, they are 10, 20, 30. The second maximum is 20.
- If the numbers are 30, 10, 20: Sorted, they are 10, 20, 30. The second maximum is 20.
- If the numbers are 5, 1, 3: Sorted, they are 1, 3, 5. The second maximum is 3.

Since the problem guarantees that the three numbers are distinct, we don't have to worry about ties (e.g., what if two numbers are the same and are the second maximum?). This simplifies the problem significantly.

The most straightforward approach to find the middle element among three distinct numbers is to:
1. Read the three numbers.
2. Store them in a data structure that can be easily sorted, such as an array or a `std::vector`.
3. Sort the data structure in ascending order.
4. After sorting, the element at the middle index (index 1 for a 0-indexed array/vector of size 3) will be the second minimum, which is equivalent to the second maximum for three distinct numbers.

This method is robust, easy to implement using standard library functions, and efficient for a small number of elements.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    For each of the `N` test cases:
    -   Reading three integers takes constant time, $O(1)$.
    -   Storing them in a `std::vector` of size 3 takes constant time, $O(1)$.
    -   Sorting a `std::vector` of 3 elements using `std::sort` is a constant time operation. It involves a fixed small number of comparisons and swaps, effectively $O(1)$.
    -   Printing the result takes constant time, $O(1)$.
    Since each test case takes $O(1)$ time, the total time complexity for `N` test cases is $N \times O(1) = O(N)$.

-   **Space Complexity**: $O(1)$
    For each test case, we use a `std::vector` of size 3 to store the numbers. This consumes a constant amount of memory, regardless of the input values or the number of test cases `N`. The memory for the vector is either re-used or re-allocated in each iteration, but its size remains constant. Therefore, the auxiliary space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for cin, cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::sort

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N; // Declare N to store the number of triples
    std::cin >> N; // Read the number of triples

    // Loop N times, once for each triple
    while (N--) {
        // Declare a vector of 3 integers to store the current triple
        std::vector<int> nums(3);
        
        // Read the three integers into the vector
        std::cin >> nums[0] >> nums[1] >> nums[2];

        // Sort the vector in ascending order.
        // After sorting, nums[0] will be the minimum,
        // nums[1] will be the second minimum (which is the second maximum for 3 distinct numbers),
        // and nums[2] will be the maximum.
        std::sort(nums.begin(), nums.end());

        // Output the second element (index 1) which is the second maximum
        std::cout << nums[1] << "\n";
    }

    return 0; // Indicate successful execution
}
```