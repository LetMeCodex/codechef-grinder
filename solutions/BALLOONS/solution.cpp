#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Using the standard namespace, as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer variable N for the number of colours.
        cin >> N; // Read the number of colours for the current test case.

        // Declare a long long variable to store the total cost.
        // Using long long is a safe practice to prevent potential integer overflow,
        // even though for the given constraints, int would also suffice.
        long long total_cost = 0;

        // Loop from i = 1 to N.
        // 'i' represents both the colour number and its cost.
        for (int i = 1; i <= N; ++i) {
            int A_i; // Declare an integer variable A_i for the count of balloons of colour i.
            cin >> A_i; // Read the count of balloons of the i-th colour.

            // Calculate the cost for balloons of colour i (A_i * i)
            // and add it to the total_cost.
            // The cast to (long long) before multiplication is not strictly necessary here
            // because A_i * i (max 100*100 = 10000) fits in int,
            // but it's a good habit for larger constraints to prevent intermediate overflow.
            total_cost += (long long)A_i * i; 
        }

        // Output the total cost for the current test case, followed by a newline.
        cout << total_cost << "\n";
    }

    return 0; // Indicate successful program execution.
}