# [Lockpicking Chef (LPC)](https://www.codechef.com/problems/LPC)
- **Difficulty Rating**: 1311
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to help Chef unlock a safe. We are given two strings, `S` and `K`, both consisting of digits '0' through '9'. `S` represents a long sequence of digits on the safe's dial, and `K` is the secret code. The length of `S` is `N` and the length of `K` is `M`, where `N >= M`.

To unlock the safe, Chef needs to find a substring of `S` of length `M` that, when transformed into `K`, requires the minimum total number of "moves". A "move" is defined as changing one digit to another. The digits are cyclic, meaning '0' follows '9' and '9' precedes '0'. For example, changing '1' to '5' takes 4 moves (`1->2->3->4->5`), and changing '1' to '9' takes 2 moves (`1->0->9`) because `abs(1-9)=8` but `10 - abs(1-9) = 2`.

Our task is to output this minimum total number of moves.

## Intuition & Mathematical Observation

The core of this problem lies in two parts:
1.  **Calculating the cost of changing one digit to another cyclically.**
2.  **Finding the optimal substring of `S` to match `K`.**

### 1. Digit Transformation Cost

For any two digits `d1` and `d2` (represented as integers), the cost to transform `d1` to `d2` can be calculated in two ways:
*   **Directly:** The absolute difference `abs(d1 - d2)`. For example, `1` to `5` is `abs(1-5) = 4` moves.
*   **Cyclically:** Moving around the dial. If `d1` is `1` and `d2` is `9`, the direct path is 8 moves. However, `1 -> 0 -> 9` is only 2 moves. This cyclic path can be calculated as `10 - abs(d1 - d2)`.
    *   Example: `d1=1, d2=9`. `abs(1-9)=8`. `10 - 8 = 2`.
    *   Example: `d1=7, d2=2`. `abs(7-2)=5`. `10 - 5 = 5`.
The minimum cost is simply the smaller of these two options: `min(abs(d1 - d2), 10 - abs(d1 - d2))`. This observation is crucial for correctly calculating individual digit costs.

### 2. Finding the Optimal Substring

Since we need to find a substring of `S` of length `M` that minimizes the total moves, we must consider all possible substrings of `S` that have length `M`.
*   A substring of length `M` can start at index `i` in `S`.
*   The first possible starting index is `0`.
*   The last possible starting index is `N - M`. (If it starts at `N-M`, it covers `S[N-M]` through `S[N-1]`, which is an `M`-length substring).
Therefore, we can iterate through all possible starting indices `i` from `0` to `N - M`.

For each starting index `i`:
*   We consider the substring `S[i...i+M-1]`.
*   We calculate the total moves required to transform this substring into `K`. This involves comparing `S[i+j]` with `K[j]` for each `j` from `0` to `M-1`, using the digit transformation cost function described above, and summing these individual costs.
*   We keep track of the minimum total moves found across all substrings.

The algorithm proceeds as follows:
1.  Initialize `min_total_moves` to a very large value (e.g., `1e9`).
2.  Loop `i` from `0` to `N - M`:
    a.  Initialize `current_total_moves` for the substring `S[i...i+M-1]` to `0`.
    b.  Loop `j` from `0` to `M - 1`:
        i.  Calculate the cost to change `S[i+j]` to `K[j]` using the `min(abs(d1 - d2), 10 - abs(d1 - d2))` formula.
        ii. Add this cost to `current_total_moves`.
    c.  Update `min_total_moves = min(min_total_moves, current_total_moves)`.
3.  After checking all possible substrings, `min_total_moves` will hold the answer.

## Complexity Analysis

*   **Time Complexity**:
    *   The outer loop iterates `N - M + 1` times (for each possible starting position of the substring in `S`).
    *   The inner loop iterates `M` times (to compare each digit of the `M`-length substring with `K`).
    *   Inside the inner loop, the `calculate_cost` function performs constant time operations (subtraction, absolute value, min).
    *   Therefore, the total time complexity is approximately `(N - M + 1) * M`. In the worst case, `M` can be close to `N/2`, making the complexity roughly `O(N * M)`. Given `N, M <= 1000`, `N * M` operations (up to `1000 * 1000 = 10^6`) are well within typical time limits for competitive programming (usually `10^8` operations per second).
    *   Thus, Time Complexity: $O(N \cdot M)$.

*   **Space Complexity**:
    *   We store the input strings `S` and `K`, which take `O(N)` and `O(M)` space respectively.
    *   A few integer variables are used for loop counters and storing minimums, which take `O(1)` space.
    *   Therefore, the total space complexity is dominated by the input strings.
    *   Thus, Space Complexity: $O(N + M)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries like iostream, string, algorithm

// Function to calculate the minimum moves to change digit d1 to d2
// Digits are cyclic (0-9).
int calculate_cost(char d1_char, char d2_char) {
    // Convert character digits to integer digits
    int d1 = d1_char - '0';
    int d2 = d2_char - '0';

    // Calculate the absolute difference
    int diff = abs(d1 - d2);

    // The cost is the minimum of moving directly (diff) or cyclically (10 - diff)
    return std::min(diff, 10 - diff);
}

// Function to solve a single test case
void solve() {
    int N, M;
    std::cin >> N >> M; // Read lengths of S and K
    std::string S, K;
    std::cin >> S >> K; // Read strings S and K

    // Initialize minimum total moves to a very large value.
    // The maximum possible moves for M=1000 is 1000 * 5 = 5000, so 1e9 is a safe upper bound.
    int min_total_moves = 1e9; 

    // Iterate through all possible starting positions for K in S.
    // A substring of length M starting at index i will occupy S[i] through S[i + M - 1].
    // The last possible starting index i is when i + M - 1 = N - 1,
    // which means i = N - M.
    for (int i = 0; i <= N - M; ++i) {
        int current_total_moves = 0; // Moves for the current substring S[i...i+M-1]

        // Calculate moves required to transform S[i...i+M-1] into K
        for (int j = 0; j < M; ++j) {
            // S[i+j] is the j-th character of the current substring of S
            // K[j] is the j-th character of the secret code K
            current_total_moves += calculate_cost(S[i + j], K[j]);
        }
        
        // Update the overall minimum total moves found so far
        min_total_moves = std::min(min_total_moves, current_total_moves);
    }

    // Output the minimum number of moves for this test case
    std::cout << min_total_moves << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}
```