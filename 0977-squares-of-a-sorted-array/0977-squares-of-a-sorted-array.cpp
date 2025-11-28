class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;

        // Split positive and negative numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        // Case 1: Only negative numbers
        if (pos.size() == 0) {
            for (int i = 0; i < neg.size(); i++)
                neg[i] = neg[i] * neg[i];  
            reverse(neg.begin(), neg.end());
            return neg;
        }

        // Case 2: Only positive numbers
        if (neg.size() == 0) {
            for (int i = 0; i < pos.size(); i++)
                pos[i] = pos[i] * pos[i];
            return pos;
        }

        // Case 3: Both exist → square both & merge
        for (int i = 0; i < pos.size(); i++)
            pos[i] = pos[i] * pos[i];

        for (int i = 0; i < neg.size(); i++)
            neg[i] = neg[i] * neg[i];

        reverse(neg.begin(), neg.end()); // now negative part is sorted

        // Merge two sorted arrays
        vector<int> result;
        int i = 0, j = 0;

        while (i < neg.size() && j < pos.size()) {
            if (neg[i] < pos[j])
                result.push_back(neg[i++]);
            else
                result.push_back(pos[j++]);
        }

        // Add remaining elements
        while (i < neg.size()) result.push_back(neg[i++]);
        while (j < pos.size()) result.push_back(pos[j++]);

        return result;
    }
};
