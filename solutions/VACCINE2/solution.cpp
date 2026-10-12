#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Using the standard namespace, as requested
using namespace std;

void solve() {
    int N, D;
    cin >> N >> D; // Read N (total people) and D (capacity per day)

    int risk_count = 0;       // Counter for people at risk
    int non_risk_count = 0;   // Counter for people not at risk

    for (int i = 0; i < N; ++i) {
        int age;
        cin >> age; // Read age of current person
        // A person is at risk if age is >= 80 OR age is <= 9
        if (age >= 80 || age <= 9) {
            risk_count++; // Person is at risk
        } else {
            non_risk_count++; // Person is not at risk
        }
    }

    // Calculate days needed for at-risk people.
    // The formula (A + B - 1) / B correctly computes ceil(A/B) for positive integers A, B.
    // It also correctly handles A=0, resulting in 0 days.
    int days_for_risk = (risk_count + D - 1) / D;

    // Calculate days needed for not-at-risk people.
    int days_for_non_risk = (non_risk_count + D - 1) / D;

    // The problem states that on any day, you cannot vaccinate both an at-risk
    // person and a not-at-risk person. This means the two groups must be
    // vaccinated on separate days. Therefore, the total minimum days is the
    // sum of days required for each group independently.
    int total_days = days_for_risk + days_for_non_risk;

    cout << total_days << "\n"; // Print the result followed by a newline
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}