# [Chef and Steps (CHEFSTEP)](https://www.codechef.com/problems/CHEFSTEP)
- **Difficulty Rating**: 1110
- **Solved in**: 2 attempt(s)

## Problem Summary

Chef has a unique step length, `K`. He needs to traverse `N` different distances, `D_1, D_2, ..., D_N`. For each distance `D_i`, we need to determine if Chef can cover it *exactly* using his step length `K`. If he can, we output '1'; otherwise, we output '0'. The output for all `N` distances should be concatenated into a single binary string.

**Example:**
If `N = 3`, `K = 2`, and distances are `D = [4, 3, 6]`:
- For `D_1 = 4`: Chef can take 2 steps (2 * 2 = 4). Output '1'.
- For `D_2 = 3`: Chef cannot cover 3 exactly with steps of 2. Output '0'.
- For `D_3 = 6`: Chef can take 3 steps (3 * 2 = 6). Output '1'.
The final output string would be "101".

## Intuition & Mathematical Observation

The core of this problem lies in understanding what it means for Chef to cover a distance `D_i` *exactly* using his step length `K`.

If Chef takes `S` steps, the total distance he covers is `S * K`. For him to cover a distance `D_i` exactly, `D_i` must be equal to `S * K` for some non-negative integer `S`.

This is the definition of divisibility: `D_i` must be a multiple of `K`.
In mathematical terms, `D_i` is a multiple of `K` if and only if the remainder when `D_i` is divided by `K` is 0. This can be checked using the modulo operator: `D_i % K == 0`.

So, for each given distance `D_i`:
- If `D_i % K == 0`, Chef can cover it exactly. We append '1' to our result string.
- If `D_i % K != 0`, Chef cannot cover it exactly. We append '0' to our result string.

We repeat this for all `N` distances and then print the final concatenated string.

## Complexity Analysis

-   **Time Complexity**: $O(\sum N)$
    -   The program reads `T` test cases.
    -   For each test case, it reads `N` and `K`.
    -   Then, it iterates `N` times. In each iteration:
        -   It reads `D_i`. This is an $O(1)$ operation.
        -   It performs a modulo operation (`D_i % K`). This is an $O(1)$ operation.
        -   It appends a character ('1' or '0') to a `std::string`. Appending a single character to `std::string` is an amortized $O(1)$ operation.
    -   Finally, it prints the `N`-character result string. This takes $O(N)$ time.
    -   Given that the sum of `N` over all test cases does not exceed $10^5$, the total number of `D_i` values processed across all test cases is $\sum N$. Each `D_i` involves constant time operations (read, modulo, append). The total time for printing all result strings is also proportional to $\sum N$.
    -   Therefore, the overall time complexity is $O(\sum N)$. With $\sum N \le 10^5$, this is very efficient and well within typical time limits.

-   **Space Complexity**: $O(N_{max})$
    -   The program uses a few integer variables (`T`, `N`, `K`, `D_i`), which take $O(1)$ space.
    -   The primary space consumer is the `result_string`, which stores `N` characters for each test case. Since test cases are processed sequentially and the string is printed and then effectively discarded (or overwritten for the next test case), the maximum space used at any point is for the largest `N` encountered in a single test case.
    -   Thus, the space complexity is $O(N_{max})$, where $N_{max}$ is the maximum value of `N` (which is $10^5$). This is also well within typical memory limits.

## Solution Code

```cpp
#include <iostream> // Required for input/output operations (std::cin, std::cout)
#include <string>   // Required for using std::string to build the output
// #include <vector> // Not strictly necessary for this problem, but often useful

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE on large inputs.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; // Variable to store the number of test cases
    std::cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, once for each test case
        int N;       // Variable to store the number of distances for the current test case
        long long K; // Variable to store Chef's step length. Using long long for K and D_i
                     // because they can be up to 10^9, which fits in 'int' on most systems
                     // but 'long long' is safer and guarantees 64-bit storage.
        std::cin >> N >> K; // Read N and K for the current test case

        std::string result_string = ""; // Initialize an empty string to build the output for this test case
        // Pre-allocating capacity can sometimes offer a minor optimization,
        // but for N up to 10^5, std::string's dynamic resizing is efficient enough.
        // result_string.reserve(N); 

        for (int i = 0; i < N; ++i) { // Loop N times to read each distance D_i
            long long D_i; // Variable to store the current distance
            std::cin >> D_i; // Read the current distance D_i

            // Check if D_i is traversable: a distance D_i is traversable if it's a multiple of K.
            // This is true if the remainder of D_i divided by K is 0.
            if (D_i % K == 0) {
                result_string += '1'; // If traversable, append '1' to the result string
            } else {
                result_string += '0'; // If not traversable, append '0' to the result string
            }
        }
        std::cout << result_string << "\n"; // Print the complete result string for the current test case, followed by a newline
    }

    return 0; // Indicate successful program execution
}
```