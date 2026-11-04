#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long p1, p2, k;
        std::cin >> p1 >> p2 >> k;
        long long total_points = p1 + p2;
        // The server changes every K points.
        // Chef serves for the first K points, then Cook for the next K, then Chef for the next K, and so on.
        // The number of full K-point intervals completed is total_points / K.
        // If total_points is a multiple of K, it means the current K-point interval has just finished.
        // The server changes *after* K points are scored.
        // So, if total_points is a multiple of K, the server has just changed.
        // The number of times the server has changed is (total_points / K).
        // Chef starts serving.
        // If the number of server changes is even, Chef is serving.
        // If the number of server changes is odd, Cook is serving.
        // However, the problem states "the player who serves would change every time after K points are scored".
        // This means the server changes *at the start* of the (K+1)-th point, (2K+1)-th point, etc.
        // So, if the total points scored is `total_points`, we are interested in the `(total_points + 1)`-th point.
        // The server changes after K points, 2K points, 3K points, etc.
        // This means the server changes at point K+1, 2K+1, 3K+1, ...
        // So, if `total_points` is `0, 1, ..., K-1`, Chef serves.
        // If `total_points` is `K, K+1, ..., 2K-1`, Cook serves.
        // If `total_points` is `2K, 2K+1, ..., 3K-1`, Chef serves.
        // This pattern repeats.
        // The server changes when `total_points` reaches `K`, `2K`, `3K`, etc.
        // The number of times the server has *completed* a K-point block is `total_points / K`.
        // If `total_points` is exactly `m * K`, then `m` blocks of K points have been completed.
        // The server changes after each block.
        // Chef serves for points 0 to K-1.
        // Cook serves for points K to 2K-1.
        // Chef serves for points 2K to 3K-1.
        // The server for the current `total_points` depends on which block `total_points` falls into.
        // The block index is `total_points / K`.
        // If `total_points / K` is even, Chef serves.
        // If `total_points / K` is odd, Cook serves.
        // This is equivalent to checking `(total_points / K) % 2`.
        // If `(total_points / K) % 2 == 0`, Chef serves.
        // If `(total_points / K) % 2 == 1`, Cook serves.

        if ((total_points / k) % 2 == 0) {
            std::cout << "CHEF\n";
        } else {
            std::cout << "COOK\n";
        }
    }
    return 0;
}