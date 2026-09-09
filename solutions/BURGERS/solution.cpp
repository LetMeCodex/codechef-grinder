#include <bits/stdc++.h> // Includes common headers like iostream, algorithm, etc.

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop T times, once for each test case
    while (T--) {
        int A, B; // Declare integer variables A for patties and B for buns
        cin >> A >> B; // Read the number of patties and buns for the current test case

        // To make 1 burger, Chef needs 1 patty and 1 bun.
        // The maximum number of burgers Chef can make is limited by the ingredient
        // that Chef has less of.
        // For example, if Chef has 5 patties and 3 buns, Chef can only make 3 burgers
        // because there are only 3 buns. The 2 extra patties cannot be used.
        // If Chef has 3 patties and 5 buns, Chef can only make 3 burgers
        // because there are only 3 patties. The 2 extra buns cannot be used.
        // This means the maximum number of burgers is the minimum of A and B.
        cout << min(A, B) << "\n"; // Calculate min(A, B) and print it, followed by a newline
    }

    return 0; // Indicate successful program execution
}