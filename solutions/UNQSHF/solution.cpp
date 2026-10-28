#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the strings
    string A, B;
    cin >> A >> B; // Read strings A and B

    // Count the number of 'a's in string A
    int countA_a = 0;
    for (char c : A) {
        if (c == 'a') {
            countA_a++;
        }
    }
    // An alternative way to count using std::count from <algorithm>:
    // int countA_a = count(A.begin(), A.end(), 'a');

    // Count the number of 'b's in string B
    int countB_b = 0;
    for (char c : B) {
        if (c == 'b') {
            countB_b++;
        }
    }
    // An alternative way to count using std::count from <algorithm>:
    // int countB_b = count(B.begin(), B.end(), 'b');

    // The condition for a solution to exist is that the number of 'a's in A
    // must be equal to the number of 'b's in B.
    // This is derived from the fact that if we want A_i != B_i for all i,
    // then for each position i, the pair (A_i, B_i) must be either ('a', 'b') or ('b', 'a').
    // Let 'k' be the number of ('a', 'b') pairs.
    // Then 'N-k' must be the number of ('b', 'a') pairs.
    // String A must contain 'k' 'a's and 'N-k' 'b's. So, countA_a = k.
    // String B must contain 'N-k' 'a's and 'k' 'b's. So, countB_b = k.
    // Therefore, countA_a must be equal to countB_b.
    if (countA_a == countB_b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cout from flushing before cin reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}