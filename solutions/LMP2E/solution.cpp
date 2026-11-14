#include <bits/stdc++.h> // Required include as per problem instructions

// Using namespace std; as per problem instructions
using namespace std;

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    
    int wear_count = 0;
    bool has_jacket = false; // Chef is not wearing a jacket initially
    
    for (int i = 0; i < N; ++i) {
        int T_i;
        cin >> T_i;
        
        if (T_i < A) {
            // Chef must wear a jacket to be comfortable.
            // (Since T_i < A and A <= B, it implies T_i <= B, so wearing a jacket works).
            if (!has_jacket) {
                // If not currently wearing, Chef puts on a jacket.
                wear_count++;
                has_jacket = true;
            }
            // If already wearing, Chef remains comfortable. No action needed.
        } else if (T_i > B) {
            // Chef must remove the jacket to be comfortable.
            // (Since T_i > B and B >= A, it implies T_i >= A, so not wearing a jacket works).
            has_jacket = false; // Removing a jacket doesn't count as an action.
            // If already not wearing, Chef remains comfortable. No action needed.
        } else { // A <= T_i <= B
            // Chef can be comfortable either with or without a jacket.
            // To minimize wear_count, Chef should maintain his current state.
            // If has_jacket is false: Chef is comfortable (T_i >= A). Stays without jacket.
            // If has_jacket is true: Chef is comfortable (T_i <= B). Stays with jacket.
            // In both cases, no change to has_jacket or wear_count is needed.
        }
    }
    
    cout << wear_count << "\n";
}

int main() {
    // Fast I/O as per problem instructions
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}