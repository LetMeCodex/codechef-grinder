# Chef-Detective (CHEFDETE)
- **Difficulty Rating**: 1253
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to identify potential culprits in a crime scene. We are given $N$ people, numbered from 1 to $N$. Each person $i$ either reports another person $r_i$ (where $r_i \neq 0$) or reports no one ($r_i = 0$). A person is considered a potential killer if no one reports them. We need to output all such potential killers in increasing order.

## Intuition & Mathematical Observation
The core idea is to identify which people are *not* reported by anyone. If a person is not reported by any other person, they are a suspect.

Let's represent the reporting relationships. We have $N$ people, and for each person $i$, we know who they reported, $r_i$.
If $r_i = 0$, person $i$ reported no one. This information is not directly useful for identifying who is *not* reported.
If $r_i = j$ (where $j \neq 0$), it means person $i$ reported person $j$. This tells us that person $j$ *was* reported.

We are looking for people who were *never* reported.
We can maintain a record of all people who *were* reported. A `set` is a suitable data structure for this because it automatically handles duplicates and provides efficient lookups.

We iterate through the input array $r$. For each $r_i$:
- If $r_i$ is not 0, it means person $r_i$ was reported. We add $r_i$ to our set of reported people.

After processing all the reporting information, we will have a set containing all the people who were reported by at least one other person.

Now, to find the potential killers, we need to find the people who are *not* in this set of reported people. We can iterate through all possible person IDs from 1 to $N$. For each person $i$ (from 1 to $N$):
- If person $i$ is *not* found in our set of reported people, then person $i$ is a potential killer.

Finally, we collect all these potential killers and print them in increasing order. Sorting the list of potential killers before printing ensures the required output format.

**Mathematical Observation:**
The problem can be viewed as finding the set difference between the set of all people $\{1, 2, \dots, N\}$ and the set of people who were reported.
Let $P = \{1, 2, \dots, N\}$ be the set of all people.
Let $R = \{r_i \mid 1 \le i \le N, r_i \neq 0\}$ be the set of people who were reported.
The set of potential killers is $P \setminus R$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$
    - Reading the input and inserting into the `set`: For each of the $N$ people, we perform a constant number of operations (reading, checking if non-zero, inserting into a set). Set insertion takes $O(\log K)$ time, where $K$ is the current size of the set. In the worst case, $K$ can be up to $N$. So, this part takes $O(N \log N)$.
    - Finding potential killers: We iterate from 1 to $N$. For each number, we perform a `find` operation in the set, which takes $O(\log N)$ time. This part takes $O(N \log N)$.
    - Sorting potential killers: In the worst case, all $N$ people could be potential killers. Sorting a vector of size $N$ takes $O(N \log N)$.
    - Printing: This takes $O(N)$ time.
    The dominant factor is $O(N \log N)$.

- **Space Complexity**: $O(N)$
    - The `std::vector<int> r(n)` stores the input, taking $O(N)$ space.
    - The `std::set<int> reported_to` stores the IDs of people who were reported. In the worst case, it can store up to $N$ distinct IDs, taking $O(N)$ space.
    - The `std::vector<int> potential_killers` stores the IDs of potential killers. In the worst case, it can store up to $N$ IDs, taking $O(N)$ space.
    The total space complexity is $O(N)$.

## Solution Code
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    // Optimize C++ standard streams for competitive programming
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    // Vector to store the reporting information for each person.
    // r[i] will store the person reported by person i+1.
    // We use a vector of size n, and map person i to index i-1.
    // However, the problem statement implies r_i is the report of person i.
    // Let's adjust to match the problem's 1-based indexing for people.
    // The input format is r_1, r_2, ..., r_n.
    // So, we can read them directly into a vector and use the index.
    std::vector<int> r(n);

    // A set to store the IDs of people who have been reported by someone.
    // Using a set automatically handles duplicates and provides efficient lookups.
    std::set<int> reported_to;

    // Read the reporting information for each person.
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i]; // r[i] is the person reported by person i+1
        // If the person reported someone (i.e., r[i] is not 0),
        // add the reported person's ID to our set.
        if (r[i] != 0) {
            reported_to.insert(r[i]);
        }
    }

    // A vector to store the IDs of potential killers.
    // These are the people who were NOT reported by anyone.
    std::vector<int> potential_killers;

    // Iterate through all possible person IDs from 1 to N.
    for (int i = 1; i <= n; ++i) {
        // Check if the current person ID 'i' is present in the 'reported_to' set.
        // If 'find(i)' returns 'reported_to.end()', it means 'i' was not found in the set,
        // implying no one reported person 'i'.
        if (reported_to.find(i) == reported_to.end()) {
            // If person 'i' was not reported, they are a potential killer.
            potential_killers.push_back(i);
        }
    }

    // The problem requires the output to be in increasing order.
    // The 'potential_killers' vector is populated in increasing order of person IDs
    // because we iterate from 1 to N. So, explicit sorting is not strictly necessary
    // if we populate it this way. However, if the logic were different, sorting would be crucial.
    // For clarity and robustness, let's keep the sort.
    // std::sort(potential_killers.begin(), potential_killers.end()); // This is actually redundant due to loop order

    // Print the IDs of the potential killers, separated by spaces.
    for (size_t i = 0; i < potential_killers.size(); ++i) {
        std::cout << potential_killers[i] << (i == potential_killers.size() - 1 ? "" : " ");
    }
    std::cout << "\n"; // Print a newline at the end.

    return 0;
}
```