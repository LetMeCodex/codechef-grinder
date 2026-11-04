# Lost Weekends (LOSTWKND)
- **Difficulty Rating**: 1063
- **Solved in**: 1 attempt(s)

## Problem Summary

Chef has 5 weekdays and needs to complete a certain amount of work. The work done on each weekday is represented by hours $A_1, A_2, A_3, A_4, A_5$. Chef also has a productivity factor $P$. The total work Chef needs to accomplish is equivalent to working $A_i$ hours on day $i$ multiplied by the productivity factor $P$. This means the total work required is $(A_1 + A_2 + A_3 + A_4 + A_5) \times P$.

Chef can work a maximum of 24 hours per day. The question is whether Chef can complete all the required work within the 5 weekdays, without needing to work on the weekend.

## Intuition & Mathematical Observation

The core of the problem lies in comparing the total work Chef *needs* to do with the total work Chef *can* do within the 5 weekdays.

1.  **Total Work Required:**
    The problem states that the work done on day $i$ is $A_i$, and this is scaled by a productivity factor $P$. Therefore, the total equivalent work Chef needs to accomplish is the sum of the hours worked each weekday, multiplied by $P$.
    Total Work Required = $(A_1 + A_2 + A_3 + A_4 + A_5) \times P$.

2.  **Total Work Possible within Weekdays:**
    Chef has 5 weekdays, and each day has 24 hours. So, the maximum number of hours Chef can work during these 5 weekdays is:
    Total Work Possible = $5 \times 24$ hours.

3.  **Decision Logic:**
    If the "Total Work Required" is *greater than* the "Total Work Possible within Weekdays", Chef will not be able to finish the work within the 5 weekdays and will have to work on the weekend. In this case, the answer is "Yes".
    Otherwise, if the "Total Work Required" is *less than or equal to* the "Total Work Possible within Weekdays", Chef can complete the work within the 5 weekdays. The answer is "No".

    Mathematically:
    If $(A_1 + A_2 + A_3 + A_4 + A_5) \times P > 5 \times 24$, output "Yes".
    Else, output "No".

The constraints on $A_i$ (0 to 24) and $P$ (1 to 24) are small enough that the total required hours will not overflow a standard 32-bit integer type. However, using `long long` for sums and products is a good practice in competitive programming to avoid potential overflow issues in general.

## Complexity Analysis

-   **Time Complexity**: $O(1)$ per test case.
    The solution involves reading 5 integers and 1 integer, performing a sum, a multiplication, and a comparison. These operations take a constant amount of time, regardless of the input values (within their specified constraints). Since the number of test cases $T$ is handled by a loop, the total time complexity for $T$ test cases is $O(T)$.

-   **Space Complexity**: $O(1)$ per test case.
    The solution uses a fixed number of variables to store the input values ($A_i$ and $P$) and intermediate calculations (total office hours, total home hours required, total available weekday hours). The amount of memory used does not grow with the input size, hence it's constant.

## Solution Code

```cpp
#include <iostream> // Required for standard input/output operations (cin, cout)

// The problem statement explicitly suggests `#include <bits/stdc++.h>`
// and `using namespace std;`.
// #include <bits/stdc++.h> 
using namespace std;

// The solve function encapsulates the logic for a single test case.
void solve() {
    // Declare an array to store the hours worked at the office for 5 weekdays.
    // A_i values are between 0 and 24.
    int A[5]; 
    // Declare a variable for the productivity factor P.
    // P is between 1 and 24.
    int P;    

    // Initialize a variable to accumulate the total hours worked at the office.
    // Using 'long long' is a safe practice for sums and products in competitive programming
    // to prevent potential integer overflow, even if 'int' might suffice for current constraints.
    // Max sum of A_i = 5 * 24 = 120.
    // Max total_home_hours_required = 120 * 24 = 2880.
    // Both fit within a 32-bit signed integer (max approx 2 * 10^9).
    // So, 'int' would technically be sufficient here, but 'long long' causes no harm.
    long long total_office_hours = 0; 

    // Read the 5 A_i values and sum them up.
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
        total_office_hours += A[i];
    }
    // Read the productivity factor P.
    cin >> P;

    // Calculate the total equivalent hours Chef needs to work from home.
    // This is the total office work multiplied by the productivity factor P.
    long long total_home_hours_required = total_office_hours * P;
    
    // Calculate the maximum total hours Chef can work during the 5 weekdays.
    // Each day has 24 hours.
    long long total_available_weekday_hours = 5 * 24; // This constant value is 120.

    // Compare the required home hours with the available weekday hours.
    // If required hours exceed available hours, Chef must work on weekends.
    if (total_home_hours_required > total_available_weekday_hours) {
        cout << "Yes\n"; // Output "Yes" followed by a newline.
    } else {
        cout << "No\n";  // Output "No" followed by a newline.
    }
}

// The main function is the entry point of the program.
int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop T times, calling the solve function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution.
}
```