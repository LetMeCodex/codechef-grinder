#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std for convenience in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Vector to store the input achievement scores
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Vector to store the results (1 for happy, 0 for not happy)
    vector<int> results(N);
    
    // current_max stores the maximum achievement score encountered among students
    // processed so far (i.e., students before the current one).
    // Initialize to 0 because achievement scores A_i are distinct integers from 1 to N,
    // so A_i will always be >= 1.
    int current_max = 0; 

    // Iterate through each student from left to right
    for (int i = 0; i < N; ++i) {
        // A student is happy if their score A[i] is greater than
        // all students before them. This is equivalent to A[i] being
        // strictly greater than the maximum score among students before them.
        if (A[i] > current_max) {
            results[i] = 1; // Student is happy
        } else {
            results[i] = 0; // Student is not happy
        }
        
        // Update current_max to include the current student's score.
        // This updated current_max will be used for the next student.
        current_max = max(current_max, A[i]);
    }

    // Print the results for the current test case
    for (int i = 0; i < N; ++i) {
        cout << results[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n"; // Newline after each test case's output
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}