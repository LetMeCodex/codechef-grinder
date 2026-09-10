#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If the number of students (n) is greater than the number of tickets (m),
        // then n - m students won't be able to book tickets.
        // Otherwise, if n <= m, all students can get tickets, so 0 students won't get tickets.
        if (n > m) {
            cout << n - m << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}