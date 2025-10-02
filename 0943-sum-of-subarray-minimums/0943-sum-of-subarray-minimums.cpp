class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> left(n), right(n);
        stack<int> st;

        // Previous Smaller Element (strictly smaller)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        // Clear stack for Next Smaller Element
        while (!st.empty()) st.pop();

        // Next Smaller Element (smaller OR equal)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        // Contribution of each element
        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long contrib = (1LL * arr[i] * left[i] * right[i]) % MOD;
            res = (res + contrib) % MOD;
        }

        return (int)res;
    }
};
