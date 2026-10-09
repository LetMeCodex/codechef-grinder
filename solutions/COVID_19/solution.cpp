#include <bits/stdc++.h> 

// The problem statement explicitly asks for using namespace std;
using namespace std;

int main() {
    // The problem statement explicitly asks for fast I/O inside main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop T times for each test case
    while (T--) { 
        int N, M;
        cin >> N >> M; // Read N (number of rows) and M (seats per row)

        // Guideline 1: Within a row, there must be at least one empty seat between people.
        // To maximize people in a row, we seat them at positions 1, 3, 5, ...
        // For M seats, the number of people that can be seated is ceil(M/2).
        // In integer arithmetic, (M + 1) / 2 achieves this.
        // Example: M=1 -> (1+1)/2 = 1; M=2 -> (2+1)/2 = 1; M=3 -> (3+1)/2 = 2; M=4 -> (4+1)/2 = 2; M=5 -> (5+1)/2 = 3.
        int max_people_per_row = (M + 1) / 2;

        // Guideline 2: Between rows, there must be at least one completely empty row.
        // To maximize the number of rows with people, we choose rows 1, 3, 5, ...
        // For N rows, the number of active rows (rows with people) is ceil(N/2).
        // In integer arithmetic, (N + 1) / 2 achieves this.
        // Example: N=1 -> (1+1)/2 = 1; N=2 -> (2+1)/2 = 1; N=3 -> (3+1)/2 = 2; N=4 -> (4+1)/2 = 2; N=5 -> (5+1)/2 = 3.
        int max_active_rows = (N + 1) / 2;

        // The total maximum number of tickets is the product of the maximum active rows
        // and the maximum people that can be seated in each of those active rows.
        // The maximum possible value for N, M is 100.
        // max_active_rows <= (100+1)/2 = 50.
        // max_people_per_row <= (100+1)/2 = 50.
        // Total tickets <= 50 * 50 = 2500, which fits comfortably in an 'int'.
        // Using 'long long' for total_tickets is a safe practice, though not strictly necessary here.
        long long total_tickets = (long long)max_active_rows * max_people_per_row;

        // Output the result followed by a newline, as requested.
        cout << total_tickets << "\n";
    }

    return 0;
}