# [COVID Pandemic and Long Queue (COVIDLQ)](https://www.codechef.com/problems/COVIDLQ)
- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if a queue of people adheres to social distancing guidelines. We are given `N` spots in a line, represented by a sequence of `0`s and `1`s, where `0` means an empty spot and `1` means a person is present. The social distancing rule states that any two people in the queue must be separated by at least 6 empty spots. This means the distance between their positions must be at least 7 (e.g., if one person is at index `i`, the next person must be at an index `j` such that `j - i >= 7`). We need to output "YES" if the rule is followed for all pairs of people, and "NO" otherwise.

## Intuition & Mathematical Observation

The core idea is to check the distance between *consecutive* people in the queue. If the distance between any two adjacent people is less than 7 (i.e., `j - i < 7`), then the social distancing rule is violated, and we can immediately conclude "NO". If all adjacent pairs satisfy the condition, then all non-adjacent pairs will also automatically satisfy it.

Consider three people at positions `p1`, `p2`, and `p3` such that `p1 < p2 < p3`, and `p2` is the first person after `p1`, and `p3` is the first person after `p2`.
If `p2 - p1 >= 7` and `p3 - p2 >= 7`, then the distance between `p1` and `p3` is `p3 - p1 = (p3 - p2) + (p2 - p1)`. Since both terms are `>= 7`, their sum `p3 - p1` will be `>= 14`, which is also `>= 7`. This logic extends to any number of people. Therefore, we only need to focus on the distance between directly adjacent people.

**Algorithm Steps:**

1.  Initialize a variable `last_person_pos` to `-1`. This variable will store the 0-indexed position of the last person encountered. Using `-1` indicates that no person has been found yet.
2.  Initialize a boolean flag `social_distancing_followed` to `true`. We will set this to `false` if any violation is found.
3.  Iterate through the `N` spots from `i = 0` to `N-1`.
4.  For each spot `i`:
    *   Read the value `A_i` (0 or 1).
    *   If `A_i` is `1` (a person is at this spot):
        *   Check if `last_person_pos` is not `-1`. This means we have found a previous person.
        *   If a previous person exists, calculate the distance: `current_position (i) - last_person_pos`.
        *   If this distance is less than `7` (meaning `i - last_person_pos < 7`), then a social distancing violation has occurred. Set `social_distancing_followed = false`.
        *   Update `last_person_pos` to the current position `i`.
5.  After iterating through all spots, if `social_distancing_followed` is still `true`, print "YES". Otherwise, print "NO".

**Edge Cases:**

*   If there are zero or one person in the queue, `last_person_pos` will either remain `-1` or be updated only once. No distance checks will be performed, and `social_distancing_followed` will remain `true`, which is correct as there are no two people to violate the rule.

## Complexity Analysis

*   **Time Complexity**: $O(N)$
    *   For each test case, the solution iterates through the `N` spots exactly once. Inside the loop, all operations (reading input, comparisons, assignments) take constant time, $O(1)$.
    *   Therefore, the time complexity per test case is linear with respect to `N`.
    *   Given `T` test cases, the total time complexity will be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum value of `N` across all test cases. With `N` up to 100 and `T` up to 1000, the total operations are roughly $1000 \times 100 = 10^5$, which is very efficient and well within typical time limits.

*   **Space Complexity**: $O(1)$
    *   The solution uses a few integer variables (`N`, `last_person_pos`, `A_i`, `i`, `T`) and a boolean variable (`social_distancing_followed`). The memory used by these variables is constant and does not depend on the input size `N`.
    *   Thus, the space complexity is constant.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read N, the number of spots

    int last_person_pos = -1; // Stores the 0-indexed position of the last person found.
                              // Initialized to -1 to indicate no person has been found yet.
    bool social_distancing_followed = true; // Flag to track if social distancing advice is followed.
                                            // Assume true initially, set to false if a violation is found.

    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read the state of the current spot (0 for empty, 1 for person)

        if (A_i == 1) { // If a person is at this spot
            if (last_person_pos != -1) { // If a previous person has already been found
                // Calculate the distance between the current person and the last found person.
                // Since spots are 0-indexed, the distance is simply the difference in their indices.
                // The rule is "at least 6 empty spots", which means a distance of at least 7.
                // So, a violation occurs if the distance is less than 7.
                if (i - last_person_pos < 7) { // Changed from 6 to 7 based on problem interpretation
                    social_distancing_followed = false; // A violation is found (distance < 7)
                    // We don't break the loop here because we still need to consume the rest of the input
                    // for the current test case to ensure correct input reading for subsequent test cases.
                    // However, further distance checks are redundant as the flag is already false.
                }
            }
            // Update last_person_pos to the current person's position for future comparisons.
            last_person_pos = i;
        }
    }

    // After iterating through all spots, print the result for the current test case.
    if (social_distancing_followed) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O setup as requested by competitive programming guidelines.
    // This unties cin/cout from C's stdio and disables synchronization, speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful execution
}
```