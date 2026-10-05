# [Dominant Element (DOMINANT2)](https://www.codechef.com/problems/DOMINANT2)
- **Difficulty Rating**: 1171
- **Solved in**: 1 attempt(s)

## Problem Summary

The problem asks us to determine if there exists a "dominant" element in a given array `A` of `N` integers. An element `X` is considered dominant if its frequency (the number of times it appears in the array) is strictly greater than the frequency of *any other* element present in the array. The elements `A_i` are guaranteed to be between 1 and `N`. We need to output "YES" if such a dominant element exists, and "NO" otherwise.

## Intuition & Mathematical Observation

The core of the problem lies in understanding the definition of a "dominant" element: its frequency must be strictly greater than *all other* elements' frequencies. This implies two crucial conditions:
1.  The dominant element must have the highest frequency among all elements.
2.  This highest frequency must be *unique* to that single element. If two or more distinct elements share the same maximum frequency, then no single element can be strictly more frequent than all others.

Based on this, our strategy will be:

1.  **Count Frequencies**: Iterate through the input array and count the occurrences of each element. Since the elements `A_i` are between 1 and `N`, a frequency array (or vector) of size `N+1` is an efficient way to store these counts. For example, `freq[x]` will store the count of element `x`.
2.  **Find Maximum Frequency**: While counting frequencies, simultaneously keep track of the `max_freq` encountered so far. This avoids a second pass just to find the maximum frequency.
3.  **Check for Uniqueness**: After processing the entire array, we will have the `max_freq`. Now, iterate through our frequency array (from 1 to `N`) and count how many *distinct* elements have a frequency equal to `max_freq`. Let's call this `count_of_max_freq_elements`.
4.  **Determine Dominance**:
    *   If `count_of_max_freq_elements` is exactly `1`, it means only one element achieved the maximum frequency. This element is dominant. Output "YES".
    *   If `count_of_max_freq_elements` is greater than `1`, it means multiple elements share the highest frequency. In this case, no single element can be strictly more frequent than all others. Output "NO".

**Example:**
*   `A = [1, 2, 1, 3]`
    *   `N = 4`
    *   Frequencies: `freq[1]=2`, `freq[2]=1`, `freq[3]=1`.
    *   `max_freq = 2`.
    *   Elements with `max_freq = 2`: Only element `1`. So, `count_of_max_freq_elements = 1`.
    *   Result: "YES" (element 1 is dominant).

*   `A = [1, 2, 1, 2]`
    *   `N = 4`
    *   Frequencies: `freq[1]=2`, `freq[2]=2`.
    *   `max_freq = 2`.
    *   Elements with `max_freq = 2`: Element `1` and element `2`. So, `count_of_max_freq_elements = 2`.
    *   Result: "NO" (both 1 and 2 have the maximum frequency).

## Complexity Analysis

*   **Time Complexity**:
    *   Reading `N`: $O(1)$.
    *   First loop (to read `N` elements, update frequencies, and find `max_freq`): This loop runs `N` times. Inside the loop, operations like `cin >> A_i`, `freq[A_i]++`, and updating `max_freq` are all $O(1)$. Thus, this part takes $O(N)$ time.
    *   Second loop (to count elements with `max_freq`): This loop iterates from `i = 1` to `N` (checking each possible element value). Inside the loop, checking `freq[i] == max_freq` is an $O(1)$ operation. Thus, this part also takes $O(N)$ time.
    *   Output: $O(1)$.
    *   Total time complexity for a single test case is $O(N) + O(N) = O(N)$.
    *   Since there are `T` test cases, the overall time complexity is $O(T \cdot N)$.

*   **Space Complexity**:
    *   `freq` vector: This vector is declared with size `N + 1` to store frequencies for elements from 1 to `N`. This requires $O(N)$ space.
    *   Other variables (`N`, `max_freq`, `A_i`, `count_of_max_freq_elements`, `T`): These use a constant amount of space, $O(1)$.
    *   Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <bits/stdc++.h> // Includes all standard libraries
using namespace std; // Uses the standard namespace

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the size of the array

    // Create a frequency array (vector) of size N+1, initialized to zeros.
    // This allows us to store frequencies for elements from 1 to N,
    // as per the problem constraints (1 <= A_i <= N).
    vector<int> freq(N + 1, 0); 
    int max_freq = 0; // Variable to store the maximum frequency found so far

    // Loop through the input array to count frequencies and find the maximum frequency
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i; // Read an element of the array
        freq[A_i]++; // Increment its frequency
        
        // Update max_freq if the current element's frequency is higher
        // This updates max_freq on the fly, avoiding a second pass just for max_freq.
        if (freq[A_i] > max_freq) {
            max_freq = freq[A_i];
        }
    }

    // Now, we need to count how many distinct elements have this maximum frequency.
    // If only one element has the maximum frequency, it's dominant.
    // Otherwise, if multiple elements share the maximum frequency, no element is dominant.
    int count_of_max_freq_elements = 0;
    for (int i = 1; i <= N; ++i) { // Iterate through possible element values (from 1 to N)
        if (freq[i] == max_freq) {
            count_of_max_freq_elements++;
        }
    }

    // Check the condition for dominance
    if (count_of_max_freq_elements == 1) {
        cout << "YES\n"; // Only one element has the maximum frequency, so it's dominant
    } else {
        cout << "NO\n"; // Multiple elements share the maximum frequency, or no elements exist (N>=1 so at least one element exists)
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming to prevent TLE (Time Limit Exceeded).
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}
```