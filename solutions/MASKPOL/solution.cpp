#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int N, A; // N: total number of people, A: number of infected people
        cin >> N >> A; // Read N and A for the current test case

        // Calculate the number of uninfected people
        int uninfected_people = N - A;

        // To stop the virus spread, we need to ensure that any interaction
        // between an infected person and an uninfected person does not lead to infection.
        // This can be achieved by either:
        // 1. Masking all 'A' infected people. Cost = A masks.
        // 2. Masking all 'N - A' uninfected people. Cost = N - A masks.
        // The minimum number of masks required is the smaller of these two options.
        int min_masks = min(A, uninfected_people);

        // Output the result for the current test case, followed by a newline
        cout << min_masks << "\n";
    }

    return 0; // Indicate successful execution
}