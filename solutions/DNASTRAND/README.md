# [Complementary Strand in a DNA (DNASTRAND)](https://www.codechef.com/problems/DNASTRAND)
- **Difficulty Rating**: 660
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to find the complementary DNA strand given an initial DNA strand. We are provided with the length `N` of the strand and the sequence `S` itself. The rules for determining the complementary nucleotide are standard:
- 'A' (Adenine) is complementary to 'T' (Thymine)
- 'T' (Thymine) is complementary to 'A' (Adenine)
- 'C' (Cytosine) is complementary to 'G' (Guanine)
- 'G' (Guanine) is complementary to 'C' (Cytosine)

We need to output the resulting complementary DNA sequence. The input sequence `S` is guaranteed to contain only 'A', 'T', 'C', 'G' characters.

## Intuition & Mathematical Observation

The problem is a direct application of a one-to-one mapping. For each nucleotide in the given DNA strand, we simply need to replace it with its corresponding complementary nucleotide according to the specified rules. There are no complex algorithms, data structures, or mathematical observations required beyond understanding this direct mapping.

The approach is straightforward:
1. Read the length `N` and the DNA sequence `S`.
2. Initialize an empty string to store the complementary strand.
3. Iterate through each character (nucleotide) of the input string `S`.
4. For each character, apply the mapping rule:
   - If it's 'A', append 'T' to the complementary string.
   - If it's 'T', append 'A' to the complementary string.
   - If it's 'C', append 'G' to the complementary string.
   - If it's 'G', append 'C' to the complementary string.
5. After iterating through all characters, print the constructed complementary string.

## Complexity Analysis

-   **Time Complexity**: $O(N)$
    -   We iterate through the input string `S` exactly once. The loop runs `N` times, where `N` is the length of the string.
    -   Inside the loop, we perform constant-time operations: character comparison (`if-else if`) and appending a character to a `std::string`. Appending a character to a `std::string` takes amortized $O(1)$ time.
    -   Therefore, the total time complexity for processing one test case is $O(N)$.
    -   If there are `T` test cases, the total time complexity would be $O(T \cdot N_{max})$, where $N_{max}$ is the maximum possible length of `S` across all test cases.

-   **Space Complexity**: $O(N)$
    -   We create a new string, `complementary_S`, to store the result. This string will have the same length `N` as the input string `S`.
    -   Thus, the auxiliary space required to store the output string is $O(N)$.
    -   The input string `S` also occupies $O(N)$ space.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the DNA strand
    string S;
    cin >> S; // Read the sequence of nucleotides of one strand of DNA

    string complementary_S = ""; // Initialize an empty string to store the complementary strand
    // Optional optimization: reserve memory for the string to avoid reallocations.
    // For N <= 100, this is a minor optimization but good practice.
    complementary_S.reserve(N); 

    // Iterate through each nucleotide in the input string S
    for (char nucleotide : S) {
        // Determine the complementary nucleotide based on the given rules
        if (nucleotide == 'A') {
            complementary_S += 'T'; // A is complementary to T
        } else if (nucleotide == 'T') {
            complementary_S += 'A'; // T is complementary to A
        } else if (nucleotide == 'C') {
            complementary_S += 'G'; // C is complementary to G
        } else if (nucleotide == 'G') {
            complementary_S += 'C'; // G is complementary to C
        }
        // The problem constraints guarantee that S contains only 'A', 'T', 'C', and 'G',
        // so no 'else' case for invalid characters is necessary.
    }

    // Output the resulting complementary strand followed by a newline character
    cout << complementary_S << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, once for each test case
        solve(); // Call the solve function to handle the current test case
    }

    return 0; // Indicate successful program execution
}
```