#include <iostream> // Required for cin, cout
#include <algorithm> // Required for std::max

// It's common in competitive programming to include <bits/stdc++.h>
// which includes most standard libraries, and use namespace std.
// However, for specific needs, including only what's necessary is good practice.
// For this problem, iostream and algorithm are sufficient.
// #include <bits/stdc++.h> 
// using namespace std;

void solve() {
    int PA, PB, QA, QB;
    std::cin >> PA >> PB >> QA >> QB;

    // Calculate time penalty for participant P
    // The penalty is the minimum time instant at which both problems are solved.
    // This means P must have solved problem A (at PA) AND problem B (at PB).
    // So, P has solved both problems only after the later of the two times.
    int penalty_P = std::max(PA, PB);

    // Calculate time penalty for participant Q
    // Similarly, Q has solved both problems only after the later of their two times.
    int penalty_Q = std::max(QA, QB);

    // Determine the winner based on penalties
    if (penalty_P < penalty_Q) {
        std::cout << "P\n";
    } else if (penalty_Q < penalty_P) {
        std::cout << "Q\n";
    } else { // penalty_P == penalty_Q
        std::cout << "TIE\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0;
}