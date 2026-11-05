# [Mode of Frequencies (MODEFREQ)](https://www.codechef.com/problems/MODEFREQ)
- **Difficulty Rating**: 1234
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, where each element $A_i$ is between 1 and 10 inclusive. We need to find the "mode of frequencies". This means we first calculate the frequency of each distinct number present in $A$. Then, we consider these frequencies as a new set of values and find the mode of this new set. If there are multiple modes (i.e., multiple frequencies that appear the same maximum number of times), we should report the smallest such frequency.

## Intuition & Mathematical Observation

The problem asks us to find the mode of frequencies. Let's break this down:

1.  **Frequency of Numbers in A**: First, we need to know how many times each number from 1 to 10 appears in the input array $A$. Since the numbers are constrained to be between 1 and 10, we can use a small array (or map) to store these counts. For example, if $A = [2, 3, 2, 3, 3]$, the frequencies are:
    *   Frequency of 1: 0
    *   Frequency of 2: 2
    *   Frequency of 3: 3
    *   Frequencies of 4-10: 0

2.  **Frequencies of Frequencies**: Now, we look at the non-zero frequencies we just calculated. In the example above, the non-zero frequencies are 2 (for the number 2) and 3 (for the number 3). We then count how many times each of these frequencies appears.
    *   The frequency '2' appears once (because only the number '2' had a frequency of 2).
    *   The frequency '3' appears once (because only the number '3' had a frequency of 3).

    Let's consider another example: $A = [1, 1, 2, 2, 3, 3, 3, 4, 4, 4]$.
    *   Frequency of 1: 2
    *   Frequency of 2: 2
    *   Frequency of 3: 3
    *   Frequency of 4: 3
    *   Frequencies of 5-10: 0

    The non-zero frequencies are 2, 2, 3, 3. Now we find the frequencies of these frequencies:
    *   The frequency '2' appears 2 times (for numbers 1 and 2).
    *   The frequency '3' appears 2 times (for numbers 3 and 4).

3.  **Mode of Frequencies**: Finally, we find the mode of these "frequencies of frequencies". In the first example ($A = [2, 3, 2, 3, 3]$), the frequencies of frequencies were:
    *   Frequency '2' occurred 1 time.
    *   Frequency '3' occurred 1 time.
    Both frequencies (2 and 3) occur 1 time, which is the maximum. Since we need to report the *smallest* mode in case of a tie, the answer is 2.

    In the second example ($A = [1, 1, 2, 2, 3, 3, 3, 4, 4, 4]$), the frequencies of frequencies were:
    *   Frequency '2' occurred 2 times.
    *   Frequency '3' occurred 2 times.
    Both frequencies (2 and 3) occur 2 times, which is the maximum. The smallest mode is 2.

**Algorithm Steps:**

1.  **Count Element Frequencies**: Create an array `counts_A` of size 11 (indexed 0 to 10) initialized to zeros. Iterate through the input array $A$. For each element `val`, increment `counts_A[val]`.
2.  **Count Frequency Frequencies**: Create an array `counts_freq` of size $N+1$ (since the maximum possible frequency of any number is $N$) initialized to zeros. Iterate through `counts_A` from index 1 to 10. If `counts_A[v]` is greater than 0 (meaning number `v` appeared in $A$), let `freq_v = counts_A[v]`. Then, increment `counts_freq[freq_v]`.
3.  **Find Mode of Frequencies**: Initialize `max_freq_of_freq = -1` and `mode_freq = -1`. Iterate through `counts_freq` from index 1 up to $N$. For each index `w` (representing a frequency):
    *   If `counts_freq[w]` is greater than `max_freq_of_freq`:
        *   Update `max_freq_of_freq = counts_freq[w]`.
        *   Update `mode_freq = w`.
    *   If `counts_freq[w]` is equal to `max_freq_of_freq`, we do nothing. This is because we are iterating `w` in increasing order, so the current `w` would be larger than the `mode_freq` already stored, and we want the smallest mode.

The key observation for the tie-breaking rule is that by iterating through possible frequencies `w` in increasing order (from 1 to $N$), the first time we encounter a frequency `w` that has the maximum count of occurrences, that `w` will automatically be the smallest such frequency.

## Complexity Analysis

-   **Time Complexity**:
    *   Step 1 (Counting element frequencies): We iterate through the input array $A$ of size $N$. This takes $O(N)$ time.
    *   Step 2 (Counting frequency frequencies): We iterate through possible values of $A_i$, which are from 1 to 10. This is a constant number of iterations (10). So, this step takes $O(10) = O(1)$ time.
    *   Step 3 (Finding mode of frequencies): We iterate through possible frequencies, which can range from 1 to $N$. This takes $O(N)$ time.
    *   The dominant factor is $O(N)$. Therefore, the total time complexity is $O(N)$.

-   **Space Complexity**:
    *   `counts_A`: An array of size 11. This is $O(1)$ space.
    *   `counts_freq`: An array of size $N+1$. This is $O(N)$ space.
    *   The dominant factor is $O(N)$. Therefore, the total space complexity is $O(N)$.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Not strictly needed for this approach, but good to include for general competitive programming.

// Function to solve a single test case
void solve() {
    int N;
    std::cin >> N;

    // Step 1: Calculate frequency of each number in A.
    // A_i are between 1 and 10. So we need an array of size 11 (indices 0-10).
    // counts_A[v] will store the frequency of number 'v' in the input array A.
    std::vector<int> counts_A(11, 0); 
    for (int i = 0; i < N; ++i) {
        int val;
        std::cin >> val;
        counts_A[val]++;
    }

    // Step 2: Calculate frequency of these frequencies.
    // Frequencies (let's call them 'w') can range from 1 (if a number appears once)
    // up to N (if all numbers in A are identical).
    // counts_freq[w] will store how many distinct numbers 'v' had a frequency of 'w'.
    std::vector<int> counts_freq(N + 1, 0); 
    // Iterate through possible values of A_i (from 1 to 10).
    for (int v = 1; v <= 10; ++v) { 
        if (counts_A[v] > 0) { // If number 'v' actually appeared in the input array A
            int freq_v = counts_A[v]; // This is the frequency 'w' for number 'v'
            counts_freq[freq_v]++;    // Increment the count for this frequency 'w'
        }
    }

    // Step 3: Find the mode of frequencies (smallest one in case of tie).
    // max_freq_of_freq stores the highest count found for any frequency 'w'.
    // mode_freq stores the 'w' that corresponds to max_freq_of_freq.
    int max_freq_of_freq = -1; 
    int mode_freq = -1;        

    // Iterate 'w' from 1 to N.
    // Iterating in increasing order of 'w' automatically handles the "report the smallest one"
    // tie-breaking rule, because if a tie occurs, the first 'w' encountered will be the smallest.
    for (int w = 1; w <= N; ++w) {
        if (counts_freq[w] > 0) { // Only consider frequencies 'w' that actually occurred
            if (counts_freq[w] > max_freq_of_freq) {
                max_freq_of_freq = counts_freq[w];
                mode_freq = w;
            }
            // If counts_freq[w] == max_freq_of_freq, we do nothing.
            // This is because 'w' is greater than the current 'mode_freq' (due to increasing iteration),
            // and we need to report the smallest 'w' in case of a tie.
        }
    }
    
    std::cout << mode_freq << "\n";
}

int main() {
    // Fast I/O setup
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T; // Read the number of test cases
    while (T--) {  // Loop through each test case
        solve();
    }

    return 0;
}
```