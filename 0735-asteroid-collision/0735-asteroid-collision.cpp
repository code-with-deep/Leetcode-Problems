class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && a < 0) {
                if (st.top() < -a) {
                    st.pop();        // top asteroid smaller → explode
                    continue;
                } else if (st.top() == -a) {
                    st.pop();        // equal size → both explode
                }
                destroyed = true;    // current asteroid destroyed
                break;
            }

            if (!destroyed) st.push(a);
        }

        // Convert stack to vector
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
