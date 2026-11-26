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
    1, // 'a'
    1, // 'b' -> 'a'
    2, // 'c' -> 'a', 'e'
    1, // 'd' -> 'e'
    1, // 'e'
    1, // 'f' -> 'e'
    2, // 'g' -> 'e', 'i'
    1, // 'h' -> 'i'
    1, // 'i'
    1, // 'j' -> 'i'
    1, // 'k' -> 'i'
    2, // 'l' -> 'i', 'o'
    1, // 'm' -> 'o'
    1, // 'n' -> 'o'
    1, // 'o'
    1, // 'p' -> 'o'
    1, // 'q' -> 'o'
    2, // 'r' -> 'o', 'u'
    1, // 's' -> 'u'
    1, // 't' -> 'u'
    1, // 'u'
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