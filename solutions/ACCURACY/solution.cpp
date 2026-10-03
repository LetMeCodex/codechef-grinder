#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        // Let 'c' be the number of correct answers, 'i' be the number of incorrect answers,
        // and 'u' be the number of unattempted questions.
        // We know that c + i + u = 100 (total questions).
        // The total score is given by 3*c - 1*i + 0*u = x.
        // So, 3*c - i = x.

        // We want to minimize 'i'.
        // From 3*c - i = x, we have i = 3*c - x.
        // To minimize 'i', we need to minimize 'c' such that 'i' is non-negative and
        // c + i <= 100 (since 'u' must be non-negative).

        // Substitute i = 3*c - x into c + i <= 100:
        // c + (3*c - x) <= 100
        // 4*c - x <= 100
        // 4*c <= 100 + x
        // c <= (100 + x) / 4

        // Also, we need i >= 0, which means 3*c - x >= 0, so 3*c >= x, or c >= x/3.
        // Since 'c' must be an integer, c >= ceil(x/3.0).

        // We also know that the maximum possible score is 100 * 3 = 300.
        // The minimum possible score is 100 * -1 = -100.
        // The problem states 0 <= X <= 100, so these bounds are fine.

        // The number of correct answers 'c' must be such that 3*c is at least 'x'
        // (to make i non-negative).
        // The smallest possible value for 'c' that satisfies 3*c >= x is ceil(x/3.0).
        // However, we are looking for the minimum number of incorrect answers.
        // The equation is 3*c - i = x.
        // We want to find the smallest non-negative integer 'i' such that there exists
        // a non-negative integer 'c' and a non-negative integer 'u' satisfying:
        // 1. c + i + u = 100
        // 2. 3*c - i = x

        // From (2), c = (x + i) / 3.
        // For 'c' to be an integer, (x + i) must be divisible by 3.
        // Also, c >= 0, which is true if x + i >= 0. Since x >= 0 and i >= 0, this is always true.

        // Substitute c into (1):
        // (x + i) / 3 + i + u = 100
        // (x + i) + 3*i + 3*u = 300
        // x + 4*i + 3*u = 300
        // 3*u = 300 - x - 4*i

        // For 'u' to be a non-negative integer, we need:
        // a) 300 - x - 4*i >= 0  => 4*i <= 300 - x => i <= (300 - x) / 4
        // b) (300 - x - 4*i) must be divisible by 3.

        // We want to find the minimum non-negative integer 'i' that satisfies these conditions.
        // We can iterate through possible values of 'i' starting from 0.

        int min_incorrect = 0;
        for (int i = 0; i <= 100; ++i) { // 'i' cannot exceed 100 as there are only 100 questions
            // Check if (x + i) is divisible by 3. If so, we can find an integer 'c'.
            if ((x + i) % 3 == 0) {
                int c = (x + i) / 3;
                // Check if the number of correct answers 'c' is valid.
                // c must be non-negative (which is guaranteed since x>=0, i>=0).
                // The total number of questions used by correct and incorrect answers
                // must not exceed 100.
                if (c + i <= 100) {
                    min_incorrect = i;
                    break; // Found the minimum 'i'
                }
            }
        }
        cout << min_incorrect << "\n";
    }
    return 0;
}