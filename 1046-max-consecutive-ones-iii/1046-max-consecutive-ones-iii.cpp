class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int zeros = 0;
        int maxlen = 0;

        while (r < nums.size()) {
            if (nums[r] == 0)
                zeros++;

            // If we have more than k zeros, shrink the window from left
            while (zeros > k) {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }

            // Update maxlen
            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};
