#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

void solve() {
    int X, Y, Z;
    // Read the number of assignments (X), time per assignment (Y), and days available (Z)
    cin >> X >> Y >> Z;

    // Calculate the total time required to complete all assignments in minutes.
    // X assignments * Y minutes/assignment = total minutes needed.
    // Using long long for calculation to prevent potential overflow,
    // though for given constraints (X, Y <= 100), int would also suffice.
    long long total_time_needed = (long long)X * Y;

    // Calculate the total time available in minutes.
    // 1 day = 24 hours
    // 1 hour = 60 minutes
    // So, 1 day = 24 * 60 = 1440 minutes.
    // Z days * 1440 minutes/day = total minutes available.
    // Using long long for calculation, though for given constraints (Z <= 10),
    // int would also suffice.
    long long total_time_available = (long long)Z * 24 * 60;

    // Compare the total time needed with the total time available.
    // If Chef needs less than or equal to the time available, he can complete them.
    if (total_time_needed <= total_time_available) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}