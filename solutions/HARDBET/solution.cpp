#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

using namespace std; // Use standard namespace

void solve() {
    int sA, sB, sC;
    cin >> sA >> sB >> sC;

    // Find the minimum number of submissions among sA, sB, and sC.
    // std::min with an initializer list is a convenient way to do this in C++11 and later.
    int min_submissions = min({sA, sB, sC});

    // Determine the winner based on which problem has the minimum submissions.
    // Since sA, sB, sC are guaranteed to be distinct, exactly one of these conditions will be true.
    if (min_submissions == sA) {
        cout << "Draw\n"; // Problem A is the hardest
    } else if (min_submissions == sB) {
        cout << "Bob\n";  // Problem B is the hardest
    } else { // min_submissions must be sC
        cout << "Alice\n"; // Problem C is the hardest
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Read the number of test cases
    while (t--) { // Loop through each test case
        solve(); // Call the function to solve the current test case
    }

    return 0; // Indicate successful execution
}