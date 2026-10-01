#include <bits/stdc++.h> // Required header for competitive programming, includes many standard libraries.

using namespace std; // Required to use standard library components without the std:: prefix.

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the number of clovers Chef found.
    cin >> N; // Read the integer N from standard input.

    // Calculate the total number of leaves.
    // According to the problem statement:
    // - Exactly one clover is a four-leaf clover, contributing 4 leaves.
    // - The remaining (N - 1) clovers are three-leaf clovers, each contributing 3 leaves.
    //
    // So, the total number of leaves is:
    // (Leaves from the four-leaf clover) + (Leaves from the three-leaf clovers)
    // = 4 + (N - 1) * 3
    int total_leaves = 4 + (N - 1) * 3;

    // Print the calculated total number of leaves to standard output.
    // A newline character "\n" is added at the end, as is standard practice in competitive programming.
    cout << total_leaves << "\n";

    return 0; // Indicate that the program executed successfully.
}