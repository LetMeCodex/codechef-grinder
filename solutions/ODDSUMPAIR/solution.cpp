#include <bits/stdc++.h> // Includes iostream, string, etc., as per problem instructions

// Use the standard namespace as requested
using namespace std;

// The compile error indicates that the testing environment expects the function
// to be a method of a class named 'Solution'.
// We need to wrap the function in a class.
class Solution {
public:
    // Function Declaration
    // Function Name: checkOddPairs
    // Parameters: A, B, C (integers)
    // Return Value: "YES" or "NO" (string)
    string checkOddPairs(int A, int B, int C) {
        // Count the number of odd integers among A, B, and C.
        // For positive integers, X % 2 is 1 if X is odd, and 0 if X is even.
        int odd_count = (A % 2) + (B % 2) + (C % 2);

        // An odd sum pair exists if and only if the number of odd integers
        // among A, B, and C is either 1 or 2.
        // - If odd_count is 0 (all even) or 3 (all odd), no odd sum pair can be formed.
        //   (Even + Even = Even; Odd + Odd = Even)
        // - If odd_count is 1 (one odd, two even) or 2 (two odd, one even),
        //   an odd sum pair (Odd + Even) can always be formed.
        //   (Odd + Even = Odd)
        if (odd_count == 1 || odd_count == 2) {
            return "YES";
        } else {
            return "NO";
        }
    }
};