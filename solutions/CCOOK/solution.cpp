#include <iostream> // Required for cin, cout
#include <string>   // Required for string (though not strictly necessary if printing literals)
#include <vector>   // Not strictly necessary for this problem, but often useful
#include <numeric>  // Not strictly necessary for this problem, but often useful
#include <algorithm> // Not strictly necessary for this problem, but often useful

// Using bits/stdc++.h as requested, which includes all standard libraries.
// This is common in competitive programming for convenience.
#include <bits/stdc++.h> 

// Using the standard namespace to avoid writing std:: repeatedly.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer N to store the number of competitors.
    cin >> N; // Read the value of N from standard input.

    // Loop N times, once for each competitor.
    for (int i = 0; i < N; ++i) {
        int solved_problems_count = 0; // Initialize a counter for problems solved by the current competitor.

        // Loop 5 times to read the status of each of the five problems.
        for (int j = 0; j < 5; ++j) {
            int problem_status; // Declare an integer to store the status of the current problem (0 or 1).
            cin >> problem_status; // Read the problem status.

            // If the problem status is 1, it means the competitor solved this problem.
            if (problem_status == 1) {
                solved_problems_count++; // Increment the counter.
            }
        }

        // Based on the total number of problems solved, classify the competitor.
        if (solved_problems_count == 0) {
            cout << "Beginner\n"; // Print "Beginner" if 0 problems solved.
        } else if (solved_problems_count == 1) {
            cout << "Junior Developer\n"; // Print "Junior Developer" if 1 problem solved.
        } else if (solved_problems_count == 2) {
            cout << "Middle Developer\n"; // Print "Middle Developer" if 2 problems solved.
        } else if (solved_problems_count == 3) {
            cout << "Senior Developer\n"; // Print "Senior Developer" if 3 problems solved.
        } else if (solved_problems_count == 4) {
            cout << "Hacker\n"; // Print "Hacker" if 4 problems solved.
        } else if (solved_problems_count == 5) {
            cout << "Jeff Dean\n"; // Print "Jeff Dean" if all 5 problems solved.
        }
    }

    return 0; // Indicate successful execution of the program.
}