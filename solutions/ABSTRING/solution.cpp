#include <iostream> // Required for std::cin, std::cout
#include <string>   // Required for std::string
#include <vector>   // Required for std::vector

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n; // Read the length of the string
    std::string s;
    std::cin >> s; // Read the string S

    // Condition 1: If N is odd, the lengths of strings A and B will be different.
    // Alice takes ceil(N/2) characters and Bob takes floor(N/2) characters.
    // If N is odd, ceil(N/2) != floor(N/2).
    // For example, if N=5, Alice takes 3, Bob takes 2. A and B cannot be the same.
    if (n % 2 != 0) {
        std::cout << "NO\n";
        return; // No need to proceed further for this test case
    }

    // Condition 2: If N is even, Alice and Bob each take N/2 characters.
    // For their strings A and B to be identical, they must have the same characters
    // in the same order. Let k = N/2.
    // A = c1 c2 ... ck
    // B = c1 c2 ... ck
    // This implies that Alice picks c1, then Bob must pick c1.
    // Then Alice picks c2, then Bob must pick c2, and so on.
    // This strategy is possible if and only if for every character Alice picks,
    // there is an identical character available in S for Bob to pick immediately after.
    // This means that every character in the original string S must appear an even number of times.
    // If any character appears an odd number of times, it's impossible to pair them up.
    // One instance of that character will always be left unpaired, meaning Alice or Bob
    // will pick it, and the other player won't be able to match it, thus making A != B.

    // Use a frequency array for lowercase English alphabets (a-z)
    // 'a' corresponds to index 0, 'b' to index 1, ..., 'z' to index 25.
    std::vector<int> freq(26, 0); 
    for (char c : s) {
        freq[c - 'a']++; // Increment count for the character
    }

    bool possible = true;
    // Check if all character counts are even
    for (int count : freq) {
        if (count % 2 != 0) { // If any character has an odd count
            possible = false; // It's not possible to make A and B identical
            break;            // No need to check further
        }
    }

    if (possible) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents std::cout from being flushed before each std::cin operation.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; // Read the number of test cases
    while (t--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}