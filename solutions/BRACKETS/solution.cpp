#include <cstdio>    // For scanf, printf
#include <algorithm> // For std::max

// Max length of A is 100000. Need 100001 for the null terminator.
// Declaring it globally avoids potential stack overflow for large arrays
// if declared inside main, and ensures zero-initialization.
char A[100001];

int main() {
    // When using scanf/printf, there's no need for ios_base::sync_with_stdio(false)
    // or cin.tie(NULL), as these are specific to C++ iostreams.

    int t;
    scanf("%d", &t); // Read the number of testcases

    while (t--) { // Loop through each testcase
        scanf("%s", A); // Read Mike's current parentheses sequence A into the char array

        int balance = 0;
        int max_balance = 0;

        // Calculate F(A), which is the maximal balance over all prefixes of A.
        // Iterate through the C-style string until the null terminator is found.
        for (int i = 0; A[i] != '\0'; ++i) {
            if (A[i] == '(') {
                balance++;
            } else { // A[i] == ')'
                balance--;
            }
            max_balance = std::max(max_balance, balance); // Update max_balance
        }

        // Construct the new parentheses sequence B.
        // B must have F(B) == max_balance, minimal length, and be lexicographically smallest.
        // This is achieved by a string of 'max_balance' opening parentheses
        // followed by 'max_balance' closing parentheses.
        // Example: if max_balance is 3, B will be "((()))"
        for (int i = 0; i < max_balance; ++i) {
            printf("("); // Print an opening parenthesis
        }
        for (int i = 0; i < max_balance; ++i) {
            printf(")"); // Print a closing parenthesis
        }
        printf("\n"); // Print a newline after each testcase output
    }

    return 0;
}