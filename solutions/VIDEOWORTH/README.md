# [Worth of a Video (VIDEOWORTH)](https://www.codechef.com/problems/VIDEOWORTH)
- **Difficulty Rating**: 382
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the "worth" of a video given its duration in seconds. The worth is defined by a specific formula: a video has 24 frames per second, and each frame is worth 1000 words. Therefore, the total worth of a video with duration $S$ seconds is $(24 \times S \times 1000)$ words. We need to read the number of test cases $T$, and for each test case, read the duration $S$ and print the calculated worth.

## Intuition & Mathematical Observation
The problem statement directly provides the formula for calculating the worth of a video.
Let $S$ be the duration of the video in seconds.
The number of frames per second is given as 24.
The total number of frames in the video is therefore $24 \times S$.
Each frame is worth 1000 words.
So, the total worth of the video in words is $(24 \times S) \times 1000$.

The constraints on $S$ are $1 \le S \le 100$.
Let's consider the maximum possible value for $S$:
If $S = 100$, the total worth would be $24 \times 100 \times 1000 = 2400 \times 1000 = 2,400,000$.
This value fits within a standard 32-bit signed integer type (which typically ranges up to $2 \times 10^9$). However, to be safe and follow good competitive programming practices, using a `long long` for the result is advisable to prevent potential overflow issues if the constraints were slightly larger or if intermediate calculations could exceed the `int` limit. The cast `(long long)24` ensures that the entire multiplication is performed using `long long` arithmetic.

The core of the solution is a direct application of this formula within a loop that iterates through the given test cases.

## Complexity Analysis
- **Time Complexity**: $O(T)$
  The program reads the number of test cases $T$. For each test case, it performs a constant number of arithmetic operations (multiplication) and input/output operations. Therefore, the total time complexity is directly proportional to the number of test cases, $T$.

- **Space Complexity**: $O(1)$
  The program uses a fixed amount of memory to store variables like $T$, $S$, and `total_worth`, regardless of the input size. Thus, the space complexity is constant.

## Solution Code
```cpp
#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Uses the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further improving performance.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int S; // Declare an integer variable S for the duration of the video in seconds.
        cin >> S; // Read the duration S for the current test case.

        // Calculate the total worth of the video in words.
        // The problem states:
        // 1. A video has 24 frames (pictures) per second.
        // 2. The video has a duration of S seconds.
        //    So, total frames = 24 * S.
        // 3. Each frame is worth 1000 words.
        //    So, total worth = (total frames) * 1000.
        // Combining these: total worth = (24 * S) * 1000 words.

        // Constraints: 1 <= S <= 100.
        // Maximum possible value for S is 100.
        // Max total worth = (24 * 100) * 1000 = 2400 * 1000 = 2,400,000.
        // This value fits comfortably within a standard 32-bit integer type (like 'int' in C++,
        // which typically handles values up to 2 * 10^9).
        // However, using 'long long' for the result is a good practice in competitive programming
        // to prevent potential overflow issues, especially if constraints were larger.
        long long total_worth = (long long)24 * S * 1000; 
        // We cast 24 to long long to ensure the entire multiplication is performed using
        // long long arithmetic, although for these specific constraints, 'int' would suffice.

        // Output the calculated total worth, followed by a newline character.
        cout << total_worth << "\n";
    }

    return 0; // Indicate successful program execution.
}
```