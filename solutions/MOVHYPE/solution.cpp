#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        for (int i = 0; i <= n; ++i) {
            std::cin >> a[i];
        }

        int min_loudness = 101; // Constraints: 1 <= A_i <= 100

        // Chef can sit in empty seats: 2, 4, 6, ..., 2N
        // Seat 2 is between seat 1 and seat 3. Hype levels are A_1 and A_2.
        // Seat 4 is between seat 3 and seat 5. Hype levels are A_2 and A_3.
        // ...
        // Seat 2i is between seat 2i-1 and seat 2i+1. Hype levels are A_i and A_{i+1}.
        // This applies for i = 1, 2, ..., N.
        // The empty seats are 2, 4, ..., 2N.
        // The occupied seats are 1, 3, ..., 2N+1.
        // The hype levels A_1, A_2, ..., A_{N+1} correspond to seats 1, 3, ..., 2N+1.
        //
        // Seat 2 is between seat 1 (hype A_1) and seat 3 (hype A_2). Loudness = max(A_1, A_2).
        // Seat 4 is between seat 3 (hype A_2) and seat 5 (hype A_3). Loudness = max(A_2, A_3).
        // ...
        // Seat 2i is between seat 2i-1 (hype A_i) and seat 2i+1 (hype A_{i+1}). Loudness = max(A_i, A_{i+1}).
        // This is for i = 1, 2, ..., N.
        // The indices for A are 0-based in the vector, so A_i corresponds to a[i-1].
        //
        // Seat 2: between seat 1 (a[0]) and seat 3 (a[1]). Loudness = max(a[0], a[1]).
        // Seat 4: between seat 3 (a[1]) and seat 5 (a[2]). Loudness = max(a[1], a[2]).
        // ...
        // Seat 2i: between seat 2i-1 (a[i-1]) and seat 2i+1 (a[i]). Loudness = max(a[i-1], a[i]).
        // This is for i = 1, 2, ..., N.
        // The loop should go from i=1 to N.
        // The indices for a will be i-1 and i.
        // So, for i=1, we consider a[0] and a[1].
        // For i=N, we consider a[N-1] and a[N].

        for (int i = 0; i < n; ++i) {
            int current_loudness = std::max(a[i], a[i + 1]);
            min_loudness = std::min(min_loudness, current_loudness);
        }

        std::cout << min_loudness << "\n";
    }
    return 0;
}