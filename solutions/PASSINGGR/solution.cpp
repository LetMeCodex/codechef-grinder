#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of students

    // Create a vector to store student scores
    vector<int> A(N);
    int chef_score;

    // Read all student scores and identify Chef's score
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // Chef is student number 1, which corresponds to index 0 in a 0-indexed array
        if (i == 0) {
            chef_score = A[i]; // Store Chef's score
        }
    }

    int passing_students_count = 0;
    // Iterate through all students to count how many pass with the optimal cutoff.
    // The optimal cutoff is Chef's score (chef_score) because it ensures Chef passes
    // and minimizes the number of other students passing (by setting the highest possible cutoff Chef can clear).
    for (int i = 0; i < N; ++i) {
        if (A[i] >= chef_score) {
            passing_students_count++;
        }
    }

    // Output the minimum number of students that pass for this test case
    cout << passing_students_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can speed up I/O in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}