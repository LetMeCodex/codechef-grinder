Here's a clean, high-quality solution writeup in GitHub-Flavored Markdown for the Chefland Library problem:

# [Chefland Library (BORROWBOOK)](https://www.codechef.com/problems/BORROWBOOK)
- **Difficulty Rating**: 1058
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef borrowed `N` books from the Chefland Library. For each book `i` (where `1 <= i <= N`), two pieces of information are given:
1.  It was returned `i` days late.
2.  It was returned on day `A_i`.

The library has a specific penalty rule: for all books returned on the *same day*, Chef only pays the penalty for the *book that was returned the latest* among them. We need to calculate the total penalty Chef has to pay, which is the sum of these maximum penalties across all unique return days.

**Example:** If books returned on day `D` were `X` days late, `Y` days late, and `Z` days late, Chef pays `max(X, Y, Z)` for day `D`.

## Intuition & Mathematical Observation

The core of this problem lies in correctly interpreting the problem statement and applying the penalty rule.

1.  **Understanding the `i`-th book's penalty**: The problem states: "For the `i`-th book (1 <= i <= N): It was returned `i` days late. It was returned on day `A_i`."
    This means that when we process the `i`-th element of the input array `A`, we are considering a book that has a potential penalty of `i` days (because it was `i` days late), and this specific book was returned on day `A_i`.

2.  **Applying the penalty rule**: The rule states: "For all books returned on the same day, Chef only pays the penalty for the book that was returned the latest among them."
    This implies that for each unique return day, we need to find the *maximum lateness* (which directly corresponds to the maximum `i` value) among all books returned on that specific day.

    Let's trace the provided example:
    `N = 4`, `A = [1, 1, 2, 2]`

    *   **Book 1 (i=1)**: Returned on day `A_1 = 1`. Lateness = 1.
    *   **Book 2 (i=2)**: Returned on day `A_2 = 1`. Lateness = 2.
    *   **Book 3 (i=3)**: Returned on day `A_3 = 2`. Lateness = 3.
    *   **Book 4 (i=4)**: Returned on day `A_4 = 2`. Lateness = 4.

    Now, we group these by their return day and find the maximum lateness for each day:

    *   **Return Day 1**:
        *   Book 1: Lateness 1
        *   Book 2: Lateness 2
        The maximum lateness for Day 1 is `max(1, 2) = 2`.

    *   **Return Day 2**:
        *   Book 3: Lateness 3
        *   Book 4: Lateness 4
        The maximum lateness for Day 2 is `max(3, 4) = 4`.

    The total penalty is the sum of these maximum penalties: `2 + 4 = 6`. This matches the sample output.

3.  **Choosing a Data Structure**: To efficiently implement this, we need a way to:
    *   Store the maximum lateness encountered so far for each unique return day.
    *   Iterate through the input `A_i` and update this maximum.

    A `std::map<int, int>` (or `std::unordered_map<int, int>`) is an ideal choice. The `key` would be the `return_day` (`A_i`), and the `value` would store the `maximum_lateness` (which is `i`) found for that specific `return_day`.

    As we iterate `i` from `1` to `N`:
    *   Read the current `A_i`.
    *   The penalty for this book is `i`.
    *   Update the map: `return_day_to_max_late_days[A_i] = std::max(return_day_to_max_late_days[A_i], i)`. If `A_i` is not yet in the map, it will be inserted with `i` as its value (as `std::map` default-constructs `int` to `0`, `max(0, i)` will correctly initialize it to `i`).

4.  **Final Calculation**: After processing all `N` books, iterate through the `std::map` and sum up all the `maximum_lateness` values stored in it. This sum will be the total penalty. Since the total penalty can be large (up to $N \times N = 10^5 \times 10^5 = 10^{10}$), a `long long` data type should be used for the `total_penalty`.

## Complexity Analysis

Let `N` be the number of books and `T` be the number of test cases.

*   **Time Complexity**:
    *   **Input Processing Loop**: We iterate `N` times (from `i=1` to `N`). In each iteration:
        *   Reading `A_i` takes $O(1)$ time.
        *   Updating the `std::map`: A `std::map` operation (insertion or update) takes $O(\log K)$ time, where `K` is the number of unique keys currently in the map. In the worst case, `K` can be up to `N` (if all books are returned on different days). Thus, each map operation takes $O(\log N)$ time.
        *   Total for the loop: $N \times O(\log N) = O(N \log N)$.
    *   **Summing Penalties Loop**: We iterate through the `std::map`. In the worst case, the map contains `N` entries. Iterating through `K` entries takes $O(K)$ time. So, $O(N)$.
    *   **Total per test case**: $O(N \log N) + O(N) = O(N \log N)$.
    *   **Total for `T` test cases**: $O(T \cdot N \log N)$. Given $N \le 10^5$, $N \log N \approx 10^5 \times 17 \approx 1.7 \times 10^6$, which is efficient enough for typical time limits.

*   **Space Complexity**:
    *   The `std::map` stores at most `N` unique return days. Each entry consists of an `int` (return day) and an `int` (maximum penalty).
    *   Therefore, the space complexity is $O(N)$ to store the map.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map> // Required for std::map

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) { // Loop through each test case
        int n; // Number of books
        std::cin >> n;

        // A map to store the maximum penalty for each unique return day.
        // Key: return_day (A_i)
        // Value: maximum_lateness (i) for that return_day
        std::map<int, int> return_day_to_max_late_days;

        // Iterate from 1 to N, representing the i-th book.
        // The i-th book is i days late.
        for (int i = 1; i <= n; ++i) {
            int return_day; // The day the i-th book was returned
            std::cin >> return_day;

            // The penalty for the i-th book is 'i'.
            int penalty = i;

            // Update the map:
            // For the current 'return_day', we want to store the maximum 'penalty' (i)
            // encountered so far for that day.
            // If return_day is not in the map, it's inserted with 'penalty'.
            // If it's already in the map, its value is updated to max(current_value, penalty).
            return_day_to_max_late_days[return_day] = std::max(return_day_to_max_late_days[return_day], penalty);
        }

        // Calculate the total penalty by summing up the maximum penalties for each unique return day.
        long long total_penalty = 0; // Use long long as total penalty can exceed int limits (N*N)
        for (auto const& [day, max_penalty] : return_day_to_max_late_days) {
            total_penalty += max_penalty;
        }

        // Print the total penalty for the current test case, followed by a newline.
        std::cout << total_penalty << "\n";
    }
    return 0; // Indicate successful execution
}

```