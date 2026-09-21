#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        // The playlist consists of songs A, B, C, each of duration X.
        // The total duration of one cycle of the playlist (A -> B -> C) is 3 * X.
        // Chef listens to song C completely if the total journey time N is
        // at least enough to finish song C.
        // The songs are played in the order A, B, C, A, B, C, ...
        // Song C is the third song in the cycle.
        // To listen to song C completely for the k-th time, the journey must have
        // completed k full cycles (A, B, C) and then listened to song C for X minutes.
        // This means the total time elapsed must be at least (k-1) * 3 * X + 2 * X + X = k * 3 * X.
        // However, we are interested in how many times song C is listened to *completely*.
        //
        // Let's analyze the sequence of songs and their completion times:
        // Song A: starts at 0, ends at X
        // Song B: starts at X, ends at 2*X
        // Song C: starts at 2*X, ends at 3*X
        // Song A: starts at 3*X, ends at 4*X
        // Song B: starts at 4*X, ends at 5*X
        // Song C: starts at 5*X, ends at 6*X
        // ...
        // Song C is completed at times 3*X, 6*X, 9*X, ... , k * 3 * X.
        //
        // For song C to be listened to completely for the k-th time, the journey duration N
        // must be greater than or equal to the completion time of the k-th C song.
        // The completion time of the k-th C song is k * 3 * X.
        // So, we need N >= k * 3 * X.
        // This implies k <= N / (3 * X).
        // Since k must be an integer, the maximum number of times C is listened to completely
        // is floor(N / (3 * X)).
        //
        // Example 1: N=6, X=1. 3*X = 3. N/(3*X) = 6/3 = 2. Output: 2. Correct.
        // Example 2: N=5, X=1. 3*X = 3. N/(3*X) = 5/3 = 1.66... floor is 1. Output: 1. Correct.
        // Example 3: N=11, X=2. 3*X = 6. N/(3*X) = 11/6 = 1.83... floor is 1. Output: 1. Correct.
        // Example 4: N=5, X=8. 3*X = 24. N/(3*X) = 5/24 = 0.2... floor is 0. Output: 0. Correct.
        // Example 5: N=100, X=9. 3*X = 27. N/(3*X) = 100/27 = 3.7... floor is 3. Output: 3. Correct.

        // The total duration of one full cycle (A, B, C) is 3 * X.
        // We need to find how many full cycles of (A, B, C) can be completed,
        // and then check if song C is completed within the remaining time.
        //
        // A simpler way:
        // The songs are A, B, C, A, B, C, ...
        // Each song has duration X.
        // The sequence of song completions is:
        // A completes at X
        // B completes at 2*X
        // C completes at 3*X
        // A completes at 4*X
        // B completes at 5*X
        // C completes at 6*X
        // ...
        // Song C is completed at times 3*X, 6*X, 9*X, ..., k * 3 * X.
        //
        // We want to find the maximum integer k such that k * 3 * X <= N.
        // This is equivalent to k <= N / (3 * X).
        // The maximum integer k is floor(N / (3 * X)).

        // Integer division in C++ automatically performs floor for positive numbers.
        int num_c_completed = n / (3 * x);
        std::cout << num_c_completed << "\n";
    }
    return 0;
}