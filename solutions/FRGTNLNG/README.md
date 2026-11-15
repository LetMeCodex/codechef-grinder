# [Forgotten Language (FRGTNLNG)](https://www.codechef.com/problems/FRGTNLNG)
- **Difficulty Rating**: 1329
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine, for each word in a given "forgotten language" dictionary, whether it appears in any of a set of "modern phrases". We are given `N` words that constitute the forgotten language dictionary. Then, we are given `K` modern phrases, each consisting of `L` words. For each of the `N` forgotten words, we need to output "YES" if it is found in any of the modern phrases, and "NO" otherwise. The output for each test case should be `N` space-separated "YES" or "NO" tokens, corresponding to the forgotten words in their original input order.

**Input Format:**
- First line: `T`, the number of test cases.
- For each test case:
    - First line: `N` (number of forgotten words) and `K` (number of modern phrases).
    - Second line: `N` space-separated strings, the forgotten words.
    - Following `K` lines: Each line starts with `L` (number of words in the phrase), followed by `L` space-separated strings, the words in the modern phrase.

**Output Format:**
- For each test case, a single line with `N` space-separated "YES" or "NO" tokens.

**Constraints:**
- `1 <= T <= 100`
- `1 <= N, K <= 1000`
- `1 <= L <= 100`
- Total length of all words across all test cases is at most $10^5$.

## Intuition & Mathematical Observation

The core task is to efficiently check the existence of `N` dictionary words within a larger collection of `K` phrases containing a total of many words. A naive approach of iterating through all modern words for each forgotten word would be too slow, especially given `N` and `K` up to 1000 and `L` up to 100. This would lead to a complexity roughly proportional to `N * K * L * M_avg` (where `M_avg` is average word length), which is about $1000 \times 1000 \times 100 = 10^8$ string comparisons, far too slow.

A more efficient approach involves using a hash-based data structure, like `std::unordered_map` or `std::unordered_set` in C++, for fast lookups.

Here's the refined intuition:

1.  **Store Forgotten Words for Fast Lookup:** We need to quickly check if a word from a modern phrase is one of the forgotten words. An `std::unordered_map` is ideal for this, as it provides average $O(M)$ time complexity for lookups (where $M$ is the length of the string).

2.  **Maintain Original Order and Handle Duplicates:** The problem requires outputting "YES/NO" for each forgotten word *in its original input order*. Also, a forgotten word might appear multiple times in the initial dictionary. If "apple" is the 1st and 5th forgotten word, and "apple" is found in a modern phrase, both the 1st and 5th words should be marked "YES".
    To address this, we can use:
    *   A `std::vector<std::string>` to store the forgotten words exactly as they appear in the input, preserving their original indices.
    *   An `std::unordered_map<std::string, std::vector<int>>` where keys are unique forgotten words, and values are vectors of integers representing all indices where that word appears in the `forgotten_words` vector.

3.  **Track Found Status:** We'll need a `std::vector<bool>` of size `N`, say `found_status`, initialized to `false`. `found_status[i]` will be set to `true` if `forgotten_words[i]` is found in any modern phrase.

**Algorithm Steps:**

1.  Read `N` and `K`.
2.  Initialize `std::vector<std::string> forgotten_words(N)` to store the dictionary words in order.
3.  Initialize `std::unordered_map<std::string, std::vector<int>> word_to_indices`.
4.  Loop `i` from `0` to `N-1`:
    a.  Read the `i`-th forgotten word into `forgotten_words[i]`.
    b.  Add `i` to the `std::vector<int>` associated with `forgotten_words[i]` in `word_to_indices`. This handles cases where the same word appears multiple times in the forgotten dictionary.
5.  Initialize `std::vector<bool> found_status(N, false)`.
6.  Loop `K` times (for each modern phrase):
    a.  Read `L`, the number of words in the current phrase.
    b.  Loop `L` times (for each word in the current phrase):
        i.  Read `modern_word`.
        ii. Check if `modern_word` exists as a key in `word_to_indices`.
        iii. If it exists, iterate through all indices `idx` stored in `word_to_indices[modern_word]`. For each `idx`, set `found_status[idx] = true`. This ensures all occurrences of a found forgotten word are marked.
7.  Finally, loop `i` from `0` to `N-1`:
    a.  Print "YES" if `found_status[i]` is `true`, otherwise print "NO".
    b.  Print a space after each token except the last one.
8.  Print a newline character at the end of the test case output.

This approach ensures that each modern word is looked up efficiently, and all relevant forgotten words are marked correctly, preserving the original order for output.

## Complexity Analysis

Let:
- `N` be the number of forgotten words.
- `K` be the number of modern phrases.
- `L_i` be the number of words in the `i`-th modern phrase.
- `M_avg` be the average length of a word.
- `S_N` be the total length of all `N` forgotten words.
- `S_K` be the total length of all words across all `K` modern phrases.
- `Total_Chars = S_N + S_K` be the total length of all words in a test case.

**Time Complexity:**

1.  **Reading `N` forgotten words and populating `forgotten_words` and `word_to_indices`:**
    - Each word is read and potentially inserted into `forgotten_words` and `word_to_indices`.
    - Reading a word of length `M` takes `O(M)`.
    - `std::unordered_map` insertion/lookup for a string of length `M` takes `O(M)` on average (due to string hashing and comparison). Appending to `std::vector<int>` is `O(1)` amortized.
    - The total time for this step is `O(S_N)` on average, as each character of the forgotten words is processed once for reading and hashing.

2.  **Processing `K` modern phrases:**
    - We iterate through all words in all `K` phrases. The total number of modern words is `Sum(L_i)`.
    - For each `modern_word` of length `M`:
        - Reading the word takes `O(M)`.
        - Looking up the word in `word_to_indices` takes `O(M)` on average.
        - If found, we iterate through the `std::vector<int>` of indices and set `found_status[idx] = true`. Each `found_status[idx]` is set to `true` at most once across all modern phrases. The total number of times `found_status[idx]` is accessed and modified in this part is bounded by `N`.
    - The total time for this step is `O(S_K + N)` on average. `S_K` accounts for reading and hashing all modern words, and `N` accounts for marking `found_status` entries.

3.  **Outputting results:**
    - We iterate `N` times to print "YES" or "NO" for each forgotten word. This takes `O(N)` time.

**Overall Time Complexity (per test case):**
Summing these parts, the total time complexity is `O(S_N + S_K + N)` on average.
Given the constraint that the total length of all words across all test cases is at most $10^5$, and `N, K <= 1000`, this simplifies to `O(Total_Chars + N + K)`.
With `Total_Chars <= 10^5`, `N <= 1000`, `K <= 1000`, the operations are roughly $10^5 + 1000 + 1000$, which is very efficient and well within typical time limits.

**Space Complexity:**

1.  `forgotten_words`: Stores `N` strings. Total space `O(S_N)`.
2.  `word_to_indices`: Stores unique forgotten words as keys and their indices as values. In the worst case, all `N` words are unique, and each index is stored once. Total space `O(S_N + N)`.
3.  `found_status`: Stores `N` boolean values. Total space `O(N)`.

**Overall Space Complexity (per test case):**
The total space complexity is `O(S_N + N)`.
Given `S_N <= 10^5` and `N <= 1000`, this is approximately `O(10^5)` characters and `O(1000)` integers/booleans, which is well within typical memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes iostream, vector, string, unordered_map, etc.

// Function to solve a single test case
void solve() {
    int N, K;
    std::cin >> N >> K;

    // forgotten_words stores the dictionary words in their input order.
    // This is needed to output "YES/NO" for the i-th word correctly.
    std::vector<std::string> forgotten_words(N);
    
    // word_to_indices maps each unique forgotten word to a list of its indices
    // in the forgotten_words vector. This handles cases where the same word
    // might appear multiple times in the dictionary and each instance needs
    // to be tracked.
    std::unordered_map<std::string, std::vector<int>> word_to_indices;

    for (int i = 0; i < N; ++i) {
        std::cin >> forgotten_words[i];
        word_to_indices[forgotten_words[i]].push_back(i);
    }

    // found_status tracks whether the word at a specific index in forgotten_words
    // has been found in any modern phrase. Initialized to false.
    std::vector<bool> found_status(N, false);

    // Process K modern phrases
    for (int i = 0; i < K; ++i) {
        int L;
        std::cin >> L; // Number of words in the current phrase
        for (int j = 0; j < L; ++j) {
            std::string modern_word;
            std::cin >> modern_word;
            
            // Check if this modern word exists in our map of forgotten words
            auto it = word_to_indices.find(modern_word);
            if (it != word_to_indices.end()) {
                // If the modern_word is a forgotten word, mark all its occurrences
                // in the original dictionary as found.
                for (int idx : it->second) {
                    found_status[idx] = true;
                }
            }
        }
    }

    // Output the results for this test case
    for (int i = 0; i < N; ++i) {
        if (found_status[i]) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
        // Print a space after each token except the last one
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}
```