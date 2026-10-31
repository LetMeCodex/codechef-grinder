# [Making a Meal (CFMM)](https://www.codechef.com/problems/CFMM)
- **Difficulty Rating**: 1214
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine the maximum number of "codechef" meals that can be prepared given a list of ingredient strings. We are provided with `N` ingredient strings, each consisting of lowercase English letters. A single "codechef" meal requires the following characters:
- 'c': 2 times
- 'o': 1 time
- 'd': 1 time
- 'e': 2 times
- 'h': 1 time
- 'f': 1 time

We need to process `T` test cases. For each test case, we read `N` and then `N` ingredient strings, and output the maximum number of complete "codechef" meals that can be made using the available characters.

## Intuition & Mathematical Observation

The core idea is to count the total availability of each character across all given ingredient strings. Once we have these total counts, we can determine how many "codechef" meals can be formed.

1.  **Character Counting**: We can use an array (or a hash map) to store the frequency of each lowercase English letter ('a' through 'z'). We iterate through all `N` ingredient strings, and for each character in each string, we increment its corresponding count in our frequency array.

2.  **Meal Calculation per Character**: For each character required for a "codechef" meal, we calculate how many meals could be made *if only that character's availability were the limiting factor*.
    *   Let `count_x` be the total available count of character 'x'.
    *   Let `req_x` be the number of times character 'x' is required for one meal.
    *   The number of meals possible based on character 'x' is `count_x / req_x` (using integer division, which naturally floors the result).

    For example:
    *   For 'c': `meals_c = total_count['c'] / 2`
    *   For 'o': `meals_o = total_count['o'] / 1`
    *   For 'd': `meals_d = total_count['d'] / 1`
    *   For 'e': `meals_e = total_count['e'] / 2`
    *   For 'h': `meals_h = total_count['h'] / 1`
    *   For 'f': `meals_f = total_count['f'] / 1`

3.  **Overall Maximum Meals**: The total number of "codechef" meals we can make is limited by the character that is most scarce relative to its requirement. Therefore, the maximum number of complete meals will be the minimum of all the individual `meals_x` values calculated in the previous step.
    `max_meals = min(meals_c, meals_o, meals_d, meals_e, meals_h, meals_f)`

This approach works because the availability of one character is independent of the availability of another. We are essentially finding the bottleneck resource.

## Complexity Analysis

Let `N` be the number of ingredient strings for a single test case, and `L_i` be the length of the $i$-th ingredient string. Let $S = \sum_{i=1}^{N} L_i$ be the total length of all ingredient strings in a test case. Let $L_{max}$ be the maximum length of any single ingredient string.

-   **Time Complexity**:
    1.  Reading `N`: $O(1)$.
    2.  Initializing `char_counts` array: $O(26) = O(1)$.
    3.  Looping `N` times to read ingredient strings:
        *   For each string `s` of length `L_i`, reading it takes $O(L_i)$ time.
        *   Iterating through its characters and updating `char_counts` takes $O(L_i)$ time.
        *   Summing this over all `N` strings, the total time for character counting is $O(\sum_{i=1}^{N} L_i) = O(S)$.
    4.  Calculating `meals_c`, `meals_o`, ..., `meals_f`: This involves a fixed number of arithmetic operations (6 divisions). $O(1)$.
    5.  Finding the minimum of these 6 values: This involves a fixed number of comparisons. $O(1)$.
    6.  Printing the result: $O(1)$.

    Therefore, the total time complexity for a single test case is dominated by reading and processing the ingredient strings, which is $O(S)$.
    Given `T` test cases, and a constraint that the sum of lengths of all strings over all test cases is $\le 10^6$, the total time complexity across all test cases will be $O(\sum S_{total})$, where $\sum S_{total}$ is the sum of `S` for all test cases. This fits within typical time limits.

-   **Space Complexity**:
    1.  `char_counts` array: Stores counts for 26 lowercase English letters. This is a fixed size, $O(26) = O(1)$.
    2.  `s` string variable: Stores one ingredient string at a time. Its maximum size is $O(L_{max})$.

    Thus, the total space complexity is $O(L_{max})$, where $L_{max}$ is the maximum length of any single ingredient string. This is efficient as $L_{max}$ is typically much smaller than the total sum of lengths.

## Solution Code

```cpp
#include <iostream>  // Required for standard input/output operations (std::cin, std::cout)
#include <string>    // Required for using std::string to handle ingredient names
#include <algorithm> // Required for std::min function

// The 'solve' function encapsulates the logic for processing a single test case.
void solve() {
    int N; // Declare an integer N to store the number of ingredients
    std::cin >> N; // Read the value of N from standard input
    
    // Declare a C-style array to store the counts of each lowercase English letter.
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    // Initialize all elements to 0. This is efficient for fixed-size arrays.
    int char_counts[26] = {0}; 
    
    // Loop N times to read each ingredient string
    for (int i = 0; i < N; ++i) {
        std::string s; // Declare a string variable to store the current ingredient
        std::cin >> s; // Read the ingredient string from standard input
        
        // Iterate over each character in the string 's'
        for (char ch : s) {
            // Increment the count for the corresponding character.
            // 'ch - 'a'' converts a character ('a' through 'z') into an integer index (0 through 25).
            char_counts[ch - 'a']++;
        }
    }
    
    // Define the character requirements for one "codechef" meal:
    // 'c': 2 times
    // 'o': 1 time
    // 'd': 1 time
    // 'e': 2 times
    // 'h': 1 time
    // 'f': 1 time
    
    // Calculate how many "codechef" meals can be made based on the availability
    // of each required character. Integer division automatically handles flooring.
    // For characters required once, division by 1 is technically redundant but makes the logic explicit.
    int meals_c = char_counts['c' - 'a'] / 2;
    int meals_o = char_counts['o' - 'a'] / 1;
    int meals_d = char_counts['d' - 'a'] / 1;
    int meals_e = char_counts['e' - 'a'] / 2;
    int meals_h = char_counts['h' - 'a'] / 1;
    int meals_f = char_counts['f' - 'a'] / 1;
    
    // The maximum number of complete meals is limited by the character that is
    // most scarce relative to its requirement. We find this by taking the minimum
    // of the potential meals calculated for each character.
    // Using nested std::min calls is a robust way to find the minimum of multiple values,
    // especially for environments that might not fully optimize initializer_list usage.
    int max_meals = std::min(meals_c, 
                      std::min(meals_o, 
                        std::min(meals_d, 
                          std::min(meals_e, 
                            std::min(meals_h, meals_f)))));
    
    // Print the final result for the current test case, followed by a newline character.
    std::cout << max_meals << "\n";
}

// The main function is the entry point of the program.
int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard I/O.
    // std::cin.tie(NULL) prevents std::cin from flushing std::cout before each input operation.
    // These two lines are crucial for performance in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T; // Declare an integer T to store the number of test cases
    std::cin >> T; // Read the number of test cases
    
    // Loop T times, processing one test case in each iteration.
    // The T-- decrements T after each check, effectively looping T times.
    while (T--) { 
        solve(); // Call the 'solve' function to handle the current test case
    }
    
    return 0; // Indicate successful program execution
}
```