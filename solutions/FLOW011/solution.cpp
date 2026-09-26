#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        double basic_salary;
        cin >> basic_salary;

        double hra, da;

        if (basic_salary < 1500) {
            hra = 0.10 * basic_salary;
            da = 0.90 * basic_salary;
        } else {
            hra = 500;
            da = 0.98 * basic_salary;
        }

        double gross_salary = basic_salary + hra + da;
        cout << fixed << setprecision(2) << gross_salary << "\n";
    }

    return 0;
}