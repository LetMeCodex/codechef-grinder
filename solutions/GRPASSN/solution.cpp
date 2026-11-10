#include <bits/stdc++.h> // Includes iostream, vector, etc.

// Using namespace std; as per problem instruction
using namespace std;

void solve() {
    int N;
    cin >> N;
    
    // Use a frequency array to store counts of preferred group sizes.
    // P_i values are from 2 to N. So, an array of size N+1 is sufficient.
    // Index i will store the count of people who prefer group size i.
    vector<int> counts(N + 1, 0);
    
    for (int i = 0; i < N; ++i) {
        int P_i;
        cin >> P_i;
        counts[P_i]++;
    }
    
    bool possible = true;
    // Iterate through all possible preferred group sizes from 2 to N.
    // P_i is guaranteed to be >= 2.
    for (int S = 2; S <= N; ++S) {
        // If there are people who prefer group size S:
        if (counts[S] > 0) {
            // The number of people who prefer group size S must be a multiple of S.
            // If not, it's impossible to form groups of size S using all of them.
            if (counts[S] % S != 0) {
                possible = false;
                break; // No need to check further, it's already impossible.
            }
        }
    }
    
    if (possible) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Fast I/O as per problem instruction
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}