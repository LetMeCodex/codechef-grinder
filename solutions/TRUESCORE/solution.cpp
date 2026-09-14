#include <bits/stdc++.h> 

// It's common practice in competitive programming to use the entire standard namespace
// to avoid repeatedly typing `std::`. The problem statement also suggests this.
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B; // Declare integers A and B for the initial scores of team 1 and team 2.
        cin >> A >> B; // Read the initial scores.

        int C, D; // Declare integers C and D for the potential final scores of team 1 and team 2.
        cin >> C >> D; // Read the potential final scores.

        // To determine if a score C:D is possible from A:B, two conditions must be met:
        // 1. Team 1's score (C) must be greater than or equal to its initial score (A).
        //    A team's score cannot decrease.
        // 2. Team 2's score (D) must be greater than or equal to its initial score (B).
        //    Similarly, a team's score cannot decrease.
        if (C >= A && D >= B) {
            // If both conditions are true, then it is possible for the score to become C:D.
            // Team 1 scores (C - A) more goals and Team 2 scores (D - B) more goals.
            cout << "POSSIBLE\n"; 
        } else {
            // If either condition is false (i.e., C < A or D < B or both),
            // then it is impossible for the score to become C:D.
            cout << "IMPOSSIBLE\n";
        }
    }

    return 0; // Indicate successful program execution.
}