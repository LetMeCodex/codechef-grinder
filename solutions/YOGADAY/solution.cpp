#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Assuming the problem statement means only a single integer N is provided in total.
    int n;
    cin >> n;
    // Each Surya Namaskar consists of 12 yoga poses.
    // To find the number of completed rounds, we need to find
    // how many times 12 fits completely into N.
    // This is equivalent to integer division of N by 12.
    cout << n / 12 << "\n";
    return 0;
}