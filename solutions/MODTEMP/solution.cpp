#include <bits/stdc++.h> // Includes all standard libraries, including iostream, vector, algorithm

using namespace std; // As requested by the problem statement

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Find the minimum and maximum temperatures among all N days.
    // std::min_element and std::max_element return iterators to the elements.
    // Dereference them to get the actual values.
    int min_temp = *min_element(A.begin(), A.end());
    int max_temp = *max_element(A.begin(), A.end());

    int liked_days_count = 0;
    // Iterate through the temperatures to count days that are neither the minimum nor the maximum.
    for (int i = 0; i < N; ++i) {
        if (A[i] != min_temp && A[i] != max_temp) {
            liked_days_count++;
        }
    }
    cout << liked_days_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common competitive programming optimization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) { // Loop T times for each test case
        solve();
    }

    return 0;
}