#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has N questions.
 * Alice scored K marks, meaning she answered K questions correctly and (N - K) questions incorrectly.
 * Bob marked the opposite of Alice for every question.
 * 
 * If Alice answered a question correctly, Bob answered it incorrectly.
 * If Alice answered a question incorrectly, Bob answered it correctly.
 * 
 * Therefore, the number of questions Bob answered correctly is equal to the number of 
 * questions Alice answered incorrectly.
 * 
 * Bob's score = N - K.
 * 
 * Constraints:
 * T <= 2000, N <= 100, 0 <= K <= N.
 * The logic N - K fits within standard integer types.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        // Bob's score is the number of questions Alice got wrong
        long long bobs_score = n - k;
        
        cout << bobs_score << "\n";
    }
    
    return 0;
}