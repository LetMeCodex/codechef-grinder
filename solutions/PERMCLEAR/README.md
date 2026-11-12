# [Permutation Clear (PERMCLEAR)](https://www.codechef.com/problems/PERMCLEAR)
- **Difficulty Rating**: 1308
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to process a given permutation `A` of length `N` and a list `B` of `K` distinct numbers. Our task is to remove all numbers from `A` that are also present in `B`. The remaining numbers from `A` should be printed in their original relative order. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

The core of this problem is efficiently checking for the presence of an element. For each number in the permutation `A`, we need to determine if it exists in the list `B`.

A naive approach would be to iterate through `B` for every element in `A`. If `A` has `N` elements and `B` has `K` elements, this would lead to an $O(N \cdot K)$ time complexity per test case. Given that `N` and `K` can be up to $10^5$, $N \cdot K$ could be as large as $10^{10}$, which is far too slow for typical time limits.

To optimize the lookup process, we need a data structure that allows for quick membership testing. A hash set (like `std::unordered_set` in C++) is ideal for this. Hash sets provide average $O(1)$ time complexity for insertion and lookup operations.

The refined intuition is as follows:
1.  First, read all `K` numbers from list `B` and insert them into a hash set. This allows us to quickly check if a number is "disliked" (i.e., present in `B`).
2.  Then, iterate through the permutation `A` from left to right. For each number `x` in `A`:
    *   Check if `x` is present in our hash set of disliked numbers.
    *   If `x` is *not* found in the hash set, it means `x` should be kept. Add `x` to a new result list.
3.  Finally, print all numbers in the result list, separated by spaces. Since we iterated through `A` in its original order and only added elements that were not disliked, the relative order of the remaining elements is preserved.

This approach leverages the average constant-time lookup property of hash sets to significantly reduce the overall time complexity.

## Complexity Analysis

Let `T` be the number of test cases, `N` be the length of permutation `A`, and `K` be the length of list `B`.

-   **Time Complexity**:
    *   **Input Reading and I/O Optimization**: `std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);` takes constant time. Reading `T`, `N`, `K` takes $O(1)$ per test case.
    *   **Reading `A`**: Storing `N` integers into `std::vector<int> a` takes $O(N)$ time.
    *   **Populating `disliked_numbers` set**: We iterate `K` times. In each iteration, we read an integer and insert it into an `std::unordered_set`. On average, `insert` operation takes $O(1)$ time. Thus, this step takes $O(K)$ time on average. In the worst case (due to hash collisions), it could degrade to $O(K^2)$, but this is rare with good hash functions and typical inputs.
    *   **Filtering `A` and building `result`**: We iterate through `N` elements of `a`. For each element, we perform a `find` operation on the `std::unordered_set`. On average, `find` takes $O(1)$ time. If the element is not disliked, we `push_back` to `std::vector<int> result`, which takes amortized $O(1)$ time. Thus, this step takes $O(N)$ time on average.
    *   **Printing `result`**: We iterate through the `result` vector, which contains at most `N` elements. This takes $O(N)$ time.

    Combining these, the time complexity per test case is $O(N + K)$ on average.
    For `T` test cases, the total time complexity is $O(T \cdot (N + K))$ on average.
    Given $N, K \le 10^5$ and $T \le 10$, the total operations would be approximately $10 \cdot (10^5 + 10^5) = 2 \cdot 10^6$, which is well within typical time limits.

-   **Space Complexity**:
    *   `std::vector<int> a`: Stores `N` integers. $O(N)$ space.
    *   `std::unordered_set<int> disliked_numbers`: Stores `K` integers. $O(K)$ space.
    *   `std::vector<int> result`: Stores at most `N` integers. $O(N)$ space.

    The total space complexity per test case is $O(N + K)$.
    Given $N, K \le 10^5$, this means storing up to $2 \cdot 10^5$ integers. Each integer typically takes 4 bytes, so $2 \cdot 10^5 \cdot 4 \text{ bytes} = 8 \cdot 10^5 \text{ bytes} = 0.8 \text{ MB}$, which is well within typical memory limits (e.g., 256 MB).

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_set> // Required for std::unordered_set

int main() {
    // Optimize C++ standard streams for faster input/output.
    // Unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int n;
        std::cin >> n; // Read the length of permutation A
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read elements of permutation A
        }

        int k;
        std::cin >> k; // Read the length of list B
        // Use an unordered_set for efficient O(1) average time lookups
        std::unordered_set<int> disliked_numbers;
        for (int i = 0; i < k; ++i) {
            int b_val;
            std::cin >> b_val; // Read elements of list B
            disliked_numbers.insert(b_val); // Add them to the hash set
        }

        std::vector<int> result; // Vector to store the filtered permutation
        // Iterate through the original permutation A
        for (int x : a) {
            // Check if the current number 'x' is in the set of disliked numbers
            // If find() returns disliked_numbers.end(), it means 'x' is NOT found.
            if (disliked_numbers.find(x) == disliked_numbers.end()) {
                result.push_back(x); // If not disliked, add it to our result
            }
        }

        // Print the elements of the result vector
        for (size_t i = 0; i < result.size(); ++i) {
            std::cout << result[i] << (i == result.size() - 1 ? "" : " "); // Print space between numbers, but not after the last one
        }
        std::cout << "\n"; // Newline after each test case's output
    }
    return 0; // Indicate successful execution
}

```