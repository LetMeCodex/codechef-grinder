# [Tourist Translations (TOTR)](https://www.codechef.com/problems/TOTR)
- **Difficulty Rating**: 1252
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to translate `T` Bytelandian sentences into English. We are given a mapping string `M` of length 26, which specifies the English equivalent for each lowercase Bytelandian letter 'a' through 'z'. For example, if `M` is "qwertyuiopasdfghjklzxcvbnm", then Bytelandian 'a' translates to 'q', 'b' to 'w', and so on.

The translation rules are as follows:
1.  **Lowercase Bytelandian letters ('a'-'z')**: Translate to their corresponding character in the mapping string `M`.
2.  **Uppercase Bytelandian letters ('A'-'Z')**: Translate to the uppercase version of their lowercase equivalent's translation. For example, if 'a' maps to 'q', then 'A' maps to 'Q'.
3.  **Underscores ('_')**: Translate to a space character (' ').
4.  **Other characters (punctuation like '.', ',', '!', '?')**: Remain unchanged in the translation.

We need to process `T` sentences, each on a new line, and output their English translations, each on a new line.

## Intuition & Mathematical Observation

The problem is a straightforward character-by-character mapping task. There are no complex algorithms or data structures required; the solution relies on careful implementation of the given translation rules.

1.  **Pre-processing the Mapping**: Since the mapping string `M` is fixed for all sentences, it's efficient to pre-process it into an easily accessible data structure. A simple `char` array of size 26 (`translation_map[26]`) is ideal. `translation_map[0]` would store the English equivalent of Bytelandian 'a', `translation_map[1]` for 'b', and so on. The index for a lowercase character `ch` can be found using `ch - 'a'`.

2.  **Character Classification and Translation**: For each character in an input Bytelandian sentence, we need to determine its type and apply the corresponding rule:
    *   **Lowercase Letter**: If `ch` is lowercase, its translated character is `translation_map[ch - 'a']`.
    *   **Uppercase Letter**: If `ch` is uppercase, we first find its corresponding lowercase Bytelandian letter (e.g., 'A' corresponds to 'a'). Then, we find the translation of this lowercase letter from our `translation_map` (e.g., `translation_map['a' - 'a']`). Finally, we convert this translated character to uppercase using `toupper()`. This can be concisely done as `toupper(translation_map[ch - 'A'])`.
    *   **Underscore**: If `ch` is `'_'`, it translates to a space `' '`.
    *   **Other Characters**: If `ch` is none of the above, it's a punctuation mark or other symbol, and it remains unchanged.

3.  **String Building**: As we process each character, we append its translated form to a new string, which will eventually hold the complete English translation of the sentence. Using `std::string::reserve()` can offer a minor performance improvement by pre-allocating memory, reducing reallocations, though for small string lengths (max 100), its impact is minimal.

This approach ensures that each character is processed exactly once, leading to an efficient solution.

## Complexity Analysis

Let `T` be the number of sentences, and `L_max` be the maximum length of a single sentence (given as 100). Let `L_total` be the sum of lengths of all `T` sentences.

-   **Time Complexity**:
    *   Reading `T` and `M`: $O(1)$ since `M` has a fixed length of 26.
    *   Creating `translation_map`: A loop runs 26 times. This is $O(1)$.
    *   Processing `T` sentences:
        *   For each sentence, we iterate through its characters. Let a sentence have length `|S|`.
        *   Inside the loop, character classification (`islower`, `isupper`), arithmetic operations, and `toupper` are all $O(1)$ operations.
        *   Appending to `std::string` (`translated_S += ch`) takes amortized $O(1)$ time per character.
        *   Thus, translating one sentence of length `|S|` takes $O(|S|)$ time.
    *   Total time for all `T` sentences: $\sum_{i=1}^{T} O(|S_i|) = O(L_{total})$.
    *   Given $T \le 1000$ and $|S| \le 100$, $L_{total} \le 1000 \times 100 = 10^5$. This is well within typical time limits.

    Therefore, the overall **Time Complexity** is $O(L_{total})$.

-   **Space Complexity**:
    *   `T` and `M`: `M` is a string of fixed length 26. $O(1)$.
    *   `translation_map`: A `char` array of fixed size 26. $O(1)$.
    *   `S`: Stores one Bytelandian sentence at a time. Maximum length `L_max`. $O(L_{max})$.
    *   `translated_S`: Stores one translated English sentence at a time. Maximum length `L_max`. $O(L_{max})$.

    Since `L_max` is a constant (100), the space used is constant regardless of `T`.

    Therefore, the overall **Space Complexity** is $O(L_{max})$, which simplifies to $O(1)$.

## Solution Code

```cpp
#include <iostream> // For std::cin, std::cout
#include <string>   // For std::string
#include <cctype>   // For std::islower, std::isupper, std::toupper

// As requested by the problem statement, use `using namespace std;`
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;          // Number of Bytelandian sentences to translate
    string M;       // The mapping string: English translation of "abcdefghijklmnopqrstuvwxyz"
    
    // Read T and the mapping string M from the first line of input.
    cin >> T >> M;

    // Create a character array to store the translation map.
    // translation_map[0] will store the English equivalent of Bytelandian 'a',
    // translation_map[1] for 'b', and so on, up to translation_map[25] for 'z'.
    char translation_map[26];
    for (int i = 0; i < 26; ++i) {
        translation_map[i] = M[i];
    }

    // Loop T times to process each Bytelandian sentence.
    for (int t_case = 0; t_case < T; ++t_case) {
        string S; // The current Bytelandian sentence
        
        // Read the Bytelandian sentence.
        // Since underscores replace spaces, sentences are single tokens.
        cin >> S;

        string translated_S = ""; // String to build the English translation
        // Pre-allocate memory for translated_S to potentially improve performance
        // by reducing reallocations, though for max length 100 it's not critical.
        translated_S.reserve(S.length()); 

        // Iterate through each character of the Bytelandian sentence.
        for (char ch : S) {
            if (islower(ch)) {
                // If the character is a lowercase letter, translate it using the map.
                // 'ch - 'a'' gives the 0-indexed position (0 for 'a', 1 for 'b', etc.).
                translated_S += translation_map[ch - 'a'];
            } else if (isupper(ch)) {
                // If the character is an uppercase letter,
                // first find its lowercase equivalent's translation,
                // then convert that translation to uppercase.
                // 'ch - 'A'' gives the 0-indexed position for uppercase letters.
                translated_S += toupper(translation_map[ch - 'A']);
            } else if (ch == '_') {
                // If the character is an underscore, replace it with a space.
                translated_S += ' ';
            } else {
                // If the character is any other symbol (punctuation: '.', ',', '!', '?'), keep it as is.
                translated_S += ch;
            }
        }
        
        // Output the translated English sentence, followed by a newline.
        cout << translated_S << "\n";
    }

    return 0; // Indicate successful execution.
}
```