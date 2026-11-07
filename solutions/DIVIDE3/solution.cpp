#include <bits/stdc++.h> 

// Using namespace std; is requested by the problem statement.
using namespace std;

int main() {
    // Fast I/O is requested by the problem statement.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement's "Input Format" section specifies:
    // "The first and only line of input contains a single integer N - the number of toffees you had."
    // This indicates that there is only one test case.
    // The "Critical Instructions" mention handling multiple test cases "as requested by the problem statement",
    // but the input format itself does not request multiple test cases.
    // Therefore, we will process a single input N.

    int N;
    cin >> N; // Read the number of toffees

    // The goal is to minimize the imbalance, defined as (mx - mn),
    // where mx is the maximum toffees any friend received, and mn is the minimum.
    // We are dividing N toffees among 3 friends. Let the toffees received be a, b, c.
    // We must have a + b + c = N, and a, b, c >= 0 (or >= 1, given N >= 3).

    // To minimize the difference between the maximum and minimum, the numbers a, b, c
    // should be as close to each other as possible.

    // Case 1: N is perfectly divisible by 3 (N % 3 == 0)
    // If N is a multiple of 3, say N = 3k, we can give k toffees to each friend.
    // For example, if N=3, we give (1, 1, 1). mx=1, mn=1. Imbalance = 1-1 = 0.
    // For example, if N=6, we give (2, 2, 2). mx=2, mn=2. Imbalance = 2-2 = 0.
    // In this scenario, mx = mn = N/3, so the imbalance is 0.
    // An imbalance cannot be negative, so 0 is the minimum possible.

    // Case 2: N is not perfectly divisible by 3 (N % 3 != 0)
    // If N is not a multiple of 3, it's impossible to divide N into three equal integer parts.
    // This means that at least two friends must receive a different number of toffees.
    // Consequently, mx must be strictly greater than mn, implying that the imbalance (mx - mn)
    // must be at least 1.

    // Let's see if we can achieve an imbalance of 1:
    // If N % 3 == 1:
    // N can be written as 3k + 1 for some integer k.
    // We can distribute the toffees as (k+1, k, k).
    // For example, if N=4 (k=1), we give (2, 1, 1). mx=2, mn=1. Imbalance = 2-1 = 1.
    // For example, if N=7 (k=2), we give (3, 2, 2). mx=3, mn=2. Imbalance = 3-2 = 1.
    // In this case, mx = k+1 and mn = k, so the imbalance is (k+1) - k = 1.

    // If N % 3 == 2:
    // N can be written as 3k + 2 for some integer k.
    // We can distribute the toffees as (k+1, k+1, k).
    // For example, if N=5 (k=1), we give (2, 2, 1). mx=2, mn=1. Imbalance = 2-1 = 1.
    // For example, if N=8 (k=2), we give (3, 3, 2). mx=3, mn=2. Imbalance = 3-2 = 1.
    // In this case, mx = k+1 and mn = k, so the imbalance is (k+1) - k = 1.

    // Combining these observations:
    // If N % 3 == 0, the minimum imbalance is 0.
    // If N % 3 == 1 or N % 3 == 2, the minimum imbalance is 1.

    if (N % 3 == 0) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }

    return 0;
}