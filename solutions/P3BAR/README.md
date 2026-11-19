# [Exit Door (P3BAR)](https://www.codechef.com/problems/P3BAR)
- **Difficulty Rating**: 1096
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario where `N` people, each with a unique ID from 1 to `N`, are seated in a single row of `N` seats. Their initial seating arrangement is given as a permutation `P`. People leave the theatre one by one, starting with person `N`, then `N-1`, and so on, down to person `1`.

When a person decides to leave, they must walk past all other people who are *currently seated* either to their left or to their right to reach an exit. They will always choose the path (left or right) that minimizes the number of people they disturb. We need to calculate the total number of people disturbed across all `N` departures.

## Intuition & Mathematical Observation

The key aspects of this problem are:
1.  **Order of Departure**: People leave in a fixed, decreasing order of their ID (N, N-1, ..., 1).
2.  **Dynamic State**: The set of "currently seated" people changes after each departure.
3.  **Minimizing Disturbances**: Each departing person chooses the path (left or right) that involves passing the fewest *currently seated* individuals.

Given the small constraint on `N` (up to 10), a direct simulation of the process is feasible and efficient enough.

Here's the step-by-step intuition:

1.  **Initial Setup**:
    *   We need to know the initial seat of each person. An array `pos[person_id]` can store the seat index for each person ID.
    *   We need to keep track of which seats are currently occupied. A boolean array `occupied[seat_idx]` can serve this purpose, initialized to `true` for all seats.

2.  **Simulation Loop**:
    *   Iterate `person_id` from `N` down to `1`. This follows the specified departure order.
    *   For each `person_id` leaving:
        *   **Find Current Seat**: Retrieve `current_seat_idx = pos[person_id]`. Note that `pos` stores the *initial* seat index. Since people only leave and don't change seats, this index remains valid for the person's location.
        *   **Count Left Disturbances**: Iterate from `seat_idx = 0` up to `current_seat_idx - 1`. For each `seat_idx`, if `occupied[seat_idx]` is `true`, increment `left_count`.
        *   **Count Right Disturbances**: Iterate from `seat_idx = current_seat_idx + 1` up to `N - 1`. For each `seat_idx`, if `occupied[seat_idx]` is `true`, increment `right_count`.
        *   **Add to Total**: The number of disturbances for this person is `min(left_count, right_count)`. Add this value to a running `total_disturbed` sum.
        *   **Update State**: Mark the `current_seat_idx` as unoccupied by setting `occupied[current_seat_idx] = false`.

3.  **Final Result**: After all `N` people have left, `total_disturbed` will hold the final answer.

Since `N` is very small (maximum 10), the counting of left and right disturbances involves simple linear scans, which are `O(N)` operations. This `O(N)` operation is performed `N` times (once for each person leaving). Thus, the total time complexity per test case will be `O(N^2)`, which is very efficient for `N=10`.

## Complexity Analysis

*   **Time Complexity**:
    *   Reading input `P` and populating the `pos` array takes `O(N)` time.
    *   Initializing the `occupied` array takes `O(N)` time.
    *   The main loop iterates `N` times (for `person_id` from `N` down to `1`).
    *   Inside this loop:
        *   Finding `current_seat_idx` is `O(1)`.
        *   Counting `left_count` involves iterating up to `N-1` elements, taking `O(N)` time.
        *   Counting `right_count` involves iterating up to `N-1` elements, taking `O(N)` time.
        *   `std::min` and updating `total_disturbed` are `O(1)`.
        *   Updating `occupied` array is `O(1)`.
    *   Therefore, each iteration of the main loop takes `O(N)` time.
    *   Total time for one test case is `O(N * N) = O(N^2)`.
    *   Given `T` test cases, the overall time complexity is `O(T * N^2)`.
    *   With `N <= 10`, `N^2 <= 100`. The problem statement implies `sum of N over all test cases <= 10^5`. This means `T` can be up to `10^5` (if `N=1` for all cases) or `10^4` (if `N=10` for all cases). In the worst case (`T=10^4, N=10`), the total operations would be `10^4 * 10^2 = 10^6`, which is well within typical time limits.

*   **Space Complexity**:
    *   `p` vector: `O(N)` to store the initial permutation.
    *   `pos` vector: `O(N)` to store the initial seat index for each person ID.
    *   `occupied` vector: `O(N)` to track occupied seats.
    *   Other variables: `O(1)`.
    *   Thus, the total space complexity is `O(N)`.

## Solution Code

```cpp
#include <iostream> // For standard input/output operations (cin, cout)
#include <vector>   // For using std::vector
#include <algorithm> // For std::min

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cin from flushing std::cout before each input operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        int n; // Number of people/seats
        std::cin >> n; // Read N

        std::vector<int> p(n); // Vector to store the initial permutation of people
        // pos[person_id] will store the 0-indexed seat position of that person.
        // Size n+1 because person IDs are 1 to N.
        std::vector<int> pos(n + 1); 

        // Read the initial seating arrangement and populate the 'pos' array
        for (int i = 0; i < n; ++i) {
            std::cin >> p[i]; // Read the person ID at seat 'i'
            pos[p[i]] = i;   // Store that person's initial seat index
        }

        long long total_disturbed = 0; // Variable to accumulate total disturbances.
                                       // Using long long for safety, though int would suffice for N <= 10.
        
        // 'occupied[i]' is true if seat 'i' is currently occupied, false otherwise.
        // Initially, all N seats are occupied.
        std::vector<bool> occupied(n, true);
        
        // People leave in decreasing order of their ID: N, N-1, ..., 1.
        for (int person_id = n; person_id >= 1; --person_id) {
            // Get the current seat index of the person who is about to leave.
            // This is their initial seat, as people don't move seats before leaving.
            int current_seat_idx = pos[person_id];
            
            // Count the number of currently occupied seats to the left of the departing person.
            int left_count = 0;
            for (int i = 0; i < current_seat_idx; ++i) {
                if (occupied[i]) { // If the seat is occupied, it's a disturbance
                    left_count++;
                }
            }
            
            // Count the number of currently occupied seats to the right of the departing person.
            int right_count = 0;
            for (int i = current_seat_idx + 1; i < n; ++i) {
                if (occupied[i]) { // If the seat is occupied, it's a disturbance
                    right_count++;
                }
            }
            
            // The person chooses the path (left or right) that minimizes disturbances.
            total_disturbed += std::min(left_count, right_count);
            
            // After leaving, the person's seat becomes unoccupied.
            occupied[current_seat_idx] = false;
        }
        
        // Print the total number of disturbed people for the current test case.
        std::cout << total_disturbed << "\n";
    }
    return 0; // Indicate successful execution
}

```