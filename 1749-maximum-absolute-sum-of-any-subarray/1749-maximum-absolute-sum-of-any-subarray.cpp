class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int posSum = 0;   // tracks max positive subarray sum
        int negSum = 0;   // tracks min (most negative) subarray sum
        int ans = 0;

        for (int x : nums) {
            // positive side
            posSum = max(0, posSum + x);
            ans = max(ans, posSum);

            // negative side
            negSum = min(0, negSum + x);
            ans = max(ans, abs(negSum));
        }

        return ans;
    }
};
