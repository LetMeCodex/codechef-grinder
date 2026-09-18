# [DNA Storage (DNASTORAGE)](https://www.codechef.com/problems/DNASTORAGE)

- **Difficulty Rating**: 801
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to encode a binary string of length $N$ (where $N$ is even) into a DNA sequence using the following mapping rules:
- `00` $\rightarrow$ `A`
- `01` $\rightarrow$ `T`
- `10` $\rightarrow$ `C`
- `11` $\rightarrow$ `G`

Given the binary string, we need to process it in pairs of two characters and output the resulting DNA sequence.

## Intuition & Mathematical Observation
Since the mapping is based on pairs of bits, we can treat each pair as a 2-bit binary number. 
- A pair `b1b2` can be converted to a decimal index using the formula: `index = (b1 * 2) + b2`.
- Mapping these indices:
    - `00` $\rightarrow$ $0 \times 2 + 0 = 0$
    - `01` $\rightarrow$ $0 \times 2 + 1 = 1$
    - `10` $\rightarrow$ $1 \times 2 + 0 = 2$
    - `11` $\rightarrow$ $1 \times 2 + 1 = 3$

By creating a lookup table `{'A', 'T', 'C', 'G'}`, we can directly access the corresponding character using the calculated index, allowing for an efficient $O(N)$ transformation.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the binary string. We iterate through the string once, processing two characters at a time.
- **Space Complexity**: $O(N)$ to store the resulting encoded string.

## Solution Code

```cpp
#include <bits/stdc++.h> 

using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the length of the binary string
    string S;
    cin >> S; // Read the binary string

    string encoded_S = "";
    // Pre-allocate memory for the encoded string to improve performance
    encoded_S.reserve(N / 2);

    // Lookup table for the encoding rules:
    // Index 0: "00" -> 'A', 1: "01" -> 'T', 2: "10" -> 'C', 3: "11" -> 'G'
    char lookup_table[] = {'A', 'T', 'C', 'G'};

    // Iterate through the binary string, taking two characters at a time
    for (int i = 0; i < N; i += 2) {
        // Convert the character '0' or '1' to its integer equivalent (0 or 1)
        int val1 = S[i] - '0';
        int val2 = S[i+1] - '0';
        
        // Calculate the index for the lookup table: (val1 * 2) + val2
        int index = val1 * 2 + val2;
        
        // Append the corresponding encoded character
        encoded_S += lookup_table[index];
    }
    
    // Output the final encoded sequence
    cout << encoded_S << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { 
        solve(); 
    }

    return 0; 
}
```