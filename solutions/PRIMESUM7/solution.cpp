#include <bits/stdc++.h> // Required header as per problem instructions

using namespace std; // Required as per problem instructions

void solve() {
    int N;
    cin >> N; // Read the length of the array

    // Initialize counters for each possible value (1, 2, 3)
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;

    // Read N integers and count their occurrences
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 1) {
            count1++;
        } else if (val == 2) {
            count2++;
        } else { // val must be 3, as per constraints 1 <= A_i <= 3
            count3++;
        }
    }

    // Variable to store the total number of pairs with prime sums.
    // Using long long for 'ans' is a safe practice, though for N <= 100,
    // the maximum possible count (around 9950) would fit in an int.
    long long ans = 0;

    // Calculate pairs that sum to a prime number:
    // Possible sums:
    // 1+1 = 2 (prime)
    // 1+2 = 3 (prime)
    // 1+3 = 4 (not prime)
    // 2+2 = 4 (not prime)
    // 2+3 = 5 (prime)
    // 3+3 = 6 (not prime)

    // 1. Pairs of (1, 1): sum is 2 (prime)
    // Number of ways to choose 2 ones from 'count1' ones is count1 * (count1 - 1) / 2
    // Cast to long long before multiplication to prevent potential overflow if counts were larger,
    // though for N=100, int is sufficient for intermediate products.
    ans += (long long)count1 * (count1 - 1) / 2;

    // 2. Pairs of (1, 2): sum is 3 (prime)
    // Number of ways to choose one 1 and one 2 is count1 * count2
    ans += (long long)count1 * count2;

    // 3. Pairs of (2, 3): sum is 5 (prime)
    // Number of ways to choose one 2 and one 3 is count2 * count3
    ans += (long long)count2 * count3;

    // Output the total count for the current test case
    cout << ans << "\n";
}

int main() {
    // Enable fast I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}