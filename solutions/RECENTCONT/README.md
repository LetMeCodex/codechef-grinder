# Recent contest problems (RECENTCONT)
- **Difficulty Rating**: 793
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to count the occurrences of two specific contest codes, "START38" and "LTIME108", from a given list of contest codes. We are given an integer $N$, followed by $N$ contest codes. We need to output the count of "START38" and the count of "LTIME108" contests.

## Intuition & Mathematical Observation
The problem is a straightforward counting task. We are given a list of strings, and we need to categorize them into two groups based on their exact string value.

The core idea is to iterate through each contest code provided and check if it matches "START38". If it does, we increment a counter for "START38". If it doesn't match "START38", we assume it must be "LTIME108" (as per the problem constraints, only these two codes are relevant for counting) and increment a counter for "LTIME108".

There isn't any complex mathematical observation required here. The problem is purely about string comparison and counting.

## Complexity Analysis
- **Time Complexity**: $O(N \cdot L)$, where $N$ is the number of contest codes and $L$ is the maximum length of a contest code. In this specific problem, the contest codes are fixed strings ("START38" and "LTIME108"), so their length $L$ is a small constant. Therefore, the time complexity effectively becomes $O(N)$ because string comparison for fixed-length strings takes constant time. We iterate through $N$ contest codes, and for each, we perform a constant-time comparison and increment.

- **Space Complexity**: $O(1)$. We only use a few integer variables to store the counts of "START38" and "LTIME108", and a string variable to read each contest code. The space used does not grow with the input size $N$.

## Solution Code
```cpp
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--) {
        int n; // Number of contest codes for the current test case
        std::cin >> n;

        int start38_count = 0; // Counter for "START38"
        int ltime108_count = 0; // Counter for "LTIME108"

        // Iterate through each contest code
        for (int i = 0; i < n; ++i) {
            std::string contest_code;
            std::cin >> contest_code;

            // Check if the contest code is "START38"
            if (contest_code == "START38") {
                start38_count++;
            } else {
                // If not "START38", it must be "LTIME108" based on problem statement
                ltime108_count++;
            }
        }
        // Output the counts for the current test case
        std::cout << start38_count << " " << ltime108_count << "\n";
    }
    return 0;
}
```