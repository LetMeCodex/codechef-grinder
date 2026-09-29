# [Chef Diet (DIET)](https://www.codechef.com/problems/DIET)
- **Difficulty Rating**: 1025
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef needs to follow a diet for `N` days. Each day, he requires exactly `K` units of protein. On day `i`, he receives `A[i]` units of protein. Any excess protein from a day can be stored and used on subsequent days. If, on any given day, Chef does not have enough protein (including stored protein) to meet the `K` unit requirement, he fails his diet.

The task is to determine if Chef can successfully complete his `N`-day diet. If he can, output "YES". If he fails, output "NO" followed by the 1-indexed day number on which he first failed.

## Intuition & Mathematical Observation

The problem can be solved by simulating the diet process day by day. We need to keep track of the `stored_protein` from previous days.

1.  **Initialization**: Start with `stored_protein = 0`. This represents the protein carried over from the day before the diet begins.
2.  **Daily Process**: For each day `i` (from 0 to `N-1`):
    *   Calculate the total protein available for the current day: `current_total_protein = stored_protein + A[i]`.
    *   **Check for Failure**: If `current_total_protein < K`, Chef does not have enough protein. He fails on this day. We record `i + 1` (since days are 1-indexed) as the `first_day_fail` and stop the simulation.
    *   **Update Stored Protein**: If Chef has enough protein (`current_total_protein >= K`), he consumes `K` units. The remaining protein, `current_total_protein - K`, becomes the `stored_protein` for the next day.
3.  **Final Result**:
    *   If the loop completes without Chef failing, it means he successfully completed the diet for all `N` days. Output "YES".
    *   If the loop was broken due to a failure, output "NO" followed by the `first_day_fail` day number.

This approach directly models the problem statement and requires no complex data structures or algorithms beyond a simple loop and variable updates.

## Complexity Analysis

-   **Time Complexity**: $O(N)$ per test case.
    *   Reading `N` and `K` takes $O(1)$.
    *   Reading the `N` protein values `A[i]` takes $O(N)$.
    *   The main `for` loop iterates at most `N` times. Inside the loop, all operations (addition, comparison, subtraction, assignment) are $O(1)$.
    *   Therefore, the total time complexity for one test case is dominated by the $O(N)$ operations.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$ per test case.
    *   We use a `std::vector<long long> a` to store the `N` protein values, which requires $O(N)$ space.
    *   All other variables (`t`, `n`, `k`, `stored_protein`, `possible`, `first_day_fail`, `current_protein`) use $O(1)$ space.
    *   Thus, the overall space complexity for one test case is $O(N)$.

## Solution Code

```cpp
#include <iostream> // For input/output operations (std::cin, std::cout)
#include <vector>   // For using std::vector to store daily protein amounts
#include <numeric>  // Not strictly needed for this solution, but often useful for vector operations

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t; // Read the number of test cases

    while (t--) { // Loop through each test case
        int n;       // Number of days
        long long k; // Required protein per day
        std::cin >> n >> k; // Read N and K for the current test case

        // Create a vector to store the protein received each day.
        // Using long long for protein amounts to avoid potential overflow,
        // as K and A[i] can be up to 10^9, and their sum can exceed int limits.
        std::vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i]; // Read protein received on day i
        }

        long long stored_protein = 0; // Protein carried over from previous days
        bool possible = true;         // Flag to track if Chef can complete the diet
        int first_day_fail = -1;      // Stores the 1-indexed day Chef first fails

        // Simulate the diet day by day
        for (int i = 0; i < n; ++i) {
            // Calculate total protein available for the current day
            long long current_protein_available = stored_protein + a[i];

            // Check if Chef has enough protein for the current day
            if (current_protein_available < k) {
                possible = false;       // Chef failed
                first_day_fail = i + 1; // Record the 1-indexed day of failure
                break;                  // No need to continue, diet failed
            }

            // If Chef has enough, consume K protein and store the excess
            stored_protein = current_protein_available - k;
        }

        // Output the result based on whether Chef completed the diet
        if (possible) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO " << first_day_fail << "\n";
        }
    }

    return 0; // Indicate successful execution
}

```