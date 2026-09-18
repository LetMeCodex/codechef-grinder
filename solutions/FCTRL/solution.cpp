#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The number of trailing zeros in N! is determined by the number of times 
 * the factor 10 appears in the prime factorization of N!.
 * Since 10 = 2 * 5, and there are always more factors of 2 than 5 in any 
 * factorial, the number of trailing zeros is equal to the number of times 
 * the factor 5 appears in the prime factorization of N!.
 * 
 * According to Legendre's Formula, the exponent of a prime p in the 
 * prime factorization of N! is given by:
 * E_p(N!) = floor(N/p) + floor(N/p^2) + floor(N/p^3) + ...
 * 
 * For p = 5:
 * Z(N) = floor(N/5) + floor(N/25) + floor(N/125) + ...
 * 
 * Complexity:
 * Each test case takes O(log_5(N)) time.
 * With T = 100,000 and N = 10^9, log_5(10^9) is approximately 13.
 * Total operations are roughly 1.3 million, which easily fits within the 8s time limit.
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;
    
    long long count = 0;
    // We divide n by powers of 5 to count the factors of 5
    while (n >= 5) {
        n /= 5;
        count += n;
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}