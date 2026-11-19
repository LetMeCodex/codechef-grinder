#include <bits/stdc++.h> // Includes iostream and other standard libraries

// It's generally good practice to avoid 'using namespace std;' in headers or large projects,
// but for competitive programming, it's common and accepted for brevity.
using namespace std; 

int main() {
    // Fast I/O setup to speed up input and output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        int K; // Variable to store the input integer K for the current test case.
               // K up to 10^9 fits comfortably within a standard 32-bit signed int.
        cin >> K; // Read the value of K.

        int count = 0; // This variable will store the maximum length of the interesting sequence.
                       // It effectively counts the number of times K can be divided by 2.

        // The core logic: find the largest N such that K is divisible by 2^N.
        // This is done by repeatedly dividing K by 2 as long as K is even.
        // Each successful division increments the count.
        //
        // If K is initially odd (e.g., K=1, K=3, K=5), the loop condition (K % 2 == 0)
        // will be false from the start. 'count' will remain 0, which is correct
        // because an odd K cannot form an interesting sequence of length 1 (A_1 = K/2 would not be an integer).
        //
        // The condition K > 0 is technically redundant given the problem constraint 1 <= K,
        // as K will become 1 (an odd number) before it becomes 0. However, it does no harm.
        while (K > 0 && K % 2 == 0) {
            K /= 2;        // Divide K by 2.
            count++;       // Increment the count for each power of 2 found.
        }
        
        // Print the calculated maximum length for the current test case, followed by a newline.
        cout << count << "\n";
    }

    return 0; // Indicate successful execution.
}