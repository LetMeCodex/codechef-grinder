# [Find Multiset State (ARRAYSTATE)](https://www.codechef.com/problems/ARRAYSTATE)
- **Difficulty Rating**: 1119
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to simulate a process on a multiset of integers. We are given an initial array `A` of `N` integers, which is guaranteed to be sorted in non-decreasing order. We need to perform `K` operations. In each operation:
1.  Identify the minimum element `X` from the current multiset.
2.  Identify the maximum element `Y` from the current multiset.
3.  Remove `X` and `Y` from the multiset.
4.  Add their sum `X + Y` to the multiset.

After `K` such operations, we must print all elements remaining in the multiset, sorted in non-decreasing order.

## Intuition & Mathematical Observation

The core challenge is efficiently managing a multiset where we frequently need to find and remove the minimum and maximum elements, and then insert a new element. A naive approach of using a `std::vector` and sorting it repeatedly would be too slow (`O(N log N)` per operation).

The key observations and strategy are:

1.  **Initial Sorted Array**: The problem states the initial array `A` is sorted. This is a crucial hint. Elements from this initial array can be efficiently accessed for their minimum (front) and maximum (back) if stored in a structure like a `std::deque`. A `deque` allows `O(1)` access and removal from both ends.

2.  **Generated Sums**: The new elements `X + Y` are generated during the operations. These sums can be anywhere in the range of existing elements; they don't maintain any specific order relative to the original elements or other sums. For these elements, we need a data structure that efficiently supports:
    *   Finding the minimum element.
    *   Finding the maximum element.
    *   Removing an element.
    *   Inserting an element.
    A `std::multiset` in C++ is perfect for this, as all these operations take `O(log S)` time, where `S` is the current size of the multiset.

3.  **Hybrid Data Structure Approach**:
    *   We can maintain two collections:
        *   A `std::deque<long long> dq`: To store the *remaining original elements* from the input array. Since the initial array is sorted, `dq.front()` will always be the minimum among these original elements, and `dq.back()` will be the maximum. `pop_front()` and `pop_back()` are `O(1)`.
        *   A `std::multiset<long long> sums`: To store all the *generated `X + Y` sums*. This multiset will keep its elements sorted, allowing `*sums.begin()` for the minimum and `*sums.rbegin()` for the maximum in `O(log S)` time.

4.  **Operation Logic**:
    For each of the `K` operations:
    *   **Find `X` (overall minimum)**: Compare the minimum element from `dq` (i.e., `dq.front()`) with the minimum element from `sums` (i.e., `*sums.begin()`). The smaller of these two is the global minimum `X`. Remove `X` from its respective container. Special care is taken for empty containers by using `std::numeric_limits<long long>::max()` as a sentinel.
    *   **Find `Y` (overall maximum)**: Similarly, compare the maximum element from `dq` (i.e., `dq.back()`) with the maximum element from `sums` (i.e., `*sums.rbegin()`). The larger of these two is the global maximum `Y`. Remove `Y` from its respective container. Special care is taken for empty containers by using `std::numeric_limits<long long>::min()` as a sentinel.
    *   **Insert Sum**: Add `X + Y` into the `sums` multiset.

5.  **Final Output**: After `K` operations, the remaining elements are distributed between `dq` (which is still sorted) and `sums` (which is also sorted). We perform a standard merge operation on these two sorted collections to produce a single sorted `std::vector<long long>` and then print its elements.

This hybrid approach leverages the strengths of both `deque` (for `O(1)` min/max from the initial sorted sequence) and `multiset` (for `O(log S)` min/max/insert/delete for the dynamically generated sums).

## Complexity Analysis

Let `N` be the initial number of elements and `K` be the number of operations.

*   **Time Complexity**:
    *   **Initialization**: Reading `N` elements and pushing them into the `deque` takes `O(N)` time. (The problem states the input is already sorted, so no initial sort is needed).
    *   **`K` Operations Loop**:
        *   In each iteration, finding `dq_min` and `dq_max` is `O(1)`.
        *   Finding `sums_min` and `sums_max` from the `multiset` is `O(log S)`, where `S` is the current number of elements in `sums`. `S` can grow up to `K` (as `K` sums are generated). So, this is `O(log K)`.
        *   Removing elements from `deque` (`pop_front`, `pop_back`) is `O(1)`.
        *   Removing elements from `multiset` (`erase`) is `O(log K)`.
        *   Inserting `X+Y` into `multiset` (`insert`) is `O(log K)`.
        *   Therefore, each of the `K` operations takes `O(log K)` time. Total for the loop: `K * O(log K)`.
    *   **Final Merge**: Merging the remaining elements from `dq` and `sums`. The total number of elements remaining is `N - K`. This merge operation takes `O(N - K)` time, which is `O(N)`.
    *   **Overall Time Complexity**: `O(N) + O(K log K) + O(N) = O(N + K log K)`. Since `K` can be at most `N/2`, `K log K` is bounded by `(N/2) log (N/2)`, which is `O(N log N)`. Thus, the overall time complexity is dominated by `O(N log N)`.

*   **Space Complexity**:
    *   `dq`: Stores up to `N` elements initially. `O(N)`.
    *   `sums`: Stores up to `K` elements (the generated sums). `O(K)`.
    *   `result` vector: Stores up to `N - K` elements (for the final output). `O(N)`.
    *   **Overall Space Complexity**: `O(N + K)`. Since `K <= N/2`, this simplifies to `O(N)`.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <vector>   // For std::vector
#include <deque>    // For std::deque
#include <set>      // For std::multiset
#include <algorithm> // For std::min, std::max, std::prev
#include <limits>   // For std::numeric_limits

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K;

    // deque to store the initial sorted elements that haven't been picked yet
    // These elements remain sorted relative to each other.
    std::deque<long long> dq;
    for (int i = 0; i < N; ++i) {
        long long val;
        std::cin >> val;
        dq.push_back(val);
    }

    // multiset to store the sums (X+Y) generated.
    // It automatically keeps elements sorted and allows efficient min/max access.
    std::multiset<long long> sums;

    // Perform K operations
    for (int op = 0; op < K; ++op) {
        long long X, Y;

        // --- Find X (overall minimum element) ---
        // Get minimum from deque (if not empty), using LLONG_MAX as sentinel if empty
        long long dq_min = dq.empty() ? std::numeric_limits<long long>::max() : dq.front();
        // Get minimum from multiset (if not empty), using LLONG_MAX as sentinel if empty
        long long sums_min = sums.empty() ? std::numeric_limits<long long>::max() : *sums.begin();
        
        if (dq_min <= sums_min) { // If deque's min is smaller or equal, it's the overall minimum
            X = dq.front();
            dq.pop_front();
        } else { // Otherwise, multiset's min is the overall minimum
            X = *sums.begin();
            sums.erase(sums.begin()); // Erase only one occurrence of X
        }

        // --- Find Y (overall maximum element) ---
        // Get maximum from deque (if not empty), using LLONG_MIN as sentinel if empty
        long long dq_max = dq.empty() ? std::numeric_limits<long long>::min() : dq.back();
        // Get maximum from multiset (if not empty), using LLONG_MIN as sentinel if empty
        long long sums_max = sums.empty() ? std::numeric_limits<long long>::min() : *sums.rbegin();
        
        if (dq_max >= sums_max) { // If deque's max is larger or equal, it's the overall maximum
            Y = dq.back();
            dq.pop_back();
        } else { // Otherwise, multiset's max is the overall maximum
            Y = *sums.rbegin();
            // std::prev(sums.end()) gets an iterator to the last element in the multiset
            sums.erase(std::prev(sums.end())); // Erase only one occurrence of Y
        }
        
        // Append X+Y to the array (by inserting into the sums multiset)
        sums.insert(X + Y);
    }

    // --- Collect and print the final array ---
    // The remaining elements in dq are sorted.
    // The elements in sums are also sorted (due to multiset property).
    // We merge these two sorted sequences into a single sorted vector.
    std::vector<long long> result;
    auto dq_it = dq.begin();
    auto sums_it = sums.begin();

    while (dq_it != dq.end() || sums_it != sums.end()) {
        if (dq_it != dq.end() && sums_it != sums.end()) {
            // Both containers have elements, compare their current minimums
            if (*dq_it < *sums_it) {
                result.push_back(*dq_it);
                dq_it++;
            } else {
                result.push_back(*sums_it);
                sums_it++;
            }
        } else if (dq_it != dq.end()) { // Only dq has elements left
            result.push_back(*dq_it);
            dq_it++;
        } else { // Only sums has elements left
            result.push_back(*sums_it);
            sums_it++;
        }
    }

    // Print the elements of the final array, space-separated
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```