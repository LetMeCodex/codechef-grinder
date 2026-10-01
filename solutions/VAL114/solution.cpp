#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input.
    int N;

    // Read the single integer N from standard input.
    cin >> N;

    // According to the problem statement, "starters 121 is likely to be organised on Valentine's day."
    // For any other starters number within the given constraints (120 to 123),
    // it is implied to be "Unlikely".
    if (N == 121) {
        // If N is 121, output "Likely".
        cout << "Likely\n";
    } else {
        // For any other value of N (120, 122, or 123), output "Unlikely".
        cout << "Unlikely\n";
    }

    return 0; // Indicate successful program execution.
}