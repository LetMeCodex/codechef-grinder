#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    ios_base::sync_with_stdio(false);
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    cin.tie(NULL);

    // Declare an integer variable N to store the number of friends.
    // According to constraints, 1 <= N <= 5.
    int N;

    // Read the value of N from standard input.
    cin >> N;

    // Calculate the total number of people for whom tickets are needed.
    // This includes N friends and 1 ticket for yourself.
    // So, total_people = N + 1.
    int total_people = N + 1;

    // Calculate the total cost.
    // Each ticket costs 5000 INR.
    // The maximum possible value for total_people is 5 (friends) + 1 (yourself) = 6.
    // The maximum total cost will be 6 * 5000 = 30000 INR.
    // This value fits comfortably within a standard 'int' data type.
    // However, using 'long long' for the result is a good general practice in
    // competitive programming to prevent potential integer overflows, even if
    // not strictly necessary for these specific constraints.
    long long total_cost = (long long)total_people * 5000;

    // Print the calculated total cost to standard output,
    // followed by a newline character as required.
    cout << total_cost << "\n";

    // Return 0 to indicate successful program execution.
    return 0;
}