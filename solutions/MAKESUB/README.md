# Make Subarray (MAKESUB)
- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary

Given a binary string $S$ of length $N$, representing a row of cells that are either white ('0') or black ('1'). We can change any white cell ('0') to a black cell ('1'). The goal is to make all black cells form a single contiguous subarray. We need to find the minimum number of changes (0s to 1s) required to achieve this.

## Intuition & Mathematical Observation

The core constraint is that we can only change '0's to '1's. We cannot change '1's to '0's. This means that any '1' that exists in the original string *must* be part of the final contiguous subarray of black cells.

Consider the positions of all the '1's in the original string. Let the index of the first '1' be $F$ and the index of the last '1' be $L$. For all the black cells to form a single contiguous subarray, this subarray must at least span from index $F$ to index $L$. Why? Because if the final contiguous subarray of black cells did not include all the original '1's, it would imply that some '1's were not part of the final black segment, which is impossible since we cannot change '1's to '0's.

Therefore, the smallest possible contiguous subarray that can contain all the original '1's is the segment from the first '1' to the last '1'. To minimize the number of changes, we should aim to make this segment the final contiguous subarray of black cells.

Any '0' that falls within this range (from the first '1' to the last '1') must be changed to a '1' to ensure the entire segment becomes black and contiguous. Any '0's outside this range (before the first '1' or after the last '1') can remain '0's, as they do not break the contiguity of the segment from $F$ to $L$.

**Special Case:** If the string contains no '1's (i.e., all cells are '0'), then the condition is already met vacuously. An empty set of black cells is a contiguous subarray. In this case, zero changes are needed.

**Algorithm:**
1. Find the index of the first occurrence of '1' in the string.
2. Find the index of the last occurrence of '1' in the string.
3. If no '1' is found, the answer is 0.
4. Otherwise, iterate through the string from the index of the first '1' to the index of the last '1'.
5. Count how many '0's are present in this range. This count is the minimum number of changes required.

## Complexity Analysis

- **Time Complexity**: $O(N)$, where $N$ is the length of the binary string.
    - Finding the first '1' using `S.find('1')` takes $O(N)$ time in the worst case.
    - Finding the last '1' using `S.rfind('1')` takes $O(N)$ time in the worst case.
    - Iterating from the first '1' to the last '1' to count '0's takes at most $O(N)$ time.
    - The overall time complexity is dominated by these linear operations.

- **Space Complexity**: $O(1)$.
    - We are only using a few variables to store indices and a counter. The space used does not depend on the input size $N$.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (cin, cout)
#include <string>   // Required for std::string and its methods (find, rfind)
#include <algorithm> // Not strictly necessary for this solution, but often useful

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N; // Read the number of cells
    std::string S;
    std::cin >> S; // Read the binary string representing the canvas state

    // Find the index of the first occurrence of '1'
    // std::string::npos is a special value indicating "not found"
    size_t first_one = S.find('1');

    // If no '1's are found in the string, it means there are no black cells.
    // An empty set of black cells satisfies the contiguous subarray condition.
    // Therefore, 0 changes are needed.
    if (first_one == std::string::npos) {
        std::cout << 0 << "\n";
        return; // Move to the next test case
    }

    // Find the index of the last occurrence of '1'
    size_t last_one = S.rfind('1');

    // If '1's are present, the final contiguous subarray of black cells
    // must span at least from 'first_one' to 'last_one'.
    // This is because we cannot change '1's to '0's, so all existing '1's
    // must remain black and be part of the final contiguous segment.
    // To minimize changes, we only fill '0's within this minimal required range.

    int changes = 0; // Counter for the number of '0's to change to '1's
    // Iterate through the cells from the first '1' to the last '1'
    for (size_t i = first_one; i <= last_one; ++i) {
        // If a cell within this range is '0' (white), it must be changed to '1' (black)
        if (S[i] == '0') {
            changes++; // Increment the count of changes needed
        }
    }

    // Output the minimum number of changes for this test case
    std::cout << changes << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from flushing before std::cin reads input.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop T times, once for each test case
        solve();   // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```