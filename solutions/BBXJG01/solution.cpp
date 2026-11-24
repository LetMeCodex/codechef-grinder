#include <iostream>
#include <queue>
#include <string>
#include <vector> // Not strictly needed for the class itself, but often included.

class StackUsingQueues {
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    // Pushes the element x onto the top of the stack.
    void push(int x) {
        // To maintain LIFO, we push the new element to q1,
        // then move all elements from q2 to q1.
        // This ensures the new element is at the front of q1.
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        // Swap q1 and q2 so that q2 always holds the stack elements
        // in the correct order (newest at front).
        std::swap(q1, q2);
    }

    // Removes and returns the top element of the stack.
    int pop() {
        // Constraints guarantee pop() is valid, so q2 will not be empty.
        int top_element = q2.front();
        q2.pop();
        return top_element;
    }

    // Returns the top element of the stack without removing it.
    int top() {
        // Constraints guarantee top() is valid, so q2 will not be empty.
        return q2.front();
    }

    // Returns true if the stack is empty, otherwise returns false.
    bool empty() {
        return q2.empty();
    }
};

// The main function should be removed for submission to CodeChef
// as the platform provides its own main function to test your class.
/*
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        StackUsingQueues stack;
        for (int i = 0; i < n; ++i) {
            std::string operation;
            std::cin >> operation;
            if (operation == "push") {
                int x;
                std::cin >> x;
                stack.push(x);
                std::cout << "None\n";
            } else if (operation == "pop") {
                std::cout << stack.pop() << "\n";
            } else if (operation == "top") {
                std::cout << stack.top() << "\n";
            } else if (operation == "empty") {
                std::cout << (stack.empty() ? "true" : "false") << "\n";
            }
        }
    }
    return 0;
}
*/