#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        int k;
        std::cin >> n >> k;

        // The grid values are A[i][j] = i + N * (j - 1) for 1 <= i, j <= N.
        // We start at (1, 1) and want to reach (N, N).
        // We can only move down (i+1, j) or right (i, j+1).
        // Any path from (1, 1) to (N, N) will consist of (N-1) down moves and (N-1) right moves,
        // for a total of 2*(N-1) moves. The total number of cells visited is 2*(N-1) + 1.

        // Let's analyze the parity of the grid values.
        // A[i][j] = i + N * (j - 1)
        // Parity of A[i][j] depends on parity of i, N, and (j-1).

        // Case 1: N is odd.
        // If N is odd, then N * (j - 1) has the same parity as (j - 1).
        // So, A[i][j] = i + (j - 1) (mod 2).
        // The sum of parities along any path:
        // Sum(A[i][j]) mod 2 = Sum(i + j - 1) mod 2
        // Consider a path. Let it visit cells (r_1, c_1), (r_2, c_2), ..., (r_m, c_m)
        // where m = 2*(N-1) + 1.
        // The sum of values is Sum_{p=1 to m} (r_p + N * (c_p - 1)).
        // Modulo 2, this is Sum_{p=1 to m} (r_p + N * (c_p - 1)) mod 2.
        // If N is odd, N mod 2 = 1.
        // Sum mod 2 = Sum_{p=1 to m} (r_p + c_p - 1) mod 2.

        // Let's consider the parity of the sum of coordinates (i+j) for cells visited.
        // When moving from (i, j) to (i+1, j), the sum (i+j) changes to (i+1+j) = (i+j)+1. Parity flips.
        // When moving from (i, j) to (i, j+1), the sum (i+j) changes to (i+j+1) = (i+j)+1. Parity flips.
        // So, each step flips the parity of (i+j).
        // The path starts at (1, 1), where i+j = 2 (even).
        // After 1 step, i+j is odd. After 2 steps, i+j is even.
        // After `s` steps, the parity of i+j is the parity of `s`.
        // The total number of steps is 2*(N-1).
        // So, at (N, N), the parity of N+N is the parity of 2*(N-1), which is always even.

        // Let's look at the parity of A[i][j] = i + N*(j-1).
        // If N is odd: A[i][j] mod 2 = (i + j - 1) mod 2.
        // The sum of parities along a path: Sum(A[i][j]) mod 2 = Sum(i + j - 1) mod 2.
        // This is equivalent to Sum(i+j) - Sum(1) mod 2.
        // Sum(1) is the number of cells, which is 2N-1.
        // So, Sum mod 2 = Sum(i+j) - (2N-1) mod 2 = Sum(i+j) - 1 mod 2.
        // The parity of Sum(i+j) along any path from (1,1) to (N,N) is the parity of the number of steps, which is 2(N-1) (even).
        // So, Sum(i+j) is always even.
        // Therefore, if N is odd, the path sum parity is (even - 1) mod 2 = 1 (odd).
        // This means if N is odd, any path will have an odd score.
        // So, if N is odd, we can achieve K=1, but not K=0.

        // Case 2: N is even.
        // If N is even, then N * (j - 1) is always even.
        // So, A[i][j] mod 2 = i mod 2.
        // The parity of A[i][j] is just the parity of i.
        // The sum of parities along any path: Sum(A[i][j]) mod 2 = Sum(i) mod 2.
        // We need to find if there's a path such that Sum(i) mod 2 = K.

        // Consider two extreme paths when N is even:
        // Path 1: Go all the way right, then all the way down.
        // Cells: (1,1), (1,2), ..., (1,N), (2,N), (3,N), ..., (N,N).
        // The 'i' values are: 1 (N times), then 2, 3, ..., N.
        // Sum(i) mod 2 = (N * 1 + Sum_{i=2 to N} i) mod 2.
        // Since N is even, N*1 is even.
        // Sum(i) mod 2 = (Sum_{i=2 to N} i) mod 2.
        // Sum_{i=1 to N} i = N*(N+1)/2.
        // Sum_{i=2 to N} i = N*(N+1)/2 - 1.
        // If N is even, N+1 is odd. N/2 is an integer.
        // N*(N+1)/2 = (N/2) * (N+1).
        // If N/2 is even, then N*(N+1)/2 is even.
        // If N/2 is odd, then N*(N+1)/2 is odd.
        // This is equivalent to checking parity of N/2.
        // N = 2, N/2 = 1 (odd). N*(N+1)/2 = 2*3/2 = 3 (odd).
        // N = 4, N/2 = 2 (even). N*(N+1)/2 = 4*5/2 = 10 (even).
        // N = 6, N/2 = 3 (odd). N*(N+1)/2 = 6*7/2 = 21 (odd).
        // So, N*(N+1)/2 is odd if N/2 is odd, and even if N/2 is even.
        // This means N*(N+1)/2 has the same parity as N/2.
        // Sum_{i=2 to N} i = N*(N+1)/2 - 1.
        // Parity of Sum_{i=2 to N} i = (N/2 mod 2) - 1 mod 2.
        // If N/2 is even, parity is 0 - 1 = -1 = 1 (odd).
        // If N/2 is odd, parity is 1 - 1 = 0 (even).

        // Let's re-evaluate Sum(i) mod 2 for Path 1.
        // Cells: (1,1), (1,2), ..., (1,N), (2,N), (3,N), ..., (N,N).
        // i values: 1 (N times), 2, 3, ..., N.
        // Sum(i) mod 2 = (N * 1 + 2 + 3 + ... + N) mod 2.
        // Since N is even, N * 1 is even.
        // Sum(i) mod 2 = (2 + 3 + ... + N) mod 2.
        // Sum_{i=1 to N} i = N(N+1)/2.
        // Sum_{i=2 to N} i = N(N+1)/2 - 1.
        // Since N is even, N(N+1)/2 is even if N/2 is even, and odd if N/2 is odd.
        // Parity of N(N+1)/2 is parity of N/2.
        // So, parity of Sum_{i=2 to N} i = (parity of N/2) - 1 mod 2.
        // If N/2 is even (e.g., N=4, 8, 12...), parity is 0 - 1 = 1 (odd).
        // If N/2 is odd (e.g., N=2, 6, 10...), parity is 1 - 1 = 0 (even).

        // Path 2: Go all the way down, then all the way right.
        // Cells: (1,1), (2,1), ..., (N,1), (N,2), ..., (N,N).
        // The 'i' values are: 1, 2, ..., N, N (N-1 times).
        // Sum(i) mod 2 = (Sum_{i=1 to N} i + (N-1) * N) mod 2.
        // Since N is even, (N-1)*N is even.
        // Sum(i) mod 2 = (Sum_{i=1 to N} i) mod 2.
        // Parity of Sum_{i=1 to N} i is parity of N/2.
        // So, for Path 2, the sum parity is parity of N/2.

        // If N is even:
        // Path 1 (right then down): Sum parity is (parity of N/2) - 1 mod 2.
        // Path 2 (down then right): Sum parity is (parity of N/2) mod 2.

        // Let P = parity of N/2.
        // Path 1 parity: (P - 1) mod 2.
        // Path 2 parity: P mod 2.

        // If P = 0 (N/2 is even, e.g., N=4, 8, ...):
        // Path 1 parity: (0 - 1) mod 2 = 1 (odd).
        // Path 2 parity: 0 mod 2 = 0 (even).
        // So, if N/2 is even, we can achieve both K=0 and K=1.

        // If P = 1 (N/2 is odd, e.g., N=2, 6, ...):
        // Path 1 parity: (1 - 1) mod 2 = 0 (even).
        // Path 2 parity: 1 mod 2 = 1 (odd).
        // So, if N/2 is odd, we can achieve both K=0 and K=1.

        // Conclusion for N is even:
        // Regardless of whether N/2 is even or odd, we can achieve both parities.
        // This means if N is even, we can always achieve K=0 and K=1.

        // Summary:
        // If N is odd: Only K=1 is possible. If K=0, output NO. If K=1, output YES.
        // If N is even: Both K=0 and K=1 are possible. Always output YES.

        if (n % 2 != 0) { // N is odd
            if (k == 0) {
                std::cout << "No\n";
            } else { // k == 1
                std::cout << "Yes\n";
            }
        } else { // N is even
            std::cout << "Yes\n";
        }
    }
    return 0;
}