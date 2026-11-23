#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use the standard namespace as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        long long a, b; // Declare a and b as long long as per problem instructions
        cin >> a >> b; // Read the two integers for the current test case
        
        // As analyzed:
        // The difference (b - a) can be changed by +1 or -1 in each step.
        // This is achieved by choosing d=1 for the magical operation.
        //
        // If d=1:
        // 1. Add 1 to a, add 0 to b. (b-a) decreases by 1.
        // 2. Add 0 to a, add 1 to b. (b-a) increases by 1.
        //
        // Since a and b are initially positive (1 <= a, b) and the operations
        // always add non-negative values (d or d-1), a and b will always remain positive.
        //
        // Therefore, we can always reach a state where a = b by repeatedly
        // applying the operation that reduces the absolute difference |b-a|.
        cout << "YES\n"; // Print "YES" for every test case
    }

    return 0; // Indicate successful execution
}