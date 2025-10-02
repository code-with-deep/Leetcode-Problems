class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;

        vector<int> left(n), right(n);
        stack<int> st;

        // ----------- MAX Contribution -----------
        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while (!st.empty()) st.pop();
        // Next Greater or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            res += 1LL * nums[i] * left[i] * right[i];
        }

        // ----------- MIN Contribution -----------
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            res -= 1LL * nums[i] * left[i] * right[i];
        }

        return res;
    }
};
