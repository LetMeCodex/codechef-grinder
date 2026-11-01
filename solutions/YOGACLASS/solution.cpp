#include <iostream> // Required for standard input/output operations (cin, cout)

void solve() {
    int N, X, Y;
    // Read the number of hours (N), price of Type 1 session (X),
    // and price of Type 2 session (Y) for the current test case.
    std::cin >> N >> X >> Y;

    long long total_money; // Use long long to store total money to prevent potential overflow,
                           // although for these constraints, int would suffice.

    // Compare the profitability per hour of Type 1 vs Type 2 sessions.
    // Type 1: X rupees per hour.
    // Type 2: Y rupees for 2 hours, effectively Y/2 rupees per hour.
    // The comparison Y > 2 * X is equivalent to Y/2 > X.

    if (Y > 2 * X) {
        // If Type 2 sessions are more profitable per hour (Y/2 > X),
        // maximize the number of Type 2 sessions.
        
        // Calculate the maximum number of Type 2 sessions possible.
        // Each Type 2 session takes 2 hours.
        long long num_type2_sessions = N / 2; 
        
        // Calculate the remaining hours after taking Type 2 sessions.
        // These remaining hours can only be filled with Type 1 sessions.
        long long remaining_hours_for_type1 = N % 2; 
        
        // Calculate total earnings.
        total_money = num_type2_sessions * Y + remaining_hours_for_type1 * X;
    } else {
        // If Type 1 sessions are equally or more profitable per hour (Y/2 <= X),
        // or if Type 2 sessions are less profitable per hour,
        // it's always better to take only Type 1 sessions.
        // This means taking N Type 1 sessions and 0 Type 2 sessions.
        
        // Calculate total earnings. Cast N to long long before multiplication
        // to ensure the product is computed as long long.
        total_money = (long long)N * X;
    }

    // Output the maximum amount of money Chef can earn.
    std::cout << total_money << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases.
    while (T--) {  // Loop through each test case.
        solve();   // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}