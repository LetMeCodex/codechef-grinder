# [Problem Difficulties (PROBDIFF)](https://www.codechef.com/problems/PROBDIFF)
- **Difficulty Rating**: 1321
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to consider four problems, each with a given difficulty level. Our goal is to form the maximum possible number of pairs of problems such that the two problems in each pair have *distinct* difficulty levels. Each problem can be used in at most one pair. We need to output this maximum number of pairs.

## Intuition & Mathematical Observation

The core idea revolves around the frequencies of the given difficulty levels. Since we only have four problems, we can categorize all possible scenarios based on how many *distinct* difficulty levels are present among these four problems. A `std::map` is an ideal data structure to count the occurrences of each difficulty level.

Let's analyze the possible cases based on the number of distinct difficulty levels:

1.  **Four Distinct Difficulties (e.g., `1 2 3 4`)**:
    *   We have four unique problems.
    *   We can form two pairs: `(1,2)` and `(3,4)`. Both pairs satisfy the distinct difficulty condition.
    *   **Result: 2 pairs.**

2.  **Three Distinct Difficulties (e.g., `1 1 2 3`)**:
    *   In this case, one difficulty level must appear twice, and the other two appear once. Let the difficulties be `A, A, B, C`.
    *   We can form two pairs: `(A, B)` and `(A, C)`. Both pairs use problems with distinct difficulties.
    *   **Result: 2 pairs.**

3.  **Two Distinct Difficulties**:
    *   This case has two sub-scenarios based on the counts of the two distinct difficulties:
        *   **Sub-case 3a: Counts are (3, 1) (e.g., `1 1 1 2`)**:
            *   Let the difficulties be `A, A, A, B`.
            *   We can form only one pair `(A, B)`. We are then left with two problems of difficulty `A`, which cannot form a pair with each other.
            *   **Result: 1 pair.**
        *   **Sub-case 3b: Counts are (2, 2) (e.g., `1 1 2 2`)**:
            *   Let the difficulties be `A, A, B, B`.
            *   We can form two pairs: `(A, B)` and `(A, B)`. Both pairs satisfy the distinct difficulty condition.
            *   **Result: 2 pairs.**

4.  **One Distinct Difficulty (e.g., `1 1 1 1`)**:
    *   All four problems have the same difficulty level.
    *   It's impossible to form any pair where the problems have distinct difficulties.
    *   **Result: 0 pairs.**

The solution code implements this logic by first counting the frequencies of each difficulty using a `std::map`. Then, it checks the size of the map (which gives the number of distinct difficulties) and applies the rules derived above. For the "two distinct difficulties" case, it further checks if any difficulty has a count of 3 to differentiate between sub-cases (3,1) and (2,2).

## Complexity Analysis

*   **Time Complexity**:
    *   For each test case:
        *   Reading 4 integers: $O(1)$.
        *   Inserting/updating 4 entries in a `std::map`: Each operation on a `std::map` (typically implemented as a balanced binary search tree) takes $O(\log K)$ time, where $K$ is the number of elements in the map. Since $K$ will be at most 4, this is effectively $O(\log 4) = O(1)$. So, 4 operations take $4 \times O(1) = O(1)$.
        *   Getting the size of the map: $O(1)$.
        *   Iterating through the map (at most 4 elements) in the `distinct_difficulty_count == 2` case: $O(K) = O(1)$.
        *   Printing the result: $O(1)$.
    *   Therefore, the time complexity for a single test case is $O(1)$.
    *   Given $T$ test cases, the total time complexity is $O(T)$.

*   **Space Complexity**:
    *   For each test case:
        *   The `std::map<int, int> counts` stores at most 4 key-value pairs (one for each distinct difficulty). This is a constant amount of memory.
        *   Other variables use constant space.
    *   Therefore, the space complexity for a single test case is $O(1)$.

## Solution Code

```cpp
#include <iostream> // Required for std::cin, std::cout
#include <map>      // Required for std::map

// Function to solve a single test case
void solve() {
    // Use a map to store the frequency of each difficulty level.
    // Key: difficulty level, Value: count of problems with that difficulty.
    std::map<int, int> counts;

    // Read the four difficulty levels and update their counts.
    for (int i = 0; i < 4; ++i) {
        int a;
        std::cin >> a;
        counts[a]++; // Increment count for difficulty 'a'
    }

    // The number of distinct difficulty levels is simply the size of the map.
    int distinct_difficulty_count = counts.size();

    // Apply the logic based on the number of distinct difficulty levels:
    if (distinct_difficulty_count == 4) {
        // Case 1: All four problems have distinct difficulties (e.g., 1 2 3 4).
        // Can form two sets: [1,2] and [3,4].
        std::cout << 2 << "\n";
    } else if (distinct_difficulty_count == 3) {
        // Case 2: Three distinct difficulties (e.g., 1 1 2 3).
        // One difficulty appears twice, others once. Can form two sets: [1,2] and [1,3].
        std::cout << 2 << "\n";
    } else if (distinct_difficulty_count == 2) {
        // Case 3: Two distinct difficulties.
        // Sub-case A: Counts are (3, 1) (e.g., 1 1 1 2). Only one set [1,2] can be formed.
        // Sub-case B: Counts are (2, 2) (e.g., 1 1 2 2). Can form two sets: [1,2] and [1,2].

        // Check if any difficulty has a count of 3 to distinguish sub-cases.
        bool has_three_count = false;
        for (auto const& pair : counts) { // Iterate through the map's key-value pairs
            if (pair.second == 3) { // If any difficulty has a count of 3
                has_three_count = true;
                break;
            }
        }

        if (has_three_count) {
            std::cout << 1 << "\n"; // Sub-case A: (3,1) counts
        } else {
            std::cout << 2 << "\n"; // Sub-case B: (2,2) counts (since it's not (3,1) and distinct_count is 2)
        }
    } else { // distinct_difficulty_count == 1
        // Case 4: All four problems have the same difficulty (e.g., 1 1 1 1).
        // Cannot form any set as problems must have distinct difficulties.
        std::cout << 0 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}
```