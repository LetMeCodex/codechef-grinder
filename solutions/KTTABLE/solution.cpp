#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; as per instructions
using namespace std;

void solve() {
    int N;
    cin >> N;

    // Read the finish times A1, A2, ..., AN
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Read the cooking times needed B1, B2, ..., BN
    vector<int> B(N);
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    int count = 0; // Counter for students who can cook
    int prev_finish_time = 0; // Represents A0, the start time for the first student (time 0)

    // Iterate through each student
    for (int i = 0; i < N; ++i) {
        int current_finish_time = A[i];
        
        // Calculate the time available for the current student.
        // This is the difference between their scheduled finish time (A[i])
        // and their scheduled start time (A[i-1], or 0 for the first student).
        int available_time = current_finish_time - prev_finish_time;
        
        // Get the time needed by the current student
        int needed_time = B[i];

        // Check if the student has enough time
        if (needed_time <= available_time) {
            count++;
        }
        
        // Update prev_finish_time for the next iteration.
        // The current student's finish time becomes the next student's start time.
        prev_finish_time = current_finish_time;
    }

    // Output the total count of students who can cook
    cout << count << "\n";
}

int main() {
    // Enable fast I/O as per instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve();
    }

    return 0;
}