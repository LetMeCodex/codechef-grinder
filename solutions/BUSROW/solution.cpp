#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::min

// It's common in competitive programming to include <bits/stdc++.h>
// which includes most standard libraries. For this specific problem,
// iostream and algorithm are sufficient.

// Using namespace std; is also common in competitive programming
// to avoid typing std:: repeatedly.
using namespace std;

int main() {
    // Fast I/O setup to speed up input and output operations.
    // This is generally good practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, M, X; // N: number of rows, M: seats per row, X: your seat number
        cin >> N >> M >> X; // Read N, M, and X for the current test case

        // Step 1: Determine the row number where seat X is located.
        // The formula (X - 1) / M + 1 correctly calculates the 1-indexed row.
        int target_row = (X - 1) / M + 1;

        // Step 2: Calculate the number of rows walked if boarding from the front.
        // To reach target_row from the front, you walk through rows 1, 2, ..., target_row.
        // The count is simply target_row.
        int rows_from_front = target_row;

        // Step 3: Calculate the number of rows walked if boarding from the back.
        // To reach target_row from the back (starting after row N),
        // you walk through rows N, N-1, ..., target_row.
        // The count is N - target_row + 1.
        int rows_from_back = N - target_row + 1;

        // Step 4: Find the minimum of the two options.
        // std::min is used to get the smaller of the two values.
        int min_rows_walked = min(rows_from_front, rows_from_back);

        // Output the minimum number of rows walked for the current test case,
        // followed by a newline character.
        cout << min_rows_walked << "\n";
    }

    return 0; // Indicate successful program execution
}