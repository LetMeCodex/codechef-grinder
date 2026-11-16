#include <iostream> // Required for standard input/output operations (cin, cout)

// Using namespace std; is common in competitive programming to avoid
// repeatedly typing std::
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the size of the arrays A and B

    int count_ones = 0; // Initialize a counter for elements in B that are 1
    for (int i = 0; i < N; ++i) {
        int B_i;
        cin >> B_i; // Read each element of the parity encoding array B
        if (B_i == 1) {
            count_ones++; // If B_i is 1, increment the counter
        }
    }

    // The core logic:
    // The sum of frequencies of all elements in A must be N.
    // That is, sum(freq(k) for k=1 to N) = N.
    // Taking this equation modulo 2:
    // sum(freq(k) mod 2 for k=1 to N) mod 2 = N mod 2.
    // By definition, freq(k) mod 2 = B_k.
    // So, sum(B_k for k=1 to N) mod 2 = N mod 2.
    // The sum(B_k) is simply count_ones.
    // Therefore, count_ones mod 2 must be equal to N mod 2.
    // If this condition holds, we can always construct a valid array A.
    // (For example, assign freq(k)=1 if B_k=1, freq(k)=0 if B_k=0.
    // The sum of these initial frequencies is count_ones.
    // The remaining N - count_ones elements must be added.
    // Since N and count_ones have the same parity, N - count_ones is even.
    // We can add (N - count_ones)/2 pairs of any element (e.g., '1's)
    // to A. Adding a pair of '1's increases freq(1) by 2, preserving its parity.
    // This way, all parities are maintained, and the total length becomes N.)
    
    if (count_ones % 2 == N % 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is crucial for competitive programming problems with large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}