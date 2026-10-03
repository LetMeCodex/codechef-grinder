#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    // Initial position is (0, 0)
    long long final_x = 0;
    long long final_y = 0;

    // Move A units along positive X axis
    final_x += a;

    // Move B units along positive Y axis
    final_y += b;

    // Move C units along negative X axis
    final_x -= c;

    // Move D units along negative Y axis
    final_y -= d;

    cout << final_x << " " << final_y << "\n";

    return 0;
}