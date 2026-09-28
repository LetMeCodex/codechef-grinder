#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies multiple test cases, but the sample
    // input/output only shows one. Assuming it's a single test case based on
    // typical competitive programming problem structures where if multiple
    // test cases are expected, the problem statement or sample would indicate it.
    // If multiple test cases were intended, a loop like `int t; cin >> t; while(t--)`
    // would be needed. Given the constraints and problem type, a single test case
    // is more likely.

    int X, N;
    cin >> X >> N;

    // Cost of one laddu is Rs. 10
    // Cost of one jalebi is Rs. 20

    // Money spent on laddus
    int money_spent_on_laddus = N * 10;

    // Remaining money after buying laddus
    int remaining_money = X - money_spent_on_laddus;

    // Number of jalebis Sushil can buy with the remaining money
    // Integer division automatically handles the floor, which is what we need.
    int num_jalebis = remaining_money / 20;

    cout << num_jalebis << "\n";

    return 0;
}