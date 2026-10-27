#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    cin >> x;

    // Chef needs at least 25 Grand Slams to break the record.
    // Let 'y' be the number of years.
    // In 'y' years, Chef wins 4 * y Grand Slams.
    // Total slams after 'y' years will be x + 4 * y.
    // We need x + 4 * y >= 25.
    // This means 4 * y >= 25 - x.
    // So, y >= (25 - x) / 4.

    // Since 'y' must be an integer, we need to find the smallest integer 'y'
    // that satisfies the inequality.
    // This can be calculated using the ceiling division: ceil((25 - x) / 4.0).
    // In integer arithmetic, ceil(a/b) for positive b is (a + b - 1) / b.
    // Here, a = 25 - x and b = 4.

    int needed_slams = 25;
    int slams_to_win = needed_slams - x;

    // If slams_to_win is already less than or equal to 0, it means Chef
    // has already broken or met the record, so 0 years are needed.
    // However, the problem implies Chef needs to *break* the record,
    // and the constraints are 0 <= X <= 24, so slams_to_win will always be positive.

    // Calculate minimum years using ceiling division.
    // (slams_to_win + 4 - 1) / 4
    int years = (slams_to_win + 3) / 4;

    cout << years << "\n";

    return 0;
}