#include <stack>

class MinStack {
public:
    std::stack<int> s;
    std::stack<int> minS;

    MinStack() = default;

    void push(int value) {
        s.push(value);

        if (minS.empty() || value <= minS.top()) {
            minS.push(value);
        }
    }

    void pop() {
        if (!s.empty() && !minS.empty() && s.top() == minS.top()) {
            minS.pop();
        }
        if (!s.empty()) {
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};