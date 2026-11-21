#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void solve() {
    std::string A;
    std::cin >> A;
    int N = A.length();

    std::string ans_W = ""; // Stores the current smallest W found

    // --- Candidate 1: Insert '1' at the beginning of A ---
    // W = "1" + A
    // For '1' to be the deleted digit, it must be the first W[k] such that W[k] < W[k+1].
    // Here, k=0. So W[0] must be < W[1].
    // W[0] is '1', W[1] is A[0].
    // So, '1' < A[0] must hold.
    // Also, W[0] cannot be '0' (satisfied by '1').
    if (A[0] > '1') {
        ans_W = "1" + A; // This is an O(N) operation. Done once.
    }

    // --- Candidate 2: Insert '0' at some position k (from 1 to N) ---
    // We want the smallest W, so we try to insert '0' as early as possible.
    // Iterate k from 1 to N (insertion position).
    // W = A[0...k-1] + '0' + A[k...N-1]
    // Conditions for '0' to be the deleted digit:
    // 1. W[0] >= W[1] >= ... >= W[k-1] (i.e., A[0] >= A[1] >= ... >= A[k-1])
    // 2. W[k-1] >= W[k] (i.e., A[k-1] >= '0', always true)
    // 3. W[k] < W[k+1] (i.e., '0' < A[k], if k < N)
    // 4. If k=N (insert '0' at end), then W must be non-increasing: A[0] >= ... >= A[N-1] >= '0'.
    //    In this case, the last digit '0' is deleted.

    int best_k_for_zero = -1; // Stores the optimal insertion position for '0'
    bool prefix_non_increasing = true; // Tracks if A[0...j] is non-increasing

    for (int k = 1; k <= N; ++k) { // k is the 0-indexed position where '0' is inserted
        // Check prefix A[0...k-1] for non-increasing property
        if (k > 1 && A[k-2] < A[k-1]) { 
            prefix_non_increasing = false;
        }

        if (prefix_non_increasing) {
            bool current_k_is_valid = false;
            if (k < N) { // Insert '0' in the middle, before A[k]
                if (A[k] > '0') { // Condition '0' < A[k]
                    current_k_is_valid = true;
                }
            } else { // k == N, insert '0' at the end of A
                // Condition A[N-1] >= '0' is always true.
                // The prefix_non_increasing check up to A[N-1] covers A[0] >= ... >= A[N-1].
                current_k_is_valid = true;
            }

            if (current_k_is_valid) {
                best_k_for_zero = k;
                break; // Found the earliest valid position for '0', so this gives the smallest W of this type.
            }
        } else {
            break; // Prefix is no longer non-increasing, no further k will work.
        }
    }

    if (best_k_for_zero != -1) {
        // Construct the W string for the best '0' insertion *once*
        std::string W_cand2_str;
        W_cand2_str.reserve(N + 1); // Pre-allocate memory for efficiency
        for (int i = 0; i < best_k_for_zero; ++i) {
            W_cand2_str += A[i];
        }
        W_cand2_str += '0';
        for (int i = best_k_for_zero; i < N; ++i) {
            W_cand2_str += A[i];
        }
        
        // Compare with ans_W and update if W_cand2_str is smaller
        if (ans_W == "" || W_cand2_str < ans_W) {
            ans_W = W_cand2_str;
        }
    }
    
    std::cout << ans_W << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}