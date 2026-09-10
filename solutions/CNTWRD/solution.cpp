#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    cin >> T; // Read the value of T from standard input.

    // Loop 'T' times, once for each test case.
    // The 'T--' decrements T after each iteration, and the loop continues as long as T > 0.
    while (T--) {
        int N, M; // Declare two integer variables 'N' and 'M' for each test case.
                  // N: number of pages in the book.
                  // M: number of words on each page.
        cin >> N >> M; // Read the values of N and M for the current test case from standard input.

        // Calculate the total number of words.
        // If there are N pages and each page has M words, the total words is N * M.
        int total_words = N * M;

        // Output the calculated total number of words.
        // A newline character "\n" is appended to ensure each output is on a new line,
        // as required by the problem statement.
        cout << total_words << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}