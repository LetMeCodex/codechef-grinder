#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies multiple test cases are not present,
    // as it doesn't specify a number of test cases 't'.
    // If there were multiple test cases, the structure would be:
    // int t;
    // cin >> t;
    // while (t--) {
    //     // ... solve one test case ...
    // }
    // Given the constraints and problem type, it's a single test case.

    long long a, b, c;
    cin >> a >> b >> c;

    // To find the second largest among three distinct numbers,
    // we can sort them and pick the middle element.
    // Since the numbers are distinct, we don't need to worry about duplicates.

    // Method 1: Using std::sort
    // vector<long long> nums = {a, b, c};
    // sort(nums.begin(), nums.end());
    // cout << nums[1] << "\n";

    // Method 2: Using conditional logic (more efficient for just 3 numbers)
    // The largest number is max(a, b, c).
    // The smallest number is min(a, b, c).
    // The sum of the three numbers is a + b + c.
    // The second largest number is (a + b + c) - max(a, b, c) - min(a, b, c).

    long long largest = max({a, b, c});
    long long smallest = min({a, b, c});
    long long second_largest = (a + b + c) - largest - smallest;

    cout << second_largest << "\n";

    return 0;
}