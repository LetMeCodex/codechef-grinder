# [Hostel Room (HOSTELROOM)](https://www.codechef.com/problems/HOSTELROOM)
- **Difficulty Rating**: 1169
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the maximum number of people that were ever in a hostel room. We are given the initial number of people in the room, `x`, and a sequence of `n` events. Each event is represented by an integer `a`. If `a` is positive, it means `a` people entered the room. If `a` is negative, it means `abs(a)` people left the room. We need to output the maximum number of people that were present in the room at any point in time.

## Intuition & Mathematical Observation

The core of the problem is to track the number of people in the room over time and find the peak value. We start with an initial number of people, `x`. Then, for each event, we update the current number of people by adding the value of `a`.

Let `current_people` be the number of people in the room at any given moment. Initially, `current_people = x`.
For each event `a_i` (where `i` ranges from 1 to `n`):
`current_people = current_people + a_i`

We also need to keep track of the maximum number of people seen so far. Let `max_people` be this value. Initially, `max_people = x` (since `x` is the number of people at the start).
After each update to `current_people`, we compare it with `max_people` and update `max_people` if `current_people` is greater:
`max_people = max(max_people, current_people)`

By iterating through all the events and performing these updates, `max_people` will eventually hold the maximum number of people that were ever in the room.

The problem statement implies that `a` can be positive or negative. However, the provided solution code only considers `a` as the *change* in people. If `a` represents the number of people *entering*, then a negative `a` would mean people leaving. The code `current_people += a;` correctly handles both positive and negative values of `a` as changes.

## Complexity Analysis

- **Time Complexity**: $O(N)$
  The code iterates through the `n` events exactly once. Inside the loop, the operations (addition, comparison, assignment) take constant time. Therefore, the total time complexity is directly proportional to the number of events, `n`.

- **Space Complexity**: $O(1)$
  The solution uses a few variables (`t`, `n`, `x`, `current_people`, `max_people`, `a`) to store the input and intermediate results. The amount of memory used does not depend on the input size `n`. Thus, the space complexity is constant.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of events
        long long x; // Initial number of people in the room
        std::cin >> n >> x;

        long long current_people = x; // Tracks the current number of people in the room
        long long max_people = x;     // Tracks the maximum number of people seen so far

        // Process each event
        for (int i = 0; i < n; ++i) {
            long long a; // Change in the number of people
            std::cin >> a;

            // Update the current number of people
            current_people += a;

            // Update the maximum number of people if the current count is higher
            if (current_people > max_people) {
                max_people = current_people;
            }
        }
        // Output the maximum number of people ever in the room for this test case
        std::cout << max_people << "\n";
    }
    return 0;
}
```