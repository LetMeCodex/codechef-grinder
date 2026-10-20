#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using the standard namespace as requested.
using namespace std; 

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // Calculate the size of the first range [A, B]
    // Number of integers in [P, Q] is Q - P + 1
    long long size1 = B - A + 1;

    // Calculate the size of the second range [C, D]
    long long size2 = D - C + 1;

    // Calculate the intersection of the two ranges.
    // The intersection range is [max(A, C), min(B, D)].
    // If max(A, C) > min(B, D), the intersection is empty.
    int intersect_start = max(A, C);
    int intersect_end = min(B, D);

    long long intersection_size = 0;
    if (intersect_start <= intersect_end) {
        intersection_size = intersect_end - intersect_start + 1;
    }

    // Using the principle of inclusion-exclusion:
    // |R1 U R2| = |R1| + |R2| - |R1 intersect R2|
    long long total_unique_integers = size1 + size2 - intersection_size;

    cout << total_unique_integers << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from C's stdio and prevents flushing cout before cin.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0;
}