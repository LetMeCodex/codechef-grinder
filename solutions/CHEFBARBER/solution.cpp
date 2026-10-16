#include <bits/stdc++.h> // Includes all standard libraries, common in competitive programming

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations significantly.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further improving I/O performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int N, M; // Declare integers N (number of customers waiting) and M (minutes per customer)
        cin >> N >> M; // Read N and M for the current test case from standard input

        // Calculate the total waiting time for Chef.
        // Chef arrives after N customers are already waiting.
        // Since each customer takes M minutes and only one person can get a haircut at a time,
        // Chef must wait for all N customers to finish.
        // The total time taken for N customers is N multiplied by M.
        int waiting_time = N * M;

        // Print the calculated waiting time to standard output,
        // followed by a newline character. Using "\n" is generally preferred
        // over `endl` in competitive programming for performance reasons,
        // as `endl` also forces a flush of the output buffer.
        cout << waiting_time << "\n";
    }

    return 0; // Indicate successful execution of the program
}