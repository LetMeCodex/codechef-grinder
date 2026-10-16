#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, K; // Declare integer variables N (total bill) and K (number of friends).
        cin >> N >> K; // Read N and K for the current test case.

        // Calculate the total number of people sharing the bill.
        // This includes 'you' and 'K' friends.
        int total_people = K + 1;

        // Calculate each person's fair share, rounded down to the nearest integer.
        // In C++, integer division (e.g., N / total_people) automatically performs
        // floor division for positive integers, which matches the problem's requirement
        // for rounding down.
        int share_per_person_rounded_down = N / total_people;

        // Calculate the total amount reimbursed by the K friends.
        // Each of the K friends pays their rounded-down share.
        int total_reimbursed_by_friends = K * share_per_person_rounded_down;

        // Calculate your net payment.
        // This is the initial total bill you paid minus the total amount
        // you received back from your friends.
        int net_payment = N - total_reimbursed_by_friends;

        // Output the calculated net payment for the current test case,
        // followed by a newline character.
        cout << net_payment << "\n";
    }

    return 0; // Indicate successful program execution.
}