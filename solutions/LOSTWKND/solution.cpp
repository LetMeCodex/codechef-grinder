#include <iostream> // Required for standard input/output operations (cin, cout)

// The problem statement explicitly suggests `#include <bits/stdc++.h>`
// and `using namespace std;`.
// #include <bits/stdc++.h> 
using namespace std;

// The solve function encapsulates the logic for a single test case.
void solve() {
    // Declare an array to store the hours worked at the office for 5 weekdays.
    // A_i values are between 0 and 24.
    int A[5]; 
    // Declare a variable for the productivity factor P.
    // P is between 1 and 24.
    int P;    

    // Initialize a variable to accumulate the total hours worked at the office.
    // Using 'long long' is a safe practice for sums and products in competitive programming
    // to prevent potential integer overflow, even if 'int' might suffice for current constraints.
    // Max sum of A_i = 5 * 24 = 120.
    // Max total_home_hours_required = 120 * 24 = 2880.
    // Both fit within a 32-bit signed integer (max approx 2 * 10^9).
    // So, 'int' would technically be sufficient here, but 'long long' causes no harm.
    long long total_office_hours = 0; 

    // Read the 5 A_i values and sum them up.
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
        total_office_hours += A[i];
    }
    // Read the productivity factor P.
    cin >> P;

    // Calculate the total equivalent hours Chef needs to work from home.
    // This is the total office work multiplied by the productivity factor P.
    long long total_home_hours_required = total_office_hours * P;
    
    // Calculate the maximum total hours Chef can work during the 5 weekdays.
    // Each day has 24 hours.
    long long total_available_weekday_hours = 5 * 24; // This constant value is 120.

    // Compare the required home hours with the available weekday hours.
    // If required hours exceed available hours, Chef must work on weekends.
    if (total_home_hours_required > total_available_weekday_hours) {
        cout << "Yes\n"; // Output "Yes" followed by a newline.
    } else {
        cout << "No\n";  // Output "No" followed by a newline.
    }
}

// The main function is the entry point of the program.
int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop T times, calling the solve function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution.
}