#include <bits/stdc++.h> // Required header

// Required namespace
using namespace std;

// Function to check if it's possible to sustain M people for D days
bool check(long long D, int M, const vector<int>& A) {
    // D will always be >= 1 due to binary search range [1, high].
    // If D were 0, it means 0 days, which is always possible (no food needed).
    // Our binary search range [1, MAX_DAYS] and ans=0 handles this:
    // if check(1) is false, ans remains 0, which is the correct output for 0 days.
    
    long long total_fed_people = 0;
    for (int units : A) {
        total_fed_people += units / D; // Integer division automatically floors
        // Optimization: if we already have enough people, we can stop early
        if (total_fed_people >= M) {
            return true;
        }
    }
    return total_fed_people >= M;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // Number of food types
    int M; // Number of people
    cin >> N >> M;

    vector<int> A(N); // Units of each food type
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long low = 1;
    // Max possible days is max(A_i). Since max(A_i) is 10^4,
    // high can be set to 10000. Using 10001 is also fine, as it covers 10000.
    long long high = 10001; 
    long long ans = 0; // Stores the maximum D for which check(D) is true

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (check(mid, M, A)) {
            ans = mid;       // It's possible for 'mid' days, so this is a potential answer.
            low = mid + 1;   // Try to achieve more days.
        } else {
            high = mid - 1;  // Not possible for 'mid' days, need to reduce days.
        }
    }

    cout << ans << "\n";

    return 0;
}