# [Coronavirus Spread (COVID19)](https://www.codechef.com/problems/COVID19)
- **Difficulty Rating**: 1219
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to consider `N` people located at distinct positions `X_1, X_2, ..., X_N` on a 1D line. These positions are given in strictly increasing order. A person at position `P` can infect another person at position `Q` if the absolute difference between their positions, `|P - Q|`, is less than or equal to 2. This infection can spread transitively (if A infects B, and B infects C, then A can indirectly infect C).

We need to determine the minimum and maximum possible number of people that can get infected, assuming the infection starts from a single person.

## Intuition & Mathematical Observation

The core of this problem lies in understanding the "infection spread" mechanism.
1.  **Direct Infection Rule**: Two people at `P` and `Q` can directly infect each other if `|P - Q| <= 2`.
2.  **Transitive Property**: If person A infects B, and B infects C, then A, B, and C all belong to the same "infected group". This means that if there's a chain of people `P_1, P_2, ..., P_k` such that `P_i` can infect `P_{i+1}` for all `1 <= i < k`, then all `k` people form a single connected group and can all be infected if any one of them is the initial source.
3.  **Sorted Positions**: The problem states that the positions `X_1, X_2, ..., X_N` are given in strictly increasing order. This is a crucial simplification. Because the positions are sorted, `|X_i - X_j|` for `j > i` simply becomes `X_j - X_i`.
4.  **Identifying Connected Components**: Due to the sorted nature and transitivity, we can identify "connected components" or "segments" of people. We iterate through the people from left to right. If the distance between two adjacent people `X_i` and `X_{i+1}` is `X_{i+1} - X_i <= 2`, they are part of the same connected group. If `X_{i+1} - X_i > 2`, then `X_i` and `X_{i+1}` cannot infect each other, and thus they belong to different, independent infection groups. This "breaks" the current chain of infection.

Therefore, the problem reduces to finding all contiguous segments of people where each adjacent pair within the segment satisfies the `distance <= 2` condition. For example, if we have positions `[1, 2, 3, 8, 9, 15]`:
- `X_1=1, X_2=2`: `2-1=1 <= 2`. Connected.
- `X_2=2, X_3=3`: `3-2=1 <= 2`. Connected. So `[1, 2, 3]` forms a group of size 3.
- `X_3=3, X_4=8`: `8-3=5 > 2`. Not connected. The group `[1, 2, 3]` ends. A new group starts with `X_4=8`.
- `X_4=8, X_5=9`: `9-8=1 <= 2`. Connected. So `[8, 9]` forms a group of size 2.
- `X_5=9, X_6=15`: `15-9=6 > 2`. Not connected. The group `[8, 9]` ends. A new group starts with `X_6=15`.
- End of people. The group `[15]` ends.

The sizes of these independent infection groups are `3`, `2`, and `1`. The minimum number of people that can get infected is the smallest of these sizes (1), and the maximum is the largest (3).

The algorithm involves iterating through the sorted positions, maintaining a `current_segment_size`. When a break in connectivity is found (`X_{i+1} - X_i > 2`), the `current_segment_size` is recorded, and a new segment begins. After the loop, the size of the last segment must also be recorded.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   Reading `N` and `T` takes constant time.
    -   Reading the `N` positions into a vector takes $O(N)$ time.
    -   The main loop iterates `N-1` times (from `i=1` to `N-1`). Inside the loop, operations like subtraction, comparison, increment, and `min`/`max` updates are all $O(1)$.
    -   The final update for the last segment is also $O(1)$.
    -   Therefore, for each test case, the time complexity is dominated by reading the input and the single pass through the positions, resulting in $O(N)$.
    -   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$
    -   A `vector<int> X` is used to store the `N` positions, requiring $O(N)$ space.
    -   All other variables (`N`, `min_infected`, `max_infected`, `current_segment_size`, loop counter `i`, `T`) use a constant amount of space, $O(1)$.
    -   Thus, the total space complexity for each test case is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, algorithm, limits, etc.

// Using namespace std as requested by problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of people
    vector<int> X(N); // Create a vector to store their positions
    for (int i = 0; i < N; ++i) {
        cin >> X[i]; // Read positions
    }

    // Initialize min_infected and max_infected.
    // Constraints state N >= 2, so there will always be at least one person
    // and thus at least one segment of size >= 1.
    // Using numeric_limits for robust initialization.
    int min_infected = numeric_limits<int>::max();
    int max_infected = numeric_limits<int>::min();
    
    // current_segment_size tracks the number of people in the current connected group.
    // Start with 1 for the first person in any segment.
    int current_segment_size = 1;

    // Iterate from the second person (index 1) to compare with the previous one.
    for (int i = 1; i < N; ++i) {
        // If the distance between current person and previous person is at most 2,
        // they are part of the same connected segment.
        if (X[i] - X[i-1] <= 2) {
            current_segment_size++;
        } else {
            // If the distance is greater than 2, the current segment ends here.
            // Update min_infected and max_infected with the size of the completed segment.
            min_infected = min(min_infected, current_segment_size);
            max_infected = max(max_infected, current_segment_size);
            
            // Start a new segment with the current person.
            current_segment_size = 1;
        }
    }

    // After the loop, the last segment's size needs to be processed.
    // This is crucial because the loop finishes without processing the segment
    // that extends to the end of the array.
    min_infected = min(min_infected, current_segment_size);
    max_infected = max(max_infected, current_segment_size);

    // Print the results for the current test case.
    cout << min_infected << " " << max_infected << "\n";
}

int main() {
    // Enable fast I/O as requested.
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