#include <bits/stdc++.h> // Includes iostream, numeric, algorithm, etc.

// Using namespace std; as requested by the problem statement.
using namespace std; 

void solve() {
    // N can fit in int, but K and D require long long due to their maximum values (10^9).
    // Reading N as long long is harmless and consistent.
    long long N, K, D; 
    cin >> N >> K >> D;
    
    long long total_problems = 0;
    // Iterate N times to read A_i and sum them up.
    for (int i = 0; i < N; ++i) {
        long long A_i; // A_i can fit in int, but reading into long long is safer for summation to total_problems.
        cin >> A_i;
        total_problems += A_i;
    }
    
    // Calculate the maximum number of contests Chef can host based on the total problems available.
    // Integer division automatically handles cases where total_problems < K, resulting in 0 contests.
    long long contests_from_problems = total_problems / K;
    
    // Chef cannot host more than one contest in a day.
    // So, over D days, Chef can host at most D contests.
    long long contests_from_days = D; 
    
    // The final answer is limited by whichever factor (problems or days) is more restrictive.
    long long result = min(contests_from_problems, contests_from_days);
    
    cout << result << "\n";
}

int main() {
    // Enable fast I/O for competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases.
    cin >> T;
    while (T--) { // Loop through each test case.
        solve();
    }
    
    return 0;
}