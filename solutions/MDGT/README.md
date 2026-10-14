# [Lost in the Fest!! (MDGT)](https://www.codechef.com/problems/MDGT)
- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem describes a scenario with `N` students standing in a line, each with a specific height. Bhoomi is initially the last student in the line (at position `N`, if we consider 1-indexed positions). Bhoomi wants to move forward in the line until she can see the stage. She can move one position forward each second. The condition for Bhoomi to see the stage is that her height must be strictly greater than the height of *all* students currently in front of her. We need to find the minimum number of seconds Bhoomi needs to move to satisfy this condition.

## Intuition & Mathematical Observation

Let's denote the heights of the students as $H_1, H_2, \ldots, H_N$, where $H_1$ is the height of the first student and $H_N$ is Bhoomi's initial height.

1.  **Bhoomi's Movement and Goal**: Bhoomi starts at position $N$. If she moves for `s` seconds, she will be at position $N-s$. Our goal is to find the *smallest* `s` such that when she is at position $N-s$, she can see the stage. This is equivalent to finding the *largest* possible position `k` (where $1 \le k \le N$) such that Bhoomi can see the stage when she is at position `k`. Once we find this `k`, the minimum number of seconds taken will be $N-k$.

2.  **Condition for Seeing**: When Bhoomi is at position `k` (1-indexed), the students in front of her are those originally at positions $1, 2, \ldots, k-1$. Bhoomi can see the stage if her height $H_N$ is strictly greater than the maximum height among these students.
    *   Mathematically: $H_N > \max(H_1, H_2, \ldots, H_{k-1})$.
    *   **Edge Case**: If $k=1$, there are no students in front of Bhoomi. In this scenario, the maximum height of students in front is effectively 0 (or negative infinity), so $H_N$ will always be strictly greater, and Bhoomi can always see.

3.  **Strategy for Finding `k`**: Since we are looking for the *largest* `k` that satisfies the seeing condition, we can iterate `k` downwards from $N$ to $1$. The first `k` we encounter that satisfies the condition will give us the minimum seconds required.

4.  **Efficiently Finding Maximum Height in a Prefix**: As we iterate `k` downwards, the set of students in front of Bhoomi (i.e., $H_1, \ldots, H_{k-1}$) changes. To efficiently find $\max(H_1, \ldots, H_{k-1})$ for various `k`, we can precompute a **prefix maximum array**.
    *   Let's use 0-indexed arrays for implementation. The input heights are $H[0], H[1], \ldots, H[N-1]$. Bhoomi's height is $H[N-1]$.
    *   We can create a `prefix_max` array where `prefix_max[j]` stores $\max(H[0], H[1], \ldots, H[j])$.
    *   When Bhoomi is at 1-indexed position `k`, the students in front are $H_1, \ldots, H_{k-1}$. In 0-indexed terms, these are $H[0], \ldots, H[k-2]$.
    *   The maximum height among these students is `prefix_max[k-2]` (provided $k-2 \ge 0$).

**Algorithm Steps:**

1.  Read the number of students `N` and their heights into a 0-indexed `std::vector<int> H`.
2.  **Handle `N=1` Edge Case**: If `N` is 1, Bhoomi is already at position 1. There are no students in front, so she can see immediately. Output `0` seconds and return.
3.  Store Bhoomi's height: `int bhoomi_h = H[N-1]`.
4.  Construct the `prefix_max` array. This array will store prefix maximums for students $H[0]$ through $H[N-2]$ (i.e., students who could potentially be in front of Bhoomi). Its size will be `N-1`.
    *   Initialize `prefix_max[0] = H[0]`.
    *   For `i` from `1` to `N-2`: `prefix_max[i] = std::max(prefix_max[i-1], H[i])`.
5.  Initialize `int seconds_taken = 0`.
6.  Iterate `k` (Bhoomi's 1-indexed position) from `N` down to `1`:
    *   Determine `max_val_in_front_of_k`:
        *   If `k == 1` (Bhoomi is at the very front), `max_val_in_front_of_k = 0`.
        *   Else (`k > 1`), `max_val_in_front_of_k = prefix_max[k-2]` (since `prefix_max` is 0-indexed and stores the maximum up to `H[k-2]`).
    *   Check the condition: If `bhoomi_h > max_val_in_front_of_k`:
        *   This is the largest `k` where Bhoomi can see.
        *   Calculate `seconds_taken = N - k`.
        *   `break` the loop, as we've found our answer.
7.  Print `seconds_taken`.

## Complexity Analysis

-   **Time Complexity**:
    *   Reading input `N` and `H`: $O(N)$
    *   Constructing the `prefix_max` array: This involves a loop that runs `N-1` times, with constant time operations inside. Thus, $O(N)$.
    *   Iterating `k` from `N` down to `1`: This loop runs at most `N` times. Inside the loop, operations (array access, comparison) are constant time. Thus, $O(N)$.
    *   Overall, for each test case, the time complexity is $O(N) + O(N) + O(N) = O(N)$.
    *   Given `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**:
    *   The `H` vector stores `N` heights: $O(N)$.
    *   The `prefix_max` vector stores `N-1` prefix maximums: $O(N)$.
    *   Other variables use constant space: $O(1)$.
    *   Overall, the space complexity is $O(N)$ per test case.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <vector>   // Required for std::vector
#include <algorithm> // Required for std::max

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of students
    std::vector<int> H(N); // Create a vector to store heights
    for (int i = 0; i < N; ++i) {
        std::cin >> H[i]; // Read heights
    }

    // If there's only one student, Bhoomi is at the front and can always see.
    // No movement needed.
    if (N == 1) {
        std::cout << 0 << "\n";
        return;
    }

    // Bhoomi's height is the last student's height (H_N in 1-indexed, H[N-1] in 0-indexed)
    int bhoomi_h = H[N - 1];

    // Create a prefix_max array.
    // prefix_max[i] will store the maximum height among H[0], H[1], ..., H[i].
    // We only need to consider students *before* Bhoomi's potential positions.
    // The maximum possible index for a student in front of Bhoomi is N-2 (if Bhoomi is at 1-indexed position N-1).
    // So prefix_max needs to go up to index N-2.
    // Its size will be N-1 (indices 0 to N-2).
    std::vector<int> prefix_max(N - 1); 
    
    // Initialize the first element
    prefix_max[0] = H[0];
    
    // Compute prefix maximums for the rest of the students in front
    for (int i = 1; i < N - 1; ++i) {
        prefix_max[i] = std::max(prefix_max[i - 1], H[i]);
    }

    int seconds_taken = 0;
    // Iterate Bhoomi's potential positions (1-indexed) from N down to 1.
    // We want to find the *first* position (largest k) where she can see.
    for (int k = N; k >= 1; --k) {
        int max_val_in_front_of_k = 0; // Default max height in front is 0 (for k=1, no one in front)

        // If k-1 >= 1, it means there are students in front of Bhoomi at position k.
        // The students in front are H_1, ..., H_{k-1} (1-indexed).
        // In 0-indexed, these are H[0], ..., H[k-2].
        // The maximum of these heights is stored in prefix_max[k-2].
        if (k - 1 >= 1) { 
            max_val_in_front_of_k = prefix_max[k - 2];
        }
        
        // Check if Bhoomi's height is strictly greater than everyone in front.
        if (bhoomi_h > max_val_in_front_of_k) {
            // If she can see, this is the earliest position (largest k) where she can.
            // The number of seconds taken is N - k (initial position N, current position k).
            seconds_taken = N - k;
            break; // Found the answer, no need to check further positions.
        }
    }
    std::cout << seconds_taken << "\n"; // Output the result
}

int main() {
    // Optimize C++ standard streams for faster input/output.
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