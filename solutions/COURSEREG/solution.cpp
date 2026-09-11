#include <bits/stdc++.h> // Includes almost all standard library headers

// The problem statement specifically requests using namespace std;
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int N, M, K;
        // Read the three integers N, M, and K for the current test case
        cin >> N >> M >> K;

        // Calculate the total number of students that would be in the course
        // if all N friends successfully enroll.
        int total_students_after_friends_enroll = K + N;

        // Check if this total number of students is within the course's maximum capacity M.
        // If total_students_after_friends_enroll is less than or equal to M,
        // then it is possible for all N friends to enroll.
        if (total_students_after_friends_enroll <= M) {
            cout << "Yes\n"; // Output "Yes" if possible
        } else {
            // Otherwise, if the total exceeds M, it's not possible.
            cout << "No\n"; // Output "No" if not possible
        }
    }

    return 0; // Indicate successful program execution
}