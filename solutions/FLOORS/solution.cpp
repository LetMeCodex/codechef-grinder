#include <bits/stdc++.h>
using namespace std;

int get_floor(int room_number) {
    return (room_number - 1) / 10 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int floor_x = get_floor(x);
        int floor_y = get_floor(y);

        cout << abs(floor_x - floor_y) << "\n";
    }

    return 0;
}