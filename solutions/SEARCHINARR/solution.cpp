#include <vector> // Required for std::vector
#include <string> // Required for std::string
// #include <iostream> // Not strictly needed in solve function, but good practice for general C++
// #include <bits/stdc++.h> // Can be used instead of specific headers, common in competitive programming

// Using namespace std; is common in competitive programming to avoid writing std::
// If not used, you'd need to prefix std:: before vector, string, etc.
using namespace std;

// Function to search for an element X in an array A
// N: size of the array
// X: element to be searched
// A: the input array
// Returns "YES" if X is found, "NO" otherwise
string solve(int N, int X, const vector<int>& A) {
    // Iterate through the array A
    for (int i = 0; i < N; ++i) {
        // If the current element A[i] is equal to X, we found it
        if (A[i] == X) {
            return "YES"; // Return "YES" immediately
        }
    }
    // If the loop finishes without finding X, it means X is not in the array
    return "NO"; // Return "NO"
}