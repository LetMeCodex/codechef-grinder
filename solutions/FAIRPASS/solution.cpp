#include <bits/stdc++.h> // Includes most standard libraries like iostream

using namespace std; // Allows using standard library elements without std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from input

    while (T--) { // Loop T times, decrementing T in each iteration
        int N, K; // Declare integer variables N and K for friends and passes
        cin >> N >> K; // Read N and K for the current test case

        // Calculate the total number of people who need passes.
        // This includes Chef himself (1 person) and his N friends.
        int people_needed = N + 1;

        // Check if Chef has enough passes (K) for all the people (people_needed).
        if (K >= people_needed) {
            // If K is greater than or equal to people_needed, Chef can enter with everyone.
            cout << "YES\n"; // Print YES followed by a newline
        } else {
            // Otherwise, Chef does not have enough passes for everyone.
            cout << "NO\n"; // Print NO followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}