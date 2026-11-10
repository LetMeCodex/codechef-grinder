# [Laptop Recommendation (LAPTOPREC)](https://www.codechef.com/problems/LAPTOPREC)
- **Difficulty Rating**: 1104
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef's `N` friends are recommending laptops. Each friend recommends a laptop with an ID from 1 to 10. Chef wants to buy the laptop that receives the maximum number of recommendations.

The rules for Chef's decision are:
1.  If there is a **unique** laptop ID that received the highest number of recommendations, Chef will buy that laptop. In this case, we should output its ID.
2.  If multiple laptop IDs received the same highest number of recommendations (i.e., there's a tie for the most recommended), Chef gets "CONFUSED". In this case, we should output "CONFUSED".

The problem involves multiple test cases.

## Intuition & Mathematical Observation

The core of this problem is to count the frequency of recommendations for each laptop ID and then determine the most recommended one, carefully checking for ties.

1.  **Frequency Counting**: Since laptop IDs are small integers (specifically, from 1 to 10), we can efficiently count their occurrences. A simple array or `std::vector` in C++ can serve as a frequency map. We can declare a vector of size 11 (e.g., `vector<int> counts(11, 0);`) to allow for 1-based indexing, where `counts[i]` will store the number of recommendations for laptop ID `i`. We initialize all counts to zero. As we read each friend's recommendation (`laptop_id`), we simply increment `counts[laptop_id]`.

2.  **Finding Maximum Recommendations and Checking for Uniqueness**: After processing all `N` recommendations and populating our `counts` vector, we need to iterate through the possible laptop IDs (from 1 to 10) to find the maximum number of recommendations any laptop received. Simultaneously, we must keep track of whether this maximum is unique.
    *   We'll maintain two variables: `max_recommendations` (to store the highest count found so far) and `num_laptops_with_max_recs` (to count how many distinct laptop IDs have achieved this `max_recommendations`).
    *   When iterating through `counts[i]` for `i` from 1 to 10:
        *   If `counts[i]` is **greater than** `max_recommendations`, it means we've found a new, higher maximum. We update `max_recommendations` to `counts[i]`, set `recommended_laptop_id` to `i`, and reset `num_laptops_with_max_recs` to 1 (because this new maximum is currently unique).
        *   If `counts[i]` is **equal to** `max_recommendations`, it means we've found another laptop with the same highest number of recommendations. We increment `num_laptops_with_max_recs` to reflect this tie.

3.  **Final Decision**:
    *   After iterating through all laptop IDs (1 to 10), if `num_laptops_with_max_recs` is exactly 1, it means there was a unique laptop with the highest number of recommendations. We then output `recommended_laptop_id`.
    *   Otherwise (if `num_laptops_with_max_recs` is greater than 1), it indicates that multiple laptops tied for the highest number of recommendations. In this scenario, Chef is "CONFUSED", and we output "CONFUSED".

This approach is efficient because the range of laptop IDs is very small and fixed, making the frequency counting and maximum finding steps constant time operations relative to the number of distinct laptop IDs.

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Initializing the `counts` vector (size 11): This takes $O(1)$ time, as 11 is a fixed small number, independent of `N`.
        *   Reading `N` recommendations and updating counts: This involves a loop that runs `N` times. Inside the loop, reading an integer and incrementing a vector element are both $O(1)$ operations. Thus, this step takes $O(N)$ time.
        *   Iterating through laptop IDs (1 to 10) to find the maximum and check for uniqueness: This involves a loop that runs 10 times. Each iteration performs constant time comparisons and assignments. Thus, this step takes $O(1)$ time (as 10 is a fixed small number).
    *   Therefore, for a single test case, the total time complexity is $O(1 + N + 1) = O(N)$.
    *   Given `T` test cases, the overall time complexity will be $O(T \cdot N)$.

*   **Space Complexity**:
    *   The `counts` vector stores 11 integers. Its size is fixed regardless of the input `N`. Therefore, it consumes $O(1)$ constant space.
    *   All other variables (`N`, `laptop_id`, `max_recommendations`, `recommended_laptop_id`, `num_laptops_with_max_recs`, `T`) also consume $O(1)$ constant space.
    *   Thus, the total space complexity is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)
#include <vector>   // Required for std::vector, a dynamic array
#include <numeric>  // Not strictly needed for this problem, but often useful (e.g., std::iota)
#include <algorithm> // Not strictly needed for this problem, but often useful (e.g., std::max)

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std:: before standard library elements.
using namespace std;

// Function to solve a single test case
void solve() {
    int N; // Number of friends
    cin >> N;

    // Create a vector to store the count of recommendations for each laptop.
    // Since laptop IDs are from 1 to 10, a vector of size 11 is used
    // to allow 1-based indexing (counts[1] for laptop 1, counts[10] for laptop 10).
    // All counts are initialized to 0.
    vector<int> counts(11, 0); 

    // Read N recommendations and update their counts
    for (int i = 0; i < N; ++i) {
        int laptop_id;
        cin >> laptop_id;
        counts[laptop_id]++; // Increment the count for the recommended laptop
    }

    int max_recommendations = 0; // Stores the highest number of recommendations found so far
    int recommended_laptop_id = -1; // Stores the ID of the laptop with max_recommendations
    int num_laptops_with_max_recs = 0; // Counts how many laptops have max_recommendations

    // Iterate through laptop IDs from 1 to 10 to find the maximum recommendations
    // and determine if there's a unique laptop with that maximum.
    for (int i = 1; i <= 10; ++i) {
        if (counts[i] > max_recommendations) {
            // Found a new maximum number of recommendations
            max_recommendations = counts[i];
            recommended_laptop_id = i; // This laptop is currently the sole winner
            num_laptops_with_max_recs = 1; // Reset count of laptops with max recommendations
        } else if (counts[i] == max_recommendations) {
            // Found another laptop with the same maximum number of recommendations
            num_laptops_with_max_recs++;
        }
    }

    // Output the result based on the number of laptops with maximum recommendations
    if (num_laptops_with_max_recs == 1) {
        // If exactly one laptop has the maximum recommendations, print its ID
        cout << recommended_laptop_id << "\n";
    } else {
        // If multiple laptops have the maximum recommendations, Chef is CONFUSED
        cout << "CONFUSED" << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```