#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, m, b;
    cin >> n >> a >> m >> b;

    // Cost of buying N trees
    long long cost = (long long)n * a;

    // Revenue from selling M trees
    long long revenue = (long long)m * b;

    // Profit is revenue - cost
    long long profit = revenue - cost;

    cout << profit << "\n";

    return 0;
}