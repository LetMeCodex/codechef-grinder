# [Seating (SEATING7)](https://www.codechef.com/problems/SEATING7)
- **Difficulty Rating**: 913
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to simulate a seating process. We are given `N` seats, numbered from 1 to `N`. Initially, `M` of these seats are occupied. Then, `K` new people arrive, one by one. Each new person follows a specific rule: they always take the lowest-numbered available (empty) seat. Our task is to print the seat numbers taken by these `K` new people, in the order they are taken. This process needs to be repeated for `T` test cases.

## Intuition & Mathematical Observation

The core of this problem lies in efficiently finding the "lowest-numbered available seat" repeatedly.

1.  **Representing Seats**: A boolean array or vector is a natural choice to keep track of seat occupancy. Let `occupied[i]` be `true` if seat `i` is taken, and `false` otherwise. Since seats are 1-indexed, a vector of size `N+1` is convenient.

2.  **Initial Setup**: First, we read the `M` initially occupied seats and mark them as `true` in our `occupied` array.

3.  **Processing New People**: For each of the `K` new people:
    *   We need to find the smallest `seat_num` such that `occupied[seat_num]` is `false`.
    *   Once found, we print `seat_num`, then mark `occupied[seat_num]` as `true`.

**Optimization**: The key observation for efficiency comes from the rule "each new person takes the lowest numbered available seat." This implies that seats are always filled from left to right (lowest to highest number). If the current person takes seat `S`, then all seats `1` through `S-1` must already be occupied (either initially or by previous new people). Therefore, for the *next* person, we don't need to start searching from seat 1 again. We can start our search from seat `S+1`.

This optimization can be implemented by maintaining a variable, say `next_available_seat`, which stores the lowest seat number from which to start searching. Initially, `next_available_seat` is 1. After a person takes seat `S`, we update `next_available_seat` to `S+1`. This ensures that we never re-check seats that are already known to be occupied.

## Complexity Analysis

Let `N` be the total number of seats, `M` be the initially occupied seats, and `K` be the number of new people.

*   **Time Complexity**: $O(N + M + K)$
    *   Initializing the `occupied` vector takes $O(N)$ time.
    *   Reading and marking the `M` initially occupied seats takes $O(M)$ time.
    *   The loop for `K` new people:
        *   The outer loop runs `K` times.
        *   The inner loop searches for the `next_available_seat`. Due to the `next_available_seat` optimization, the `seat_num` variable in the inner loop (`for (int seat_num = next_available_seat; seat_num <= N; ++seat_num)`) effectively traverses the seats from 1 to `N` *at most once in total* across all `K` iterations of the outer loop. Each seat is checked a constant number of times (when `next_available_seat` points to it, and then when it's incremented past it).
        *   Therefore, the total work done by the inner search loop across all `K` people is $O(N)$.
    *   Printing the `K` seat numbers takes $O(K)$ time.
    *   Combining these, the total time complexity per test case is $O(N + M + K)$. Given that $M < N$ and $K \le N-M$, this can be simplified to $O(N)$ as $N$ is the dominant factor.

*   **Space Complexity**: $O(N)$
    *   We use a boolean vector `occupied` of size `N+1` to store the occupancy status of seats. This requires $O(N)$ space.

Given $N \le 10^5$, $O(N)$ time and space per test case is efficient enough for the given constraints ($T \le 10$).

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested
using namespace std;

void solve() {
    int N, M, K;
    cin >> N >> M >> K;

    // Using a boolean vector to represent seats.
    // occupied[i] is true if seat i is taken, false otherwise.
    // Size N+1 because seats are 1-indexed (seats 1 to N).
    vector<bool> occupied(N + 1, false);

    // Read the M initially occupied seats and mark them
    for (int i = 0; i < M; ++i) {
        int seat_num;
        cin >> seat_num;
        occupied[seat_num] = true;
    }

    // next_available_seat keeps track of the lowest seat number
    // from which to start searching for an empty seat.
    // This is an optimization: since people always take the lowest
    // available seat, and seats are only ever taken, we don't need
    // to search from seat 1 every time.
    int next_available_seat = 1;

    // For each of the K new people
    for (int i = 0; i < K; ++i) {
        // Find the lowest numbered available seat
        // Start search from next_available_seat, as seats below it
        // must already be occupied.
        for (int seat_num = next_available_seat; seat_num <= N; ++seat_num) {
            if (!occupied[seat_num]) {
                // Found an available seat
                // Print the seat number. Add a space after it unless it's the last number for this test case.
                cout << seat_num << (i == K - 1 ? "" : " "); 
                
                occupied[seat_num] = true; // Mark this seat as occupied
                
                // Update next_available_seat for the next person.
                // The next person will search from the seat immediately after this one.
                next_available_seat = seat_num + 1; 
                
                break; // Move to the next person
            }
        }
    }
    cout << "\n"; // Newline after all K seats for the current test case
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}
```