#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int N, P;
    cin >> N >> P; // Read the number of problems (N) and total participants (P)

    // Calculate the thresholds for cakewalk and hard problems using integer division
    int cakewalk_threshold = P / 2;
    int hard_threshold = P / 10;

    int cakewalk_count = 0; // Counter for problems categorized as cakewalk
    int hard_count = 0;     // Counter for problems categorized as hard

    // Loop through each of the N problems
    for (int i = 0; i < N; ++i) {
        int solvers;
        cin >> solvers; // Read the number of participants who solved the current problem

        // Check if the current problem is a cakewalk problem
        if (solvers >= cakewalk_threshold) {
            cakewalk_count++;
        }
        // Check if the current problem is a hard problem
        if (solvers <= hard_threshold) {
            hard_count++;
        }
    }

    // Determine if the contest is balanced based on the counts
    // A balanced contest must have exactly 1 cakewalk and exactly 2 hard problems
    if (cakewalk_count == 1 && hard_count == 2) {
        cout << "yes\n"; // If balanced, print "yes"
    } else {
        cout << "no\n";  // Otherwise, print "no"
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}