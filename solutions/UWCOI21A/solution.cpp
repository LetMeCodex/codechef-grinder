#include <bits/stdc++.h> // Includes all standard libraries as requested

// Use the standard namespace as requested
using namespace std;

int main() {
    // Enable fast I/O operations as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of testcases
    cin >> T; // Read the number of testcases

    // Loop T times, once for each testcase
    while (T--) {
        int N; // Declare an integer variable N for the input number
        cin >> N; // Read the integer N for the current testcase

        // The problem asks us to find any two integers A and B such that:
        // 1. 1 <= A, B <= 10^9
        // 2. A * B = N
        //
        // The simplest solution that satisfies all conditions is to choose A = 1 and B = N.
        // Let's verify this choice against the constraints:
        //
        // Constraint 1: 1 <= A, B
        // - For A = 1, 1 <= 1 is true.
        // - For B = N, since the problem states 1 <= N, 1 <= N is true.
        //   So, this constraint is satisfied.
        //
        // Constraint 2: A, B <= 10^9
        // - For A = 1, 1 <= 10^9 is true.
        // - For B = N, since the problem states N <= 10^9, N <= 10^9 is true.
        //   So, this constraint is satisfied.
        //
        // Constraint 3: A * B = N
        // - For A = 1 and B = N, A * B = 1 * N = N.
        //   So, this constraint is satisfied.
        //
        // All constraints are met. The value of N (up to 10^9) fits within a standard 'int' type in C++.
        // Therefore, we can simply output 1 and N for each testcase.
        cout << 1 << " " << N << "\n";
    }

    return 0; // Indicate successful execution
}