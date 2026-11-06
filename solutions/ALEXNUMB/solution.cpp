#include <bits/stdc++.h> // Includes common headers like iostream, vector, etc.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop through each test case
        int n;
        cin >> n; // Read the integer n

        // The problem states n distinct integers a1, a2, ..., an are given.
        // However, their actual values are not needed for the solution.
        // We only need to read them to consume the input.
        for (int i = 0; i < n; ++i) {
            int temp_a;
            cin >> temp_a; // Read and discard each a_i
        }

        // The core logic:
        // We need to count pairs (i, j) such that a_i < a_j.
        // Since all a_k are distinct:
        // 1. If i = j, then a_i < a_i is false. So no pairs (i, i) are counted.
        // 2. If i != j, then either a_i < a_j OR a_j < a_i must be true.
        //    Exactly one of these conditions will hold.
        // This means for every unique unordered pair of distinct indices {i, j},
        // exactly one of the ordered pairs (i, j) or (j, i) will satisfy the condition.
        // The number of unique unordered pairs of distinct indices from n items is
        // given by the combination formula "n choose 2", which is n * (n - 1) / 2.

        // Calculate the result.
        // Cast n to long long before multiplication to prevent potential overflow,
        // as n * (n - 1) can exceed the maximum value of an int for n up to 100,000.
        long long result = (long long)n * (n - 1) / 2;

        // Output the result for the current test case, followed by a newline.
        cout << result << "\n";
    }

    return 0; // Indicate successful execution
}