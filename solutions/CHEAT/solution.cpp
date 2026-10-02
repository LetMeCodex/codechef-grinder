#include <bits/stdc++.h> // Includes all standard libraries

// Using namespace std; as requested
using namespace std;

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read N for each test case

        int count_tuesdays;
        if (N < 2) {
            // If N is 1 (only Monday), no Tuesdays are encountered.
            count_tuesdays = 0;
        } else {
            // The first Tuesday is on day 2. This accounts for 1 Tuesday.
            // For any subsequent Tuesdays, they occur every 7 days.
            // The number of days remaining after the first Tuesday is N - 2.
            // Each full 7-day cycle within these remaining days (starting from day 3)
            // adds one more Tuesday.
            // (N - 2) / 7 performs integer division, giving the number of full 7-day cycles.
            // So, total Tuesdays = 1 (for day 2) + (number of additional 7-day cycles).
            count_tuesdays = 1 + (N - 2) / 7;
        }
        cout << count_tuesdays << "\n"; // Output the result followed by a newline
    }
    return 0;
}