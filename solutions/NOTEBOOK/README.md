# Count the Notebooks (NOTEBOOK)
- **Difficulty Rating**: 563
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem states that 1 kilogram of pulp can be used to produce 1000 pages of paper. A single notebook is made up of 100 pages. Given an amount of pulp in kilograms, we need to calculate the total number of notebooks that can be produced.

## Intuition & Mathematical Observation
The core of the problem lies in understanding the conversion rates between pulp, pages, and notebooks.

1.  **Pulp to Pages**: We are given that 1 kg of pulp yields 1000 pages.
2.  **Pages to Notebooks**: We are given that 1 notebook requires 100 pages.

Let's combine these two pieces of information to find out how many notebooks can be made from 1 kg of pulp:

If 1 kg of pulp makes 1000 pages, and each notebook needs 100 pages, then:
Number of notebooks from 1 kg of pulp = (Total pages from 1 kg of pulp) / (Pages per notebook)
Number of notebooks from 1 kg of pulp = 1000 pages / 100 pages/notebook = 10 notebooks.

So, for every kilogram of pulp, we can produce 10 notebooks.

Now, if we are given $N$ kilograms of pulp, the total number of notebooks that can be produced will be:
Total notebooks = (Number of kilograms of pulp) * (Notebooks per kilogram of pulp)
Total notebooks = $N \times 10$.

The input $N$ is an integer. The output, the number of notebooks, can also be an integer. Since $N$ can be up to $10^9$ (based on typical competitive programming constraints for integer inputs, though not explicitly stated here, it's good practice to consider), multiplying by 10 could result in a value up to $10^{10}$. A standard 32-bit integer (`int`) might overflow. Therefore, it's safer to use a 64-bit integer type like `long long` in C++ for storing the result to avoid potential overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$
    The solution involves a fixed number of arithmetic operations (multiplication and assignment) for each test case. The number of operations does not depend on the input value $N$.

- **Space Complexity**: $O(1)$
    The solution uses a constant amount of extra space to store variables like `t`, `n`, and `notebooks`, regardless of the input size.