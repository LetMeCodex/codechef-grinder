# [Discrepancies in the Voters List (VOTERS)](https://www.codechef.com/problems/VOTERS)
- **Difficulty Rating**: 1400
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find all voter IDs that appear in at least two out of three given lists of voter IDs. We are given the sizes of the three lists ($N_1, N_2, N_3$) and then the voter IDs for each list.

## Intuition & Mathematical Observation
The core of the problem is to efficiently count the occurrences of each voter ID across the three lists. A voter ID is considered "discrepant" if it appears in two or more lists.

A straightforward approach is to iterate through each list and keep track of how many times each unique voter ID has been encountered. A hash map (or `std::map` in C++) is an ideal data structure for this. The keys of the map will be the voter IDs, and the values will be the count of lists that contain that ID.

We can iterate through the first list, then the second, and finally the third. For each voter ID read, we increment its corresponding count in the map. If an ID is encountered for the first time, it will be added to the map with a count of 1. If it's encountered again (from the same or a different list), its count will be incremented.

After processing all three lists, we can iterate through the map. Any voter ID whose count is 2 or more is a discrepant voter and should be included in our final output. The problem also requires us to output the total number of such voters first, followed by the IDs themselves in ascending order. Since `std::map` stores keys in sorted order, iterating through it will naturally give us the IDs in ascending order.

## Complexity Analysis
- **Time Complexity**: $O((N_1 + N_2 + N_3) \log(N_1 + N_2 + N_3))$
    - We iterate through all $N_1 + N_2 + N_3$ voter IDs.
    - For each voter ID, we perform an insertion or update operation in `std::map`. The `std::map` in C++ is typically implemented as a balanced binary search tree (like a Red-Black Tree). Insertion and lookup operations take logarithmic time with respect to the number of elements in the map.
    - In the worst case, all voter IDs are unique, and the map will contain up to $N_1 + N_2 + N_3$ elements. Therefore, each map operation takes $O(\log(N_1 + N_2 + N_3))$ time.
    - After populating the map, we iterate through its elements. The number of unique voter IDs can be at most $N_1 + N_2 + N_3$. This iteration takes time proportional to the number of unique elements.
    - Thus, the dominant factor is the map operations, leading to the overall time complexity.

- **Space Complexity**: $O(U)$ where $U$ is the number of unique voter IDs across all three lists.
    - The `std::map` stores each unique voter ID and its count.
    - In the worst case, if all voter IDs are unique, $U$ can be up to $N_1 + N_2 + N_3$.
    - The `result` vector also stores the discrepant voter IDs, which in the worst case could be all unique IDs if they appear in at least two lists.
    - Therefore, the space complexity is proportional to the number of unique voter IDs.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// Function to speed up I/O operations
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

int main() {
    fast_io(); // Apply fast I/O

    int N1, N2, N3;
    // Read the sizes of the three voter lists
    std::cin >> N1 >> N2 >> N3;

    // Use a map to store voter IDs and their counts across lists.
    // Key: voter ID (int), Value: count of lists it appears in (int).
    // std::map automatically keeps keys sorted, which is useful for output.
    std::map<int, int> voter_counts;

    // Process the first list
    for (int i = 0; i < N1; ++i) {
        int id;
        std::cin >> id;
        voter_counts[id]++; // Increment count for this ID. If ID is new, it's added with count 1.
    }

    // Process the second list
    for (int i = 0; i < N2; ++i) {
        int id;
        std::cin >> id;
        voter_counts[id]++; // Increment count for this ID.
    }

    // Process the third list
    for (int i = 0; i < N3; ++i) {
        int id;
        std::cin >> id;
        voter_counts[id]++; // Increment count for this ID.
    }

    // Collect the results: voter IDs that appear in at least 2 lists.
    std::vector<int> result;
    // Iterate through the map. `std::map` iterates in ascending order of keys.
    for (auto const& [id, count] : voter_counts) {
        if (count >= 2) { // Check if the voter ID appeared in 2 or more lists
            result.push_back(id); // Add the ID to our result list
        }
    }

    // Output the total number of discrepant voters
    std::cout << result.size() << "\n";
    // Output each discrepant voter ID
    for (int id : result) {
        std::cout << id << "\n";
    }

    return 0; // Indicate successful execution
}
```