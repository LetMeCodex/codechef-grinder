#include <bits/stdc++.h> // Includes iostream, vector, etc. as requested

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // counts[0]: count of numbers A_i such that A_i % 3 == 0
    // counts[1]: count of numbers A_i such that A_i % 3 == 1
    // counts[2]: count of numbers A_i such that A_i % 3 == 2
    vector<int> counts(3, 0); 
    
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        counts[A_i % 3]++;
    }
    
    bool found = false;
    
    // Condition 1: An element itself is divisible by 3.
    // If there's any number A_i such that A_i % 3 == 0, we can pick just that number.
    // This forms a non-empty subsequence with sum divisible by 3.
    if (counts[0] > 0) {
        found = true;
    }
    // Condition 2: Combine an element with remainder 1 and an element with remainder 2.
    // Their sum will be (1 + 2) % 3 = 0.
    // This forms a non-empty subsequence with sum divisible by 3.
    else if (counts[1] > 0 && counts[2] > 0) {
        found = true;
    }
    // Condition 3: Combine three elements with remainder 1.
    // Their sum will be (1 + 1 + 1) % 3 = 3, which is 0 % 3.
    // This forms a non-empty subsequence with sum divisible by 3.
    else if (counts[1] >= 3) {
        found = true;
    }
    // Condition 4: Combine three elements with remainder 2.
    // Their sum will be (2 + 2 + 2) % 3 = 6, which is 0 % 3.
    // This forms a non-empty subsequence with sum divisible by 3.
    else if (counts[2] >= 3) {
        found = true;
    }
    
    if (found) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // Fast I/O as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}