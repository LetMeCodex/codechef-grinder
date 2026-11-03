# [A - Books (BIT2A)](https://www.codechef.com/problems/BIT2A)
- **Difficulty Rating**: 1175
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to process several test cases. For each test case, we are given an integer `N`, representing the number of books, followed by `N` integers `A_1, A_2, ..., A_N`, representing the heights of these books. A crucial piece of information is that the list of book heights `A` is guaranteed to be sorted in non-decreasing order.

Our task is to determine, for each book `A_i`, how many other books `A_j` have a height strictly greater than `A_i`. The counts for each `A_i` should be printed in the original order, separated by spaces.

## Intuition & Mathematical Observation

The core of this problem lies in efficiently counting elements strictly greater than a given value `A[i]` within a *sorted* array.

1.  **Leveraging Sorted Order**: Since the array `A` is sorted in non-decreasing order, all elements that are strictly greater than `A[i]` will appear *after* all elements that are less than or equal to `A[i]`. This property is key to an efficient solution.

2.  **Finding the "Cut-off" Point**: If we can find the first element `A[k]` in the array such that `A[k]` is strictly greater than `A[i]`, then all subsequent elements `A[k], A[k+1], ..., A[N-1]` will also be strictly greater than `A[i]`. The number of such elements would simply be `N - k` (where `k` is the 0-based index of this first element).

3.  **Using `std::upper_bound`**: The C++ Standard Library provides a function `std::upper_bound` which is perfectly suited for this task.
    *   `std::upper_bound(first, last, value)` returns an iterator to the first element in the range `[first, last)` that is *strictly greater* than `value`.
    *   In our solution, for each `A[i]`, we call `std::upper_bound(a.begin(), a.end(), a[i])`. This returns an iterator, let's call it `it`, pointing to the first element in `A` that is strictly greater than `A[i]`.
    *   The number of elements from this iterator `it` to the end of the array `a.end()` gives us the desired count. This can be calculated using `std::distance(it, a.end())`.

**Example Walkthrough:**
Let `A = [10, 20, 20, 30, 40]` and `N=5`.

*   For `A[0] = 10`:
    *   `std::upper_bound(A.begin(), A.end(), 10)` returns an iterator to the first `20` (at index 1).
    *   `std::distance(iterator_to_A[1], A.end())` = `5 - 1 = 4`. (Books: 20, 20, 30, 40)
*   For `A[1] = 20`:
    *   `std::upper_bound(A.begin(), A.end(), 20)` returns an iterator to `30` (at index 3).
    *   `std::distance(iterator_to_A[3], A.end())` = `5 - 3 = 2`. (Books: 30, 40)
*   For `A[2] = 20`:
    *   `std::upper_bound(A.begin(), A.end(), 20)` returns an iterator to `30` (at index 3).
    *   `std::distance(iterator_to_A[3], A.end())` = `5 - 3 = 2`. (Books: 30, 40)
*   For `A[3] = 30`:
    *   `std::upper_bound(A.begin(), A.end(), 30)` returns an iterator to `40` (at index 4).
    *   `std::distance(iterator_to_A[4], A.end())` = `5 - 4 = 1`. (Book: 40)
*   For `A[4] = 40`:
    *   `std::upper_bound(A.begin(), A.end(), 40)` returns `A.end()` (as no element is strictly greater).
    *   `std::distance(A.end(), A.end())` = `5 - 5 = 0`. (No books)

The resulting counts are `4 2 2 1 0`.

## Complexity Analysis

-   **Time Complexity**: $O(T \cdot N \log N)$
    -   Reading the input array `A` of size `N` takes $O(N)$ time.
    -   For each of the `N` elements in `A`, we perform a `std::upper_bound` operation. `std::upper_bound` on a sorted range of size `N` uses binary search, taking $O(\log N)$ time.
    -   Calculating `std::distance` from the returned iterator to `a.end()` takes $O(1)$ time for random-access iterators (like those of `std::vector`).
    -   Therefore, the loop to populate the result array `b` takes $N \times (O(\log N) + O(1)) = O(N \log N)$ time.
    -   Printing the `N` elements of `b` takes $O(N)$ time.
    -   Combining these, the total time complexity per test case is $O(N + N \log N + N) = O(N \log N)$.
    -   Since there are `T` test cases, the overall time complexity is $O(T \cdot N \log N)$.

-   **Space Complexity**: $O(N)$
    -   We use `std::vector<int> a` to store the input book heights, which requires $O(N)$ space.
    -   We use `std::vector<int> b` to store the calculated counts, which also requires $O(N)$ space.
    -   All other variables use constant space.
    -   Thus, the total space complexity per test case is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for std::upper_bound and std::distance

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        int n;
        std::cin >> n; // Read the number of books

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read book heights into vector 'a'
        }

        std::vector<int> b(n); // Vector to store the counts for each book
        for (int i = 0; i < n; ++i) {
            // Since the list A is sorted, all elements strictly greater than A[i]
            // will appear after the last occurrence of A[i].
            // We can find the first element strictly greater than A[i] using std::upper_bound.
            // std::upper_bound returns an iterator to the first element that is strictly greater than a[i].
            auto it = std::upper_bound(a.begin(), a.end(), a[i]);

            // The number of elements strictly greater than A[i] will be the number of elements
            // from 'it' to the end of the vector 'a'.
            // std::distance calculates the number of elements between two iterators.
            b[i] = std::distance(it, a.end());
        }

        // Print the results for the current test case
        for (int i = 0; i < n; ++i) {
            // Print the count, followed by a space, unless it's the last element.
            std::cout << b[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n"; // Print a newline character after each test case's output
    }
    return 0;
}
```