#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b;
    std::cin >> a >> b;

    int diff = a - b;
    std::string diff_str = std::to_string(diff);
    std::string result_str = diff_str;

    // Try to change the first digit
    if (diff_str[0] == '1') {
        result_str[0] = '2';
    } else {
        result_str[0] = '1';
    }

    // Check if the modified result is positive and has the same number of digits
    // The problem statement guarantees that A and B are such that A-B will have at least one digit.
    // The constraints 1 <= B and A-B can be negative.
    // However, the problem statement implies the correct answer is positive, and the wrong answer must be positive.
    // If A-B is negative, we need to make it positive with one digit change.
    // The simplest way to guarantee a positive answer with one digit change is to change the first digit.
    // If the first digit is '1', changing it to '2' will keep it positive and same length.
    // If the first digit is not '1', changing it to '1' will keep it positive and same length.
    // This strategy works because the smallest possible positive answer with one digit change from a negative number
    // would involve changing the sign or a leading digit.
    // Given the sample and constraints, it's likely A-B is intended to be positive or we need to produce a positive output.
    // The problem states "Your answer must be a *positive* integer".
    // If diff is negative, e.g., -123, changing -1 to -2 gives -223 (still negative).
    // Changing -1 to 1 gives 123. This is a valid positive answer.
    // If diff is -987, changing -9 to -8 gives -887.
    // Changing -9 to 1 gives 187. This is a valid positive answer.
    // So, changing the first digit to '1' or '2' is a robust strategy to ensure positivity and same length.

    // If the initial difference was negative, and changing the first digit to '1' or '2'
    // resulted in a number that is still negative (e.g., if the original was -1 and we change to 2, it's 2, which is positive)
    // or if the original was -10 and we change to 20, it's 20, which is positive.
    // The only case where changing the first digit might lead to a non-positive number is if the original was 0,
    // but A-B cannot be 0 if A != B. If A=B, diff is 0. Changing 0 to 1 gives 1.
    // The problem statement says "Your answer must be a *positive* integer".
    // If the correct answer is negative, we must produce a positive answer.
    // The simplest way to ensure a positive answer with one digit change is to target the first digit.
    // If the first digit is '1', change it to '2'.
    // If the first digit is anything else (including '-'), change it to '1'.
    // This will always result in a positive number with the same number of digits.

    if (diff_str[0] == '1') {
        result_str[0] = '2';
    } else {
        result_str[0] = '1';
    }

    std::cout << result_str << "\n";

    return 0;
}