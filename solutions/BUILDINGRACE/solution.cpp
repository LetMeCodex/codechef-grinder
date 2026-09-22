#include <iostream> // Required for cin and cout

// Using the standard namespace to avoid prefixing std:: to every standard library element.
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int A, B, X, Y; // Declare integer variables for Chef's floor, Chefina's floor, Chef's speed, and Chefina's speed.
        cin >> A >> B >> X >> Y; // Read the four integers for the current test case.

        // Calculate "effective time" numerators for Chef and Chefina using cross-multiplication.
        // This avoids floating-point arithmetic and potential precision issues.
        // Chef's time = A/X. Chefina's time = B/Y.
        // Comparing A/X vs B/Y is equivalent to comparing A*Y vs B*X
        // (since X and Y are positive, multiplying by X*Y doesn't change inequality direction).
        
        // Using long long for intermediate products to be absolutely safe,
        // even though int is sufficient given the constraints (max 100*10 = 1000).
        // This is a common defensive programming practice in competitive programming
        // to prevent any potential, however unlikely, overflow issues or
        // platform-specific integer size quirks.
        long long chef_time_numerator = (long long)A * Y;
        long long chefina_time_numerator = (long long)B * X;

        // Compare the calculated integer products to determine who reaches first.
        if (chef_time_numerator < chefina_time_numerator) {
            // If Chef's effective time numerator is smaller, Chef takes less time.
            cout << "Chef\n";
        } else if (chef_time_numerator > chefina_time_numerator) {
            // If Chefina's effective time numerator is smaller, Chefina takes less time.
            cout << "Chefina\n";
        } else {
            // If both numerators are equal, both take the same amount of time.
            cout << "Both\n";
        }
    }

    return 0; // Indicate successful program execution.
}