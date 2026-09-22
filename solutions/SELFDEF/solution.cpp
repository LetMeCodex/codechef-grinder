#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int eligible_count = 0;
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            if (age >= 10 && age <= 60) {
                eligible_count++;
            }
        }
        cout << eligible_count << "\n";
    }

    return 0;
}