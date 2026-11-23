#include <bits/stdc++.h> // Includes iostream, algorithm, etc.

// Using namespace std; as requested by the problem instructions
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the length of the array

    int count1 = 0; // Count of elements with value 1
    int count2 = 0; // Count of elements with value 2
    int count3 = 0; // Count of elements with value 3

    // Read array elements and count their occurrences
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

    int deletions = 0;

    // Condition for a "good" array: no two elements from different indices sum to 4.
    // The possible values for A_i are 1, 2, 3.
    // Let's analyze pairs that sum to 4:
    // 1. (1, 3): If both 1s and 3s are present in the array, any 1 and any 3 will sum to 4.
    //    To resolve this conflict, we must eliminate all 1s or all 3s.
    //    To minimize deletions, we choose to delete the group with fewer elements.
    //    The number of deletions for this conflict is min(count1, count3).
    deletions += min(count1, count3);

    // 2. (2, 2): If there are two or more 2s in the array, any pair of them will sum to 4.
    //    To resolve this conflict, we can keep at most one element of value 2.
    //    If count2 is 0 or 1, no deletions are needed for 2s.
    //    If count2 > 1, we must delete (count2 - 1) elements of value 2.
    //    The number of deletions for this conflict is max(0, count2 - 1).
    deletions += max(0, count2 - 1);

    // Output the total minimum deletions
    cout << deletions << "\n";
}

int main() {
    // Optimize C++ standard streams for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}