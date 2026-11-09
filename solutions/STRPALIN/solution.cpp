#include <bits/stdc++.h> // Include all standard libraries

// Using namespace std; as requested by the prompt.
using namespace std;

void solve() {
    string A, B;
    cin >> A >> B;

    // A boolean array to keep track of characters present in string A.
    // Since characters are lowercase English alphabets, an array of size 26 is sufficient.
    // present_in_A[0] corresponds to 'a', present_in_A[1] to 'b', and so on.
    vector<bool> present_in_A(26, false);

    // Populate present_in_A based on characters in string A.
    for (char c : A) {
        present_in_A[c - 'a'] = true;
    }

    bool found_common_char = false;
    // Iterate through string B to check for common characters.
    for (char c : B) {
        // If the current character from B is also present in A,
        // then we have found a common character.
        if (present_in_A[c - 'a']) {
            found_common_char = true;
            break; // No need to check further, one common character is enough.
        }
    }

    // If a common character 'x' was found:
    // We can choose s1 = "x" (a substring of A) and s2 = "x" (a substring of B).
    // The concatenation s1 + s2 = "xx" is a palindrome.
    // So, the answer is "Yes".
    //
    // If no common character was found:
    // Let s1 be any non-empty substring of A, and s2 be any non-empty substring of B.
    // For s1 + s2 to be a palindrome, its first character (s1[0]) must be equal to its last character (s2[length(s2)-1]).
    // s1[0] is a character from A. s2[length(s2)-1] is a character from B.
    // If there are no common characters between A and B, then no character from A can be equal to any character from B.
    // Therefore, s1[0] cannot be equal to s2[length(s2)-1].
    // This means s1 + s2 cannot be a palindrome.
    // So, the answer is "No".
    if (found_common_char) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}