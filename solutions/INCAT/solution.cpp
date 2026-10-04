#include <bits/stdc++.h> // Includes iostream, string, algorithm, etc.

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare a string variable to store the input.
    // The problem states the string S will always be of length 3.
    string s;
    
    // Read the input string S.
    cin >> s;

    // To check if the letters of string S can be rearranged to form "cat",
    // we can sort the letters of S and compare it with the sorted version of "cat".
    // The letters 'c', 'a', 't' when sorted alphabetically become 'a', 'c', 't'.
    
    // Sort the characters of the string S in ascending order.
    // For a string of length 3, this operation is constant time.
    sort(s.begin(), s.end());

    // After sorting, if the string S contains exactly the letters 'a', 'c', 't'
    // (one of each), then it will be equal to the string "act".
    if (s == "act") {
        // If they are equal, it means "cat" can be formed.
        cout << "Yes\n";
    } else {
        // Otherwise, "cat" cannot be formed.
        cout << "No\n";
    }

    return 0; // Indicate successful execution.
}