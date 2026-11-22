#include <iostream>
#include <vector>
#include <numeric> // Not strictly needed, but often useful.

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    if (N == 1) {
        // Case 1: N = 1.
        // If A = [0], Score(A) = 0. C = [1], Score(C) = 0.
        // If A = [1], Score(A) = 0. C = [0], Score(C) = 0.
        std::cout << 1 - A[0] << "\n";
        return;
    }

    // Case 2: N > 1
    
    // Check if all elements of A are the same.
    bool all_same = true;
    for (int i = 1; i < N; ++i) {
        if (A[i] != A[0]) {
            all_same = false;
            break;
        }
    }

    if (all_same) {
        // Subcase 2.1: All elements are the same (e.g., [0,0,0]). Score(A) = 0.
        // Flip all elements to get C (e.g., [1,1,1]). Score(C) = 0.
        // C is different from A. This works.
        for (int i = 0; i < N; ++i) {
            std::cout << 1 - A[i] << (i == N - 1 ? "" : " ");
        }
        std::cout << "\n";
    } else {
        // A is not all same. Score(A) > 0.
        
        // Check if A is perfectly alternating (e.g., [0,1,0,1] or [1,0,1,0]).
        bool alternating = true;
        for (int i = 0; i < N - 1; ++i) {
            if (A[i] == A[i+1]) { // If any adjacent elements are same, it's not alternating.
                alternating = false;
                break;
            }
        }

        if (alternating) {
            // Subcase 2.2: A is perfectly alternating (e.g., [0,1,0,1]). Score(A) = N-1.
            // Flip all elements to get C (e.g., [1,0,1,0]). Score(C) = N-1.
            // C is different from A. This works.
            for (int i = 0; i < N; ++i) {
                std::cout << 1 - A[i] << (i == N - 1 ? "" : " ");
            }
            std::cout << "\n";
        } else {
            // Subcase 2.3: A is neither all same nor perfectly alternating.
            // This implies N >= 3. (For N=2, not all same implies alternating).
            // In this case, there must exist an index k (1 <= k <= N-2)
            // such that flipping A[k] results in a score change of 0.
            // This happens if (A[k-1] == A[k]) != (A[k] == A[k+1]).
            // Example: A = [0,0,1,1]. Score(A)=1.
            // For k=1: A[0]=0, A[1]=0, A[2]=1. (A[0]==A[1]) is true. (A[1]==A[2]) is false.
            // true != false is true. So flip A[1]. C = [0,1,1,1]. Score(C)=1.
            
            std::vector<int> C = A;
            int flip_idx = -1;
            for (int k = 1; k < N - 1; ++k) {
                // Check if (A[k-1] == A[k]) is different from (A[k] == A[k+1])
                if ((A[k-1] == A[k]) != (A[k] == A[k+1])) {
                    flip_idx = k;
                    break;
                }
            }
            // Such a flip_idx is guaranteed to exist in this subcase.
            C[flip_idx] = 1 - C[flip_idx];

            for (int i = 0; i < N; ++i) {
                std::cout << C[i] << (i == N - 1 ? "" : " ");
            }
            std::cout << "\n";
        }
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}