#include <bits/stdc++.h> 

// It's good practice to use specific headers if possible, but for competitive programming,
// <bits/stdc++.h> is commonly used as a convenience.
// For this problem, <iostream> would be sufficient.

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the total number of testcases.
    cin >> T; // Read the number of testcases.

    // Loop through each testcase.
    while (T--) {
        int N; // Variable to store the input sum N.
        cin >> N; // Read the sum N for the current testcase.

        int notes_count = 0; // Initialize a counter for the total number of notes.

        // The problem asks for the smallest number of notes.
        // For standard currency denominations (1, 2, 5, 10, 50, 100),
        // a greedy approach works optimally.
        // We start with the largest denomination and take as many as possible,
        // then move to the next largest, and so on.

        // Denomination: Rs. 100
        notes_count += N / 100; // Add the number of 100-rupee notes.
        N %= 100;               // Update N to the remaining amount after taking 100-rupee notes.

        // Denomination: Rs. 50
        notes_count += N / 50;  // Add the number of 50-rupee notes.
        N %= 50;                // Update N.

        // Denomination: Rs. 10
        notes_count += N / 10;  // Add the number of 10-rupee notes.
        N %= 10;                // Update N.

        // Denomination: Rs. 5
        notes_count += N / 5;   // Add the number of 5-rupee notes.
        N %= 5;                 // Update N.

        // Denomination: Rs. 2
        notes_count += N / 2;   // Add the number of 2-rupee notes.
        N %= 2;                 // Update N.

        // Denomination: Rs. 1
        // At this point, N will be either 0 or 1.
        notes_count += N / 1;   // Add the number of 1-rupee notes.
        // N %= 1; // This line is not strictly necessary as N will become 0,
                  // and no further calculations depend on N.

        // Display the smallest number of notes for the current testcase,
        // followed by a newline character.
        cout << notes_count << "\n";
    }

    return 0; // Indicate successful execution.
}