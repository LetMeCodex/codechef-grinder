#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        int s, x, y, z;
        std::cin >> s >> x >> y >> z;
        int current_used = x + y;
        int available_memory = s - current_used;

        if (available_memory >= z) {
            std::cout << 0 << "\n";
        } else {
            // Need to free up memory.
            // We have two apps, X and Y.
            // To install Z, we need to have at least Z MB free.
            // The total memory is S.
            // If we delete 0 apps, used memory is X+Y. Free is S-(X+Y). If S-(X+Y) < Z, we need to delete.
            // If we delete 1 app:
            //   - Delete X: used memory is Y. Free is S-Y. If S-Y >= Z, we can install.
            //   - Delete Y: used memory is X. Free is S-X. If S-X >= Z, we can install.
            // If we delete 2 apps:
            //   - Delete X and Y: used memory is 0. Free is S. If S >= Z, we can install.

            // We want the minimum number of deletions.
            // Check if deleting 1 app is enough.
            // To maximize free space after deleting 1 app, we should delete the larger app.
            // Let's assume X <= Y without loss of generality for checking deletion.
            // If we delete X, remaining space is S - Y.
            // If we delete Y, remaining space is S - X.
            // We need to check if S - std::min(x, y) >= z.
            // This is equivalent to checking if S - x >= z OR S - y >= z.
            // Since we want minimum deletions, we check if deleting 1 app is sufficient.
            // If we delete the app with size Y, remaining space is S - X.
            // If we delete the app with size X, remaining space is S - Y.
            // If either S - X >= Z or S - Y >= Z, then 1 deletion is enough.
            // This is equivalent to checking if S - std::min(X, Y) >= Z.
            // Or, more directly, if we delete the larger app (Y), we have S-X memory. If this is enough, 1 deletion.
            // If we delete the smaller app (X), we have S-Y memory. If this is enough, 1 deletion.
            // The condition for 1 deletion is: (S - Y >= Z) or (S - X >= Z).
            // This simplifies to: S - std::min(X, Y) >= Z.

            if (s - std::min(x, y) >= z) {
                std::cout << 1 << "\n";
            } else {
                // If deleting 1 app is not enough, we must delete both.
                // Deleting both apps leaves S memory. Since Z <= S is guaranteed,
                // deleting both apps will always be sufficient.
                std::cout << 2 << "\n";
            }
        }
    }
    return 0;
}