class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minEnd = nums[0];
        int maxEnd = nums[0];

        int result = nums[0];
        for(int i=1; i<nums.size() ; i++){
            int v1 = nums[i];
            int v2 = minEnd * nums[i];
            int v3 = maxEnd * nums[i];

            maxEnd = max(v1,max(v2,v3));
            minEnd = min(v1,min(v2,v3));
            result = max(result,max(maxEnd,minEnd));
        }
        return result;
        
    }
};