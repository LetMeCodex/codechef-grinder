# [Counting Words (CNTWRD)](https://www.codechef.com/problems/CNTWRD)
- **Difficulty Rating**: 296
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total number of words in a book. We are given two integers for each test case: `N`, representing the total number of pages in the book, and `M`, representing the number of words on each page. We need to output the total number of words for each test case.

## Intuition & Mathematical Observation
This is a very basic arithmetic problem. If a book has `N` pages and each page contains exactly `M` words, then to find the total number of words in the entire book, we simply multiply the number of pages by the number of words per page.

**Mathematical Observation:**
Total Words = `Number of Pages` $\times$ `Words per Page`
Total Words = `N` $\times$ `M`

No complex algorithms, data structures, or advanced mathematical concepts are required. We just need to perform a simple multiplication for each test case.

## Complexity Analysis
- **Time Complexity**: $O(T)$
    - The program iterates `T` times, once for each test case.
    - Inside the loop, it performs a constant number of operations: reading two integers (`N`, `M`), one multiplication (`N * M`), and one print operation. Each of these operations takes constant time, $O(1)$.
    - Therefore, the total time complexity is proportional to the number of test cases, $T$, resulting in $O(T)$.

- **Space Complexity**: $O(1)$
    - The program uses a fixed number of integer variables (`T`, `N`, `M`, `total_words`) to store input and intermediate results.
    - The memory usage does not depend on the input values `N` or `M` (beyond the fixed size of an integer).
    - No dynamic data structures (like arrays or vectors) whose size depends on the input are used.
    - Hence, the space complexity is constant, $O(1)$.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    cin >> T; // Read the value of T from standard input.

    // Loop 'T' times, once for each test case.
    // The 'T--' decrements T after each iteration, and the loop continues as long as T > 0.
    while (T--) {
        int N, M; // Declare two integer variables 'N' and 'M' for each test case.
                  // N: number of pages in the book.
                  // M: number of words on each page.
        cin >> N >> M; // Read the values of N and M for the current test case from standard input.

        // Calculate the total number of words.
        // If there are N pages and each page has M words, the total words is N * M.
        int total_words = N * M;

        // Output the calculated total number of words.
        // A newline character "\n" is appended to ensure each output is on a new line,
        // as required by the problem statement.
        cout << total_words << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}
```