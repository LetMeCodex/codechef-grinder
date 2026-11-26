# [Closest Vowels (CLOSEVOWEL)](https://www.codechef.com/problems/CLOSEVOWEL)
- **Difficulty Rating**: 1241
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to count the total number of distinct strings that can be formed by transforming a given input string `S` of length `N`. The transformation rule is as follows:
1. If a character in `S` is a vowel ('a', 'e', 'i', 'o', 'u'), it remains unchanged.
2. If a character in `S` is a consonant, it must be replaced by one of its *closest* vowels. If there are two vowels that are equally close to the consonant, either of them can be chosen.
We need to output the total count of such distinct strings, modulo $10^9 + 7$.

## Intuition & Mathematical Observation
The core idea behind solving this problem efficiently lies in two key observations:

1.  **Independent Choices**: The choice of replacing a consonant (or keeping a vowel) at any position in the string `S` is entirely independent of the choices made at other positions. This means that if we can determine the number of valid choices for each character `c` in `S`, the total number of distinct strings will simply be the product of these individual counts.

2.  **Precomputation of Choices**: For each character from 'a' to 'z', we can determine the number of closest vowels.
    *   **Vowels**: For 'a', 'e', 'i', 'o', 'u', there is only 1 choice (the character itself).
    *   **Consonants**: For consonants, we need to find the minimum absolute difference in alphabetical position to any of the five vowels. If multiple vowels share this minimum distance, they all count as valid choices.
        Let's list the vowels and their 0-indexed positions: `a=0, e=4, i=8, o=14, u=20`.
        By manually calculating the distances for each consonant, we can determine the number of choices:
        *   `b`: Closest to 'a' (dist 1). 1 choice.
        *   `c`: Equally close to 'a' (dist 2) and 'e' (dist 2). 2 choices.
        *   `d`: Closest to 'e' (dist 1). 1 choice.
        *   `f`: Closest to 'e' (dist 1). 1 choice.
        *   `g`: Equally close to 'e' (dist 2) and 'i' (dist 2). 2 choices.
        *   `h`: Closest to 'i' (dist 1). 1 choice.
        *   `j`: Closest to 'i' (dist 1). 1 choice.
        *   `k`: Closest to 'i' (dist 2). 1 choice.
        *   `l`: Equally close to 'i' (dist 3) and 'o' (dist 3). 2 choices.
        *   `m`: Closest to 'o' (dist 2). 1 choice.
        *   `n`: Closest to 'o' (dist 1). 1 choice.
        *   `p`: Closest to 'o' (dist 1). 1 choice.
        *   `q`: Closest to 'o' (dist 2). 1 choice.
        *   `r`: Equally close to 'o' (dist 3) and 'u' (dist 3). 2 choices.
        *   `s`: Closest to 'u' (dist 2). 1 choice.
        *   `t`: Closest to 'u' (dist 1). 1 choice.
        *   `v`: Closest to 'u' (dist 1). 1 choice.
        *   `w`: Closest to 'u' (dist 2). 1 choice.
        *   `x`: Closest to 'u' (dist 3). 1 choice.
        *   `y`: Closest to 'u' (dist 4). 1 choice.
        *   `z`: Closest to 'u' (dist 5). 1 choice.

    This precomputation can be stored in a small array (e.g., `num_choices[26]`) where `num_choices[0]` corresponds to 'a', `num_choices[1]` to 'b', and so on.

3.  **Modulo Arithmetic**: Since the product can become very large, we must apply the modulo operator ($10^9 + 7$) after each multiplication to prevent integer overflow and ensure the final result fits within standard integer types.

**Algorithm Steps:**
1.  Initialize a variable `total_distinct_strings` to 1. This will store the running product.
2.  Iterate through each character `c` in the input string `S`.
3.  For each character `c`, retrieve its corresponding number of choices from the precomputed `num_choices` array (using `c - 'a'` as the index).
4.  Multiply `total_distinct_strings` by this number of choices, and then take the result modulo $10^9 + 7$.
    `total_distinct_strings = (total_distinct_strings * num_choices[c - 'a']) % MOD;`
5.  After iterating through all characters, `total_distinct_strings` will hold the final answer. Print this value.

## Complexity Analysis
-   **Time Complexity**: $O(N)$ per test case.
    *   The precomputation of `num_choices` is done manually and hardcoded, taking $O(1)$ constant time.
    *   For each test case, we iterate through the input string `S` once. The length of `S` is `N`.
    *   Inside the loop, operations like array lookup, multiplication, and modulo are all $O(1)$.
    *   Therefore, the total time complexity for processing one test case is $O(N)$.
    *   For `T` test cases, the total time complexity is $O(T \cdot N)$.

-   **Space Complexity**: $O(N)$ per test case.
    *   The `num_choices` array stores 26 integers, which is $O(1)$ constant space.
    *   The input string `S` requires $O(N)$ space.
    *   Other variables use $O(1)$ space.
    *   Thus, the dominant factor for space complexity is storing the input string, leading to $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <string>
// No need for cmath, vector, algorithm as choices are hardcoded

// Define the modulo constant
const int MOD = 1e9 + 7;

// Precomputed array to store the number of closest vowel choices for each character
// 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
// Values derived from manual calculation:
// a:1, b:1, c:2, d:1, e:1, f:1, g:2, h:1, i:1, j:1, k:1, l:2, m:1, n:1, o:1, p:1, q:1, r:2, s:1, t:1, u:1, v:1, w:1, x:1, y:1, z:1
const int num_choices[26] = {
    1, // 'a' - vowel
    1, // 'b' -> 'a'
    2, // 'c' -> 'a', 'e'
    1, // 'd' -> 'e'
    1, // 'e' - vowel
    1, // 'f' -> 'e'
    2, // 'g' -> 'e', 'i'
    1, // 'h' -> 'i'
    1, // 'i' - vowel
    1, // 'j' -> 'i'
    1, // 'k' -> 'i'
    2, // 'l' -> 'i', 'o'
    1, // 'm' -> 'o'
    1, // 'n' -> 'o'
    1, // 'o' - vowel
    1, // 'p' -> 'o'
    1, // 'q' -> 'o'
    2, // 'r' -> 'o', 'u'
    1, // 's' -> 'u'
    1, // 't' -> 'u'
    1, // 'u' - vowel
    1, // 'v' -> 'u'
    1, // 'w' -> 'u'
    1, // 'x' -> 'u'
    1, // 'y' -> 'u'
    1  // 'z' -> 'u'
};

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;

    long long total_distinct_strings = 1; // Initialize product to 1

    // Iterate through each character of the input string S
    for (char c : S) {
        // Multiply the current total by the number of choices for this character
        // and take modulo to prevent overflow
        total_distinct_strings = (total_distinct_strings * num_choices[c - 'a']) % MOD;
    }

    std::cout << total_distinct_strings << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // No need to call precompute_choices() as num_choices is hardcoded

    int T; // Number of test cases
    std::cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```