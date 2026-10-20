#include <bits/stdc++.h> // Includes iostream, cmath, etc. for standard operations

// Use the standard namespace as requested by the problem instructions.
using namespace std;

// Function to solve a single test case
void solve() {
    // Declare variables for the input factors and speed.
    // Using 'double' for floating-point numbers to maintain precision,
    // as the problem involves decimal values and precise comparisons.
    double k1, k2, k3, v;
    
    // Read the four float values for the current test case from standard input.
    cin >> k1 >> k2 >> k3 >> v;

    // Calculate Chef's final speed in competition.
    // This is the product of the practice speed 'v' and all three modifying factors.
    double final_speed = k1 * k2 * k3 * v;

    // Calculate the time taken to complete 100 meters.
    // The formula is Time = Distance / Speed. Distance is 100 meters.
    double time_taken = 100.0 / final_speed;

    // The problem states that the final time displayed by the Olympics clock
    // is rounded to 2 places of decimal. We must apply this rounding.
    // To round a number 'x' to 'N' decimal places:
    // 1. Multiply 'x' by 10^N. (Here, N=2, so multiply by 100.0)
    // 2. Round the result to the nearest integer using std::round().
    // 3. Divide the rounded integer back by 10^N.
    double rounded_time = round(time_taken * 100.0) / 100.0;

    // Compare the rounded time with the world record (9.58 seconds).
    // Chef breaks the record if his rounded time is *strictly less than* 9.58.
    if (rounded_time < 9.58) {
        // If Chef's time is strictly less than 9.58, he breaks the record.
        cout << "YES\n";
    } else {
        // Otherwise (if rounded_time is 9.58 or greater), he does not break the record.
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // 'ios_base::sync_with_stdio(false)' disables synchronization with C's stdio library.
    // 'cin.tie(NULL)' unties cin from cout, meaning cin will not flush cout before reading input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare a variable for the number of test cases.
    int t;
    // Read the number of test cases from standard input.
    cin >> t;
    
    // Loop through each test case.
    // The 'while (t--)' construct decrements 't' after each iteration
    // and continues as long as 't' is greater than 0.
    while (t--) {
        // Call the 'solve' function to process the current test case.
        solve();
    }

    // Return 0 to indicate successful program execution.
    return 0;
}