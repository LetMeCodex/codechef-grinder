#include <bits/stdc++.h> // Includes all standard libraries, as requested by the problem statement

using namespace std; // Uses the standard namespace, as requested by the problem statement

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    // This significantly speeds up I/O operations, which is crucial for problems with large inputs or tight time limits.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N, X; // Declare integer variables N and X for the current test case.
        cin >> N >> X; // Read N (total members) and X (members voted in favour) from standard input.

        // According to the constitution, a resolution is passed if and only if
        // "half or more than half the members present in the Parliament vote in favour".
        // This condition can be mathematically expressed as X >= N/2.
        //
        // To handle this condition correctly using integer arithmetic for both even and odd N,
        // we can multiply both sides of the inequality by 2:
        // 2 * X >= N
        //
        // Let's verify this logic:
        // Case 1: N is even (e.g., N=10). Half is 5.
        // The condition is X >= 5.
        // Using our logic: 2 * X >= 10.
        // If X=5, 2*5 = 10, so 10 >= 10 (True). Correct.
        // If X=4, 2*4 = 8, so 8 >= 10 (False). Correct.
        //
        // Case 2: N is odd (e.g., N=9). Half is 4.5.
        // "Half or more than half" means X must be at least 4.5. Since X must be an integer,
        // this implies X >= 5.
        // Using our logic: 2 * X >= 9.
        // If X=5, 2*5 = 10, so 10 >= 9 (True). Correct.
        // If X=4, 2*4 = 8, so 8 >= 9 (False). Correct.
        //
        // This logic correctly captures the problem's requirement for all valid N and X.

        if (2 * X >= N) {
            cout << "YES\n"; // If the condition is met, print "YES" followed by a newline.
        } else {
            cout << "NO\n"; // Otherwise, print "NO" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}