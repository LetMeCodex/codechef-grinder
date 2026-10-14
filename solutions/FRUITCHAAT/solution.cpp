#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // which can speed up I/O operations significantly in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of testcases.
    cin >> T; // Read the number of testcases.

    // Loop T times, once for each testcase.
    while (T--) {
        int X, Y; // Declare integer variables X for bananas and Y for apples.
        cin >> X >> Y; // Read the number of bananas and apples for the current testcase.

        // Calculate the maximum number of chaats Chef can make.
        // Each fruit chaat requires 2 bananas and 1 apple.
        //
        // The number of chaats is limited by two factors:
        // 1. The available bananas: With X bananas, Chef can make at most X / 2 chaats.
        //    (Integer division X / 2 correctly handles cases where X is odd,
        //    e.g., 7 bananas can make 3 chaats, using 6 bananas).
        // 2. The available apples: With Y apples, Chef can make at most Y chaats.
        //
        // To make a chaat, both conditions must be met. Therefore, the total number
        // of chaats Chef can make is limited by the minimum of these two quantities.
        int max_chaats = min(X / 2, Y);

        // Output the result for the current testcase, followed by a newline.
        cout << max_chaats << "\n";
    }

    return 0; // Indicate successful execution of the program.
}