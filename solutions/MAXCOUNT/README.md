# [Count of Maximum (MAXCOUNT)](https://www.codechef.com/problems/MAXCOUNT)
- **Difficulty Rating**: 1180
- **Solved in**: 3 attempt(s)

## Problem Summary

The problem asks us to find the element that appears most frequently in a given array of integers. If there are multiple elements with the same maximum frequency, we need to output the smallest among them. We also need to output the count of this most frequent (and smallest) element.

## Intuition & Mathematical Observation

The core of this problem is to count the occurrences of each distinct element in the array and then identify the element with the highest frequency. A crucial detail is the tie-breaking rule: if multiple elements share the maximum frequency, we must choose the smallest element.

A natural data structure for counting frequencies is a hash map (or dictionary). In C++, `std::map` or `std::unordered_map` can be used. `std::map` stores key-value pairs and keeps the keys sorted. This sorting property is particularly useful here because it directly helps us with the tie-breaking condition.

**Algorithm Idea:**

1.  **Frequency Counting:** Iterate through the input array `A`. For each element, increment its count in a frequency map.
2.  **Finding Maximum Frequency and Smallest Element:** After counting, iterate through the frequency map. Keep track of the maximum frequency encountered so far (`max_freq`) and the element associated with it (`best_element`).
    *   If we find an element with a frequency *greater than* `max_freq`, update `max_freq` and `best_element` to this new element and its frequency.
    *   If we find an element with a frequency *equal to* `max_freq`, we need to compare it with the current `best_element`. Since `std::map` iterates through its elements in ascending order of keys (the array elements themselves), if we encounter an element with the same `max_freq`, it will automatically be larger than or equal to the current `best_element`. Therefore, we only need to update `best_element` if the new element's frequency is strictly greater. The first time we hit the maximum frequency, the `best_element` will be set to the smallest element achieving that frequency.

**Example Walkthrough:**

Let's say the input array is `A = [2, 3, 2, 1, 3, 3]`.

1.  **Frequency Map:**
    *   `2` appears 2 times.
    *   `3` appears 3 times.
    *   `1` appears 1 time.
    The `std::map` would look like: `{1: 1, 2: 2, 3: 3}`.

2.  **Finding Max Frequency and Smallest Element:**
    *   Initialize `max_freq = 0`, `best_element = -1` (or some value guaranteed to be smaller than any valid input element).
    *   Iterate through the map:
        *   **Element 1, Frequency 1:** `freq (1) > max_freq (0)`. Update `max_freq = 1`, `best_element = 1`.
        *   **Element 2, Frequency 2:** `freq (2) > max_freq (1)`. Update `max_freq = 2`, `best_element = 2`.
        *   **Element 3, Frequency 3:** `freq (3) > max_freq (2)`. Update `max_freq = 3`, `best_element = 3`.

    The final result is `best_element = 3` and `max_freq = 3`.

**Tie-breaking Example:**

Let's say `A = [5, 2, 5, 2, 1]`.

1.  **Frequency Map:** `{1: 1, 2: 2, 5: 2}`.

2.  **Finding Max Frequency and Smallest Element:**
    *   Initialize `max_freq = 0`, `best_element = -1`.
    *   Iterate through the map:
        *   **Element 1, Frequency 1:** `freq (1) > max_freq (0)`. Update `max_freq = 1`, `best_element = 1`.
        *   **Element 2, Frequency 2:** `freq (2) > max_freq (1)`. Update `max_freq = 2`, `best_element = 2`.
        *   **Element 5, Frequency 2:** `freq (2) == max_freq (2)`. Since the map iterates in increasing order of keys, `5` is greater than the current `best_element` (`2`). We do *not* update `best_element` because we want the *smallest* element with the maximum frequency.

    The final result is `best_element = 2` and `max_freq = 2`.

The use of `std::map` simplifies the tie-breaking logic significantly. If `std::unordered_map` were used, we would need an additional check: `if (freq == max_freq && element < best_element)`.

## Complexity Analysis

*   **Time Complexity**: $O(N \log N)$
    *   Populating the `std::map`: For each of the $N$ elements in the input array, inserting or updating an element in a `std::map` takes $O(\log K)$ time, where $K$ is the number of distinct elements. In the worst case, $K$ can be up to $N$. So, this step is $O(N \log N)$.
    *   Iterating through the `std::map`: The map contains at most $N$ distinct elements. Iterating through it takes $O(K)$ time, which is at most $O(N)$.
    *   The dominant factor is the map population, leading to an overall time complexity of $O(N \log N)$.

*   **Space Complexity**: $O(K)$ or $O(N)$
    *   The `std::map` stores the frequency of each distinct element. In the worst case, all elements are distinct, so the map will store $N$ key-value pairs. Thus, the space complexity is $O(N)$ in the worst case, or $O(K)$ where $K$ is the number of distinct elements.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility> // For std::pair

// Function to find the most frequent element and its count
// Returns a pair: {smallest_element_with_max_frequency, max_frequency}
std::pair<int, int> mostFrequent(int N, std::vector<int>& A) {
    // std::map automatically stores elements in sorted order of keys.
    // This is crucial for the tie-breaking condition (smallest element).
    std::map<int, int> counts;

    // Populate the frequency map
    for (int x : A) {
        counts[x]++;
    }

    int max_freq = 0;
    // Initialize best_element. Since problem constraints state A[i] >= 1,
    // -1 is a safe initial placeholder that will be overwritten by the first element.
    int best_element = -1;

    // Iterate through the frequency map.
    // The map iterates in increasing order of keys (the elements from array A).
    for (auto const& [element, freq] : counts) {
        if (freq > max_freq) {
            // Found a new maximum frequency. Update both max_freq and best_element.
            max_freq = freq;
            best_element = element;
        } else if (freq == max_freq) {
            // If frequencies are equal, we want the smaller element.
            // Since the map iterates in increasing order of 'element',
            // the 'best_element' will already be the smallest one encountered
            // for this 'max_freq' when this condition is met.
            // Therefore, no explicit update is needed here. The first element
            // encountered with 'max_freq' will be the smallest.
        }
    }

    return {best_element, max_freq};
}

// The main function structure for competitive programming platforms.
// This part is usually provided by the platform, but we include it for completeness
// and to show how mostFrequent would be called.
/*
int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        int N; // Number of elements in the array
        std::cin >> N;
        std::vector<int> A(N); // The input array
        for (int i = 0; i < N; ++i) {
            std::cin >> A[i];
        }

        // Call the function to get the result
        std::pair<int, int> result = mostFrequent(N, A);

        // Output the smallest element with maximum frequency and its count
        std::cout << result.first << " " << result.second << "\n";
    }
    return 0;
}
*/
```