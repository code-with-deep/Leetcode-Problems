class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];

            // Push opening brackets onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                // If stack is empty when a closing bracket appears
                if (st.empty()) return false;

                // Check for matching pair
                if ((st.top() == '(' && ch == ')') ||
                    (st.top() == '{' && ch == '}') ||
                    (st.top() == '[' && ch == ']')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        // Valid if no unmatched brackets remain
        return st.empty();
    }
};
