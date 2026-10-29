#include <cstdio> // Required for standard input/output operations (scanf/printf)

void solve() {
    long long N, M, X0, Y0, L;
    // Read the five space-separated integers for the current test case using scanf
    scanf("%lld %lld %lld %lld %lld", &N, &M, &X0, &Y0, &L);

    // Calculate the smallest reachable row coordinate (X_start)
    // This is the smallest number >= 1 that has the same remainder as X0 when divided by L.
    // (X0 - 1) % L gives a remainder in [0, L-1]. Adding 1 shifts it to [1, L].
    long long X_start = (X0 - 1) % L + 1;
    
    // Calculate the number of reachable rows.
    // The reachable rows form an arithmetic progression: X_start, X_start + L, X_start + 2L, ...
    // The largest term is X_start + k*L <= N.
    // The number of terms is k_max + 1, where k_max = (N - X_start) / L (integer division).
    long long count_rows = (N - X_start) / L + 1;

    // Perform the same calculation for column coordinates
    long long Y_start = (Y0 - 1) % L + 1;
    long long count_cols = (M - Y_start) / L + 1;

    // The total number of distinct reachable cells is the product of the number of reachable rows
    // and the number of reachable columns. This is because any combination of a reachable row
    // and a reachable column forms a reachable cell.
    long long total_reachable_cells = count_rows * count_cols;

    // Print the result for the current test case using printf, followed by a newline
    printf("%lld\n", total_reachable_cells);
}

int main() {
    // When using scanf/printf, std::ios_base::sync_with_stdio(false) and std::cin.tie(NULL) are not needed.
    
    int T;
    // Read the number of test cases
    scanf("%d", &T);
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0;
}