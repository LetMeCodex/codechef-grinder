#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Declare an integer variable N to store the day of the week.
    cin >> N; // Read the integer N from standard input.

    // According to the problem statement:
    // Sunday is 1st, Monday is 2nd, Tuesday is 3rd, Wednesday is 4th, and so on.
    // Codechef rounds are held ONLY on Wednesday.
    // Therefore, we need to check if the input day N corresponds to Wednesday, which is the 4th day.
    if (N == 4) {
        cout << "YES\n"; // If N is 4, it's Wednesday, so output "YES".
    } else {
        cout << "NO\n"; // For any other day (N is not 4), output "NO".
    }

    return 0; // Indicate successful program execution.
}