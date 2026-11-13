# [Fancy Quotes (FANCY)](https://www.codechef.com/problems/FANCY)
- **Difficulty Rating**: 1279
- **Solved in**: 2 attempt(s)

## Problem Summary

The problem asks us to determine if a given quote contains the word "not". If the word "not" appears as a standalone word within the quote, we should output "Real Fancy". Otherwise, if "not" is not found as a standalone word (e.g., it's part of another word like "nothing" or "notable", or simply absent), we should output "regularly fancy". The input consists of multiple test cases, each containing a single quote.

## Intuition & Mathematical Observation

The core challenge here is to correctly identify "not" as a *word*, not just a substring. For instance, if the quote is "This is nothing", the substring "not" is present, but it's not a standalone word. We need a mechanism to break down the input quote into individual words and then check each word.

A common and robust approach for tokenizing a string into words in C++ is to use a `stringstream`. A `stringstream` can be initialized with the input string, and then words can be extracted one by one using the `>>` operator, similar to how `cin` reads input. This method automatically handles various delimiters (like single or multiple spaces) and leading/trailing spaces.

The steps would be:
1. Read the entire quote line using `getline` because quotes can contain spaces.
2. Create a `stringstream` from the read quote.
3. Iterate through the words extracted from the `stringstream`.
4. For each extracted word, compare it exactly with "not".
5. If "not" is found, set a flag and break the loop, as we only need to find it once.
6. Based on the flag's final state, print "Real Fancy" or "regularly fancy".

This approach ensures that "not" is only matched when it's a complete, separate word.

## Complexity Analysis

-   **Time Complexity**:
    -   Reading `T` and `cin.ignore()`: $O(1)$ (effectively, as `cin.ignore` clears up to `numeric_limits<streamsize>::max()` characters or until a newline, but for typical line lengths, it's very fast).
    -   For each test case:
        -   `getline(cin, S)`: $O(|S|)$, where $|S|$ is the length of the input quote.
        -   `stringstream ss(S)`: $O(|S|)$ to construct the stringstream and copy the string.
        -   `while (ss >> word)` loop: In the worst case, we iterate through all words in the string. Each extraction `ss >> word` takes time proportional to the length of the word. The total time for extracting all words is proportional to the total length of the string, $O(|S|)$, as each character is processed a constant number of times.
        -   Comparing `word == "not"`: $O(1)$ because "not" is a constant-length string.
    -   Therefore, the total time complexity for one test case is dominated by string processing, which is $O(|S|)$.
    -   Given $T$ test cases, the overall time complexity is $O(T \cdot |S|_{max})$, where $|S|_{max}$ is the maximum length of a quote. With $|S|_{max} \le 100$ and $T \le 100$, this is approximately $100 \times 100 = 10^4$ operations, which is extremely efficient and well within typical time limits.

-   **Space Complexity**:
    -   `string S`: $O(|S|)$ to store the input quote.
    -   `stringstream ss`: $O(|S|)$ to store a copy of the input string for parsing.
    -   `string word`: $O(L_{word})$ to store the current word being processed, where $L_{word}$ is the maximum length of a single word. In the worst case, a single word could be as long as the entire quote.
    -   The dominant factor is storing the input string and its copy in the stringstream. Thus, the overall space complexity is $O(|S|_{max})$.

## Solution Code

```cpp
#include <iostream> // For cin, cout
#include <string>   // For string, getline
#include <sstream>  // For stringstream
#include <limits>   // For numeric_limits (used with cin.ignore)

// It's common in competitive programming to use the entire std namespace
// to avoid repeatedly typing std::.
using namespace std;

// Function to solve a single test case
void solve() {
    string S;
    // Read the entire line for the quote, including spaces.
    // This is crucial because quotes can contain spaces.
    getline(cin, S);

    // Use stringstream to easily tokenize the string into words.
    // This is generally a safer and often cleaner approach for word-based problems
    // compared to manual character-by-character parsing, as it handles
    // multiple spaces, leading/trailing spaces, etc., automatically.
    stringstream ss(S);
    string word;
    bool found_not_word = false;

    // Extract words one by one from the stringstream
    while (ss >> word) {
        if (word == "not") {
            found_not_word = true;
            break; // Found the word "not", no need to check further.
        }
    }

    // Print the result based on whether "not" was found as a word.
    if (found_not_word) {
        cout << "Real Fancy\n";
    } else {
        cout << "regularly fancy\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases.

    // After reading an integer with cin >> T, a newline character remains in the input buffer.
    // The subsequent getline(cin, S) would read this empty line for the first test case.
    // cin.ignore() discards this leftover newline character.
    // Using the version with arguments is safer to clear the entire line,
    // ensuring no unexpected characters remain for subsequent getline calls.
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    // Loop through each test case.
    while (T--) {
        solve();
    }

    return 0;
}
```