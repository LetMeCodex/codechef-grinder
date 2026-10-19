#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;

        int passed_exams = 0;
        if (x >= 50) {
            passed_exams++;
        }
        if (y >= 50) {
            passed_exams++;
        }
        if (z >= 50) {
            passed_exams++;
        }

        if (passed_exams >= 2) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}